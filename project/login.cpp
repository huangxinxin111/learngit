#include "login.h"
#include "ui_login.h"
bool temp::optEnable = false;
bool temp::zt = false;
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->comboBox->addItem("worker");
    ui->comboBox->addItem("manager");
//    ui->comboBox->setSizeIncrement(5000,20);


}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    if(ui->comboBox->currentText() == "worker" && ui->lineEdit->text() == "123456"){


        temp::zt = true;
        this->hide();
        emit showmain();
    }else if(ui->comboBox->currentText() == "manager" && ui->lineEdit->text() == "666666"){
        temp::optEnable = true;
        temp::zt = true;
        this->hide();
        emit showmain();
    }else{
        QMessageBox::critical(this,"错误" ,"密码错误");



    }


}
