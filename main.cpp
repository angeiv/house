#include "mainwindow.h"
#include "login.h"
#include "housedata.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login l;
    l.show();

    return a.exec();
}
