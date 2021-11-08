#include "database.h"



//const char *Type = "QMYSQL";  //数据库类型
//const QString& Host = "127.0.0.1";      //数据库ip地址
//const int Port = 3306;
//const QString& Password = "123456";
//const QString& Username = "root";

Database::Database()
{
//    mutex.lock();


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
//    selectsql = "select * from project_;";
    db.setDatabaseName("mysql");
    query = QSqlQuery(db);


//    qDebug()<< query.exec(selectsql);




    bool flagdb = db.open();

    if( flagdb == false){
        QMessageBox::critical(NULL,QObject::tr("无法打开数据库"),"无法创建数据库连接！",QMessageBox::Cancel);

    }
//    if( !query.exec(selectsql)){
    query.exec("create table project_PLC( id int(30) primary key not null auto_increment ,number  int(11)  ,time  datetime , current_1  varchar(10), voltage_1 varchar(10),speed_1 varchar(10) , current_2  varchar(10), voltage_2 varchar(10),speed_2 varchar(10) ,current_3  varchar(10), voltage_3 varchar(10),speed_3 varchar(10) ,current_4  varchar(10), voltage_4 varchar(10),speed_4 varchar(10) ,current_5  varchar(10), voltage_5 varchar(10),speed_5 varchar(10) ,current_6  varchar(10), voltage_6 varchar(10),speed_6 varchar(10) ) character set = utf8;");
    query.exec("create table project_DM( id int(30) primary key not null auto_increment , code    varchar(20)) character set = utf8;");
    query.exec("create table project_3D( id int(30) primary key not null auto_increment  , test1   varchar(10),test2   varchar(10),test3   varchar(10),test4   varchar(10),test5   varchar(10),test6   varchar(10)) character set = utf8;");




}

void Database::DB_insert_dm( QString code ){
    qDebug()<<"insert_dm"<<code;
    query = QSqlQuery(db);
    query.prepare("insert into project_dm ( code ) values( :code );");

    query.bindValue(":code",code);
    query.exec();



}
void Database::DB_insert_plc(int number , QString current_1, QString voltage_1, QString speed_1, QString current_2, QString voltage_2, QString speed_2 , QString current_3, QString voltage_3, QString speed_3  , QString current_4, QString voltage_4,  QString speed_4, QString current_5, QString voltage_5,  QString speed_5 , QString current_6, QString voltage_6,  QString speed_6){

    query = QSqlQuery(db);
     qDebug()<<number<<current_1<<current_2<<current_3<<current_4<<voltage_1<<voltage_2<<voltage_3<<voltage_4<<speed_1<<speed_2<<speed_3<<speed_4;
    query.prepare("insert into project_plc ( number , time, current_1, voltage_1, speed_1,current_2, voltage_2, speed_2 ,current_3, voltage_3, speed_3  ,current_4, voltage_4, speed_4,current_5, voltage_5, speed_5,current_6, voltage_6, speed_6) values( :number , now(), :current_1, :voltage_1, :speed_1,:current_2, :voltage_2, :speed_2 ,:current_3, :voltage_3, :speed_3, :current_4, :voltage_4, :speed_4, :current_5, :voltage_5, :speed_5, :current_6, :voltage_6, :speed_6);");
    query.bindValue(":number",number);
    query.bindValue(":current_1",current_1);
    query.bindValue(":voltage_1",voltage_1);
    query.bindValue(":speed_1",speed_1);
    query.bindValue(":current_2",current_2);
    query.bindValue(":voltage_2",voltage_2);
    query.bindValue(":speed_2",speed_2);
    query.bindValue(":current_3",current_3);
    query.bindValue(":voltage_3",voltage_3);
    query.bindValue(":speed_3",speed_3);
    query.bindValue(":current_4",current_4);
    query.bindValue(":voltage_4",voltage_4);
    query.bindValue(":speed_4",speed_4);

    query.bindValue(":current_5",current_5);
    query.bindValue(":voltage_5",voltage_5);
    query.bindValue(":speed_5",speed_5);

    query.bindValue(":current_6",current_6);
    query.bindValue(":voltage_6",voltage_6);
    query.bindValue(":speed_6",speed_6);
    query.exec();


}
void Database::DB_insert_3d(QString test1,QString test2,QString test3,QString test4,QString test5,QString test6){

     query = QSqlQuery(db);
     query.prepare("insert into project_3d ( test1,test2,test3,test4,test5,test6) values( :test1,:test2,:test3,:test4,:test5 ,:test6);");
     qDebug()<<"insert_3d"<<test1;

     query.bindValue(":test1",test1);
     query.bindValue(":test2",test2);
     query.bindValue(":test3",test3);
     query.bindValue(":test4",test4);
     query.bindValue(":test5",test5);
     query.bindValue(":test6",test6);
     query.exec();



}
void Database::DB_delete(QString code){
    query = QSqlQuery(db);
    int id;
    query.prepare("select * from project_dm where code = :code;");
    query.bindValue(":code" ,code);
    query.exec();
    if(query.first()){
      id = query.value("code").toInt();
      query.prepare("delete from project_plc where :id = id;");
      query.bindValue(":code" ,code);
      query.exec();
      query.prepare("delete from project_3d where :id = id;");
      query.bindValue(":code" ,code);
      query.exec();
      query.prepare("delete from project_dm where :id = id;");
      query.bindValue(":code" ,code);
      query.exec();

    }

}


Database::~Database(){

}

