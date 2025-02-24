/********************************************************************************
** Form generated from reading UI file 'RuleWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEWIDGET_H
#define UI_RULEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RuleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *rule;
    QLabel *ruleContext;
    QLabel *quantity;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *returnButton;

    void setupUi(QWidget *RuleWidget)
    {
        if (RuleWidget->objectName().isEmpty())
            RuleWidget->setObjectName("RuleWidget");
        RuleWidget->resize(1000, 700);
        verticalLayout = new QVBoxLayout(RuleWidget);
        verticalLayout->setSpacing(60);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(70, 70, 70, 90);
        rule = new QVBoxLayout();
        rule->setSpacing(70);
        rule->setObjectName("rule");
        rule->setContentsMargins(-1, 90, -1, -1);
        ruleContext = new QLabel(RuleWidget);
        ruleContext->setObjectName("ruleContext");
        ruleContext->setMaximumSize(QSize(16777215, 180));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font.setPointSize(20);
        ruleContext->setFont(font);
        ruleContext->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        rule->addWidget(ruleContext);

        quantity = new QLabel(RuleWidget);
        quantity->setObjectName("quantity");
        quantity->setMaximumSize(QSize(16777215, 80));
        quantity->setFont(font);

        rule->addWidget(quantity);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        returnButton = new QPushButton(RuleWidget);
        returnButton->setObjectName("returnButton");
        returnButton->setMaximumSize(QSize(370, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font1.setPointSize(21);
        returnButton->setFont(font1);

        horizontalLayout_3->addWidget(returnButton);


        rule->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(rule);


        retranslateUi(RuleWidget);

        QMetaObject::connectSlotsByName(RuleWidget);
    } // setupUi

    void retranslateUi(QWidget *RuleWidget)
    {
        RuleWidget->setWindowTitle(QCoreApplication::translate("RuleWidget", "Form", nullptr));
        ruleContext->setText(QCoreApplication::translate("RuleWidget", "<html><head/><body><p>\350\246\217\345\211\207\357\274\232</p><p>\346\214\211\344\270\213\351\226\213\345\247\213\351\201\212\346\210\262\345\276\214\357\274\214\350\253\213\346\214\211\344\270\213\346\255\243\347\242\272\351\201\270\351\240\205\344\273\245\344\275\234\347\255\224\343\200\202</p><p>\346\214\211\344\270\213\351\214\257\350\252\244\351\201\270\351\240\205\345\260\207\350\207\252\345\213\225\351\241\257\347\244\272\346\255\243\347\242\272\351\201\270\351\240\205\343\200\202</p><p><br/></p></body></html>", nullptr));
        quantity->setText(QCoreApplication::translate("RuleWidget", "\351\241\214\347\233\256\345\272\253\345\205\261\346\234\211n\346\242\235\357\274\214\346\257\217\346\254\241\351\226\213\345\247\213\351\201\212\346\210\262\347\263\273\347\265\261\346\234\203\351\232\250\346\251\237\346\212\275\345\217\226k\346\242\235\351\241\257\347\244\272\343\200\202", nullptr));
        returnButton->setText(QCoreApplication::translate("RuleWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RuleWidget: public Ui_RuleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEWIDGET_H
