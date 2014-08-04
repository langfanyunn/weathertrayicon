#ifndef TRAY_H
#define TRAY_H

#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QTimer>



class Tray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    Tray();
    void bink();
    QAction *bye;
    QAction *hours1;
    QAction *hours3;
    QAction *hours6;
private slots:

private:

    QMenu *m;
    QTimer *timer;
    int index=0;



};

#endif // TRAY_H
