#include "database.h"

Database::Database(QObject *parent) :
    QObject(parent)
{
    init();
}

void Database::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if("TimeCounter"!=db.databaseName())
    {
        db.setDatabaseName("TimeCounter");
        QSqlTableModel model;
        model.setTable("Time");
        model.setHeaderData(0, Qt::Horizontal, "id");
        qDebug()<<this<<__FUNCTION__<<__LINE__<<"Db created"<<db;
        model.setHeaderData(1, Qt::Horizontal, "Time");
        model.setHeaderData(2, Qt::Horizontal, "Date");
        model.select();
    }
    else {qDebug()<<this<<__FUNCTION__<<__LINE__<<"database name TimeCounter exists";}
    db.close();
}
