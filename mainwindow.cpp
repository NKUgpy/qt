#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"score.h"
#include"scorepro.h"
#include"scorepros.h"
//#include<QMediaPlayer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc=new myScene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this,SLOT(btnStart()));
    //connect(this->ui->btn_start,SIGNAL(clicked(bool)),this,SLOT(musicGamestart())); //背景音乐
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this,SLOT(btnPause()));
    connect(this->ui->btn_finish,SIGNAL(clicked(bool)),this->sc,SLOT(finishGame()));
    connect(this->ui->btn_finish,SIGNAL(clicked(bool)),this,SLOT(resetGoal()));         //以上连接界面控件
    connect(this->ui->btn_finish,SIGNAL(clicked(bool)),this,SLOT(btnFinish()));
    this->goal=0;      //计分
    score *scor=score::getInstance();

    connect(scor,SIGNAL(beatMouse()),this,SLOT(updateGoal()));   //用信号与槽机制更新分数
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGoal()
{
    scorePro *num=scorePro::getNum();
    scorePros *num1=scorePros::getNum1();
    this->goal=this->goal+100;
    if(this->goal>=500&&this->goal<1000)
    {
        num->beatNum();
    }                                                     //分数大于500小于1000  游戏变为中等难度
    else if(this->goal>=1000) num1->beatNum1();          //分数大于1000  难度变为困难
    this->ui->lcdNumber->display(this->goal);
}                                                     //更新分数函数   并发送改变游戏难度的信号


void MainWindow::resetGoal()
{
    this->goal=0;
    this->ui->lcdNumber->display(this->goal);
}                                                          //游戏结束时重置分数的函数

void MainWindow::btnStart()
{
    this->ui->btn_start->setEnabled(false);
    this->ui->btn_pause->setEnabled(true);
}


void MainWindow::btnPause()
{
     this->ui->btn_pause->setEnabled(false);
    this->ui->btn_start->setEnabled(true);
}

void MainWindow::btnFinish()
{
    this->ui->btn_start->setEnabled(true);
    this->ui->btn_pause->setEnabled(true);
}


















//void MainWindow::musicGamestart()
//{
//    QMediaPlayer *p1=new QMediaPlayer;
//    p1->setMedia(QUrl::fromLocalFile("C:\\Users\\18338\\Desktop\\music\\backgroundmusic.mp3"));
//    p1->setVolume(40);
//    p1->play();
//}


//   void MainWindow::fivekill()
//{       QMediaPlayer*p1=new QMediaPlayer;
//        p1->setMedia(QUrl::fromLocalFile("C:\\Users\\yangkaixing\\Desktop\\Crazy_Arcade_Exclusive\\Crazy_Arcade\\music\\five.mp3"));
//        p1->setVolume(48);p1->play();
//}     游戏音效
