#pragma once
#ifndef QUESTIONTEMPLATE
#define QUESTIONTEMPLATE
#include <QWidget>
#include <QString>
#include <array>
#include <map>
#include <QPushButton>
#include "ui_multiplechoiceform.h"
#include "ui_trueorfalse.h"
#include "ui_questionbaseform.h"

#define Functions
#define Variables
#define Widgets

#define TODOUBLE(val) static_cast<double>(val)

namespace Question{
struct QuestionBase;
struct MultipleChoice;
struct TrueorFalse;
}

namespace QuestionTemplate{
class QuestionBase;
class MultipleChoice;
class TrueorFalse;
}

struct Question::QuestionBase{virtual ~QuestionBase() = default;};

struct Question::MultipleChoice : QuestionBase{
    MultipleChoice(QString questiontitle, const std::array<QString, 4>& options, int corroption, QString description="") : QuestionTitle(questiontitle), Options(options), CorrOption(corroption), Description(description){}
    QString QuestionTitle;
    std::array<QString, 4> Options;
    int CorrOption;
    QString Description;
};

struct Question::TrueorFalse : QuestionBase{
    TrueorFalse(QString questiontitle, bool corroption, QString description="") : QuestionTitle(questiontitle), CorrOption(corroption), Description(description){}
    QString QuestionTitle;
    bool CorrOption;
    QString Description;
};

using QQB = Question::QuestionBase;
using QMC = Question::MultipleChoice;
using QTF = Question::TrueorFalse;

class QuestionTemplate::QuestionBase : public QWidget{
    Q_OBJECT
    public:
        QuestionBase(QWidget* parent = 0);
        ~QuestionBase();
        inline void SetScore(int Corr, int Incorr){base_ui->correctState->setText(QString("<font color=\"#ff0000\">錯誤數 %1</font> | <font color=\"#00dd12\">%2 正確數</font>").arg(Incorr).arg(Corr));}
        inline void SetProgress(int CurrentProgress, int Total){base_ui->progress->setText(QString("進度：%1 / %2 - %3%").arg(CurrentProgress).arg(Total).arg(TODOUBLE(CurrentProgress) / TODOUBLE(Total) * 100));}
        Ui::QuestionBase* base_ui;
    protected:
        void Cooldown(int msec);
    signals:
        void Score(bool Corr);
};

class QuestionTemplate::MultipleChoice : public QuestionBase{
    public Functions:
        MultipleChoice(QMC* question, QWidget* parent = 0);
        ~MultipleChoice();
        inline void SetIndex(int Index){this->Index = Index;}
    public Variables:
        Ui::MultipleChoice* ui;
    private Variables:
        QMC* Question;
        std::map<int,QPushButton*> IndextoButton;
        bool Answered = false;
        int Index = 1;
    private Functions:
        void AnswerCheck(int Option);
};

class QuestionTemplate::TrueorFalse : public QuestionBase{
    public Functions:
        TrueorFalse(QTF* question, QWidget* parent = 0);
        ~TrueorFalse();
        inline void SetIndex(int Index){this->Index = Index;}
    public Variables:
        Ui::TrueorFalse* ui;
    private Variables:
        QTF* Question;
        bool Answered = false;
        int Index = 1;
    private Functions:
        void AnswerCheck(bool Option);
        QPushButton* OptiontoButton(bool Option);
};

using QTQB = QuestionTemplate::QuestionBase;
using QTMC = QuestionTemplate::MultipleChoice;
using QTTF = QuestionTemplate::TrueorFalse;

#endif
