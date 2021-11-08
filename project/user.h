#ifndef USER_H
#define USER_H
#include "login.h"
#include "database.h"
#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QtXlsx/QtXlsx>
#include <QFileDialog>
 #include<QTableWidgetItem>
#include <String>
#include "find.h"
#include "ip.h"
namespace Ui {
class User;
}

class User : public QMainWindow
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = 0);
    Login *l;
    Find *f;
    Ip *p;


    void excel();
//    void timerEvent(QTimerEvent *);
    ~User();


private slots:
    void on_pushButton_clicked();
    void loginSlots();
    void on_delete_2_clicked();
    void showtable();


    void on_baocun_clicked();

    void on_ip_clicked();

    void on_read_clicked();
    void on_tableWidget_2_itemClicked(QTableWidgetItem *item);

protected:
    void resizeEvent(QResizeEvent *event);


public:
    Ui::User *ui;
private:
    Database *D;
    int i;


};

#endif // USER_H
