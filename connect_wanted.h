#ifndef CONNECT_WANTED_H
#define CONNECT_WANTED_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
#include "wantedinfo.h"

bool queryWantedNumber(int *count1)
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

bool queryWantedInfo(wantedInfo *wt)
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
        wt[num].customerId=query.value(0).toInt();
                wt[num].customerName=query.value(1).toString();
                wt[num].phoneNumber=query.value(2).toInt();
                wt[num].roomType=query.value(3).toString();
                wt[num].area=query.value(4).toInt();
                wt[num].circumstance=query.value(5).toString();
               // wt[num].area=query.value(6).toInt();
              //  wt[num].circumstance=query.value(7).toString();
                wt[num].price=query.value(6).toInt();
                wt[num].roomId=query.value(7).toInt();
                wt[num].sj=query.value(8).toInt();
                wt[num].remark=query.value(9).toString();

                num++;
    }
    return true;
}

bool insertWantedInfo(wantedInfo wt,int *maxIndex)
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
    query.prepare("insert into wanted "
                  "(customerId,customerName,phoneNumber,roomType,"
                  "area,circumstance,price,roomId,sj,remark) "
                  "values(:customerId,:customerName,:phoneNumber,:roomType,:area,:circumstance,"
                  ":price,:roomId,:sj,:remark)");

    //将数据绑定到指定的位置
    query.bindValue(":customerId", wt.customerId);
    query.bindValue(":customerName", wt.customerName);
    query.bindValue(":phoneNumber", wt.phoneNumber);
    query.bindValue(":roomType", wt.roomType);
    query.bindValue(":area",wt.area);
    query.bindValue(":circumstance", wt.circumstance);
    query.bindValue(":price", wt.price);
    query.bindValue(":roomId", wt.roomId);

    query.bindValue(":sj",wt.sj);

    query.bindValue(":remark", wt.remark);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec()) {
        *maxIndex = *maxIndex + 1;
        return true;
    }
    else{
        return false;
    }
}

bool updateWantedInfo(wantedInfo wt)
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
    query.prepare("update `wanted` set "
                  "`customerName`=:customerName,"
                  "`phoneNumber`=:phoneNumber,"
                  "`roomType`=:roomType,"
                  "`area`=:area,"
                  "`circumstance`=:circumstance,"
                  "`price`=:price,"
                  "`roomId`=:roomId,"
                  "`sj`=:sj,"



                  "`remark`=:remark "
                  "where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":customerId", wt.customerId);
    query.bindValue(":customerName", wt.customerName);
    query.bindValue(":phoneNumber", wt.phoneNumber);
    query.bindValue(":roomType", wt.roomType);
    query.bindValue(":area",wt.area);
    query.bindValue(":circumstance", wt.circumstance);
    query.bindValue(":price", wt.price);
    query.bindValue(":roomId", wt.roomId);

    query.bindValue(":sj",wt.sj);

    query.bindValue(":remark", wt.remark);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}

bool deleteWantedInfo(wantedInfo wt)
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
    query.prepare("delete from `wanted` "
                  "where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":cutomerId", wt.customerId);

    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}
bool searchWantedInfo(int customerId)
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

    query.prepare("select * from `wanted` where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":customerId", customerId);
    query.exec();
    //qDebug()<<roomId;
    if (!query.isActive()) {
        return false;
    }
    else {
        while (query.next()) {
            tem.customerId=query.value(0).toInt();
            tem.customerName=query.value(1).toString();
            tem.phoneNumber=query.value(2).toInt();
            tem.roomType=query.value(3).toString();
            tem.area=query.value(4).toInt();
            tem.circumstance=query.value(5).toString();
            tem.price=query.value(6).toInt();
            tem.roomId=query.value(7).toInt();
            tem.sj=query.value(8).toInt();


            tem.remark=query.value(9).toString();
            //qDebug()<<temp.roomId;
            return true;
        }
        return true;
    }
}

#endif // CONNECT_WANTED_H
