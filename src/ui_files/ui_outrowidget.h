/********************************************************************************
** Form generated from reading UI file 'OutroWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTROWIDGET_H
#define UI_OUTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutroWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *upperNavigator;
    QPushButton *muteSwitch;
    QPushButton *exitButton;
    QVBoxLayout *resultLayout;
    QLabel *title;
    QLabel *score;
    QLabel *totalTime;
    QLabel *avgTime;
    QVBoxLayout *gamemodeLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *featureBox;
    QLabel *gamemodeExplanation;
    QPushButton *replayButton;

    void setupUi(QWidget *OutroWidget)
    {
        if (OutroWidget->objectName().isEmpty())
            OutroWidget->setObjectName("OutroWidget");
        OutroWidget->resize(1000, 700);
        QFont font;
        font.setPointSize(25);
        OutroWidget->setFont(font);
        verticalLayout = new QVBoxLayout(OutroWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 40);
        upperNavigator = new QHBoxLayout();
        upperNavigator->setSpacing(650);
        upperNavigator->setObjectName("upperNavigator");
        muteSwitch = new QPushButton(OutroWidget);
        muteSwitch->setObjectName("muteSwitch");
        muteSwitch->setMaximumSize(QSize(50, 50));
        muteSwitch->setIconSize(QSize(40, 40));

        upperNavigator->addWidget(muteSwitch);

        exitButton = new QPushButton(OutroWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setMaximumSize(QSize(120, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(16);
        exitButton->setFont(font1);

        upperNavigator->addWidget(exitButton);


        verticalLayout->addLayout(upperNavigator);

        resultLayout = new QVBoxLayout();
        resultLayout->setSpacing(40);
        resultLayout->setObjectName("resultLayout");
        resultLayout->setContentsMargins(-1, -1, -1, 40);
        title = new QLabel(OutroWidget);
        title->setObjectName("title");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(26);
        title->setFont(font2);
        title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        resultLayout->addWidget(title);

        score = new QLabel(OutroWidget);
        score->setObjectName("score");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font3.setPointSize(18);
        score->setFont(font3);
        score->setTextFormat(Qt::TextFormat::MarkdownText);
        score->setAlignment(Qt::AlignmentFlag::AlignCenter);

        resultLayout->addWidget(score);

        totalTime = new QLabel(OutroWidget);
        totalTime->setObjectName("totalTime");
        totalTime->setFont(font3);
        totalTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        resultLayout->addWidget(totalTime);

        avgTime = new QLabel(OutroWidget);
        avgTime->setObjectName("avgTime");
        avgTime->setFont(font3);
        avgTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        resultLayout->addWidget(avgTime);


        verticalLayout->addLayout(resultLayout);

        gamemodeLayout = new QVBoxLayout();
        gamemodeLayout->setObjectName("gamemodeLayout");
        gamemodeLayout->setContentsMargins(-1, 15, -1, 15);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        featureBox = new QComboBox(OutroWidget);
        featureBox->setObjectName("featureBox");
        featureBox->setMaximumSize(QSize(240, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font4.setPointSize(25);
        featureBox->setFont(font4);
        featureBox->setStyleSheet(QString::fromUtf8(""));
        featureBox->setEditable(false);

        horizontalLayout->addWidget(featureBox);


        gamemodeLayout->addLayout(horizontalLayout);

        gamemodeExplanation = new QLabel(OutroWidget);
        gamemodeExplanation->setObjectName("gamemodeExplanation");
        gamemodeExplanation->setFont(font1);
        gamemodeExplanation->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        gamemodeLayout->addWidget(gamemodeExplanation);


        verticalLayout->addLayout(gamemodeLayout);

        replayButton = new QPushButton(OutroWidget);
        replayButton->setObjectName("replayButton");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font5.setPointSize(20);
        replayButton->setFont(font5);

        verticalLayout->addWidget(replayButton);


        retranslateUi(OutroWidget);

        QMetaObject::connectSlotsByName(OutroWidget);
    } // setupUi

    void retranslateUi(QWidget *OutroWidget)
    {
        OutroWidget->setWindowTitle(QCoreApplication::translate("OutroWidget", "Form", nullptr));
        muteSwitch->setText(QString());
        exitButton->setText(QCoreApplication::translate("OutroWidget", "\351\200\200\345\207\272", nullptr));
        title->setText(QCoreApplication::translate("OutroWidget", "\346\204\237\350\254\235\351\201\212\347\216\251", nullptr));
        score->setText(QCoreApplication::translate("OutroWidget", "\344\275\240\347\232\204\345\276\227\345\210\206\347\202\272\357\274\232this / that\357\274\232thisat%", nullptr));
        totalTime->setText(QCoreApplication::translate("OutroWidget", "\347\270\275\347\255\224\351\241\214\346\231\202\351\226\223\357\274\232this s", nullptr));
        avgTime->setText(QCoreApplication::translate("OutroWidget", "\345\271\263\345\235\207\347\255\224\351\241\214\346\231\202\351\226\223\357\274\232this s", nullptr));
        gamemodeExplanation->setText(QCoreApplication::translate("OutroWidget", "TextLabel", nullptr));
        replayButton->setText(QCoreApplication::translate("OutroWidget", "\351\207\215\347\216\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutroWidget: public Ui_OutroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTROWIDGET_H
