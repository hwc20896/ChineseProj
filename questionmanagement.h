#pragma once
#ifndef QUESTIONMANAGEMENT
#define QUESTIONMANAGEMENT
#include <QStackedWidget>
#include <vector>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "questiontemplate.h"

#define PrivateInsidePrivate

class QuestionManagement : public QStackedWidget{
    Q_OBJECT
    public:
        QuestionManagement(const std::vector<QuestionTemplate::MultipleChoice*>& questionList, size_t displayCount, QWidget* parent = 0);
        ~QuestionManagement();
    private:
        std::vector<QuestionTemplate::MultipleChoice*> questionList;
        std::vector<QuestionWidget::MultipleChoice*> pageList;
        std::vector<QuestionTemplate::MultipleChoice*> GetRandomOrder(std::vector<QuestionTemplate::MultipleChoice*> Questions, size_t Quantity);
        void Finish();
        void UpdatePages();
        std::vector<int> range(int Lim);
        int Corr=0, Incorr=0;
        int CurrentIndex=0;

        //  BGM & Sound effects
        QAudioOutput* out;
        QMediaPlayer* bgm;
    signals:
        void GameFinish();
};

#endif
