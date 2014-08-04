#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    //去窗口栏
//    this->setWindowFlags(Qt::FramelessWindowHint);
    manager = new QNetworkAccessManager(this);
    city = "温州";
    queryWeather();
    connect(manager,SIGNAL(finished(QNetworkReply*)),  // 必须要有finished信号才算下载完数据
            this,SLOT(replyFinished(QNetworkReply*)));

    //托盘图标
    tray = new Tray;
    tray->show();
    timer = new QTimer;
    timer->start(3600000);
    connect(tray->hours1,&QAction::triggered,[this](){timer->start(3600000);qDebug() << timer->interval();});
    connect(tray->hours3,&QAction::triggered,[this](){timer->start(10800000);qDebug() << timer->interval();});
    connect(tray->hours6,&QAction::triggered,[this](){timer->start(21600000);qDebug() << timer->interval();});
    //计时器到了后查天气
    connect(timer,&QTimer::timeout,[this](){
       this->queryWeather();
    });
    //托盘图标点击事件
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(widgetShow(QSystemTrayIcon::ActivationReason)));
   //托盘消息点击
    connect(tray,SIGNAL(messageClicked()),this,SLOT(widgetShow(QSystemTrayIcon::DoubleClick)));
}

widget::~widget()
{
    delete ui;
}



void widget::replyFinished(QNetworkReply *reply)
{
    QJsonParseError json_error;
    json =QJsonDocument::fromJson(reply->readAll(),&json_error);
    list = json.array().toVariantList();
    QString str;
    str.append(list.at(1).toMap()["Title"].toString()+"\n");
    str.append(list.at(2).toMap()["Title"].toString()+"\n");
    str.append(list.at(3).toMap()["Title"].toString()+"\n");


    ui->textBrowser->setText(str);
//    if(list.at(2).toMap()["Title"].toString().contains())


    str = list.at(3).toMap()["Title"].toString();
    tray->setToolTip(str);
    tray->bink();
    tray->showMessage(tr("天气预报"),ui->textBrowser->toPlainText(),QSystemTrayIcon::Information,10000);


    reply->deleteLater();   //最后要释放reply对象
}


void widget::on_pushButton_clicked()
{

    city = ui->lineEdit->text();
    queryWeather();

}

void widget::widgetShow(QSystemTrayIcon::ActivationReason reason)
{

    switch (reason) {
    //单击托盘
    case QSystemTrayIcon::Trigger:
         this->showNormal();
        break;
    //双击托盘
    case QSystemTrayIcon::DoubleClick:
        this->showNormal();
        break;
    default:
        break;
    }
    timer->setSingleShot(true);
}




void widget::queryWeather()
{
    url.setUrl("http://apix.sinaapp.com/weather/");
    query.addQueryItem("appkey", "trialuser");
    query.addQueryItem("city", city);
    url.setQuery(query);
    manager->get(QNetworkRequest(url)); //发送请求

}
