/********************************************************************************
** Form generated from reading UI file 'MultipleChoiceForm.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLECHOICEFORM_H
#define UI_MULTIPLECHOICEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultipleChoice
{
public:
    QLabel *questionTitle;
    QPushButton *optionA;
    QPushButton *optionB;
    QPushButton *optionC;
    QPushButton *optionD;
    QPushButton *prevButton;
    QPushButton *nextQuestion;
    QLabel *correctState;
    QLabel *progress;
    QLabel *timerDisplay;
    QPushButton *muteState;

    void setupUi(QWidget *MultipleChoice)
    {
        if (MultipleChoice->objectName().isEmpty())
            MultipleChoice->setObjectName("MultipleChoice");
        MultipleChoice->resize(1000, 700);
        questionTitle = new QLabel(MultipleChoice);
        questionTitle->setObjectName("questionTitle");
        questionTitle->setGeometry(QRect(100, 95, 800, 150));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(26);
        questionTitle->setFont(font);
        questionTitle->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        optionA = new QPushButton(MultipleChoice);
        optionA->setObjectName("optionA");
        optionA->setEnabled(true);
        optionA->setGeometry(QRect(200, 266, 270, 140));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(15);
        optionA->setFont(font1);
        optionB = new QPushButton(MultipleChoice);
        optionB->setObjectName("optionB");
        optionB->setEnabled(true);
        optionB->setGeometry(QRect(530, 266, 270, 140));
        optionB->setFont(font1);
        optionC = new QPushButton(MultipleChoice);
        optionC->setObjectName("optionC");
        optionC->setEnabled(true);
        optionC->setGeometry(QRect(200, 420, 270, 140));
        optionC->setFont(font1);
        optionD = new QPushButton(MultipleChoice);
        optionD->setObjectName("optionD");
        optionD->setEnabled(true);
        optionD->setGeometry(QRect(530, 420, 270, 140));
        optionD->setFont(font1);
        prevButton = new QPushButton(MultipleChoice);
        prevButton->setObjectName("prevButton");
        prevButton->setGeometry(QRect(50, 590, 160, 60));
        prevButton->setFont(font1);
        nextQuestion = new QPushButton(MultipleChoice);
        nextQuestion->setObjectName("nextQuestion");
        nextQuestion->setEnabled(false);
        nextQuestion->setGeometry(QRect(790, 590, 160, 60));
        nextQuestion->setFont(font1);
        correctState = new QLabel(MultipleChoice);
        correctState->setObjectName("correctState");
        correctState->setGeometry(QRect(150, 10, 190, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(16);
        correctState->setFont(font2);
        correctState->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progress = new QLabel(MultipleChoice);
        progress->setObjectName("progress");
        progress->setGeometry(QRect(790, 10, 190, 50));
        progress->setFont(font2);
        progress->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timerDisplay = new QLabel(MultipleChoice);
        timerDisplay->setObjectName("timerDisplay");
        timerDisplay->setGeometry(QRect(500, 10, 220, 50));
        timerDisplay->setFont(font2);
        timerDisplay->setAlignment(Qt::AlignmentFlag::AlignCenter);
        muteState = new QPushButton(MultipleChoice);
        muteState->setObjectName("muteState");
        muteState->setGeometry(QRect(380, 10, 50, 50));
        muteState->setIconSize(QSize(40, 40));

        retranslateUi(MultipleChoice);

        QMetaObject::connectSlotsByName(MultipleChoice);
    } // setupUi

    void retranslateUi(QWidget *MultipleChoice)
    {
        MultipleChoice->setWindowTitle(QCoreApplication::translate("MultipleChoice", "Form", nullptr));
        questionTitle->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        optionA->setText(QString());
        optionB->setText(QString());
        optionC->setText(QString());
        optionD->setText(QString());
        prevButton->setText(QCoreApplication::translate("MultipleChoice", "\342\206\220 \344\270\212\344\270\200\351\240\201", nullptr));
        nextQuestion->setText(QCoreApplication::translate("MultipleChoice", "\344\270\213\344\270\200\351\240\201 \342\206\222", nullptr));
        correctState->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        progress->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        timerDisplay->setText(QCoreApplication::translate("MultipleChoice", "TextLabel", nullptr));
        muteState->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MultipleChoice: public Ui_MultipleChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLECHOICEFORM_H
