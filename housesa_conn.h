#ifndef HOUSESA_CONN_H
#define HOUSESA_CONN_H

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include "houseInfo.h"

bool HouseNumber(int *count)
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

    query.exec("select * from roomInfo");
    *count=query.size();

    //close connection
    query.clear();//清空查询语句，并释放内存空间
    db.commit();
    db.close();   //关闭数据库连接
    //qDebug()<<"connection closed.";
    return true;
}

bool queryHouseInfo(houseInfo *ho)
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

    query.exec("select * from roomInfo");

    int num=0;
    while (query.next()) {
        ho[num].roomId=query.value(0).toInt();
        ho[num].renterId=query.value(1).toInt();
        ho[num].lessee=query.value(2).toInt();
        ho[num].roomType=query.value(3).toString();
        ho[num].location=query.value(4).toString();
        ho[num].realNum=query.value(5).toInt();
        ho[num].area=query.value(6).toInt();
        ho[num].circumstance=query.value(7).toString();
        ho[num].price=query.value(8).toInt();
        ho[num].remark=query.value(9).toString();

        num++;
    }

    return true;
}
#endif // HOUSESA_CONN_H
