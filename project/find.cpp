#include "find.h"
#include "ui_find.h"

Find::Find(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);
    ui->lineEdit->setClearButtonEnabled(true);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setItem( 0,0,new QTableWidgetItem("二维码序号") );
    ui->tableWidget->setItem( 0,1,new QTableWidgetItem("工位号") );
    ui->tableWidget->setItem( 0,2,new QTableWidgetItem("焊缝检测1") );
    ui->tableWidget->setItem( 0,3,new QTableWidgetItem("电流1(A)") );
    ui->tableWidget->setItem( 0,4,new QTableWidgetItem("电压1(V)") );
    ui->tableWidget->setItem( 2,0,new QTableWidgetItem("速度1(mm/min)") );
    ui->tableWidget->setItem( 2,1,new QTableWidgetItem("电流2(A)") );
    ui->tableWidget->setItem( 2,2,new QTableWidgetItem("电压2(V)") );
    ui->tableWidget->setItem( 2,3,new QTableWidgetItem("速度2(mm/min)") );
    ui->tableWidget->setItem( 2,4,new QTableWidgetItem("电流3(A)") );
    ui->tableWidget->setItem( 4,0,new QTableWidgetItem("电压3(V)") );
    ui->tableWidget->setItem( 4,1,new QTableWidgetItem("速度3(mm/min)") );
    ui->tableWidget->setItem( 4,2,new QTableWidgetItem("电流4(A)") );
    ui->tableWidget->setItem( 4,3,new QTableWidgetItem("电压4(V)") );
    ui->tableWidget->setItem( 4,4,new QTableWidgetItem("速度4(mm/min)") );
    ui->tableWidget->setItem( 6,0,new QTableWidgetItem("焊缝检测2") );
    ui->tableWidget->setItem( 6,1,new QTableWidgetItem("焊缝检测3") );
    ui->tableWidget->setItem( 6,2,new QTableWidgetItem("焊缝检测4") );
    ui->tableWidget->setItem( 6,3,new QTableWidgetItem("焊缝检测5") );
    ui->tableWidget->setItem( 6,4,new QTableWidgetItem("焊缝检测6") );

    ui->tableWidget->setItem( 8,0,new QTableWidgetItem("电流5(A)") );
    ui->tableWidget->setItem( 8,1,new QTableWidgetItem("电压5(V)") );
    ui->tableWidget->setItem( 8,2,new QTableWidgetItem("速度5(mm/min)") );
    ui->tableWidget->setItem( 8,3,new QTableWidgetItem("电流6(A)") );
    ui->tableWidget->setItem( 8,4,new QTableWidgetItem("电压6(V)") );
    ui->tableWidget->setItem( 10,0,new QTableWidgetItem("速度6(mm/min)") );




}
void Find::keyPressEvent(QKeyEvent *e){
    if(e->key()== Qt::Key_Enter || e->key() == Qt::Key_Return){
    ui->find->clicked();
    }
//    qDebug()<<e->key();



}
Find::~Find()
{
    delete ui;
}

