#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDebug>
#include <QSettings>
#include <QVariantMap>>
#include <QDate>
#include <QtSql>
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
public slots:
    void getTime();
    void saveTime();

};

#endif // MAINWINDOW_H
