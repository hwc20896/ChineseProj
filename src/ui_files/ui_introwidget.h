/********************************************************************************
** Form generated from reading UI file 'IntroWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTROWIDGET_H
#define UI_INTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntroWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *upperNavigator;
    QPushButton *muteSwitch;
    QPushButton *rule;
    QLabel *gameTitle;
    QVBoxLayout *gamemode;
    QHBoxLayout *featureBoxLayout;
    QComboBox *featureBox;
    QLabel *gamemodeExplanation;
    QHBoxLayout *startLayout;
    QPushButton *startGame;

    void setupUi(QWidget *IntroWidget)
    {
        if (IntroWidget->objectName().isEmpty())
            IntroWidget->setObjectName("IntroWidget");
        IntroWidget->resize(1000, 700);
        verticalLayout = new QVBoxLayout(IntroWidget);
        verticalLayout->setSpacing(80);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 90);
        upperNavigator = new QHBoxLayout();
        upperNavigator->setSpacing(400);
        upperNavigator->setObjectName("upperNavigator");
        upperNavigator->setContentsMargins(120, -1, -1, -1);
        muteSwitch = new QPushButton(IntroWidget);
        muteSwitch->setObjectName("muteSwitch");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(muteSwitch->sizePolicy().hasHeightForWidth());
        muteSwitch->setSizePolicy(sizePolicy);
        muteSwitch->setMinimumSize(QSize(50, 50));
        muteSwitch->setMaximumSize(QSize(120, 120));
        QFont font;
        font.setPointSize(12);
        muteSwitch->setFont(font);
        muteSwitch->setIconSize(QSize(80, 80));

        upperNavigator->addWidget(muteSwitch);

        rule = new QPushButton(IntroWidget);
        rule->setObjectName("rule");
        rule->setMinimumSize(QSize(120, 0));
        rule->setMaximumSize(QSize(150, 80));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(20);
        rule->setFont(font1);

        upperNavigator->addWidget(rule);


        verticalLayout->addLayout(upperNavigator);

        gameTitle = new QLabel(IntroWidget);
        gameTitle->setObjectName("gameTitle");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(30);
        gameTitle->setFont(font2);
        gameTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(gameTitle);

        gamemode = new QVBoxLayout();
        gamemode->setSpacing(30);
        gamemode->setObjectName("gamemode");
        featureBoxLayout = new QHBoxLayout();
        featureBoxLayout->setObjectName("featureBoxLayout");
        featureBox = new QComboBox(IntroWidget);
        featureBox->setObjectName("featureBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(featureBox->sizePolicy().hasHeightForWidth());
        featureBox->setSizePolicy(sizePolicy1);
        featureBox->setMaximumSize(QSize(300, 16777215));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font3.setPointSize(25);
        featureBox->setFont(font3);
        featureBox->setStyleSheet(QString::fromUtf8(""));
        featureBox->setEditable(false);
        featureBox->setCurrentText(QString::fromUtf8(""));

        featureBoxLayout->addWidget(featureBox);


        gamemode->addLayout(featureBoxLayout);

        gamemodeExplanation = new QLabel(IntroWidget);
        gamemodeExplanation->setObjectName("gamemodeExplanation");
        gamemodeExplanation->setFont(font1);
        gamemodeExplanation->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gamemode->addWidget(gamemodeExplanation);


        verticalLayout->addLayout(gamemode);

        startLayout = new QHBoxLayout();
        startLayout->setObjectName("startLayout");
        startGame = new QPushButton(IntroWidget);
        startGame->setObjectName("startGame");
        startGame->setMinimumSize(QSize(0, 80));
        startGame->setMaximumSize(QSize(180, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font4.setPointSize(18);
        startGame->setFont(font4);

        startLayout->addWidget(startGame);


        verticalLayout->addLayout(startLayout);


        retranslateUi(IntroWidget);

        QMetaObject::connectSlotsByName(IntroWidget);
    } // setupUi

    void retranslateUi(QWidget *IntroWidget)
    {
        IntroWidget->setWindowTitle(QCoreApplication::translate("IntroWidget", "Form", nullptr));
        muteSwitch->setText(QString());
        rule->setText(QCoreApplication::translate("IntroWidget", "\350\246\217\345\211\207", nullptr));
        gameTitle->setText(QCoreApplication::translate("IntroWidget", "\344\270\255\350\217\257\346\226\207\345\214\226\347\237\245\350\255\230100\351\241\214", nullptr));
        gamemodeExplanation->setText(QCoreApplication::translate("IntroWidget", "TextLabel", nullptr));
        startGame->setText(QCoreApplication::translate("IntroWidget", "\351\226\213\345\247\213\351\201\212\346\210\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntroWidget: public Ui_IntroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROWIDGET_H
