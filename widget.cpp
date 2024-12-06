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
                {Question1,Question2,Question3,Question4,Question5,Question6,Question7},3);
    this->close();
    mng->show();
}
