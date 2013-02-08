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

    connect(ui->pB_time,SIGNAL(clicked()),this,SLOT(getTime()));
    connect(database,SIGNAL(signal_send_model(QSqlTableModel*)),this,SLOT(outputData(QSqlTableModel*)));


    /// qTableView init
    QStandardItemModel *model= new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));
    ui->tableView->setModel(model);

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

    //test
    database->outputAllTime();
}
void MainWindow::outputData(QSqlTableModel *model)
{
    ui->tableView->setModel(model);

    //ui->tableView->resizeColumnsToContents();
   // ui->tableView->setVisible(true);
    qDebug()<<this<<__FUNCTION__<<__LINE__<<"output"<<model->tableName()<<model->columnCount();
}
MainWindow::~MainWindow()
{
    delete ui;
}

