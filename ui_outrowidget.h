/********************************************************************************
** Form generated from reading UI file 'OutroWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTROWIDGET_H
#define UI_OUTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutroWidget
{
public:
    QLabel *title;
    QPushButton *replayButton;
    QLabel *score;
    QLabel *totalTime;
    QLabel *avgTime;
    QPushButton *exitButton;

    void setupUi(QWidget *OutroWidget)
    {
        if (OutroWidget->objectName().isEmpty())
            OutroWidget->setObjectName("OutroWidget");
        OutroWidget->resize(1000, 700);
        title = new QLabel(OutroWidget);
        title->setObjectName("title");
        title->setGeometry(QRect(305, 60, 390, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(26);
        title->setFont(font);
        title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        replayButton = new QPushButton(OutroWidget);
        replayButton->setObjectName("replayButton");
        replayButton->setGeometry(QRect(380, 520, 240, 90));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(20);
        replayButton->setFont(font1);
        score = new QLabel(OutroWidget);
        score->setObjectName("score");
        score->setGeometry(QRect(210, 140, 580, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(18);
        score->setFont(font2);
        score->setTextFormat(Qt::TextFormat::MarkdownText);
        score->setAlignment(Qt::AlignmentFlag::AlignCenter);
        totalTime = new QLabel(OutroWidget);
        totalTime->setObjectName("totalTime");
        totalTime->setGeometry(QRect(210, 280, 580, 60));
        totalTime->setFont(font2);
        totalTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        avgTime = new QLabel(OutroWidget);
        avgTime->setObjectName("label");
        avgTime->setGeometry(QRect(210, 350, 580, 60));
        avgTime->setFont(font2);
        avgTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        exitButton = new QPushButton(OutroWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(840, 20, 120, 70));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font3.setPointSize(16);
        exitButton->setFont(font3);

        retranslateUi(OutroWidget);

        QMetaObject::connectSlotsByName(OutroWidget);
    } // setupUi

    void retranslateUi(QWidget *OutroWidget)
    {
        OutroWidget->setWindowTitle(QCoreApplication::translate("OutroWidget", "Form", nullptr));
        title->setText(QCoreApplication::translate("OutroWidget", "\346\204\237\350\254\235\346\270\270\347\216\251", nullptr));
        replayButton->setText(QCoreApplication::translate("OutroWidget", "\351\207\215\347\216\251", nullptr));
        score->setText(QCoreApplication::translate("OutroWidget", "\344\275\240\347\232\204\345\276\227\345\210\206\347\202\272\357\274\232this / that", nullptr));
        totalTime->setText(QCoreApplication::translate("OutroWidget", "\347\270\275\347\255\224\351\241\214\346\231\202\351\226\223\357\274\232this s", nullptr));
        avgTime->setText(QCoreApplication::translate("OutroWidget", "\345\271\263\345\235\207\347\255\224\351\241\214\346\231\202\351\226\223\357\274\232this s", nullptr));
        exitButton->setText(QCoreApplication::translate("OutroWidget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutroWidget: public Ui_OutroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTROWIDGET_H
