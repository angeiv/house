#include "updatarepay.h"
#include "ui_updatarepay.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
#include <QtCore/QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
updatarepay::updatarepay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updatarepay)
{
    ui->setupUi(this);
}

updatarepay::~updatarepay()
{
    delete ui;
}

void updatarepay::on_pushButton_clicked()
{
   //

    QSqlQuery query;
    QString item;
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if (db.open()) {//打开数据库连接
        qDebug()<<"database is established.";
    }
    else {
        qDebug()<<"build error!";

    }
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty())
    {

         QMessageBox::about(NULL,"提示","不能为空！");
    }
    else{
      item="updata repay set moneyEver=moneyEver+";
      item+=ui->lineEdit_2->text();
      item+=" ,moneyOwn=moneyShould-";
      item+=ui->lineEdit_2->text();
      item+=" where roomId=";
      item+=ui->lineEdit->text();
        qDebug()<<item;
      if(query.exec(item))
      {
           QMessageBox::about(NULL,"提示","预定成功！");
      }

    }
  item=" ";
}
