#include "widget.h"
#include "QuestionList.h"
#include <QApplication>

IntroWidget::IntroWidget(QWidget* parent) : QWidget(parent), intro_form(new Ui::IntroWidget){intro_form->setupUi(this);}

RuleWidget::RuleWidget(QWidget* parent) : QWidget(parent), rule_form(new Ui::RuleWidget){rule_form->setupUi(this);}

OutroWidget::OutroWidget(QWidget* parent) : QWidget(parent), ui(new Ui::OutroWidget){
    ui->setupUi(this);
    connect(ui->replayButton,BUTTONCLICK,this,&OutroWidget::Replay);
    connect(ui->exitButton,BUTTONCLICK,this,&QApplication::quit);
}

Widget::Widget(QWidget* parent) : QStackedWidget(parent){
    this->resize(1000,700);
    IntroWidget* intro = new IntroWidget;
    this->addWidget(intro);
    RuleWidget* rule = new RuleWidget;
    this->addWidget(rule);
    this->setCurrentIndex(0);
    using namespace QuestionList;
    questionList = {
        Question01, Question02, Question03, Question04, Question05, Question06, Question07, Question08, Question09, Question10,
        Question11, Question12, Question13, Question14, Question15, Question16, Question17, Question18, Question19, Question20,
        Question21, Question22, Question23, Question24, Question25, Question26, Question27, Question28, Question29, Question30,
        Question31, Question32, Question33, Question34, Question35, Question36, Question37, Question38, Question39, Question40
    };
    connect(intro->intro_form->startGame,BUTTONCLICK,this,&Widget::startGame);
    connect(intro->intro_form->rule,BUTTONCLICK,this,[=]{this->setCurrentWidget(rule);});
    connect(rule->rule_form->returnButton,BUTTONCLICK,this,[=]{this->setCurrentWidget(intro);});
}

void Widget::startGame(){
    mng = new QuestionManagement(questionList,5);
    this->close();
    mng->show();
    connect(mng,&QuestionManagement::GameFinish,this,&Widget::outroCall);
}

void Widget::outroCall(){
    OutroWidget* out = new OutroWidget;
    mng->close();
    int64_t totaltime = 0;
    for (auto i : mng->timeStamp) totaltime += i;
    out->ui->score->setText(QString("你的得分為：%1 / %2").arg(AddColor(mng->Corr,mng->displayCount)).arg(mng->displayCount));
    out->ui->totalTime->setText(QString("總答題時間：%1").arg(TimeDisplay(totaltime)));
    out->ui->avgTime->setText(QString("平均答題時間：%1").arg(TimeDisplay(totaltime / mng->displayCount)));
    out->show();
    connect(out,&OutroWidget::Replay,this,[=]{
        mng = new QuestionManagement(questionList,5);
        out->close();
        mng->show();
        connect(mng,&QuestionManagement::GameFinish,this,&Widget::outroCall);
    });
    delete mng;
}

QString Widget::AddColor(int Corr, size_t Count){
    double Rate = TODOUBLE(Corr) / TODOUBLE(Count) * 100;
    /*  (80% ~ 100%] -> S
     *  (55% ~ 80%] -> A
     *  (30% ~ 55%] -> B
     *  [0% ~ 30%] -> C
     */
    if (Rate > 80 && Rate <= 100) return QString("<font color=\"#e0cf37\">%1</font>").arg(Corr);
    else if (Rate > 55 && Rate <= 80) return QString("<font color=\"#8a43c1\">%1</font>").arg(Corr);
    else if (Rate > 30 && Rate <= 55) return QString("<font color=\"#0ebd2f\">%1</font>").arg(Corr);
    else if (Rate >= 0 && Rate <= 30) return QString("<font color=\"#343bcd\">%1</font>").arg(Corr);
    else throw std::range_error("Rate out of range: Pls Check");
}

QString Widget::TimeDisplay(double timeInput){
    if (timeInput > 6e4){
            double remain = remainder(timeInput,60.0);
            return QString("%1分%2秒").arg(floor(timeInput/6e4)).arg(QString::number(remain<0?remain+60:remain,'g',3));
        }
        else if (timeInput == 6e4) return "1分鐘";
        else if (timeInput >= 0) return QString("%1秒").arg(QString::number(timeInput/1000.0,'g',3));
        else throw std::range_error("Invalid duration");
}
