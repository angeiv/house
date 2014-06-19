#ifndef WANTEDSATI_H
#define WANTEDSATI_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
#include "customer.h"
bool WantedNumber(int *count1)
{
    //check connection exist or not
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
        ;//qDebug()<<"database is established.";
    }
    else {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query; //定义一个QSqlQuery 类型的变量

    query.exec("select * from wanted");
    *count1=query.size();

    //close connection
    query.clear();//清空查询语句，并释放内存空间
    db.commit();
    db.close();   //关闭数据库连接
    //qDebug()<<"connection closed.";
    return true;
}

bool WantedInfo(wantedInfo *t)
{
    //check connection exist or not
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
        ;//qDebug()<<"database is established!";
    }
    else {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query;

    query.exec("select * from wanted");

    int num=0;
    while (query.next()) {
        t[num].customerId=query.value(0).toInt();
                t[num].customerName=query.value(1).toString();
                t[num].phoneNumber=query.value(2).toInt();
                t[num].roomType=query.value(3).toString();
                t[num].area=query.value(4).toInt();
                t[num].circumstance=query.value(5).toString();
               // wt[num].area=query.value(6).toInt();
              //  wt[num].circumstance=query.value(7).toString();
                t[num].price=query.value(8).toInt();
                t[num].roomId=query.value(8).toInt();
                t[num].sj=query.value(8).toInt();
                t[num].remark=query.value(9).toString();

                num++;
    }
    return true;
}
#endif // WANTEDSATI_H
