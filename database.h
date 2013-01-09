#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = 0);
    
signals:
    
public slots:
    QSqlDatabase createDatabase(QString basename);
    QSqlDatabase createTable(QString tablename);
    int insertTime(QTime time);//insert new line in table
    int removeTime(QTime time);
};

#endif // DATABASE_H
