#ifndef FIND_H
#define FIND_H
#include <QKeyEvent>
#include <QWidget>
#include "database.h"
#include <QtSql/QSqlQuery>
#include<QtSql/QSqlDatabase>
namespace Ui {
class Find;
}

class Find : public QWidget
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = 0);
    ~Find();

private slots:
    void on_find_clicked();

    void on_delete_2_clicked();

    void on_preservation_clicked();
protected:
    void resizeEvent(QResizeEvent *event);
private:
    Ui::Find *ui;
    void keyPressEvent(QKeyEvent *e);

};

#endif // FIND_H
