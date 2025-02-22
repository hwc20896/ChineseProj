/********************************************************************************
** Form generated from reading UI file 'MultipleChoiceForm.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLECHOICEFORM_H
#define UI_MULTIPLECHOICEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultipleChoice
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *upperNavigator;
    QLabel *correctState;
    QPushButton *muteState;
    QLabel *timerDisplay;
    QLabel *progress;
    QLabel *questionTitle;
    QGridLayout *optionLayout;
    QPushButton *optionB;
    QPushButton *optionA;
    QPushButton *optionC;
    QPushButton *optionD;
    QHBoxLayout *bottomNavigator;
    QPushButton *prevButton;
    QPushButton *nextQuestion;

    void setupUi(QWidget *MultipleChoice)
    {
        if (MultipleChoice->objectName().isEmpty())
            MultipleChoice->setObjectName("MultipleChoice");
        MultipleChoice->resize(1000, 700);
        verticalLayout = new QVBoxLayout(MultipleChoice);
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        upperNavigator = new QHBoxLayout();
        upperNavigator->setObjectName("upperNavigator");
        correctState = new QLabel(MultipleChoice);
        correctState->setObjectName("correctState");
        correctState->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(16);
        correctState->setFont(font);
        correctState->setAlignment(Qt::AlignmentFlag::AlignCenter);

        upperNavigator->addWidget(correctState);

        muteState = new QPushButton(MultipleChoice);
        muteState->setObjectName("muteState");
        muteState->setMaximumSize(QSize(50, 50));
        muteState->setIconSize(QSize(40, 40));

        upperNavigator->addWidget(muteState);

        timerDisplay = new QLabel(MultipleChoice);
        timerDisplay->setObjectName("timerDisplay");
        timerDisplay->setMaximumSize(QSize(16777215, 50));
        timerDisplay->setFont(font);
        timerDisplay->setAlignment(Qt::AlignmentFlag::AlignCenter);

        upperNavigator->addWidget(timerDisplay);

        progress = new QLabel(MultipleChoice);
        progress->setObjectName("progress");
        progress->setMaximumSize(QSize(16777215, 50));
        progress->setFont(font);
        progress->setAlignment(Qt::AlignmentFlag::AlignCenter);

        upperNavigator->addWidget(progress);


        verticalLayout->addLayout(upperNavigator);

        questionTitle = new QLabel(MultipleChoice);
        questionTitle->setObjectName("questionTitle");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(26);
        questionTitle->setFont(font1);
        questionTitle->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(questionTitle);

        optionLayout = new QGridLayout();
        optionLayout->setObjectName("optionLayout");
        optionLayout->setHorizontalSpacing(7);
        optionLayout->setContentsMargins(80, -1, 80, -1);
        optionB = new QPushButton(MultipleChoice);
        optionB->setObjectName("optionB");
        optionB->setEnabled(true);
        optionB->setMinimumSize(QSize(0, 120));
        optionB->setMaximumSize(QSize(350, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(15);
        optionB->setFont(font2);

        optionLayout->addWidget(optionB, 0, 1, 1, 1);

        optionA = new QPushButton(MultipleChoice);
        optionA->setObjectName("optionA");
        optionA->setEnabled(true);
        optionA->setMinimumSize(QSize(0, 120));
        optionA->setMaximumSize(QSize(350, 16777215));
        optionA->setFont(font2);

        optionLayout->addWidget(optionA, 0, 0, 1, 1);

        optionC = new QPushButton(MultipleChoice);
        optionC->setObjectName("optionC");
        optionC->setEnabled(true);
        optionC->setMinimumSize(QSize(0, 120));
        optionC->setMaximumSize(QSize(400, 16777215));
        optionC->setFont(font2);

        optionLayout->addWidget(optionC, 1, 0, 1, 1);

        optionD = new QPushButton(MultipleChoice);
        optionD->setObjectName("optionD");
        optionD->setEnabled(true);
        optionD->setMinimumSize(QSize(0, 120));
        optionD->setMaximumSize(QSize(350, 16777215));
        optionD->setFont(font2);

        optionLayout->addWidget(optionD, 1, 1, 1, 1);


        verticalLayout->addLayout(optionLayout);

        bottomNavigator = new QHBoxLayout();
        bottomNavigator->setSpacing(600);
        bottomNavigator->setObjectName("bottomNavigator");
        prevButton = new QPushButton(MultipleChoice);
        prevButton->setObjectName("prevButton");
        prevButton->setMinimumSize(QSize(120, 70));
        prevButton->setMaximumSize(QSize(180, 16777215));
        prevButton->setFont(font2);

        bottomNavigator->addWidget(prevButton);

        nextQuestion = new QPushButton(MultipleChoice);
        nextQuestion->setObjectName("nextQuestion");
        nextQuestion->setEnabled(false);
        nextQuestion->setMinimumSize(QSize(120, 70));
        nextQuestion->setMaximumSize(QSize(180, 70));
        nextQuestion->setFont(font2);

        bottomNavigator->addWidget(nextQuestion);


        verticalLayout->addLayout(bottomNavigator);


        retranslateUi(MultipleChoice);

        QMetaObject::connectSlotsByName(MultipleChoice);
    } // setupUi

    void retranslateUi(QWidget *MultipleChoice)
    {
        MultipleChoice->setWindowTitle(QCoreApplication::translate("MultipleChoice", "Form", nullptr));
        correctState->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        muteState->setText(QString());
        timerDisplay->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        progress->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        questionTitle->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        optionB->setText(QString());
        optionA->setText(QString());
        optionC->setText(QString());
        optionD->setText(QString());
        prevButton->setText(QCoreApplication::translate("MultipleChoice", "\342\206\220 \344\270\212\344\270\200\351\240\201", nullptr));
        nextQuestion->setText(QCoreApplication::translate("MultipleChoice", "\344\270\213\344\270\200\351\240\201 \342\206\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MultipleChoice: public Ui_MultipleChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLECHOICEFORM_H
