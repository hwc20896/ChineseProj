#pragma once
#ifndef QUESTIONMANAGEMENT
#define QUESTIONMANAGEMENT
#include <QStackedWidget>
#include <vector>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSoundEffect>
#include <chrono>
#include <QTimer>
#include "questiontemplate.h"
using namespace std::chrono;

#define PrivateInsidePrivate

class QuestionManagement : public QStackedWidget{
    Q_OBJECT
    public:
        QuestionManagement(const std::vector<QuestionTemplate::MultipleChoice*>& questionList, size_t displayCount, int Mode,QWidget* parent = 0);
        ~QuestionManagement();
        std::vector<long long> timeStamp;
        size_t displayCount;
        int Corr = 0;
    private:
        std::vector<QuestionTemplate::MultipleChoice*> questionList;
        std::vector<QuestionWidget::MultipleChoice*> pageList;
        std::vector<QuestionTemplate::MultipleChoice*> GetRandomOrder(std::vector<QuestionTemplate::MultipleChoice*> Questions, size_t Quantity);
        void UpdatePages();
        std::vector<int> range(int Lim);
        int Incorr=0;
        int CurrentIndex=0;
        int Mode = 0;

        //  BGM & Sound effects
        QAudioOutput* out;
        QMediaPlayer* bgm;

        //  Timer
        high_resolution_clock timer;
        time_point<high_resolution_clock> start, end;

        //  Countdown
        QTimer* countdown,* tick;
        void TimeTick();
        static constexpr double countdownTime = 6e4;
        double timeLimit;
    signals:
        void GameFinish();
};

#endif
