/********************************************************************************
** Form generated from reading UI file 'IntroWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTROWIDGET_H
#define UI_INTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntroWidget
{
public:
    QLabel *gameTitle;
    QPushButton *rule;
    QPushButton *startGame;

    void setupUi(QWidget *IntroWidget)
    {
        if (IntroWidget->objectName().isEmpty())
            IntroWidget->setObjectName("IntroWidget");
        IntroWidget->resize(1000, 700);
        gameTitle = new QLabel(IntroWidget);
        gameTitle->setObjectName("gameTitle");
        gameTitle->setGeometry(QRect(235, 120, 530, 90));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(30);
        gameTitle->setFont(font);
        gameTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rule = new QPushButton(IntroWidget);
        rule->setObjectName("rule");
        rule->setGeometry(QRect(670, 10, 171, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(16);
        rule->setFont(font1);
        startGame = new QPushButton(IntroWidget);
        startGame->setObjectName("startGame");
        startGame->setGeometry(QRect(365, 310, 270, 130));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(18);
        startGame->setFont(font2);

        retranslateUi(IntroWidget);

        QMetaObject::connectSlotsByName(IntroWidget);
    } // setupUi

    void retranslateUi(QWidget *IntroWidget)
    {
        IntroWidget->setWindowTitle(QCoreApplication::translate("IntroWidget", "Form", nullptr));
        gameTitle->setText(QCoreApplication::translate("IntroWidget", "\344\270\255\350\217\257\346\226\207\345\214\226\347\237\245\350\255\23040\351\241\214", nullptr));
        rule->setText(QCoreApplication::translate("IntroWidget", "\350\246\217\345\211\207", nullptr));
        startGame->setText(QCoreApplication::translate("IntroWidget", "\351\226\213\345\247\213\346\270\270\346\210\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntroWidget: public Ui_IntroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROWIDGET_H
