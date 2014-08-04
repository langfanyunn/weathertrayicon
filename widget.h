#ifndef WIDGET_H
#define WIDGET_H
#include "tray.h"
#include <QWidget>
#include <QtNetwork>
#include <QUrl>
#include <QTimer>

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = 0);
    ~widget();
    void queryWeather();
private slots:
    void replyFinished(QNetworkReply*);
    void on_pushButton_clicked();
    void widgetShow(QSystemTrayIcon::ActivationReason reason);
private:
    Ui::widget *ui;

    QNetworkAccessManager *manager;
    QUrlQuery query;
    QJsonDocument json;
    QVariantList list;
    QString city;
    QUrl url;
    Tray *tray;

    QTimer *timer;

};

#endif // WIDGET_H
