#pragma once
#ifndef QUESTIONMANAGEMENT
#define QUESTIONMANAGEMENT
#include <QStackedWidget>
#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSoundEffect>
#include <chrono>
#include <QTimer>
#include <QIcon>
#include "questiontemplate.h"
using namespace std::chrono;

class QuestionManagement : public QStackedWidget{
    Q_OBJECT
    public:
        QuestionManagement(const QList<QuestionTemplate::MultipleChoice>& questionList, int64_t displayCount, int Mode,QWidget* parent = 0);
        ~QuestionManagement();
        QList<int64_t> timeStamp;
        int64_t displayCount;
        int Corr = 0;

        //  Mute Switch
        QIcon muted, unmuted;
        bool isMuted;
        void UpdateMute();
    private:
        QList<QuestionTemplate::MultipleChoice> questionList;
        QList<QuestionWidget::MultipleChoice*> pageList;
        QList<QuestionTemplate::MultipleChoice> GetRandomOrder(QList<QuestionTemplate::MultipleChoice> Questions, int64_t Quantity);
        void UpdatePages();
        QList<int> range(int Lim);
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
