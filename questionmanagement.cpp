#include "questionmanagement.h"
#include <algorithm>
#include <random>
#define TIMERUNSOUT &QTimer::timeout

QuestionManagement::QuestionManagement(const std::vector<QuestionTemplate::MultipleChoice*>& questionList, size_t displayCount, int Mode, QWidget* parent) : QStackedWidget(parent), displayCount(displayCount), questionList(questionList), Mode(Mode){
    this->resize(1000,700);
    if (questionList.size() < this->displayCount) throw std::out_of_range("Cannot assign, Question too few");
    auto order = GetRandomOrder(questionList, this->displayCount);
    bool isHardMode = this->Mode == 1;
    countdown = new QTimer;
    tick = new QTimer;
    timeLimit = countdownTime;
    connect(countdown,TIMERUNSOUT,this,&QuestionManagement::GameFinish);
    connect(tick,TIMERUNSOUT,this,[=]{
        timeLimit -= 1000;
        TimeTick();
    });
    for (size_t i=0; i<this->displayCount;i++){
        QuestionWidget::MultipleChoice* page = new QuestionWidget::MultipleChoice(order[i],i);
        this->addWidget(page);
        pageList.push_back(page);
        if (i==0) page->ui->prevButton->setVisible(false);
        if (i==displayCount-1) page->ui->nextQuestion->setText("結束");
        page->ui->timerDisplay->setVisible(isHardMode);
        connect(page->ui->prevButton, BUTTONCLICK, this, [=]{this->setCurrentIndex(currentIndex()-1);});
        connect(page->ui->nextQuestion, BUTTONCLICK, this, [=]{
            if (i < displayCount-1) {
                this->setCurrentIndex(currentIndex()+1);
                if (!isHardMode) start = timer.now();
            }
            else emit GameFinish();
        });
        connect(page,&QuestionWidget::MultipleChoice::Score,this,[=](bool Corr){
            if (Corr) this->Corr++;
            else Incorr++;
            CurrentIndex++;
            UpdatePages();
        });
        connect(page,&QuestionWidget::MultipleChoice::TimeTap,this,[=]{
            if (!isHardMode){
                end = timer.now();
                long long timeLapsed = duration_cast<milliseconds>(end - start).count();
                timeStamp.push_back(timeLapsed);
            }
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

    out = new QAudioOutput;
    out->setVolume(.15);
    bgm = new QMediaPlayer();
    bgm->setAudioOutput(out);
    bgm->setSource(QUrl("qrc:/BGM/OMFG_Pizza.mp3"));
    connect(bgm,&QMediaPlayer::mediaStatusChanged,this,[=](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::LoadedMedia) bgm->play();
    });
}

QuestionManagement::~QuestionManagement(){
    bgm->disconnect();
    bgm->stop();
    delete bgm;
}

std::vector<QuestionTemplate::MultipleChoice*> QuestionManagement::GetRandomOrder(std::vector<QuestionTemplate::MultipleChoice*> Questions, size_t Quantity){
    std::shuffle(Questions.begin(),Questions.end(),std::mt19937_64(time(0)));
    return std::vector<QuestionTemplate::MultipleChoice*>(Questions.begin(), Questions.begin() + Quantity);
}

void QuestionManagement::UpdatePages(){
    for (auto i : pageList){
        i->SetScore(Corr,Incorr);
        i->SetProgress(CurrentIndex,pageList.size());
    }
}

void QuestionManagement::TimeTick(){
    int sec = timeLimit / 1000;
    for (auto i : pageList){
        if (sec >= 20)  i->ui->timerDisplay->setText(QString("Time left: %1:%2").arg(floor(TODOUBLE(timeLimit)/countdownTime)).arg(sec%60 < 10 ? QString("0%1").arg(sec%60) : QString::number(sec%60)));
        else i->ui->timerDisplay->setText(QString("Time left: <font color=\"#ff0000\">%1:%2</font>").arg(floor(TODOUBLE(timeLimit)/countdownTime)).arg(sec%60 < 10 ? QString("0%1").arg(sec%60) : QString::number(sec%60)));
    }
}
