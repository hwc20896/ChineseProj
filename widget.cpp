#include "widget.h"
#include "QuestionList.h"
#include <QMessageBox>

IntroWidget::IntroWidget(QWidget* parent) : QWidget(parent), intro_form(new Ui::IntroWidget){
    using namespace QuestionList;
    intro_form->setupUi(this);
    questionList = {
        Question01, Question02, Question03, Question04, Question05, Question06, Question07, Question08, Question09, Question10,
        Question11, Question12, Question13, Question14, Question15, Question16, Question17, Question18, Question19, Question20,
        Question21, Question22, Question23, Question24, Question25, Question26, Question27, Question28, Question29, Question30,
        Question31, Question32, Question33, Question34, Question35, Question36, Question37, Question38, Question39, Question40
    };
    connect(intro_form->startGame,&QPushButton::clicked,this,&IntroWidget::startGame);
    connect(intro_form->rule,&QPushButton::clicked,this,[]{
        QMessageBox* box = new QMessageBox(QMessageBox::Icon::Information,"尚未建設","規則頁尚未建設",QMessageBox::StandardButton::Ok);
        box->show();
    });
}

void IntroWidget::startGame(){
    mng = new QuestionManagement(questionList,5);
    this->close();
    mng->show();
    connect(mng,&QuestionManagement::GameFinish,this,&IntroWidget::outroCall);
}

void IntroWidget::outroCall(){
    OutroWidget* out = new OutroWidget;
    mng->close();
    out->show();
    connect(out,&OutroWidget::Replay,this,[=]{
        mng = new QuestionManagement(questionList,5);
        out->close();
        mng->show();
        connect(mng,&QuestionManagement::GameFinish,this,&IntroWidget::outroCall);
    });
    delete mng;
}

OutroWidget::OutroWidget(QWidget* parent) : QWidget(parent), ui(new Ui::OutroWidget){
    ui->setupUi(this);
    connect(ui->replayButton,BUTTONCLICK,this,&OutroWidget::Replay);
}
