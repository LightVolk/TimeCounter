#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QCoreApplication::setOrganizationName("Konstantin Maleev");
    QCoreApplication::setOrganizationDomain("simplevolk.net");
    QCoreApplication::setApplicationName("TimeCounter");

    ui->setupUi(this);
    h=0;m=0;s=0;ms=0;
    time=new QTime(h,m,s,ms);
    date=new QDate();
    database=new Database(this);
    database->init();
    connect(ui->pB_time,SIGNAL(clicked()),this,SLOT(getTime()));
}

// get and viev time
void MainWindow::getTime()
{
    qDebug()<<time->currentTime().toString();

    saveTime(time->currentTime(),date->currentDate());
    ui->lineEdit_hours_per_week->setText("");
    ui->lineEdit_hours_per_week->setText(time->currentTime().toString());

}

// save time to sqllite3
void MainWindow::saveTime(QTime time,QDate date)
{
      database->saveTime(time,date);
}

MainWindow::~MainWindow()
{
    delete ui;
}

