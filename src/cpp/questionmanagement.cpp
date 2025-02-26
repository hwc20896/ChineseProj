#include "src/headers/questionmanagement.h"
#include <algorithm>
#include <random>
#define TIMERUNSOUT &QTimer::timeout

QuestionManagement::QuestionManagement(const QList<QuestionTemplate::MultipleChoice>& questionList, int64_t displayCount, int Mode, int64_t time, QWidget* parent) : QStackedWidget(parent), displayCount(displayCount), questionList(questionList), Mode(Mode), countdownTime(time){
    if (questionList.size() < this->displayCount) throw std::out_of_range("Cannot assign, Question too few");
    auto order = GetRandomOrder(questionList, this->displayCount);
    bool isHardMode = this->Mode == 1;
    countdown = new QTimer;
    tick = new QTimer;
    timeLimit = countdownTime;
    connect(countdown,TIMERUNSOUT,this,&QuestionManagement::GameFinish);
    connect(tick,TIMERUNSOUT,this,[this]{
        timeLimit -= 1000;
        TimeTick();
    });

    muted.addFile(":/Drawables/drawables/mute.png");
    unmuted.addFile(":/Drawables/drawables/unmute.png");

    out = new QAudioOutput;
    out->setVolume(.15);
    for (int64_t i=0; i<this->displayCount;i++){
        QuestionWidget::MultipleChoice* page = new QuestionWidget::MultipleChoice(order[i],i);
        this->addWidget(page);
        pageList.push_back(page);
        if (i==0) page->ui->prevButton->setVisible(false);
        if (i==displayCount-1) page->ui->nextQuestion->setText("結束");
        page->ui->timerDisplay->setVisible(isHardMode);
        connect(page->ui->prevButton, BUTTONCLICK, this, [=,this]{this->setCurrentIndex(currentIndex()-1);});
        connect(page->ui->nextQuestion, BUTTONCLICK, this, [=,this]{
            if (i < displayCount-1) {
                this->setCurrentIndex(currentIndex()+1);
                if (!isHardMode) start = timer.now();
            }
            else emit GameFinish();
        });
        connect(page,&QuestionWidget::MultipleChoice::Score,this,[this](bool Corr){
            if (Corr) this->Corr++;
            else Incorr++;
            CurrentIndex++;
            UpdatePages();
        });
        connect(page,&QuestionWidget::MultipleChoice::TimeTap,this,[=,this]{
            if (!isHardMode){
                end = timer.now();
                long long timeLapsed = duration_cast<milliseconds>(end - start).count();
                timeStamp.push_back(timeLapsed);
            }
        });
        connect(page->ui->muteState,BUTTONCLICK,this,[=, this]{
            isMuted = !isMuted;
            UpdateMute();
        });
    }
    this->setCurrentIndex(0);
    UpdatePages();
    if (!isHardMode) start = timer.now();
    else {
        countdown->start(countdownTime);
        tick->start(1000);
        TimeTick();
    }

    bgm = new QMediaPlayer();
    bgm->setAudioOutput(out);
    bgm->setSource({"qrc:/BGM/medias/OMFG_Pizza.mp3"});
    connect(bgm,&QMediaPlayer::mediaStatusChanged,this,[=,this](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::LoadedMedia) bgm->play();
    });
}

QuestionManagement::~QuestionManagement(){
    bgm->disconnect();
    bgm->stop();
    delete bgm;
}

QList<QuestionTemplate::MultipleChoice> QuestionManagement::GetRandomOrder(QList<QuestionTemplate::MultipleChoice> Questions, int64_t Quantity){
    std::ranges::shuffle(Questions,std::mt19937_64(time(0)));
    return QList<QuestionTemplate::MultipleChoice>(Questions.begin(), Questions.begin() + Quantity);
}

void QuestionManagement::UpdatePages(){
    std::ranges::for_each(pageList,[=,this](QuestionWidget::MultipleChoice* i){
        i->SetScore(Corr,Incorr);
        i->SetProgress(CurrentIndex,pageList.size());
    });
}

void QuestionManagement::TimeTick(){
    int sec = timeLimit / 1000;
    std::ranges::for_each(pageList,[=,this](QuestionWidget::MultipleChoice* i){
        i->ui->timerDisplay->setText(QString(sec >= 20 ? "剩餘時間: %1:%2" : "剩餘時間: <font color=\"#ff0000\">%1:%2</font>").arg(floor(TODOUBLE(timeLimit)/countdownTime)).arg(sec%60 < 10 ? QString("0%1").arg(sec%60) : QString::number(sec%60)));
    });
}

void QuestionManagement::UpdateMute(){
    out->setMuted(isMuted);
    std::ranges::for_each(pageList,[=,this](QuestionWidget::MultipleChoice* i){i->ui->muteState->setIcon(isMuted?muted:unmuted);});
}

void QuestionManagement::setEffectMute(bool isMute){
    std::ranges::for_each(pageList,[=](QuestionWidget::MultipleChoice* i){
        i->corrSound->setMuted(isMute);
        i->incorrSound->setMuted(isMute);
    });
}
