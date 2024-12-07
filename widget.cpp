#include "widget.h"
#include "questionmanagement.h"
#include "QuestionList.h"

IntroWidget::IntroWidget(QWidget* parent) : QWidget(parent), intro_form(new Ui::IntroWidget){
    intro_form->setupUi(this);
    connect(intro_form->startGame,&QPushButton::clicked,this,&IntroWidget::startGame);
}

void IntroWidget::startGame(){
    using namespace QuestionList;
    QuestionManagement* mng = new QuestionManagement(
                              {
                                  Question01, Question02, Question03, Question04, Question05, Question06, Question07, Question08, Question09, Question10,
                                  Question11, Question12, Question13, Question14, Question15, Question16, Question17, Question18, Question19, Question20,
                                  Question21, Question22, Question23, Question24, Question25, Question26, Question27, Question28, Question29, Question30,
                                  Question31, Question32, Question33, Question34, Question35, Question36, Question37, Question38, Question39, Question40
                              },22);
    this->close();
    mng->show();
}
