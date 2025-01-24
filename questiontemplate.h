#pragma once
#ifndef QUESTIONTEMPLATE
#define QUESTIONTEMPLATE
#include <QWidget>
#include <QString>
#include <map>
#include <QPushButton>
#include <QSoundEffect>

#include <QJsonArray>
#include <QJsonObject>
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

struct QuestionTemplate::MultipleChoice{
    explicit MultipleChoice(QString questiontitle, const QStringList& options, int corroption) : QuestionTitle(questiontitle), Options(options), CorrOption(corroption){assert(options.size() <= 4);}
    explicit MultipleChoice(QJsonObject jsonObject) : MultipleChoice(jsonObject.value("questiontitle").toString(),jsonObject.value("options").toVariant().toStringList(), jsonObject.value("corroption").toInt()){}
    QString QuestionTitle;
    QStringList Options;
    int CorrOption;
};

class QuestionWidget::MultipleChoice : public QWidget{
    Q_OBJECT
    public:
        MultipleChoice(QuestionTemplate::MultipleChoice question, size_t Index, QWidget* parent = 0);
        ~MultipleChoice();
        Ui::MultipleChoice* ui;
        void SetScore(int Corr, int Incorr);
        void SetProgress(int CurrentProgress, int Total);
    private:
        QuestionTemplate::MultipleChoice question;
        QString corrText;
        std::map<QString,QPushButton*> textToButton;

        void AnswerCheck(QPushButton* targetButton);
        void Cooldown(int msec);
        size_t Index = 0;
        bool Answered = false;
        QSoundEffect* corrSound,* incorrSound;
    signals:
        void Score(bool Corr);
        void TimeTap();
};

#endif
