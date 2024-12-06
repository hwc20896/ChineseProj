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

    void setupUi(QWidget *MultipleChoice)
    {
        if (MultipleChoice->objectName().isEmpty())
            MultipleChoice->setObjectName("MultipleChoice");
        MultipleChoice->resize(1000, 700);
        questionTitle = new QLabel(MultipleChoice);
        questionTitle->setObjectName("questionTitle");
        questionTitle->setGeometry(QRect(100, 115, 800, 125));
        QFont font;
        font.setPointSize(26);
        questionTitle->setFont(font);
        questionTitle->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        optionA = new QPushButton(MultipleChoice);
        optionA->setObjectName("optionA");
        optionA->setEnabled(false);
        optionA->setGeometry(QRect(200, 216, 270, 140));
        QFont font1;
        font1.setPointSize(15);
        optionA->setFont(font1);
        optionB = new QPushButton(MultipleChoice);
        optionB->setObjectName("optionB");
        optionB->setEnabled(false);
        optionB->setGeometry(QRect(530, 216, 270, 140));
        optionB->setFont(font1);
        optionC = new QPushButton(MultipleChoice);
        optionC->setObjectName("optionC");
        optionC->setEnabled(false);
        optionC->setGeometry(QRect(200, 385, 270, 140));
        optionC->setFont(font1);
        optionD = new QPushButton(MultipleChoice);
        optionD->setObjectName("optionD");
        optionD->setEnabled(false);
        optionD->setGeometry(QRect(530, 385, 270, 140));
        optionD->setFont(font1);

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
    } // retranslateUi

};

namespace Ui {
    class MultipleChoice: public Ui_MultipleChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLECHOICEFORM_H
