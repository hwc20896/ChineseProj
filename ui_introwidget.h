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
#include <QtWidgets/QComboBox>
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
    QComboBox *featureBox;
    QLabel *gamemodeExplanation;
    QPushButton *muteSwitch;

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
        rule->setGeometry(QRect(670, 10, 170, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(20);
        rule->setFont(font1);
        startGame = new QPushButton(IntroWidget);
        startGame->setObjectName("startGame");
        startGame->setGeometry(QRect(360, 500, 270, 130));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(18);
        startGame->setFont(font2);
        featureBox = new QComboBox(IntroWidget);
        featureBox->setObjectName("featureBox");
        featureBox->setGeometry(QRect(360, 340, 270, 81));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font3.setPointSize(25);
        featureBox->setFont(font3);
        featureBox->setStyleSheet(QString::fromUtf8(""));
        featureBox->setCurrentText(QString::fromUtf8(""));
        gamemodeExplanation = new QLabel(IntroWidget);
        gamemodeExplanation->setObjectName("gamemodeExplanation");
        gamemodeExplanation->setGeometry(QRect(210, 430, 580, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font4.setPointSize(16);
        gamemodeExplanation->setFont(font4);
        gamemodeExplanation->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        muteSwitch = new QPushButton(IntroWidget);
        muteSwitch->setObjectName("muteSwitch");
        muteSwitch->setGeometry(QRect(230, 10, 50, 50));
        muteSwitch->setIconSize(QSize(40, 40));

        retranslateUi(IntroWidget);

        QMetaObject::connectSlotsByName(IntroWidget);
    } // setupUi

    void retranslateUi(QWidget *IntroWidget)
    {
        IntroWidget->setWindowTitle(QCoreApplication::translate("IntroWidget", "Form", nullptr));
        gameTitle->setText(QCoreApplication::translate("IntroWidget", "\344\270\255\350\217\257\346\226\207\345\214\226\347\237\245\350\255\230100\351\241\214", nullptr));
        rule->setText(QCoreApplication::translate("IntroWidget", "\350\246\217\345\211\207", nullptr));
        startGame->setText(QCoreApplication::translate("IntroWidget", "\351\226\213\345\247\213\346\270\270\346\210\262", nullptr));
        gamemodeExplanation->setText(QCoreApplication::translate("IntroWidget", "TextLabel", nullptr));
        muteSwitch->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IntroWidget: public Ui_IntroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROWIDGET_H
