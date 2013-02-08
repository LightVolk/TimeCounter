#include "database.h"

Database::Database(QObject *parent) :
    QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");


    rowcounter=0;
    _model=new QSqlTableModel(this);


    qDebug()<<this<<__FUNCTION__<<__LINE__<<db.lastError().text();
    db.setDatabaseName("TimeCounter");
    _model->setTable("Time");
    if(_model->select()!=true)
    {
          qDebug()<<this<<__FUNCTION__<<__LINE__<<"model select failed";
    }
    if(_model->database().transaction()!=true)
    {
        qDebug()<<this<<__FUNCTION__<<__LINE__<<"transaction failed";
    }

   bool inscolumn=_model->insertColumn(0);
    _model->insertColumn(1);
    _model->insertColumn(2);


    _model->setHeaderData(0, Qt::Horizontal, "id");
    _model->setHeaderData(1, Qt::Horizontal, "Time");
    _model->setHeaderData(2, Qt::Horizontal, "Date");

    if(_model->submitAll()!=true)
    {
         qDebug()<<this<<__FUNCTION__<<__LINE__<<"submit failed";
    }
    else {
         qDebug()<<this<<__FUNCTION__<<__LINE__<<"sumbit success";
    }
    qDebug()<<this<<__FUNCTION__<<__LINE__<<"Db created"<<db.databaseName()<<"insert column"<<inscolumn;
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
    _model->database().commit();
    qDebug()<<this<<__FUNCTION__<<__LINE__<<"is model submit "<<issubmitall<<"rowcount"<<_model->rowCount();
    rowcounter++;
  emit signal_send_model(_model);



}

