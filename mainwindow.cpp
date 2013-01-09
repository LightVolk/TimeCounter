#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h=0;m=0;s=0;ms=0;
    time=new QTime(h,m,s,ms);

    connect(ui->pB_time,SIGNAL(clicked()),this,SLOT(getTime()));
}


QTime MainWindow::getTime()
{
    return time->currentTime();
    qDebug()<<time->currentTime();
}

QTime MainWindow::saveTime(QTime *time)
{

    return time;
}

MainWindow::~MainWindow()
{
    delete ui;
}
