#include "ip.h"
#include "ui_ip.h"

Ip::Ip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ip)
{
    ui->setupUi(this);
//    tcpServer = new QTcpServer(this);
    d = new Database();
//    QList<QTcpSocket*> tcpClient ;
//    currentClient = new QTcpSocket();
//    QObject::connect(tcpServer,SIGNAL(newConnection()),this,SLOT(NewConnectionSlot()));
    socket = new QTcpSocket(this);
     connect(socket,&QTcpSocket::readyRead,this,&Ip::ReadData);

//     ui->ip->setText("192.168.3.39");

     ui->ip->setText("192.168.0.2");

     ui->port->setText("8080");
//     ui->port->setText("4990");
     on_pushButton_clicked();
     startTimer(100000);



}



//void Ip::DB_ip3(QString str)
//{
//    qDebug()<<"3d_"<<str;
//    if(str=="TRUE")
//    d->DB_insert_3d("OK");
//    else if(str=="FALSE")
//    d->DB_insert_3d("NG");
//}



Ip::~Ip()
{
    delete ui;
}

void Ip::ReadData()
{
    QByteArray arr = socket->readAll();
//    qDebug()<<arr;
    QString str = arr.toHex();
//    qDebug()<<str;
//    QString p= "1"+str[0]+"."+str[1];
//    qDebug()<<p;
    qDebug()<<"十六进制"<<str;

//    QString p = str[1]+str[3]+str[5]+str[7]+str[9]+str[11]+str[13]+str[15]+str[17]+str[19]+str[21];
     d->DB_insert_dm(str.mid(1,1)+str.mid(3,1)+str.mid(5,1)+str.mid(7,1)+str.mid(9,1)+str.mid(11,1)+str.mid(13,1)+str.mid(15,1)+str.mid(17,1)+str.mid(19,1)+str.mid(21,1)+str.mid(23,1));
//    d->DB_insert_dm(str.mid(1,1)+str.mid(3,1)+str.mid(5,1)+str.mid(7,1)+str.mid(9,1)+str.mid(11,1)+str.mid(13,1)+str.mid(15,1)+str.mid(17,1)+str.mid(19,1)+str.mid(21,1));
//    d->DB_insert_plc(str[41],    str[51]+str[48]+str[49],     str[55]+str[52]+"."+str[53],                 str[54]+str[55],     str[64]+str[61]+str[62],   str[67]+str[64]+"."+str[65],           str[68]+str[69],                str[75]+str[72]+str[73],str[79]+str[76]+"."+str[77],                         str[80]+str[81],          str[87]+str[84]+str[85],str[91]+str[88]+"."+str[89],str[92]+str[93]);


     d->DB_insert_plc(str.mid(41,1).toInt(),str.mid(51,1)+str.mid(48,2),str.mid(55,1)+str.mid(52,1)+"."+str.mid(53,1),str.mid(56,2),str.mid(63,1)+str.mid(60,2),str.mid(67,1)+str.mid(64,1)+"."+str.mid(65,1),str.mid(68,2),str.mid(75,1)+str.mid(72,2), str.mid(79,1)+str.mid(76,1)+"."+str.mid(77,1),str.mid(80,2),str.mid(87,1)+str.mid(84,2),str.mid(91,1)+str.mid(88,1)+"."+str.mid(89,1),str.mid(92,2),"1","1","1","1","1","1");


     //    if(str[97] == '1'){ d->DB_insert_3d("OK");}
//    if(str[97] == '2'){ d->DB_insert_3d("NG");}
    QString test1,test2,test3,test4,test5, test6;
    if(str[97] =='1') test1 = "OK";
    if(str[97] =='2') test1 = "NG";
    if(str[101] =='1') test2 = "OK";
    if(str[101] =='2') test2 = "NG";
    if(str[105] =='1') test3 = "OK";
    if(str[105] =='2') test3 = "NG";
    if(str[109] =='1') test4 = "OK";
    if(str[109] =='2') test4 = "NG";
    if(str[113] =='1') test5 = "OK";
    if(str[113] =='2') test5 = "NG";
    if(str[117] =='1') test6 = "OK";
    if(str[117] =='2') test6 = "NG";
    d->DB_insert_3d(test1,test2,test3,test4,test5,test6);
    sleep(1);
    emit fashe();

}

//void Ip::on_pushButton_2_clicked()
//{
//    int port = ui->leport->text().toInt();
//    if(tcpServer->listen(QHostAddress::Any,port))
//        QMessageBox::about(NULL,"提示","开启成功");
//}

//void Ip::NewConnectionSlot()
//{
//    currentClient = tcpServer->nextPendingConnection();
//    tcpClient.append(currentClient);
//    QObject::connect(currentClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
//    QString pt;
//    pt = currentClient->peerAddress().toString().split("::ffff:")[1];
//    qDebug()<<pt<<"连接";
//    if(pt == ui->ip1->text()&&!ip_1){
//        ip_1 = true;
//        QMessageBox::about(NULL,"提示","终端设备1完成连接");

//    }
//    if(pt == ui->ip2->text()&&!ip_2){
//        ip_2 = true;
//        QMessageBox::about(NULL,"提示","终端设备2完成连接");

//    }
//    if(pt == ui->ip3->text()&&!ip_3){
//        ip_3 = true;
//        QMessageBox::about(NULL,"提示","终端设备3完成连接");

//    }
//    qDebug()<<currentClient->peerAddress().toString().split("::ffff:")[1];

//    qDebug()<<"连接完成";


//}

//void Ip::ReadData()
//{

//    for(int i = 0;i < tcpClient.length(); i++){
//        QByteArray buffer = tcpClient[i]->readAll();
//        QString str = buffer.data();
//        str = str.split("\r\n")[0];


//        if(buffer.isEmpty())  continue;
//        qDebug()<<"收到消息"<<str;
//        static QString IP_Port;

//        IP_Port = currentClient->peerAddress().toString().split("::ffff:")[1];
//        qDebug()<<IP_Port;
//        if(IP_Port == ui->ip1->text()){
//            qDebug()<<"ip1"<<str;
//            DB_ip1(str);
//        }else if(IP_Port == ui->ip2->text()){
//            qDebug()<<"ip2"<<str;
//            DB_ip2(str);
//        }else if(IP_Port == ui->ip3->text()){
//            qDebug()<<"ip3"<<str;
//            DB_ip3(str);
//        }

//    }
//}

//void Ip::on_pushButton_clicked()
//{

//    this->hide();

//}

void Ip::on_pushButton_clicked()
{

    socket->connectToHost(ui->ip->text(),ui->port->text().toInt());
    if(socket->waitForConnected(10000)){
        QMessageBox::about(NULL,"提示","连接成功");

    }
    else
        QMessageBox::about(NULL,"提示","连接超时");
    this->hide();

}

void Ip::on_pushButton_2_clicked()
{
    socket->abort();
    QMessageBox::about(NULL,"提示","断开成功");
}
void Ip::timerEvent(QTimerEvent *)
{
    socket->connectToHost(ui->ip->text(),ui->port->text().toInt());
}
