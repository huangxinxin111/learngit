#include "user.h"
#include "ui_user.h"


User::User(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    ui->baocun->setEnabled(false);

//    setCentralWidget(ui->tableWidget);

//    setCentralWidget(ui->tableWidget);
//    QHBoxLayout *windowLayout = new QHBoxLayout;
//    windowLayout->addWidget(ui->tableWidget);
//    ui->tableWidget->setLayout(windowLayout);




    ui->delete_2->setEnabled(false);
    ui->ip->setEnabled(false);
    ui->read->setEnabled(false);
    l = new Login();
    f = new Find();
    p = new Ip();
    connect(l,SIGNAL(showmain()),this,SLOT(loginSlots()));
    connect(p,SIGNAL(fashe()),this,SLOT(showtable()));
    D = new Database();


//    D = new Database();
//    D->DB_insert(3,2,"asdf","afda","afs","asfd","afdsf");
//     D->DB_select(2);



//    connect(ui->delete_2,&QPushButton::clicked,D,&Database::deleteall);

//    D->DB_select(2);

    //建表
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setRowCount(10);
    ui->tableWidget_2->verticalHeader()->setHidden(true);
    int i = 1;
    do{
                ui->tableWidget_2->setItem( i-1,0, new QTableWidgetItem(QString::number(i)));
                 ui->tableWidget_2->item(i-1,0)->setTextAlignment(Qt::AlignCenter);
                i++;

            }while( i <= 10);

    ui->erweima->setStyleSheet("QLabel{background-color:rgb(193,210,240);}");

    ui->gongweihao->setStyleSheet("QLabel{background-color:rgb(193,210,240);}");


    ui->shijian->setStyleSheet("QLabel{background-color:rgb(193,210,240);}");



//    startTimer(1000);






}



User::~User()
{
    delete ui;
    delete l;
    delete D;
}

