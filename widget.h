#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include "ui_introwidget.h"
#include "ui_outrowidget.h"
#include <vector>
#include "questionmanagement.h"

class IntroWidget : public QWidget{
    Q_OBJECT
    public:
        IntroWidget(QWidget* parent = 0);
    private:
        Ui::IntroWidget* intro_form;
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
