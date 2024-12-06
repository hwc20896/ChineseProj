#include "questiontemplate.h"
#include <QEventLoop>
#include <QTimer>

#define SETCOLOR(col) setStyleSheet(QString("background-color: %1;").arg(col))
#define SETCHOSEN SETCOLOR("#6d7dff")
#define SETWRONG SETCOLOR("#ff0011")
#define SETRIGHT SETCOLOR("#00ee22")
#define BUTTONCLICK &QPushButton::clicked

QTQB::QuestionBase(QWidget* parent) : QWidget(parent), base_ui(new Ui::QuestionBase){
    base_ui->setupUi(this);
}

QTQB::~QuestionBase(){delete base_ui;}

void QTQB::Cooldown(int msec){
    QEventLoop* lp = new QEventLoop;
    QTimer::singleShot(msec,lp,&QEventLoop::quit);
    lp->exec();
}

QTMC::MultipleChoice(QMC* question, QWidget* parent) : QuestionBase(parent), ui(new Ui::MultipleChoice), Question(question){
    ui->setupUi(this);
    ui->questionTitle->setText(QString("(%1) %2").arg(this->Index).arg(Question->QuestionTitle));
    IndextoButton = {{0,ui->optionA},{1,ui->optionB},{2,ui->optionC},{3,ui->optionD}};
    for (int i=0;i<4;i++) if (!Question->Options[i].isEmpty()){
        IndextoButton[i]->setEnabled(true);
        IndextoButton[i]->setText(Question->Options[i]);
        connect(IndextoButton[i],BUTTONCLICK,this,[=]{AnswerCheck(i);});
    }
    this->setStyleSheet("QPushButton#AnswerOption:hover{background-color: #6d7dff; color: black;");
}

QTMC::~MultipleChoice(){delete ui;}

void QTMC::AnswerCheck(int Option){
    if (!Answered){
        Answered = true;
        auto* target = IndextoButton[Option];
        target->SETCHOSEN;
        Cooldown(800);
        if (Option == Question->CorrOption) target->SETRIGHT;
        else{
            target->SETWRONG;
            Cooldown(400);
            IndextoButton[Question->CorrOption]->SETRIGHT;
        }
        Cooldown(500);
        base_ui->nextQuestion->setEnabled(true);
    }
}


QuestionTemplate::TrueorFalse::TrueorFalse(Question::TrueorFalse* question, QWidget* parent) : QuestionBase(parent), ui(new Ui::TrueorFalse), Question(question){
    ui->setupUi(this);
    ui->title->setText(QString("(%1) %2").arg(this->Index).arg(Question->QuestionTitle));
    connect(ui->trueOption,BUTTONCLICK,this,[=]{AnswerCheck(true);});
    connect(ui->falseOption,BUTTONCLICK,this,[=]{AnswerCheck(false);});
    this->setStyleSheet("QPushButton#AnswerOption:hover{background-color: #6d7dff; color: black;");
}

QTTF::~TrueorFalse(){delete ui;}

void QTTF::AnswerCheck(bool Option){
    if (!Answered){
        Answered = true;
        auto* target = OptiontoButton(Option);
        target->SETCHOSEN;
        Cooldown(800);
        bool Corr = Option == Question->CorrOption;
        if (Corr) target->SETRIGHT;
        else{
            target->SETWRONG;
            Cooldown(400);
            OptiontoButton(Question->CorrOption)->SETRIGHT;
        }
        emit Score(Corr);
        Cooldown(500);
        base_ui->nextQuestion->setEnabled(true);
    }
}

QPushButton* QTTF::OptiontoButton(bool Option){return Option ? ui->trueOption : ui->falseOption;}
