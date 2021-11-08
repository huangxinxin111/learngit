#ifndef IP_H
#define IP_H
#include <QObject>
#include <QByteArray>
#include <QWidget>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include "database.h"
#include <QString>
#include <unistd.h>

namespace Ui {
class Ip;
}

class Ip : public QWidget
{
    Q_OBJECT

public:
    explicit Ip(QWidget *parent = 0);

//    void DB_ip3(QString str);

    ~Ip();
signals:
    void fashe();

private slots:
//    void on_pushButton_2_clicked();
//    void NewConnectionSlot();
    void ReadData();
//    void on_pushButton_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
     void timerEvent(QTimerEvent *);

private:
    Ui::Ip *ui;
//    QTcpServer *tcpServer;
//    QList<QTcpSocket*> tcpClient;
    QTcpSocket *socket;
    Database *d;


};
static bool ip_1 = false;
static bool ip_2 = false;
static bool ip_3 = false;

#endif // IP_H
