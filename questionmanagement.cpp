#include "questionmanagement.h"
#include "outrowidget.h"

QuestionManagement::QuestionManagement(const std::vector<QQB*>& questions, int Quantity, QWidget* parent) : QStackedWidget(parent), Quantity(Quantity){
    this->resize(1000,700);
    auto order = GetRandomOrder(questions, this->Quantity);
    for (int i=0;i<this->Quantity;i++){
        auto* subquestion = questions[order[i]];
        this->QuestionList.push_back(subquestion);
        QMC* multq = dynamic_cast<Question::MultipleChoice*>(subquestion);
        QTF* tfq = dynamic_cast<Question::TrueorFalse*>(subquestion);
        if (multq && !tfq){
            QTMC* mc = new QTMC(multq);
            this->addWidget(mc);
            if (i==0) mc->base_ui->prevQuestion->setEnabled(false);
            else connect(mc->base_ui->prevQuestion, &QPushButton::clicked,this,[=]{this->CurrentIndex--;});
            if (i<this->Quantity-1) connect(mc->base_ui->nextQuestion,&QPushButton::clicked,this,[=]{this->CurrentIndex++;});
            else {
                mc->base_ui->nextQuestion->setText("完成");
                connect(mc->base_ui->prevQuestion, &QPushButton::clicked,this,&QuestionManagement::Finish);
            }
            connect(mc,&QTQB::Score,this,[=](bool Corr){
                if (Corr) this->Corr++;
                else Incorr++;
                CurrentIndex++;
                UpdatePages();
            });
            PageList.push_back(mc);
        }
        else if (!multq && tfq){
            QTTF* tf = new QTTF(tfq);
            this->addWidget(tf);
            if (i==0) tf->base_ui->prevQuestion->setEnabled(false);
            else connect(tf->base_ui->prevQuestion, &QPushButton::clicked,this,[=]{this->CurrentIndex--;});
            if (i<this->Quantity-1) connect(tf->base_ui->nextQuestion,&QPushButton::clicked,this,[=]{this->CurrentIndex++;});
            else {
                tf->base_ui->nextQuestion->setText("完成");
                connect(tf->base_ui->prevQuestion, &QPushButton::clicked,this,&QuestionManagement::Finish);
            }
            PageList.push_back(tf);
        }
    }
    this->setCurrentIndex(0);
    UpdatePages();
}

std::vector<int> QuestionManagement::range(int Lim){
    std::vector<int> Out;
    for (int i=0;i<Lim;i++) Out.push_back(i);
    return Out;
}

std::vector<int> QuestionManagement::GetRandomOrder(const std::vector<QQB*>& Questions, size_t Quantity){
    if (Questions.size() < Quantity) throw std::out_of_range("Unable to get Question Order: Question List too few");
    std::vector<int> Output, Copy = range(Questions.size());
    for (size_t i=0; i<Quantity;i++){
        srand(time(0));
        size_t Target = (size_t)GetRandomNumber(Copy.size());
        Output.push_back(Copy[Target]);
        Copy.erase(Copy.begin()+Target);
    }
    return Output;
}

void QuestionManagement::UpdatePages(){
    for (auto* tar : PageList){
        tar->SetScore(Corr,Incorr);
        tar->SetProgress(CurrentIndex,PageList.size());
    }
}

void QuestionManagement::Finish(){
    OutroWidget* outro = new OutroWidget;
    this->close();
    outro->show();
}
