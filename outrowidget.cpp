#include "outrowidget.h"
#include <QApplication>

OutroWidget::OutroWidget(QWidget* parent) : QWidget(parent){
    this->resize(1000,700);

    QLabel* tempLabel = new QLabel("結束頁面建設中",this);
    tempLabel->setGeometry(100,100,500,100);
    tempLabel->setAlignment(Qt::AlignCenter);
}

void OutroWidget::keyPressEvent(QKeyEvent* event){
    if (event->key() == Qt::Key_Escape) qApp->quit();
}
