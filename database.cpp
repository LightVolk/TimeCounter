#include "database.h"

Database::Database(QObject *parent) :
    QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.open();

    rowcounter=0;
    _model=new QSqlTableModel(this);


    qDebug()<<this<<__FUNCTION__<<__LINE__<<db.lastError().text();
    db.setDatabaseName("TimeCounter");
    _model->setTable("Time");
    _model->insertColumn(0);
    _model->insertColumn(1);
    _model->insertColumn(2);


    _model->setHeaderData(0, Qt::Horizontal, "id");
    _model->setHeaderData(1, Qt::Horizontal, "Time");
    _model->setHeaderData(2, Qt::Horizontal, "Date");

    _model->submitAll();
    qDebug()<<this<<__FUNCTION__<<__LINE__<<"Db created"<<db.databaseName();
    qDebug()<<this<<__FUNCTION__<<__LINE__<<_model->tableName()<<_model->columnCount();

    rowcounter=0;
}


void Database::saveTime(QTime time,QDate date)
{


    qDebug()<<rowcounter;

    _model->insertRow(rowcounter);
  //  _model->insertRows(rowcounter, 1);
     //    //вносим одну запись, которая станет последней
    _model->setData(_model->index(rowcounter,0),rowcounter);
    _model->setData(_model->index(rowcounter,1),time.toString());
    _model->setData(_model->index(rowcounter,2),date.toString());


    bool issubmitall=_model->submitAll();

    qDebug()<<this<<__FUNCTION__<<__LINE__<<issubmitall<<"rowcount"<<_model->rowCount();
    rowcounter++;
  emit signal_send_model(_model);



}