void User::on_pushButton_clicked()
{
//    Login *l = new Login();
    l->show();

    l->setWindowTitle("用户登录");


}
void User::loginSlots()
{
    if(temp::zt == true){
        ui->baocun->setEnabled(temp::optEnable);

        ui->delete_2->setEnabled(temp::optEnable);
        ui->ip->setEnabled(temp::optEnable);
        ui->read->setEnabled(temp::optEnable );
    }
}
void User::showtable(){
//    ui->tableWidget->clearContents();
//    QString sqlstr = "select a.number, a.time,a.current_1,a.voltage_1,a.speed_1,a.current_2,a.voltage_2,a.speed_2,a.current_3,a.voltage_3,a.speed_3,a.current_4,a.voltage_4,a.speed_4,b.code,c.test1,c.test2,c.test3,c.test4,c.test5 from project_plc a left join project_dm b on a.id = b.id left join project_3d c on a.id = c.id;";
//    QSqlQuery query;
//    int i = 0;
//    if(query.exec(sqlstr)){
//        query.last();
//        do{
//            ui->tableWidget->setItem( i,0, new QTableWidgetItem(query.value("code").toString()));
//            ui->tableWidget->setItem( i,1, new QTableWidgetItem(query.value("number").toString()));
//            ui->tableWidget->setItem( i,2, new QTableWidgetItem(query.value("time").toString()));
//            ui->tableWidget->setItem( i,3, new QTableWidgetItem(query.value("current_1").toString()));
//            ui->tableWidget->setItem( i,4, new QTableWidgetItem(query.value("voltage_1").toString()));
//            ui->tableWidget->setItem( i,5, new QTableWidgetItem(query.value("speed_1").toString()));
//            ui->tableWidget->setItem( i,6, new QTableWidgetItem(query.value("current_2").toString()));
//            ui->tableWidget->setItem( i,7, new QTableWidgetItem(query.value("voltage_2").toString()));
//            ui->tableWidget->setItem( i,8, new QTableWidgetItem(query.value("speed_2").toString()));
//            ui->tableWidget->setItem( i,9, new QTableWidgetItem(query.value("current_3").toString()));
//            ui->tableWidget->setItem( i,10, new QTableWidgetItem(query.value("voltage_3").toString()));
//            ui->tableWidget->setItem( i,11, new QTableWidgetItem(query.value("speed_3").toString()));
//            ui->tableWidget->setItem( i,12, new QTableWidgetItem(query.value("current_4").toString()));
//            ui->tableWidget->setItem( i,13, new QTableWidgetItem(query.value("voltage_4").toString()));
//            ui->tableWidget->setItem( i,14, new QTableWidgetItem(query.value("speed_4").toString()));
//            ui->tableWidget->setItem( i,15, new QTableWidgetItem(query.value("test1").toString()));
//            ui->tableWidget->setItem( i,16, new QTableWidgetItem(query.value("test2").toString()));
//            ui->tableWidget->setItem( i,17, new QTableWidgetItem(query.value("test3").toString()));
//            ui->tableWidget->setItem( i,18, new QTableWidgetItem(query.value("test4").toString()));
//            ui->tableWidget->setItem( i,19, new QTableWidgetItem(query.value("test5").toString()));
//            i++;

//        }while(query.previous() && i < 10);

//}
        QString sqlstr = "select a.number, a.time,a.current_1,a.voltage_1,a.speed_1,a.current_2,a.voltage_2,a.speed_2,a.current_3,a.voltage_3,a.speed_3,a.current_4,a.voltage_4,a.speed_4,a.current_5,a.voltage_5,a.speed_5,a.current_6,a.voltage_6,a.speed_6,b.code,c.test1,c.test2,c.test3,c.test4,c.test5,c.test6 from project_plc a left join project_dm b on a.id = b.id left join project_3d c on a.id = c.id;";
        QSqlQuery query;
         qDebug()<<"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
        i = 0;
        if(query.exec(sqlstr)){
            //table_1
            query.last();
            do{
            ui->tableWidget_2->setItem( i,1, new QTableWidgetItem(query.value("code").toString()));



            if(i == 0){
                ui->tableWidget->setItem( 0,0, new QTableWidgetItem(query.value("current_1").toString()));
                ui->tableWidget->setItem( 0,1, new QTableWidgetItem(query.value("voltage_1").toString()));
                ui->tableWidget->setItem( 0,2, new QTableWidgetItem(query.value("speed_1").toString()));
                ui->tableWidget->setItem( 0,3, new QTableWidgetItem(query.value("test1").toString()));

                ui->tableWidget->setItem( 1,0, new QTableWidgetItem(query.value("current_2").toString()));
                ui->tableWidget->setItem( 1,1, new QTableWidgetItem(query.value("voltage_2").toString()));
                ui->tableWidget->setItem( 1,2, new QTableWidgetItem(query.value("speed_2").toString()));
                ui->tableWidget->setItem( 1,3, new QTableWidgetItem(query.value("test2").toString()));

                ui->tableWidget->setItem( 2,0, new QTableWidgetItem(query.value("current_3").toString()));
                ui->tableWidget->setItem( 2,1, new QTableWidgetItem(query.value("voltage_3").toString()));
                ui->tableWidget->setItem( 2,2, new QTableWidgetItem(query.value("speed_3").toString()));
                ui->tableWidget->setItem( 2,3, new QTableWidgetItem(query.value("test3").toString()));

                ui->tableWidget->setItem( 3,0, new QTableWidgetItem(query.value("current_4").toString()));
                ui->tableWidget->setItem( 3,1, new QTableWidgetItem(query.value("voltage_4").toString()));
                ui->tableWidget->setItem( 3,2, new QTableWidgetItem(query.value("speed_4").toString()));
                ui->tableWidget->setItem( 3,3, new QTableWidgetItem(query.value("test4").toString()));

                ui->tableWidget->setItem( 4,0, new QTableWidgetItem(query.value("current_5").toString()));
                ui->tableWidget->setItem( 4,1, new QTableWidgetItem(query.value("voltage_5").toString()));
                ui->tableWidget->setItem( 4,2, new QTableWidgetItem(query.value("speed_5").toString()));
                ui->tableWidget->setItem( 4,3, new QTableWidgetItem(query.value("test5").toString()));

                ui->tableWidget->setItem( 5,0, new QTableWidgetItem(query.value("current_6").toString()));
                ui->tableWidget->setItem( 5,1, new QTableWidgetItem(query.value("voltage_6").toString()));
                ui->tableWidget->setItem( 5,2, new QTableWidgetItem(query.value("speed_6").toString()));
                ui->tableWidget->setItem( 5,3, new QTableWidgetItem(query.value("test6").toString()));

                ui->erweima->setText(query.value("code").toString());
                ui->shijian->setText(query.value("time").toString());
                ui->gongweihao->setText(query.value("number").toString());


            }
            qDebug()<<query.value("code").toString()<<"wwwwwwwwwwwwwwwwwwwwwwwwwww";
            i++;

            }while(query.previous() && i < 10);


        }



}




