#include "widget.h"
#include "QuestionList.h"
#include <QApplication>
#include <QLineEdit>

IntroWidget::IntroWidget(QWidget* parent) : QWidget(parent), intro_form(new Ui::IntroWidget){
    intro_form->setupUi(this);
    muted.addFile(":/Drawables/drawables/mute_unpressed.png",QSize(),QIcon::Normal);
    muted.addFile(":/Drawables/drawables/mute_pressed.png",QSize(),QIcon::Active);
    unmuted.addFile(":/Drawables/drawables/unmute_unpressed.png",QSize(),QIcon::Normal);
    unmuted.addFile(":/Drawables/drawables/unmute_pressed.png",QSize(),QIcon::Active);
    connect(intro_form->muteSwitch,BUTTONCLICK,this,[=]{
        isMuted = !isMuted;
        SetMute(isMuted);
    });
    SetMute(isMuted);
}

void IntroWidget::SetMute(bool isMuted){intro_form->muteSwitch->setIcon(isMuted?muted:unmuted);}

RuleWidget::RuleWidget(QWidget* parent) : QWidget(parent), rule_form(new Ui::RuleWidget){rule_form->setupUi(this);}

OutroWidget::OutroWidget(QWidget* parent) : QWidget(parent), ui(new Ui::OutroWidget){
    ui->setupUi(this);
    muted.addFile(":/Drawables/drawables/mute_unpressed.png",QSize(50,50),QIcon::Normal);
    muted.addFile(":/Drawables/drawables/mute_pressed.png",QSize(50,50),QIcon::Active);
    unmuted.addFile(":/Drawables/drawables/unmute_unpressed.png",QSize(50,50),QIcon::Normal);
    unmuted.addFile(":/Drawables/drawables/unmute_pressed.png",QSize(50,50),QIcon::Active);
    connect(ui->replayButton,BUTTONCLICK,this,&OutroWidget::Replay);
    connect(ui->exitButton,BUTTONCLICK,this,&QApplication::quit);
    connect(ui->muteSwitch,BUTTONCLICK,this,[=]{
        isMuted = !isMuted;
        SetMute(isMuted);
    });
}

void OutroWidget::SetMute(bool isMuted){ui->muteSwitch->setIcon(isMuted?muted:unmuted);}

Widget::Widget(QWidget* parent) : QStackedWidget(parent){
    this->resize(1000,700);
    intro = new IntroWidget;
    this->addWidget(intro);
    RuleWidget* rule = new RuleWidget;
    this->addWidget(rule);
    this->setCurrentIndex(currentGameMode);
    using namespace QuestionList;
    questionList = {
        Q001, Q002, Q003, Q004, Q005, Q006, Q007, Q008, Q009, Q010,
        Q011, Q012, Q013, Q014, Q015, Q016, Q017, Q018, Q019, Q020,
        Q021, Q022, Q023, Q024, Q025, Q026, Q027, Q028, Q029, Q030,
        Q031, Q032, Q033, Q034, Q035, Q036, Q037, Q038, Q039, Q040,
        Q041, Q042, Q043, Q044, Q045, Q046, Q047, Q048, Q049, Q050,
        Q051, Q052, Q053, Q054, Q055, Q056, Q057, Q058, Q059, Q060,
        Q061, Q062, Q063, Q064, Q065, Q066, Q067, Q068, Q069, Q070,
        Q071, Q072, Q073, Q074, Q075, Q076, Q077, Q078, Q079, Q080,
        Q081, Q082, Q083, Q084, Q085, Q086, Q087, Q088, Q089, Q090,
        Q091, Q092, Q093, Q094, Q095, Q096, Q097, Q098, Q099, Q100
    };
    featureList = {"普通","限時"};
    modeExplanation = {
        "普通模式：不限時，結尾顯示答題時間及平均每題時間",
        "限時模式：限時1分鐘，超時將強制跳轉至結束頁"
    };
    intro->intro_form->featureBox->addItems(featureList);
    intro->intro_form->featureBox->setCurrentIndex(0);
    intro->intro_form->gamemodeExplanation->setText(modeExplanation[0]);
    connect(intro->intro_form->startGame,BUTTONCLICK,this,&Widget::startGame);
    connect(intro->intro_form->rule,BUTTONCLICK,this,[=]{this->setCurrentWidget(rule);});
    connect(rule->rule_form->returnButton,BUTTONCLICK,this,[=]{this->setCurrentWidget(intro);});
    connect(intro->intro_form->featureBox,&QComboBox::currentIndexChanged,this,[=](int index){intro->intro_form->gamemodeExplanation->setText(modeExplanation[index]);});
}

void Widget::startGame(){
    currentGameMode = intro->intro_form->featureBox->currentIndex();
    mng = new QuestionManagement(questionList,5,currentGameMode);
    mng->isMuted = intro->isMuted;
    mng->UpdateMute();
    this->close();
    mng->show();
    connect(mng,&QuestionManagement::GameFinish,this,&Widget::outroCall);
}

void Widget::outroCall(){
    OutroWidget* out = new OutroWidget;
    mng->close();
    int64_t totaltime = 0;
    for (auto i : mng->timeStamp) totaltime += i;
    out->ui->featureBox->addItems(featureList);
    out->ui->featureBox->setCurrentIndex(currentGameMode);
    out->ui->gamemodeExplanation->setText(modeExplanation[currentGameMode]);
    connect(out->ui->featureBox, &QComboBox::currentIndexChanged,this,[=](int index){out->ui->gamemodeExplanation->setText(modeExplanation[index]);});
    out->ui->score->setText(QString("你的得分為：%1 / %2：%3%").arg(AddColor(mng->Corr,mng->displayCount)).arg(mng->displayCount).arg(TODOUBLE(mng->Corr)/TODOUBLE(mng->displayCount)*100));
    if (currentGameMode == 0){
        out->ui->totalTime->setText(QString("總答題時間：%1").arg(TimeDisplay(totaltime)));
        out->ui->avgTime->setText(QString("平均答題時間：%1").arg(TimeDisplay(totaltime / mng->displayCount)));
    }
    else{
        out->ui->totalTime->setVisible(false);
        out->ui->avgTime->setVisible(false);
    }
    out->isMuted = mng->isMuted;
    out->SetMute(out->isMuted);
    out->show();
    connect(out,&OutroWidget::Replay,this,[=]{
        currentGameMode = out->ui->featureBox->currentIndex();
        mng = new QuestionManagement(questionList,5,currentGameMode);
        mng->isMuted = out->isMuted;
        mng->UpdateMute();
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
