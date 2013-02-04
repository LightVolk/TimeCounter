#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QTime>
#include <QDate>
class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = 0);

private:
 QSqlDatabase *db;
 QSqlTableModel *_model;
 int rowcounter;
 QSqlDatabase getDb();
// QSqlTableModel getModel();

signals:
 void signal_send_model(QSqlTableModel*);
public slots:

   void saveTime(QTime time,QDate date);
   void outputAllTime();
};

#endif // DATABASE_H