void User::on_delete_2_clicked()
{

//    QMessageBox::question(this, "提示", QMessageBox::Yes | QMessageBox::Cancel);
    QMessageBox messageBox(QMessageBox::NoIcon,"警告","即将清除数据库",QMessageBox::Yes | QMessageBox::No ,NULL);
    int result = messageBox.exec();
    if(result == QMessageBox::Yes){
    QSqlQuery query ;
    if(query.exec("delete from project_plc;")&&query.exec("delete from project_dm;")&&query.exec("delete from project_3d;"))
    QMessageBox::information(this,"提示","数据库清除成功",QMessageBox::Ok);
    }

}

void User::excel(){
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setDatabaseName("mysql");

    QXlsx::Document xlsx1;
    QXlsx::Document xlsx2;


    QXlsx::Format format2;/*数据内容样式*/
    format2.setBorderStyle(QXlsx::Format::BorderThin);//外边框
    format2.setFontColor(QColor(Qt::blue));
    format2.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

    QXlsx::Format format3;
    format3.setBorderStyle(QXlsx::Format::BorderThin);

    xlsx1.setColumnWidth(1,22,20);
    xlsx1.write("A1","二维码序号",format2);
    xlsx1.write("B1", "工位号", format2);/*写入文字，应该刚才设置的样式*/
    xlsx1.write("C1", "日期/时间", format2);
    xlsx1.write("D1", "电流1(A)", format2);
    xlsx1.write("E1", "电压1(V)", format2);
    xlsx1.write("F1", "速度1(m/min)", format2);
    xlsx1.write("G1", "电流2(A)", format2);
    xlsx1.write("H1", "电压2(V)", format2);
    xlsx1.write("I1", "速度2(mm/min)", format2);
    xlsx1.write("J1", "电流3(A)", format2);
    xlsx1.write("K1", "电压3(V)", format2);
    xlsx1.write("L1", "速度3(mm/min)", format2);
    xlsx1.write("M1", "电流4(A)", format2);
    xlsx1.write("N1", "电压4(V)", format2);
    xlsx1.write("O1", "速度4(mm/min)", format2);

    xlsx1.write("P1", "电流5(A)", format2);
    xlsx1.write("Q1", "电压5(V)", format2);
    xlsx1.write("R1", "速度5(mm/min)", format2);

    xlsx1.write("S1", "电流6(A)", format2);
    xlsx1.write("T1", "电压6(V)", format2);
    xlsx1.write("U1", "速度6(mm/min)", format2);
    xlsx1.write("V1", "备注",format2);



    xlsx2.setColumnWidth(1,10,20);
    xlsx2.write("A1","二维码序号",format2);
    xlsx2.write("B1", "工位号", format2);/*写入文字，应该刚才设置的样式*/
    xlsx2.write("C1", "日期/时间", format2);
    xlsx2.write("D1", "焊缝测试1", format2);
    xlsx2.write("E1", "焊缝测试2", format2);
    xlsx2.write("F1", "焊缝测试3", format2);
    xlsx2.write("G1", "焊缝测试4", format2);
    xlsx2.write("H1", "焊缝测试5", format2);
    xlsx2.write("I1", "焊缝测试6", format2);
    xlsx2.write("J1", "备注", format2);


    QString sqlstr = "select a.number, a.time,a.current_1,a.voltage_1,a.speed_1,a.current_2,a.voltage_2,a.speed_2,a.current_3,a.voltage_3,a.speed_3,a.current_4,a.voltage_4,a.speed_4 ,a.current_5,a.voltage_5,a.speed_5 ,a.current_6,a.voltage_6,a.speed_6,b.code,c.test1,c.test2 ,c.test3,c.test4,c.test5,c.test6 from project_plc a left join project_dm b on a.id = b.id left join project_3d c on a.id = c.id;";
    QSqlQuery query;
    query.exec(sqlstr);
    int i = 2;
    while(query.next()){
        //xlsx1
        xlsx1.write(i , 1 , query.value("code").toString(),format3);
        xlsx1.write(i , 2 , query.value("number").toString(),format3);
        xlsx1.write(i , 3 , query.value("time").toString(),format3);
        xlsx1.write(i , 4 , query.value("current_1").toString(),format3);
        xlsx1.write(i , 5 , query.value("voltage_1").toString(),format3);
        xlsx1.write(i , 6 , query.value("speed_1").toString(),format3);
        xlsx1.write(i , 7 , query.value("current_2").toString(),format3);
        xlsx1.write(i , 8 , query.value("voltage_2").toString(),format3);
        xlsx1.write(i , 9 , query.value("speed_2").toString(),format3);
        xlsx1.write(i , 10 , query.value("current_3").toString(),format3);
        xlsx1.write(i , 11, query.value("voltage_3").toString(),format3);
        xlsx1.write(i , 12, query.value("speed_3").toString(),format3);
        xlsx1.write(i , 13, query.value("current_4").toString(),format3);
        xlsx1.write(i , 14, query.value("voltage_4").toString(),format3);
        xlsx1.write(i , 15, query.value("speed_4").toString(),format3);

        xlsx1.write(i , 16, query.value("current_5").toString(),format3);
        xlsx1.write(i , 17, query.value("voltage_5").toString(),format3);
        xlsx1.write(i , 18, query.value("speed_5").toString(),format3);

        xlsx1.write(i , 19, query.value("current_6").toString(),format3);
        xlsx1.write(i , 20, query.value("voltage_6").toString(),format3);
        xlsx1.write(i , 21, query.value("speed_6").toString(),format3);


        //xlsx2
        xlsx2.write(i , 1 , query.value("code").toString(),format3);
        xlsx2.write(i , 2 , query.value("number").toString(),format3);
        xlsx2.write(i , 3 , query.value("time").toString(),format3);
        xlsx2.write(i , 4 , query.value("test1").toString(),format3);
        xlsx2.write(i , 5 , query.value("test2").toString(),format3);
        xlsx2.write(i , 6 , query.value("test3").toString(),format3);
        xlsx2.write(i , 7 , query.value("test4").toString(),format3);
        xlsx2.write(i , 8 , query.value("test5").toString(),format3);
        xlsx2.write(i , 9 , query.value("test6").toString(),format3);


        i++;

    }
//    QString current_date = QDateTime::currentDateTime().toString(Qt::ISODate);

    QString Filename = QFileDialog::getSaveFileName(this,"选择保存路径");

        xlsx1.saveAs(Filename +"1.xlsx");
        xlsx2.saveAs( Filename+"2.xlsx");
        if(!Filename.isEmpty())
        QMessageBox::about(NULL,"提示","导出成功");

}
// void User::timerEvent(QTimerEvent *){
//     showtable();


