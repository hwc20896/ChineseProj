#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include "ui_introwidget.h"

class IntroWidget : public QWidget{
    Q_OBJECT
    public:
        IntroWidget(QWidget* parent = 0);
    private:
        Ui::IntroWidget* intro_form;
        void startGame();
};

#endif // WIDGET_H
