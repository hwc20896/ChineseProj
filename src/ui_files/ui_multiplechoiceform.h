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
#include <QtWidgets/QSpacerItem>
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
    QWidget *timerDisplayContainer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *timerDisplayAligner;
    QLabel *timerDisplay;
    QLabel *progress;
    QLabel *questionTitle;
    QGridLayout *optionLayout;
    QWidget *optionBSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *optionBAligner;
    QPushButton *optionB;
    QWidget *optionASpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *optionAAligner;
    QPushButton *optionA;
    QWidget *optionCSpacer;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *optionCAligner;
    QPushButton *optionC;
    QWidget *optionDSpacer;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *optionDAligner;
    QPushButton *optionD;
    QHBoxLayout *bottomNavigator;
    QWidget *prevButtonSpacer;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *prevButtonAligner;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextQuestion;

    void setupUi(QWidget *MultipleChoice)
    {
        if (MultipleChoice->objectName().isEmpty())
            MultipleChoice->setObjectName("MultipleChoice");
        MultipleChoice->resize(1000, 700);
        verticalLayout = new QVBoxLayout(MultipleChoice);
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 40);
        upperNavigator = new QHBoxLayout();
        upperNavigator->setSpacing(20);
        upperNavigator->setObjectName("upperNavigator");
        upperNavigator->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        upperNavigator->setContentsMargins(-1, -1, -1, 20);
        correctState = new QLabel(MultipleChoice);
        correctState->setObjectName("correctState");
        correctState->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(16);
        correctState->setFont(font);
        correctState->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        upperNavigator->addWidget(correctState);

        muteState = new QPushButton(MultipleChoice);
        muteState->setObjectName("muteState");
        muteState->setMaximumSize(QSize(50, 50));
        muteState->setIconSize(QSize(40, 40));

        upperNavigator->addWidget(muteState);

        timerDisplayContainer = new QWidget(MultipleChoice);
        timerDisplayContainer->setObjectName("timerDisplayContainer");
        verticalLayout_2 = new QVBoxLayout(timerDisplayContainer);
        verticalLayout_2->setObjectName("verticalLayout_2");
        timerDisplayAligner = new QHBoxLayout();
        timerDisplayAligner->setObjectName("timerDisplayAligner");
        timerDisplay = new QLabel(timerDisplayContainer);
        timerDisplay->setObjectName("timerDisplay");
        timerDisplay->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(16);
        timerDisplay->setFont(font1);
        timerDisplay->setAlignment(Qt::AlignmentFlag::AlignCenter);

        timerDisplayAligner->addWidget(timerDisplay);


        verticalLayout_2->addLayout(timerDisplayAligner);


        upperNavigator->addWidget(timerDisplayContainer);

        progress = new QLabel(MultipleChoice);
        progress->setObjectName("progress");
        progress->setMaximumSize(QSize(16777215, 50));
        progress->setFont(font);
        progress->setAlignment(Qt::AlignmentFlag::AlignCenter);

        upperNavigator->addWidget(progress);


        verticalLayout->addLayout(upperNavigator);

        questionTitle = new QLabel(MultipleChoice);
        questionTitle->setObjectName("questionTitle");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(26);
        questionTitle->setFont(font2);
        questionTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(questionTitle);

        optionLayout = new QGridLayout();
        optionLayout->setObjectName("optionLayout");
        optionLayout->setHorizontalSpacing(7);
        optionLayout->setContentsMargins(80, -1, 80, -1);
        optionBSpacer = new QWidget(MultipleChoice);
        optionBSpacer->setObjectName("optionBSpacer");
        verticalLayout_4 = new QVBoxLayout(optionBSpacer);
        verticalLayout_4->setObjectName("verticalLayout_4");
        optionBAligner = new QHBoxLayout();
        optionBAligner->setObjectName("optionBAligner");
        optionB = new QPushButton(optionBSpacer);
        optionB->setObjectName("optionB");
        optionB->setMinimumSize(QSize(0, 100));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font3.setPointSize(15);
        optionB->setFont(font3);

        optionBAligner->addWidget(optionB);


        verticalLayout_4->addLayout(optionBAligner);


        optionLayout->addWidget(optionBSpacer, 1, 1, 1, 1);

        optionASpacer = new QWidget(MultipleChoice);
        optionASpacer->setObjectName("optionASpacer");
        verticalLayout_3 = new QVBoxLayout(optionASpacer);
        verticalLayout_3->setObjectName("verticalLayout_3");
        optionAAligner = new QHBoxLayout();
        optionAAligner->setObjectName("optionAAligner");
        optionA = new QPushButton(optionASpacer);
        optionA->setObjectName("optionA");
        optionA->setMinimumSize(QSize(0, 100));
        optionA->setFont(font3);

        optionAAligner->addWidget(optionA);


        verticalLayout_3->addLayout(optionAAligner);


        optionLayout->addWidget(optionASpacer, 1, 0, 1, 1);

        optionCSpacer = new QWidget(MultipleChoice);
        optionCSpacer->setObjectName("optionCSpacer");
        verticalLayout_8 = new QVBoxLayout(optionCSpacer);
        verticalLayout_8->setObjectName("verticalLayout_8");
        optionCAligner = new QVBoxLayout();
        optionCAligner->setObjectName("optionCAligner");
        optionC = new QPushButton(optionCSpacer);
        optionC->setObjectName("optionC");
        optionC->setMinimumSize(QSize(0, 100));
        optionC->setFont(font3);

        optionCAligner->addWidget(optionC);


        verticalLayout_8->addLayout(optionCAligner);


        optionLayout->addWidget(optionCSpacer, 2, 0, 1, 1);

        optionDSpacer = new QWidget(MultipleChoice);
        optionDSpacer->setObjectName("optionDSpacer");
        verticalLayout_6 = new QVBoxLayout(optionDSpacer);
        verticalLayout_6->setObjectName("verticalLayout_6");
        optionDAligner = new QVBoxLayout();
        optionDAligner->setObjectName("optionDAligner");
        optionD = new QPushButton(optionDSpacer);
        optionD->setObjectName("optionD");
        optionD->setMinimumSize(QSize(0, 100));
        optionD->setFont(font3);

        optionDAligner->addWidget(optionD);


        verticalLayout_6->addLayout(optionDAligner);


        optionLayout->addWidget(optionDSpacer, 2, 1, 1, 1);


        verticalLayout->addLayout(optionLayout);

        bottomNavigator = new QHBoxLayout();
        bottomNavigator->setSpacing(0);
        bottomNavigator->setObjectName("bottomNavigator");
        bottomNavigator->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        prevButtonSpacer = new QWidget(MultipleChoice);
        prevButtonSpacer->setObjectName("prevButtonSpacer");
        prevButtonSpacer->setMinimumSize(QSize(120, 70));
        prevButtonSpacer->setMaximumSize(QSize(180, 70));
        horizontalLayout_2 = new QHBoxLayout(prevButtonSpacer);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        prevButtonAligner = new QHBoxLayout();
        prevButtonAligner->setSpacing(0);
        prevButtonAligner->setObjectName("prevButtonAligner");
        prevButton = new QPushButton(prevButtonSpacer);
        prevButton->setObjectName("prevButton");
        prevButton->setMinimumSize(QSize(120, 70));
        prevButton->setMaximumSize(QSize(180, 70));
        prevButton->setFont(font3);

        prevButtonAligner->addWidget(prevButton);


        horizontalLayout_2->addLayout(prevButtonAligner);


        bottomNavigator->addWidget(prevButtonSpacer);

        horizontalSpacer = new QSpacerItem(600, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        bottomNavigator->addItem(horizontalSpacer);

        nextQuestion = new QPushButton(MultipleChoice);
        nextQuestion->setObjectName("nextQuestion");
        nextQuestion->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(120);
        sizePolicy.setVerticalStretch(70);
        sizePolicy.setHeightForWidth(nextQuestion->sizePolicy().hasHeightForWidth());
        nextQuestion->setSizePolicy(sizePolicy);
        nextQuestion->setMinimumSize(QSize(180, 70));
        nextQuestion->setMaximumSize(QSize(180, 70));
        nextQuestion->setFont(font3);

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
        optionB->setText(QCoreApplication::translate("MultipleChoice", "PushButton", nullptr));
        optionA->setText(QCoreApplication::translate("MultipleChoice", "PushButton", nullptr));
        optionC->setText(QCoreApplication::translate("MultipleChoice", "PushButton", nullptr));
        optionD->setText(QCoreApplication::translate("MultipleChoice", "PushButton", nullptr));
        prevButton->setText(QCoreApplication::translate("MultipleChoice", "\342\206\220 \344\270\212\344\270\200\351\240\201", nullptr));
        nextQuestion->setText(QCoreApplication::translate("MultipleChoice", "\344\270\213\344\270\200\351\240\201 \342\206\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MultipleChoice: public Ui_MultipleChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLECHOICEFORM_H
