/********************************************************************************
** Form generated from reading UI file 'OutroWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTROWIDGET_H
#define UI_OUTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutroWidget
{
public:
    QLabel *tempLabel;
    QPushButton *replayButton;

    void setupUi(QWidget *OutroWidget)
    {
        if (OutroWidget->objectName().isEmpty())
            OutroWidget->setObjectName("OutroWidget");
        OutroWidget->resize(1000, 700);
        tempLabel = new QLabel(OutroWidget);
        tempLabel->setObjectName("tempLabel");
        tempLabel->setGeometry(QRect(280, 160, 391, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(20);
        tempLabel->setFont(font);
        tempLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        replayButton = new QPushButton(OutroWidget);
        replayButton->setObjectName("replayButton");
        replayButton->setGeometry(QRect(370, 440, 241, 111));
        QFont font1;
        font1.setPointSize(20);
        replayButton->setFont(font1);

        retranslateUi(OutroWidget);

        QMetaObject::connectSlotsByName(OutroWidget);
    } // setupUi

    void retranslateUi(QWidget *OutroWidget)
    {
        OutroWidget->setWindowTitle(QCoreApplication::translate("OutroWidget", "Form", nullptr));
        tempLabel->setText(QCoreApplication::translate("OutroWidget", "Outro page under construction", nullptr));
        replayButton->setText(QCoreApplication::translate("OutroWidget", "Replay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutroWidget: public Ui_OutroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTROWIDGET_H
