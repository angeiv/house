/********************************************************************************
* File Name:	connectdatabase.h
* Description:	第4章实例训练
* Reference book:《Linux环境下Qt4图形界面与MySQL编程》，机械工业出版社.2012.1
* E_mail: openlinux2011@gmail.com
*
********************************************************************************/
#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
#include "lesseeInfo.h"


bool queryLesseeNumber(int *count)
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

    query.exec("select * from lesseeInfo");
    *count=query.size();

    //close connection
    query.clear();//清空查询语句，并释放内存空间
    db.commit();
    db.close();   //关闭数据库连接
    //qDebug()<<"connection closed.";
    return true;
}


bool queryLesseeInfo(lesseeInfo *li)
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

    query.exec("select * from lesseeInfo");

    int num=0;
    while (query.next()) {
        li[num].zuhuId=query.value(0).toInt();
        li[num].zuhuname=query.value(3).toString();
        li[num].worklocation=query.value(2).toString();
        li[num].telephone=query.value(7).toInt();
        li[num].Idcard=query.value(6).toInt();
        li[num].toll=query.value(14).toString();
        li[num].remark=query.value(15).toString();
        num++;
    }
    return true;
}

bool insertLesseeInfo(lesseeInfo li,int *maxIndex)
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
    //设置将要执行的SQL语句，并设定被绑定的数据的位置
    query.prepare("insert into lesseeInfo "
                  "(zuhuId,zuhuname,xingbie,worklocation,telephone,"
                  "Idcard,toll,remark) "
                  "values(:zuhuId,:zuhuname,:worklocation,:telephone,"
                  ":Idcard,:toll,:remark)");

    //将数据绑定到指定的位置
    query.bindValue(":zuhuId", li.zuhuId);
    query.bindValue(":zuhuname", li.zuhuname);
    query.bindValue(":worklocation", li.worklocation);
    query.bindValue(":telephone", li.telephone);
    query.bindValue(":Idcard", li.Idcard);
    query.bindValue(":toll", li.toll);
    query.bindValue(":remark", li.remark);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec()) {
        *maxIndex = *maxIndex + 1;
        return true;
    }
    else{
        return false;
    }
}

bool updateLesseeInfo(lesseeInfo li)
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
    //设置将要执行的SQL语句，并设定被绑定的数据的位置
    query.prepare("update `lesseeInfo` set "
                  "`zuhuId`=:zuhuId,"
                  "`zuhuname`=:zuhuname,"
                  "`xingbie`=:xiangbie,"
                  "`worklocation`=:worklocation,"
                  "`telephone`=:telephone,"
                  "`Idcard`=:Idcard,"
                  "`toll`=:toll,"
                  "`remark`=:remark "
                  "where `zuhuId`=:zuhuId") ;

    //将数据绑定到指定的位置
    query.bindValue(":zuhuId", li.zuhuId);
    query.bindValue(":zuhuname", li.zuhuname);
    query.bindValue(":xingbie", li.xingbie);
    query.bindValue(":worklocation", li.worklocation);
    query.bindValue(":telephone", li.telephone);
    query.bindValue(":Idcard", li.Idcard);
    query.bindValue(":toll", li.toll);
    query.bindValue(":remark", li.remark);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}

bool deleteLesseeInfo(lesseeInfo li)
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
    //设置将要执行的SQL语句，并设定被绑定的数据的位置
    query.prepare("delete from `lesseeInfo` "
                  "where `zuhuId`=:lesseeId") ;

    //将数据绑定到指定的位置
    query.bindValue(":zuhuId", li.zuhuId);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}
bool searchLesseeInfo(int zuhuId)
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

    query.prepare("select * from `lesseeInfo` where `zuhuId`=:zuhuId") ;

    //将数据绑定到指定的位置
    query.bindValue(":zuhuId", zuhuId);
    query.exec();
    //qDebug()<<zuhuId;
    if (!query.isActive()) {
        return false;
    }
    else {
        while (query.next()) {
            li[num].zuhuId=query.value(0).toInt();
            li[num].zuhuname=query.value(3).toString();
            li[num].worklocation=query.value(2).toString();
            li[num].telephone=query.value(7).toInt();
            li[num].Idcard=query.value(6).toInt();
            li[num].toll=query.value(14).toString();
            li[num].remark=query.value(15).toString();
            //qDebug()<<temp.zuhuId;
            return true;
        }
        return true;
    }
}
#endif
