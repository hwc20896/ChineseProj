#include "outrowidget.h"
#include <QApplication>

OutroWidget::OutroWidget(QWidget* parent) : QWidget(parent){
    QLabel* tempLabel = new QLabel("On Construction",this);
    tempLabel->setGeometry(100,100,500,100);
    tempLabel->setAlignment(Qt::AlignCenter);
}

void OutroWidget::keyPressEvent(QKeyEvent* event){
    if (event->key() == Qt::Key_Escape) qApp->quit();
}
