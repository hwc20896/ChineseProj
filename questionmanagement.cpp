#include "questionmanagement.h"
#include <algorithm>
#include <random>

QuestionManagement::QuestionManagement(const std::vector<QuestionTemplate::MultipleChoice*>& questionList, size_t displayCount, QWidget* parent) : QStackedWidget(parent), displayCount(displayCount), questionList(questionList){
    this->resize(1000,700);
    if (questionList.size() < this->displayCount) throw std::out_of_range("Cannot assign, Question too few");
    auto order = GetRandomOrder(questionList, this->displayCount);
    for (size_t i=0; i<this->displayCount;i++){
        QuestionWidget::MultipleChoice* page = new QuestionWidget::MultipleChoice(order[i],i);
        this->addWidget(page);
        pageList.push_back(page);
        if (i==0) page->ui->prevButton->setVisible(false);
        if (i==displayCount-1) page->ui->nextQuestion->setText("結束");
        connect(page->ui->prevButton, BUTTONCLICK, this, [=]{this->setCurrentIndex(currentIndex()-1);});
        connect(page->ui->nextQuestion, BUTTONCLICK, this, [=]{
            if (i < displayCount-1) {
                this->setCurrentIndex(currentIndex()+1);
                start = timer.now();
            }
            else Finish();
        });
        connect(page,&QuestionWidget::MultipleChoice::Score,this,[=](bool Corr){
            if (Corr) this->Corr++;
            else Incorr++;
            CurrentIndex++;
            UpdatePages();
        });
        connect(page,&QuestionWidget::MultipleChoice::TimeTap,this,[=]{
            end = timer.now();
            long long timeLapsed = duration_cast<milliseconds>(end - start).count();
            timeStamp.push_back(timeLapsed);
        });
    }
    this->setCurrentIndex(0);
    UpdatePages();
    start = timer.now();

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

void QuestionManagement::Finish(){
    emit GameFinish();
}
