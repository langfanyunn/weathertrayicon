
#include <QApplication>
#include "stdlib.h"
#include "widget.h"
#include "tray.h"
#include <QMessageBox>
#include <QDebug>


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(image);
    QApplication a(argc, argv);
    if(!QSystemTrayIcon::isSystemTrayAvailable()){
        qDebug()<<QSystemTrayIcon::isSystemTrayAvailable();
        return EXIT_FAILURE;
    }
    QApplication::setQuitOnLastWindowClosed(false);//QuitOnLastWindowClosed指没有窗口就退出 false即不退出
    widget w;
    w.show();




    return a.exec();
}