void Find::on_find_clicked()
{
    if(ui->lineEdit->text() == NULL) QMessageBox::about(NULL,"提示","文本为空");
    else{
    QSqlQuery query;
    query.prepare("select *from (select a.number, a.time,a.current_1,a.voltage_1,a.speed_1,a.current_2,a.voltage_2,a.speed_2,a.current_3,a.voltage_3,a.speed_3,a.current_4,a.voltage_4,a.speed_4 ,a.current_5,a.voltage_5,a.speed_5,a.current_6,a.voltage_6,a.speed_6,b.code,c.test1,c.test2,c.test3,c.test4,c.test5,c.test6 from project_plc a left join project_dm b on a.id = b.id left join project_3d c on a.id = c.id) t where code = :value;");

    query.bindValue(":value",ui->lineEdit->text());
    query.exec();
    query.first();
//    ui->tableWidget->setItem(2,3,"二维码序号");
    ui->tableWidget->setItem( 1,0,new QTableWidgetItem(query.value("code").toString()) );
    ui->tableWidget->setItem( 1,1,new QTableWidgetItem(query.value("number").toString()) );
    ui->tableWidget->setItem( 1,2,new QTableWidgetItem(query.value("test1").toString()) );
    ui->tableWidget->setItem( 1,3,new QTableWidgetItem(query.value("current_1").toString()) );
    ui->tableWidget->setItem( 1,4,new QTableWidgetItem(query.value("voltage_1").toString()) );
    ui->tableWidget->setItem( 3,0,new QTableWidgetItem(query.value("speed_1").toString()) );
    ui->tableWidget->setItem( 3,1,new QTableWidgetItem(query.value("current_2").toString()) );
    ui->tableWidget->setItem( 3,2,new QTableWidgetItem(query.value("voltage_2").toString()) );
    ui->tableWidget->setItem( 3,3,new QTableWidgetItem(query.value("speed_2").toString() ));
    ui->tableWidget->setItem( 3,4,new QTableWidgetItem(query.value("current_3").toString()) );
    ui->tableWidget->setItem( 5,0,new QTableWidgetItem(query.value("voltage_3").toString()) );
    ui->tableWidget->setItem( 5,1,new QTableWidgetItem(query.value("speed_3").toString() ) );
    ui->tableWidget->setItem( 5,2,new QTableWidgetItem(query.value("current_4").toString()) );
    ui->tableWidget->setItem( 5,3,new QTableWidgetItem(query.value("voltage_4").toString()) );
    ui->tableWidget->setItem( 5,4,new QTableWidgetItem(query.value("speed_4").toString() ) );

    ui->tableWidget->setItem( 7,0,new QTableWidgetItem(query.value("test2").toString()) );
    ui->tableWidget->setItem( 7,1,new QTableWidgetItem(query.value("test3").toString() ) );
    ui->tableWidget->setItem( 7,2,new QTableWidgetItem(query.value("test4").toString()) );
    ui->tableWidget->setItem( 7,3,new QTableWidgetItem(query.value("test5").toString()) );
    ui->tableWidget->setItem( 7,4,new QTableWidgetItem(query.value("test6").toString()) );

    ui->tableWidget->setItem( 9,0,new QTableWidgetItem(query.value("current_5").toString()) );
    ui->tableWidget->setItem( 9,1,new QTableWidgetItem(query.value("voltage_5").toString()) );
    ui->tableWidget->setItem( 9,2,new QTableWidgetItem(query.value("speed_5").toString()) );
    ui->tableWidget->setItem( 9,3,new QTableWidgetItem(query.value("current_6").toString()) );
    ui->tableWidget->setItem( 9,4,new QTableWidgetItem(query.value("voltage_6").toString()) );
    ui->tableWidget->setItem( 11,0,new QTableWidgetItem(query.value("speed_6").toString() ));

    qDebug()<<query.value("code").toString()<<"wwwwwwwwwwwwwwwwwwwwwwwwwww";



    }


}

void Find::on_delete_2_clicked()
{
    if(ui->lineEdit->text() == NULL) QMessageBox::about(NULL,"提示","文本为空");
    else{
    QSqlQuery query;

    query.prepare("select * from project_dm where code = :code;");
    query.bindValue(":code",ui->lineEdit->text());
    query.exec();
    query.first();
    int id = query.value("id").toInt();
//    query.prepare("delete from project_dm a left join project_plc b on a.id = b.id left join project_3d c on a.id = c.id where a.id = :id;");
    query.prepare("delete from project_plc where id = :ip");
    query.bindValue(":ip",id);
    query.exec();
    query.prepare("delete from project_dm where id = :id");
    query.bindValue(":id",id);
    query.exec();
    query.prepare("delete  from project_3d where id = :iq");
    query.bindValue(":iq",id);

    QMessageBox::about(NULL,"提示","删除成功");
    }



}


