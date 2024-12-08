#include "widget.h"
#include "QuestionList.h"
#include <QMessageBox>

IntroWidget::IntroWidget(QWidget* parent) : QWidget(parent), intro_form(new Ui::IntroWidget){intro_form->setupUi(this);}

RuleWidget::RuleWidget(QWidget* parent) : QWidget(parent), rule_form(new Ui::RuleWidget){rule_form->setupUi(this);}

OutroWidget::OutroWidget(QWidget* parent) : QWidget(parent), ui(new Ui::OutroWidget){
    ui->setupUi(this);
    connect(ui->replayButton,BUTTONCLICK,this,&OutroWidget::Replay);
}

Widget::Widget(QWidget* parent) : QStackedWidget(parent){
    IntroWidget* intro = new IntroWidget;
    this->addWidget(intro);
    RuleWidget* rule = new RuleWidget;
    this->addWidget(rule);
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
    out->show();
    connect(out,&OutroWidget::Replay,this,[=]{
        mng = new QuestionManagement(questionList,5);
        out->close();
        mng->show();
        connect(mng,&QuestionManagement::GameFinish,this,&Widget::outroCall);
    });
    delete mng;
}
