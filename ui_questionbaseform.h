/********************************************************************************
** Form generated from reading UI file 'QuestionBaseForm.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONBASEFORM_H
#define UI_QUESTIONBASEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionBase
{
public:
    QPushButton *prevQuestion;
    QPushButton *nextQuestion;
    QLabel *correctState;
    QLabel *progress;

    void setupUi(QWidget *QuestionBase)
    {
        if (QuestionBase->objectName().isEmpty())
            QuestionBase->setObjectName("QuestionBase");
        QuestionBase->resize(1000, 700);
        prevQuestion = new QPushButton(QuestionBase);
        prevQuestion->setObjectName("prevQuestion");
        prevQuestion->setGeometry(QRect(50, 590, 160, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(17);
        prevQuestion->setFont(font);
        nextQuestion = new QPushButton(QuestionBase);
        nextQuestion->setObjectName("nextQuestion");
        nextQuestion->setGeometry(QRect(790, 590, 160, 60));
        nextQuestion->setFont(font);
        correctState = new QLabel(QuestionBase);
        correctState->setObjectName("correctState");
        correctState->setGeometry(QRect(200, 10, 190, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(14);
        correctState->setFont(font1);
        correctState->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progress = new QLabel(QuestionBase);
        progress->setObjectName("progress");
        progress->setGeometry(QRect(790, 10, 190, 50));
        progress->setFont(font1);
        progress->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(QuestionBase);

        QMetaObject::connectSlotsByName(QuestionBase);
    } // setupUi

    void retranslateUi(QWidget *QuestionBase)
    {
        QuestionBase->setWindowTitle(QCoreApplication::translate("QuestionBase", "Form", nullptr));
        prevQuestion->setText(QCoreApplication::translate("QuestionBase", "\342\206\220  \344\270\212\344\270\200\351\240\201", nullptr));
        nextQuestion->setText(QCoreApplication::translate("QuestionBase", "\344\270\213\344\270\200\351\240\201  \342\206\222", nullptr));
        correctState->setText(QCoreApplication::translate("QuestionBase", "TextLabel", nullptr));
        progress->setText(QCoreApplication::translate("QuestionBase", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionBase: public Ui_QuestionBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONBASEFORM_H
