#include "widget.h"
#include <QApplication>
#include <QLineEdit>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>

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

    QFile file(QString("%1/QuestionList.json").arg(QDir::currentPath()));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        intro->intro_form->startGame->setEnabled(false);
    }
    else{
        QString jsonContext = QTextStream(&file).readAll();
        file.close();
        questionList = Json::deserializeArray<QuestionTemplate::MultipleChoice>(jsonContext);
    }

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

template <class T> QList<T> Json::deserializeArray(const QString& jsonString){
    QList<T> items;
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    if (doc.isArray()){
        QJsonArray arr = doc.array();
        for (const QJsonValue& val : arr){
            T i = T(val.toObject());
            items.push_back(i);
        }
    }
    return items;
}