void Find::on_preservation_clicked()
{

    if(ui->lineEdit->text() == NULL) QMessageBox::about(NULL,"提示","文本为空");
    else{
    QSqlQuery query;
    bool a, b,c;

    query.prepare("select * from project_dm where code = :code;");
    query.bindValue(":code",ui->lineEdit->text());
    query.exec();
    query.first();
    int id = query.value("id").toInt();
    query.prepare("update project_plc set number = :number , current_1 = :current_1 ,voltage_1 = :voltage_1,speed_1 = :speed_1,current_2 = :current_2 ,voltage_2 = :voltage_2, speed_2 = :speed_2 ,current_3 = :current_3 ,voltage_3 = :voltage_3, speed_3 = :speed_3 ,current_4 = :current_4 ,voltage_4 = :voltage_4, speed_4 = :speed_4 ,current_5 = :current_5 ,voltage_5 = :voltage_5, speed_5 = :speed_5 ,current_6 = :current_6 ,voltage_6 = :voltage_6, speed_6 = :speed_6  where id = :id;");
    query.bindValue(":id" ,id);
    query.bindValue(":number",ui->tableWidget->item(1,1)->text().toInt());
    query.bindValue(":current_1",ui->tableWidget->item(1,3)->text());
    query.bindValue(":voltage_1",ui->tableWidget->item(1,4)->text());
    query.bindValue(":speed_1",ui->tableWidget->item(3,0)->text());
    query.bindValue(":current_2",ui->tableWidget->item(3,1)->text());
    query.bindValue(":voltage_2",ui->tableWidget->item(3,2)->text());
    query.bindValue(":speed_2",ui->tableWidget->item(3,3)->text());
    query.bindValue(":current_3",ui->tableWidget->item(3,4)->text());
    query.bindValue(":voltage_3",ui->tableWidget->item(5,0)->text());
    query.bindValue(":speed_3",ui->tableWidget->item(5,1)->text());
    query.bindValue(":current_4",ui->tableWidget->item(5,2)->text());
    query.bindValue(":voltage_4",ui->tableWidget->item(5,3)->text());
    query.bindValue(":speed_4",ui->tableWidget->item(5,4)->text());

    query.bindValue(":current_5",ui->tableWidget->item(9,0)->text());
    query.bindValue(":voltage_5",ui->tableWidget->item(9,1)->text());
    query.bindValue(":speed_5",ui->tableWidget->item(9,2)->text());
    query.bindValue(":current_6",ui->tableWidget->item(9,3)->text());
    query.bindValue(":voltage_6",ui->tableWidget->item(9,4)->text());
    query.bindValue(":speed_6",ui->tableWidget->item(11,0)->text());
    a = query.exec();


    query.prepare("update  project_3d set test1 = :test1,test2 = :test2,test3 = :test3,test4 = :test4,test5 = :test5,test6 = :test6 where id = :ip;");
    query.bindValue(":ip",id);
    query.bindValue(":test1",ui->tableWidget->item(1,2)->text());
    query.bindValue(":test2",ui->tableWidget->item(7,0)->text());
    query.bindValue(":test3",ui->tableWidget->item(7,1)->text());
    query.bindValue(":test4",ui->tableWidget->item(7,2)->text());
    query.bindValue(":test5",ui->tableWidget->item(7,3)->text());

    query.bindValue(":test6",ui->tableWidget->item(7,4)->text());
    b = query.exec();
    if(a && b)
//    query.prepare("update  project_dm set code = :code where id = :id;");

//    query.bindValue(":id",id);
//    query.bindValue(":code",ui->lineEdit->text().toInt());
//    query.exec();
        QMessageBox::about(NULL,"提示","保存成功");
    else
        QMessageBox::about(NULL,"提示","保存失败");




    }






}

void Find::resizeEvent(QResizeEvent *event)
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}
