/********************************************************************************
** Form generated from reading UI file 'TrueorFalseForm.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUEORFALSE_H
#define UI_TRUEORFALSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrueorFalse
{
public:
    QLabel *correctState;
    QLabel *progress;
    QLabel *title;
    QPushButton *trueOption;
    QPushButton *falseOption;
    QPushButton *prevQuestion;
    QPushButton *nextQuestion;

    void setupUi(QWidget *TrueorFalse)
    {
        if (TrueorFalse->objectName().isEmpty())
            TrueorFalse->setObjectName("TrueorFalse");
        TrueorFalse->resize(1000, 700);
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(15);
        TrueorFalse->setFont(font);
        correctState = new QLabel(TrueorFalse);
        correctState->setObjectName("correctState");
        correctState->setGeometry(QRect(200, 10, 190, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(14);
        correctState->setFont(font1);
        correctState->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progress = new QLabel(TrueorFalse);
        progress->setObjectName("progress");
        progress->setGeometry(QRect(790, 10, 190, 50));
        progress->setFont(font1);
        progress->setAlignment(Qt::AlignmentFlag::AlignCenter);
        title = new QLabel(TrueorFalse);
        title->setObjectName("title");
        title->setGeometry(QRect(100, 115, 800, 125));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(26);
        title->setFont(font2);
        title->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        trueOption = new QPushButton(TrueorFalse);
        trueOption->setObjectName("trueOption");
        trueOption->setGeometry(QRect(213, 331, 250, 125));
        falseOption = new QPushButton(TrueorFalse);
        falseOption->setObjectName("falseOption");
        falseOption->setGeometry(QRect(563, 331, 250, 125));
        prevQuestion = new QPushButton(TrueorFalse);
        prevQuestion->setObjectName("prevQuestion");
        prevQuestion->setGeometry(QRect(50, 590, 160, 60));
        nextQuestion = new QPushButton(TrueorFalse);
        nextQuestion->setObjectName("nextQuestion");
        nextQuestion->setEnabled(false);
        nextQuestion->setGeometry(QRect(790, 590, 160, 60));

        retranslateUi(TrueorFalse);

        QMetaObject::connectSlotsByName(TrueorFalse);
    } // setupUi

    void retranslateUi(QWidget *TrueorFalse)
    {
        TrueorFalse->setWindowTitle(QCoreApplication::translate("TrueorFalse", "Form", nullptr));
        correctState->setText(QCoreApplication::translate("TrueorFalse", "\346\255\243\347\242\272\346\225\270 0 | 0 \351\214\257\350\252\244\346\225\270", nullptr));
        progress->setText(QCoreApplication::translate("TrueorFalse", "\351\200\262\345\272\246\357\274\2321/10\357\274\23210%", nullptr));
        title->setText(QCoreApplication::translate("TrueorFalse", "TextLabel", nullptr));
        trueOption->setText(QCoreApplication::translate("TrueorFalse", "PushButton", nullptr));
        falseOption->setText(QCoreApplication::translate("TrueorFalse", "PushButton", nullptr));
        prevQuestion->setText(QCoreApplication::translate("TrueorFalse", "<- \344\270\212\344\270\200\351\241\214", nullptr));
        nextQuestion->setText(QCoreApplication::translate("TrueorFalse", "\344\270\213\344\270\200\351\241\214 ->", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrueorFalse: public Ui_TrueorFalse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUEORFALSE_H
