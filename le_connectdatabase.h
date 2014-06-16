/********************************************************************************
* File Name:	connectdatabase.h
* Description:	第4章实例训练
* Reference book:《Linux环境下Qt4图形界面与MySQL编程》，机械工业出版社.2012.1
* E_mail: openlinux2011@gmail.com
*
********************************************************************************/
#ifndef LE_CONNECTDATABASE_H
#define LE_CONNECTDATABASE_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
#include "le_customer.h"


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

    query.exec("select * from lessee");
    *count=query.size();

    //close connection
    query.clear();//清空查询语句，并释放内存空间
    db.commit();
    db.close();   //关闭数据库连接
    //qDebug()<<"connection closed.";
    return true;
}


bool queryLesseeInfo(customer *li)
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

    query.exec("select * from lessee");

    int num=0;
    while (query.next()) {
        li[num].customerId=query.value(0).toInt();
        li[num].customerName=query.value(1).toString();
        li[num].nativePlace=query.value(2).toString();
        li[num].phoneNumber=query.value(3).toString();
        li[num].sex=query.value(4).toString();
        li[num].idCard=query.value(5).toString();
        li[num].number=query.value(6).toInt();
        li[num].remark=query.value(7).toString();
        num++;
    }
    return true;
}

bool insertLesseeInfo(customer li,int *maxIndex_le)
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
    query.prepare("insert into lessee "
                  "(customerId,customerName,sex,nativePlace,phoneNumber,"
                  "idCard,number,remark) "
                  "values(:customerId,:customerName,:sex,:nativePlace,:phoneNumber,"
                  ":Idcard,:number,:remark)");

    //将数据绑定到指定的位置
    query.bindValue(":customerId", li.customerId);
    query.bindValue(":customerName", li.customerName);
    query.bindValue(":sex",li.sex);
    query.bindValue(":idCard", li.idCard);
    query.bindValue(":nativePlace", li.nativePlace);
    query.bindValue(":number", li.number);
    query.bindValue(":phoneNumber", li.phoneNumber);
    query.bindValue(":remark", li.remark);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec()) {
        *maxIndex_le = *maxIndex_le + 1;
        return true;
    }
    else{
        return false;
    }
}

bool updateLesseeInfo(customer li)
{
    //check connection exist or not
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        //D:\Qt\MyQt\house\le_connectdatabase.h:152: error: multiple definition of `temp'

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
    query.prepare("update `lessee` set "
                  "`customerId`=:customerId,"
                  "`customerName`=:customerName,"
                  "`sex`=:sex,"
                  "`nativePlace`=:nativePlace,"
                  "`phoneNumber`=:phoneNumber,"
                  "`idCard`=:idCard,"
                  "`number`=:number,"
                  "`remark`=:remark "
                  "where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":customerId", li.customerId);
    query.bindValue(":customerName", li.customerName);
    query.bindValue(":sex",li.sex);
    query.bindValue(":idCard", li.idCard);
    query.bindValue(":nativePlace", li.nativePlace);
    query.bindValue(":number", li.number);
    query.bindValue(":phoneNumber", li.phoneNumber);
    query.bindValue(":remark", li.remark);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}

bool deleteLesseeInfo(customer li)
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
    query.prepare("delete from `lessee` "
                  "where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":customerId", li.customerId);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}

bool searchLesseeInfo(int customerId)
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

    query.prepare("select * from `lessee` where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":customerId", customerId);
    query.exec();
    //qDebug()<<customerId;
    if (!query.isActive()) {
        return false;
    }
    else {
        while (query.next()) {
            temp_le.customerId=query.value(0).toInt();
            temp_le.customerName=query.value(1).toString();
            temp_le.nativePlace=query.value(2).toString();
            temp_le.phoneNumber=query.value(3).toString();
            temp_le.sex=query.value(4).toString();
            temp_le.idCard=query.value(5).toString();
            temp_le.number=query.value(6).toInt();
            temp_le.remark=query.value(7).toString();
            //qDebug()<<temp.zuhuId;
            return true;
        }
        return true;
    }
}
#endif