// }




void User::on_baocun_clicked()
{
      excel();
}

void User::on_ip_clicked()
{
    p->show();
    p->setWindowTitle("设备连接");


}

void User::on_read_clicked()
{

    f->show();
    f->setWindowTitle("信息读取");

}

void User::resizeEvent(QResizeEvent *event)
{

//    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->resizeColumnsToContents();
//    ui->tableWidget->horizontalHeader();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);




}

void User::on_tableWidget_2_itemClicked(QTableWidgetItem *item)
{
//    QString code = item->text();
//    QString sqlstr = "select a.number, a.time,a.current_1,a.voltage_1,a.speed_1,a.current_2,a.voltage_2,a.speed_2,a.current_3,a.voltage_3,a.speed_3,a.current_4,a.voltage_4,a.speed_4 ,a.current_5,a.voltage_5,a.speed_5 ,a.current_6,a.voltage_6,a.speed_6,b.code,c.test1,c.test2 ,c.test3,c.test4,c.test5,c.test6 from project_plc a left join project_dm b on a.id = b.id left join project_3d c on a.id = c.id;";
    QSqlQuery query;
    query.prepare("select *from (select a.number, a.time,a.current_1,a.voltage_1,a.speed_1,a.current_2,a.voltage_2,a.speed_2,a.current_3,a.voltage_3,a.speed_3,a.current_4,a.voltage_4,a.speed_4 ,a.current_5,a.voltage_5,a.speed_5,a.current_6,a.voltage_6,a.speed_6,b.code,c.test1,c.test2,c.test3,c.test4,c.test5,c.test6 from project_plc a left join project_dm b on a.id = b.id left join project_3d c on a.id = c.id) t where code = :value;");

    query.bindValue(":value",item->text());
    query.exec();
    query.first();
    ui->tableWidget->setItem( 0,0, new QTableWidgetItem(query.value("current_1").toString()));
    ui->tableWidget->setItem( 0,1, new QTableWidgetItem(query.value("voltage_1").toString()));
    ui->tableWidget->setItem( 0,2, new QTableWidgetItem(query.value("speed_1").toString()));
    ui->tableWidget->setItem( 0,3, new QTableWidgetItem(query.value("test1").toString()));

    ui->tableWidget->setItem( 1,0, new QTableWidgetItem(query.value("current_2").toString()));
    ui->tableWidget->setItem( 1,1, new QTableWidgetItem(query.value("voltage_2").toString()));
    ui->tableWidget->setItem( 1,2, new QTableWidgetItem(query.value("speed_2").toString()));
    ui->tableWidget->setItem( 1,3, new QTableWidgetItem(query.value("test2").toString()));

    ui->tableWidget->setItem( 2,0, new QTableWidgetItem(query.value("current_3").toString()));
    ui->tableWidget->setItem( 2,1, new QTableWidgetItem(query.value("voltage_3").toString()));
    ui->tableWidget->setItem( 2,2, new QTableWidgetItem(query.value("speed_3").toString()));
    ui->tableWidget->setItem( 2,3, new QTableWidgetItem(query.value("test3").toString()));

    ui->tableWidget->setItem( 3,0, new QTableWidgetItem(query.value("current_4").toString()));
    ui->tableWidget->setItem( 3,1, new QTableWidgetItem(query.value("voltage_4").toString()));
    ui->tableWidget->setItem( 3,2, new QTableWidgetItem(query.value("speed_4").toString()));
    ui->tableWidget->setItem( 3,3, new QTableWidgetItem(query.value("test4").toString()));

    ui->tableWidget->setItem( 4,0, new QTableWidgetItem(query.value("current_5").toString()));
    ui->tableWidget->setItem( 4,1, new QTableWidgetItem(query.value("voltage_5").toString()));
    ui->tableWidget->setItem( 4,2, new QTableWidgetItem(query.value("speed_5").toString()));
    ui->tableWidget->setItem( 4,3, new QTableWidgetItem(query.value("test5").toString()));

    ui->tableWidget->setItem( 5,0, new QTableWidgetItem(query.value("current_6").toString()));
    ui->tableWidget->setItem( 5,1, new QTableWidgetItem(query.value("voltage_6").toString()));
    ui->tableWidget->setItem( 5,2, new QTableWidgetItem(query.value("speed_6").toString()));
    ui->tableWidget->setItem( 5,3, new QTableWidgetItem(query.value("test6").toString()));

    ui->erweima->setText(query.value("code").toString());
    ui->shijian->setText(query.value("time").toString());
    ui->gongweihao->setText(query.value("number").toString());


}
