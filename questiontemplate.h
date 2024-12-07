#pragma once
#ifndef QUESTIONTEMPLATE
#define QUESTIONTEMPLATE
#include <QWidget>
#include <QString>
#include <array>
#include <map>
#include <QPushButton>
#include "ui_multiplechoiceform.h"

#define Functions
#define Variables
#define Widgets

#define TODOUBLE(val) static_cast<double>(val)
#define BUTTONCLICK &QPushButton::clicked

namespace QuestionTemplate{
struct MultipleChoice;
}

namespace QuestionWidget{
class MultipleChoice;
}

enum Option{A,B,C,D};

struct QuestionTemplate::MultipleChoice{
    MultipleChoice(QString questiontitle, const std::array<QString, 4>& options, Option corroption) : QuestionTitle(questiontitle), Options(options), CorrOption(corroption){}
    QString QuestionTitle;
    std::array<QString, 4> Options;
    Option CorrOption;
};

class QuestionWidget::MultipleChoice : public QWidget{
    Q_OBJECT
    public:
        MultipleChoice(QuestionTemplate::MultipleChoice* question, size_t Index, QWidget* parent = 0);
        ~MultipleChoice();
        Ui::MultipleChoice* ui;
        inline void SetScore(int Corr, int Incorr){ui->correctState->setText(QString("<font color=\"#ff0000\">錯誤數 %1</font> | <font color=\"#00dd12\">%2 正確數</font>").arg(Incorr).arg(Corr));}
        inline void SetProgress(int CurrentProgress, int Total){ui->progress->setText(QString("進度：%1 / %2 - %3%").arg(CurrentProgress).arg(Total).arg(TODOUBLE(CurrentProgress) / TODOUBLE(Total) * 100, 0, 'g', 2));}
    private:
        QuestionTemplate::MultipleChoice* question;
        std::map<Option, QPushButton*> OptiontoButton;
        void AnswerCheck(Option option);
        void Cooldown(int msec);
        size_t Index = 0;
        bool Answered = false;
    signals:
        void Score(bool Corr);
};

#endif
