#include "database.h"

Database::Database(QObject *parent) :
    QObject(parent)
{

}


QSqlDatabase Database::createDatabase(QString basename)
{
    QSqlDatabase db = new QSqlDatabase::addDatabase(basename);

    return db;
}

QSqlDatabase Database::createTable(QString tablename)
{


}
