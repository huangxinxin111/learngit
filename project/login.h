#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();
signals:
    void showmain();

private:
    Ui::Login *ui;
};
class temp{
public:
    static bool optEnable;
    static bool zt;
};

#endif // LOGIN_H
