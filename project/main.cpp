#include "user.h"
#include <QApplication>
#include "login.h"

#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QApplication::addLibraryPath("./plugins");
    Login l;
    User w;

    w.setWindowTitle("                                                                                         用户管理");

//    w.showtable();
//    D.showtable();


//    D.DB_insert(3,2,"asdf","afda","afs","asfd","afdsf");
//    D.DB_update("number","3","13");

//    connect(w.,&QPushButton::clicked  , D ,&Database::deleteall  );
//    D.DB_select(2);

    w.show();

    return a.exec();
}
