#ifndef OUTROWIDGET_H
#define OUTROWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

class OutroWidget : public QWidget{
    Q_OBJECT
    public:
        OutroWidget(QWidget* parent = 0);
    private:
        void keyPressEvent(QKeyEvent* event);
};

#endif // OUTROWIDGET_H
