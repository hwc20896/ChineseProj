/********************************************************************************
** Form generated from reading UI file 'RuleWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEWIDGET_H
#define UI_RULEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RuleWidget
{
public:
    QLabel *label;
    QPushButton *returnButton;

    void setupUi(QWidget *RuleWidget)
    {
        if (RuleWidget->objectName().isEmpty())
            RuleWidget->setObjectName("RuleWidget");
        RuleWidget->resize(1000, 700);
        label = new QLabel(RuleWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 110, 780, 300));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        returnButton = new QPushButton(RuleWidget);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(390, 550, 210, 80));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(21);
        returnButton->setFont(font1);

        retranslateUi(RuleWidget);

        QMetaObject::connectSlotsByName(RuleWidget);
    } // setupUi

    void retranslateUi(QWidget *RuleWidget)
    {
        RuleWidget->setWindowTitle(QCoreApplication::translate("RuleWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("RuleWidget", "<html><head/><body><p>\350\246\217\345\211\207\357\274\232</p><p>\346\214\211\344\270\213\351\226\213\345\247\213\346\270\270\346\210\262\345\276\214\357\274\214\350\253\213\346\214\211\344\270\213\346\255\243\347\242\272\351\201\270\351\240\205\344\273\245\344\275\234\347\255\224\343\200\202</p><p>\346\214\211\344\270\213\351\214\257\350\252\244\351\201\270\351\240\205\345\260\207\350\207\252\345\213\225\351\241\257\347\244\272\346\255\243\347\242\272\351\201\270\351\240\205\343\200\202</p><p><br/></p><p>\351\241\214\347\233\256\345\272\253\345\205\261\346\234\21140\346\242\235\357\274\214\346\257\217\346\254\241\351\226\213\345\247\213\346\270\270\346\210\262\347\263\273\347\265\261\346\234\203\351\232\250\346\251\237\346\212\275\345\217\2265\346\242\235\351\241\257\347\244\272\343\200\202</p></body></html>", nullptr));
        returnButton->setText(QCoreApplication::translate("RuleWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RuleWidget: public Ui_RuleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEWIDGET_H
