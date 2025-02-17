#include "src/headers/questiontemplate.h"
#include <QEventLoop>
#include <QTimer>
#include <algorithm>
#include <random>
#include <tuple>
<<<<<<< HEAD
#include <ranges>
#include <QStyle>
#include <QFile>
=======
>>>>>>> d837d8fac7d4ebbd65e13f2b31de7e0b30cf4f7b

#define __REFRESH(button)\
    this->style()->unpolish(button);\
    this->style()->polish(button)

#define __SET_PROPERTY(button, value)\
    button->setProperty("answer_status",value);\
    __REFRESH(button)

#define __SET_CHOSEN(button) __SET_PROPERTY(button,"chosen")

#define __SET_CORRECT(button) __SET_PROPERTY(button,"correct")

#define __SET_INCORRECT(button) __SET_PROPERTY(button,"incorrect")

QuestionWidget::MultipleChoice::MultipleChoice(QuestionTemplate::MultipleChoice question, size_t Index, QWidget* parent) : QWidget(parent), ui(new Ui::MultipleChoice), question(question), Index(Index){
    ui->setupUi(this);
    Answered = false;
    corrText = this->question.Options[this->question.CorrOption];
    std::mt19937 mt((std::random_device()()));
    std::ranges::shuffle(this->question.Options, mt);
    std::array<QPushButton*,4> linker_array = {ui->optionA,ui->optionB,ui->optionC,ui->optionD};
    std::ranges::for_each(linker_array, [=](QPushButton* btn){
        btn->setVisible(false);
        btn->setObjectName("option");
        btn->setProperty("answer_status","unselected");
    });
    for (auto [option,button] = std::tuple{this->question.Options.begin(),linker_array.begin()}; option != this->question.Options.end(); option++, button++) if (!option->isEmpty()){
        auto targetButton = *button;
        targetButton->setVisible(true);
        textToButton.insert({*option,targetButton});
        targetButton->setText(*option);
        connect(targetButton,BUTTONCLICK,this,[=,this]{AnswerCheck(targetButton);});
    }

    ui->questionTitle->setText(question.QuestionTitle);
    ui->muteState->setObjectName("icon");
    ui->nextQuestion->setObjectName("navigator");
    ui->prevButton->setObjectName("navigator");

    corrSound = new QSoundEffect;
    corrSound->setSource({"qrc:/SoundEffects/medias/bingo.wav"});
    incorrSound = new QSoundEffect;
    incorrSound->setSource({"qrc:/SoundEffects/medias/ohno.wav"});
    this->setStyleSheet(StyleSheet::getStyleFromURI(":/style/src/css_files/before_choose.css"));
}

QuestionWidget::MultipleChoice::~MultipleChoice(){delete ui;}

void QuestionWidget::MultipleChoice::AnswerCheck(QPushButton* targetButton){
    if (!Answered){
        Answered = true;
        this->setStyleSheet(StyleSheet::getStyleFromURI(":/style/src/css_files/after_choose.css"));
        emit TimeTap();
        __SET_CHOSEN(targetButton);
        bool Corr = targetButton->text() == this->corrText;
        Cooldown(800);
        if (Corr){
            __SET_CORRECT(targetButton);
            corrSound->play();
        }
        else{
            __SET_INCORRECT(targetButton);
            incorrSound->play();
            Cooldown(500);
            auto temp = textToButton[corrText];
            __SET_CORRECT(temp);
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

QString StyleSheet::getStyleFromURI(const QString& uri){
    if (QFile file(uri); file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString result = file.readAll();
        file.close();
        return result;
    }
    return "";
}
