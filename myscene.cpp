#include "myscene.h"
#include<stdlib.h>
#include"scorepro.h"
#include"scorepros.h"

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    for(int i=0;i<16;i++)
    {
        this->item[i]=new myitem;
        this->item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);

    }                               //设置16张图元   游戏开始的界面图
    this->ptimer=new QTimer;      //定时器
    this->n=0;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));     //连接定时器的信号   来让老数出来
    scorePro *num=scorePro::getNum();
    scorePros *num1=scorePros::getNum1();
    connect(num,SIGNAL(beatNum()),this,SLOT(chanPtimer()));
    connect(num1,SIGNAL(beatNum1()),this,SLOT(chanPtimer1()));         //以上均用于改变游戏难度
}


void myScene::showMouse()
{


        this->item[this->n]->setPic(":/bg/qtwork/1.png");   //每次让老鼠出来前重置所有图元   换成没有老鼠的图片
        this->item[this->n]->setMouse(false);
        int m=rand()%16;                                       //随机一个数
        this->n=m;
        this->item[m]->setPic(":/bg/qtwork/2.png");  //   换成有老鼠的图片
        this->item[m]->setMouse(true);
}

void myScene::startGame()
{
    this->ptimer->start(2000);             //开始时为简单难度
    for(int i=0;i<16;i++)
    {
        this->item[i]->setStart(true);
    }
}                           //游戏开始函数


void myScene::pauseGame()
{
    this->ptimer->stop();
    for(int i=0;i<16;i++)
        this->item[i]->setStart(false);
}                    //游戏暂停函数


void myScene::finishGame()
{
    this->ptimer->stop();
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setPic(":/bg/qtwork/1.png");   //   换成没有老鼠的图片
        this->item[i]->setMouse(false);
        this->item[i]->setStart(false);
    }
}                                          //游戏结束函数


void myScene::chanPtimer()
{
    this->ptimer->start(1300);
}                                            //中等难度设置

void myScene::chanPtimer1()
{
    this->ptimer->start(800);
}                                           //困难难度设置









