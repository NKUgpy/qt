#include "myitem.h"
#include<QPixmap>
#include"score.h"
#include<QCursor>


myitem::myitem()
{
   this->setPixmap(QPixmap(":/bg/qtwork/1.png"));
    this->mouse=false;                                              //初始化没有老鼠
    this->start=false;                                              //初始化为游戏结束模式
    this->setCursor(QCursor(QPixmap(":/bg/qtwork/chuizi.png")));   //初始化锤子抬起

}

void myitem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}                                             //自定义设置图片函数


void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(this->getStart())      //判定游戏开始
    {
        this->setCursor(QCursor(QPixmap(":/bg/qtwork/chuizi2.png")));//锤子落下
        score *scor=score::getInstance();

        if(this->getMousse())  //判定打中老鼠
        {
            this->setPic(":/bg/qtwork/3.png");//换成老鼠被打的图片
            scor->addScore();  //发送计分信号

            this->mouse=false;     //防止连按两下记两次分的bug
        }
    }
}                                                        //自定义鼠标按压事件   相当于游戏引擎

void myitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/bg/qtwork/chuizi.png")));
}                               //自定义鼠标松开事件   让锤子拿起












void myitem::setMouse(bool mou)
{
    this->mouse=mou;
}

bool myitem::getMousse()
{
    return this->mouse;
}

void myitem::setStart(bool str)
{
    this->start=str;
}

bool myitem::getStart()
{
    return this->start;
}
             //以上为判定游戏是否开始以是否打中老鼠做的准备











