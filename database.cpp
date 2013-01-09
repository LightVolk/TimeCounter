#include "database.h"

Database::Database(QObject *parent) :
    QObject(parent)
{
    rowcounter=0;
    init();
}
QSqlDatabase Database::getDb()
{
    return db;
}

void Database::init()
{
    db.addDatabase("QSQLITE");
    if(db.isOpen())
    {
        db.close();
        if("TimeCounter"!=db.databaseName())
        {
            db.setDatabaseName("TimeCounter");
            _model.setTable("Time");
            _model.setHeaderData(0, Qt::Horizontal, "id");
            qDebug()<<this<<__FUNCTION__<<__LINE__<<"Db created"<<db;
            _model.setHeaderData(1, Qt::Horizontal, "Time");
            _model.setHeaderData(2, Qt::Horizontal, "Date");
            _model.select();

        }
        else {qDebug()<<this<<__FUNCTION__<<__LINE__<<"database name TimeCounter exists";}
    }

    db.close();
}
void Database::saveTime(QTime time,QDate date)
{
    QSqlDatabase db;
    QSqlTableModel model;



    //qDebug()<<this<<__FUNCTION__<<__LINE__<<db;
    int row = _model.rowCount(); //запомним количество строчек.

    qDebug()<<rowcounter;
    _model.insertRows(rowcounter, 1);

     //    //вносим одну запись, которая станет последней
    _model.setData(_model.index(row,0),row);
    _model.setData(_model.index(row,1),time);
    _model.setData(_model.index(row,1),date);
    _model.submitAll();
    rowcounter++;

}
