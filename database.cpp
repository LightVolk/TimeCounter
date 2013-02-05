#include "database.h"

Database::Database(QObject *parent) :
    QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    rowcounter=0;
    _model=new QSqlTableModel(this);

    if("TimeCounter"!=db.databaseName())
        {
            qDebug()<<this<<__FUNCTION__<<__LINE__<<db.lastError().text();
            db.setDatabaseName("TimeCounter");
            _model->setTable("Time");
            _model->setHeaderData(0, Qt::Horizontal, "id");
            _model->setHeaderData(1, Qt::Horizontal, "Time");
            _model->setHeaderData(2, Qt::Horizontal, "Date");
            qDebug()<<this<<__FUNCTION__<<__LINE__<<"Db created"<<db.databaseName();
            qDebug()<<this<<__FUNCTION__<<__LINE__<<_model->tableName();
        }
    else {
        qDebug()<<this<<__FUNCTION__<<__LINE__<<"TimeCounter name exists";

    }


}
QSqlDatabase Database::getDb()
{
  //  return *db;
}


void Database::saveTime(QTime time,QDate date)
{
    QSqlDatabase db;  QSqlTableModel model;
    qDebug()<<rowcounter;
    _model->insertRows(2, 1);
    //    //вносим одну запись, которая станет последней
    _model->setData(_model->index(_model->rowCount(),0),_model->rowCount());
    _model->setData(_model->index(_model->rowCount(),1),time);
    _model->setData(_model->index(_model->rowCount(),1),date);
    _model->submitAll();
    rowcounter++;
}

void Database::outputAllTime()
{
    _model->setFilter("id");
    _model->setFilter("Time");
    _model->setFilter("Date");

    _model->select();
    emit signal_send_model(_model);
}
