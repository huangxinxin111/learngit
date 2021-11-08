#ifndef DATABASE_H
#define DATABASE_H
#include<QtSql/QSqlDatabase>
#include<QtDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QString>
#include <QTime>
using namespace std;



class Database
{
public:
    Database();
    void test();

    ~Database();


private:
    QSqlDatabase db;//数据库操作对象
    QSqlQuery query;
    QString selectsql;


public slots:
    void DB_insert_dm(QString code );
    void DB_insert_plc(int number , QString current_1, QString voltage_1, QString speed_1, QString current_2, QString voltage_2, QString speed_2 , QString current_3, QString voltage_3, QString speed_3  , QString current_4, QString voltage_4,  QString speed_4 ,QString current_5, QString voltage_5,  QString speed_5 , QString current_6, QString voltage_6,  QString speed_6);
    void DB_insert_3d(QString test1,QString test2,QString test3,QString test4,QString test5,QString test6);
    void DB_delete(QString code);
//    void DB_update(QString name,QString value, QString xvalue);
//    void DB_select(int code);
//    void deleteall();



};


#endif // DATABASE_H
