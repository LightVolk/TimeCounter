#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDebug>
#include <QSettings>
#include <QVariantMap>>
#include <QDate>
#include <QtSql>

#include <database.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QTime *time;
    int h,m,s,ms;
    QSettings *mysettings;
    QVariantMap timemap;
    QDate *date;
    Database *database;
    QSqlTableModel model;
public slots:
    void getTime();
    void saveTime(QTime time, QDate date);
    void outputData(QSqlTableModel *model);

};

#endif // MAINWINDOW_H
