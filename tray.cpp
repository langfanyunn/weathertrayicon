#include "tray.h"

#include <Qmenu>

Tray::Tray()
{




    this->setIcon(QIcon(":/image/sunny"));
    bye = new QAction(tr("退出"),this);
    hours1 = new QAction(tr("1个小时提醒一次"),this);
    hours3 = new QAction(tr("3个小时提醒一次"),this);
    hours6 = new QAction(tr("6个小时提醒一次"),this);
    m = new QMenu;

    m->addAction(hours1);
    m->addAction(hours3);
    m->addAction(hours6);
    m->addAction(bye);
    this->setContextMenu(m);
    connect(bye,&QAction::triggered,[](){exit(0);});

    timer = new QTimer(this);


//    connect(hours1,SIGNAL(triggered()),this,SLOT(setTimer(3600000)));
//    connect(hours3,SIGNAL(triggered()),this,SLOT(setTimer(10800000)));
//    connect(hours6,SIGNAL(triggered()),this,SLOT(setTimer(21600000)));






}

void Tray::bink()
{
    timer->setSingleShot(true);//非单次出发  即多次触发
    timer->start(500);
    connect(timer,&QTimer::timeout,[this](){
        this->index = (this->index + 1)%10;
        if(this->index%2==0){
                    this->setIcon(QIcon(":/image/sunny"));
        }else{
                    this->setIcon(QIcon());
             }
        this->setIcon(QIcon(":/image/sunny"));
    });

}



