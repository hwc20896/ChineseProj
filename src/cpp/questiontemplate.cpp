#include "src/headers/questiontemplate.h"
#include <QEventLoop>
#include <QTimer>
#include <algorithm>
#include <random>
#include <tuple>
#include <ranges>

#define SETCOLOR(col) setStyleSheet(QString("background-color: %1;").arg(col))
#define SETCHOSEN SETCOLOR("#1d74f5")
#define SETWRONG SETCOLOR("#ff0011")
#define SETRIGHT SETCOLOR("#00ee22")

QuestionWidget::MultipleChoice::MultipleChoice(QuestionTemplate::MultipleChoice question, size_t Index, QWidget* parent) : QWidget(parent), ui(new Ui::MultipleChoice), question(question), Index(Index){
    ui->setupUi(this);
    Answered = false;
    corrText = this->question.Options[this->question.CorrOption];
    std::mt19937 mt((std::random_device()()));
    std::ranges::shuffle(this->question.Options, mt);
    std::array<QPushButton*,4> linker_array = {ui->optionA,ui->optionB,ui->optionC,ui->optionD};
    for (auto i : linker_array) i->setVisible(false);
    for (auto [option,button] = std::tuple{this->question.Options.begin(),linker_array.begin()}; option != this->question.Options.end(); option++, button++) if (!option->isEmpty()){
        auto targetButton = *button;
        targetButton->setVisible(true);
        textToButton.insert({*option,targetButton});
        targetButton->setText(*option);
        connect(targetButton,BUTTONCLICK,this,[=,this]{AnswerCheck(targetButton);});
    }

    ui->questionTitle->setText(question.QuestionTitle);

    corrSound = new QSoundEffect;
    corrSound->setSource({"qrc:/SoundEffects/medias/bingo.wav"});
    incorrSound = new QSoundEffect;
    incorrSound->setSource({"qrc:/SoundEffects/medias/bingo.wav"});
}

QuestionWidget::MultipleChoice::~MultipleChoice(){delete ui;}

void QuestionWidget::MultipleChoice::AnswerCheck(QPushButton* targetButton){
    if (!Answered){
        Answered = true;
        emit TimeTap();
        targetButton->SETCHOSEN;
        bool Corr = targetButton->text() == this->corrText;
        Cooldown(800);
        if (Corr){
            targetButton->SETRIGHT;
            corrSound->play();
        }
        else{
            targetButton->SETWRONG;
            incorrSound->play();
            Cooldown(500);
            textToButton[corrText]->SETRIGHT;
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

void QuestionWidget::MultipleChoice::SetScore(int Corr, int Incorr){
    ui->correctState->setText(QString("<font color=\"#ff0000\">錯誤數 %1</font> | <font color=\"#00dd12\">%2 正確數</font>").arg(Incorr).arg(Corr));
}

void QuestionWidget::MultipleChoice::SetProgress(int CurrentProgress, int Total){
    ui->progress->setText(QString("進度：%1 / %2 - %3%").arg(CurrentProgress).arg(Total).arg(TODOUBLE(CurrentProgress) / TODOUBLE(Total) * 100));
}
