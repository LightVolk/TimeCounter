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
   void init();
};

#endif // DATABASE_H
