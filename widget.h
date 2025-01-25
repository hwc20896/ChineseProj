#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QStackedWidget>
#include "ui_introwidget.h"
#include "ui_outrowidget.h"
#include "ui_rulewidget.h"
#include <QList>
#include <QJsonDocument>
#include "questionmanagement.h"

class IntroWidget : public QWidget{
    Q_OBJECT
    public:
        IntroWidget(QWidget* parent = 0);
        Ui::IntroWidget* intro_form;
        bool isMuted = false;
        void SetMute(bool isMuted);
    private:
        QIcon muted, unmuted;
};

class RuleWidget : public QWidget{
    Q_OBJECT
    public:
        RuleWidget(QWidget* parent = 0);
        Ui::RuleWidget* rule_form;
};

class Widget : public QStackedWidget{
    public:
        Widget(QWidget* parent = 0);
    private:
        void startGame();
        void restartGame();
        void outroCall();
        QString AddColor(int Corr, size_t Count);
        QString TimeDisplay(double time);
        QList<QuestionTemplate::MultipleChoice> questionList;
        QuestionManagement* mng;
        QStringList featureList;
        QStringList modeExplanation;
        IntroWidget* intro;
        int currentGameMode = 0;

        QString title;
        bool defaultBGMMute = false;
        bool defaultEffectMute = false;
        int64_t hardmodeTick = 30000;
        int64_t displayCount = 1;
};

class OutroWidget : public QWidget{
    Q_OBJECT
    public:
        OutroWidget(QWidget* parent = 0);
        Ui::OutroWidget* ui;
        bool isMuted;
        void SetMute(bool isMuted);
    private:
        QIcon muted, unmuted;
    signals:
        void Replay();
};

namespace Json{
template <class T> QList<T> deserializeArray(const QString& jsonString);
}

#endif // WIDGET_H
