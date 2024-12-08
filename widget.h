#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QStackedWidget>
#include "ui_introwidget.h"
#include "ui_outrowidget.h"
#include "ui_rulewidget.h"
#include <vector>
#include "questionmanagement.h"

class IntroWidget : public QWidget{
    Q_OBJECT
    public:
        IntroWidget(QWidget* parent = 0);
        Ui::IntroWidget* intro_form;
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
        std::vector<QuestionTemplate::MultipleChoice*> questionList;
        QuestionManagement* mng;
};

class OutroWidget : public QWidget{
    Q_OBJECT
    public:
        OutroWidget(QWidget* parent = 0);
        Ui::OutroWidget* ui;
    signals:
        void Replay();
};



#endif // WIDGET_H
