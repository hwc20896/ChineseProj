#include "questiontemplate.h"
#include <QEventLoop>
#include <QTimer>

#define SETCOLOR(col) setStyleSheet(QString("background-color: %1;").arg(col))
#define SETCHOSEN SETCOLOR("#6d7dff")
#define SETWRONG SETCOLOR("#ff0011")
#define SETRIGHT SETCOLOR("#00ee22")

QuestionWidget::MultipleChoice::MultipleChoice(QuestionTemplate::MultipleChoice* question, size_t Index, QWidget* parent) : QWidget(parent), ui(new Ui::MultipleChoice), question(question), Index(Index){
    ui->setupUi(this);
    Answered = false;
    OptiontoButton = {{Option::A,ui->optionA},{Option::B,ui->optionB},{Option::C,ui->optionC},{Option::D,ui->optionD}};
    ui->questionTitle->setText(question->QuestionTitle);
    for (size_t i = 0; i < OptiontoButton.size(); i++){
        auto tar = OptiontoButton.begin();
        std::advance(tar,i);
        if (!question->Options[i].isEmpty()){
            tar->second->setEnabled(true);
            tar->second->setText(question->Options[i]);
        }
        connect(tar->second,&QPushButton::clicked,this,[=]{AnswerCheck(tar->first);});
    }
    corrSound = new QSoundEffect;
    corrSound->setSource({"qrc:/SoundEffects/bingo.wav"});
    incorrSound = new QSoundEffect;
    incorrSound->setSource({"qrc:/SoundEffects/ohno.wav"});
}

QuestionWidget::MultipleChoice::~MultipleChoice(){delete ui;}

void QuestionWidget::MultipleChoice::AnswerCheck(Option option){
    if (!Answered){
        Answered = true;
        emit TimeTap();
        bool Corr = option == question->CorrOption;
        Cooldown(800);
        if (Corr){
            OptiontoButton[option]->SETRIGHT;
            corrSound->play();
        }
        else{
            OptiontoButton[option]->SETWRONG;
            incorrSound->play();
            Cooldown(500);
            OptiontoButton[question->CorrOption]->SETRIGHT;
        }
        Cooldown(700);
        emit Score(Corr);
        ui->nextQuestion->setEnabled(true);
    }
}

void QuestionWidget::MultipleChoice::Cooldown(int msec){
    QEventLoop lp;
    QTimer::singleShot(msec,&lp,&QEventLoop::quit);
    lp.exec();
}

