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
#include "roomInfo.h"

bool queryHouseNumber(int *count)
{
    //check connection exist or not
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if(db.open()) //打开数据库连接
    {
        ;//qDebug()<<"database is established.";
    }
    else
    {
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

bool queryRoomInfo(roomInfo *ri)
{
    //check connection exist or not
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if(db.open()) //打开数据库连接
    {
        ;//qDebug()<<"database is established!";
    }
    else
    {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query;

    query.exec("select * from roomInfo");

    int num=0;
    while(query.next())
    {
        ri[num].roomId=query.value(0).toInt();
        ri[num].location=query.value(3).toString();
        ri[num].roomType=query.value(2).toString();
        ri[num].area=query.value(7).toInt();
        ri[num].realNum=query.value(6).toInt();
        ri[num].ratingNum=query.value(14).toString();
        ri[num].price=query.value(8).toInt();
        ri[num].remark=query.value(15).toString();
        ri[num].floor=query.value(4).toInt();
        num++;
    }
    return true;
}

bool insertRoomInfo(roomInfo ri,int *maxIndex)
{
    //check connection exist or not
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if(db.open()) //打开数据库连接
    {
        ;//qDebug()<<"database is established!";
    }
    else
    {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query;
    //设置将要执行的SQL语句，并设定被绑定的数据的位置
    query.prepare("insert into roomInfo "
                  "(roomId,floor,roomtype,location,realNum,"
                  "area,price,fridge,remark) "
                  "values(:roomId,:floor,:roomtype,:location,:realNum,"
                  ":area,:price,:fridge,:remark)");

        //将数据绑定到指定的位置
        query.bindValue(":roomId", ri.roomId);
        query.bindValue(":floor", ri.floor);
        query.bindValue(":roomtype", ri.roomType);
        query.bindValue(":location", ri.location);
        query.bindValue(":realNum", ri.realNum);
        query.bindValue(":area", ri.area);
        query.bindValue(":price", ri.price);
        query.bindValue(":fridge", ri.ratingNum);
        query.bindValue(":remark", ri.remark);

//qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if(query.exec())
    {
        *maxIndex = *maxIndex + 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool updateRoomInfo(roomInfo ri)
{
    //check connection exist or not
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if(db.open()) //打开数据库连接
    {
        ;//qDebug()<<"database is established!";
    }
    else
    {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query;
    //设置将要执行的SQL语句，并设定被绑定的数据的位置
    query.prepare("update `roomInfo` set "
                  "`floor`=:floor,"
                  "`roomtype`=:roomtype,"
                  "`location`=:location,"
                  "`realNum`=:realNum,"
                  "`area`=:area,"
                  "`price`=:price,"
                  "`fridge`=:fridge,"
                  "`remark`=:remark "
                  "where `roomId`=:roomId") ;

        //将数据绑定到指定的位置
        query.bindValue(":roomId", ri.roomId);
        query.bindValue(":floor", ri.floor);
        query.bindValue(":roomtype", ri.roomType);
        query.bindValue(":location", ri.location);
        query.bindValue(":realNum", ri.realNum);
        query.bindValue(":area", ri.area);
        query.bindValue(":price", ri.price);
        query.bindValue(":fridge", ri.ratingNum);
        query.bindValue(":remark", ri.remark);

//qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool deleteRoomInfo(roomInfo ri)
{
    //check connection exist or not
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if(db.open()) //打开数据库连接
    {
        ;//qDebug()<<"database is established!";
    }
    else
    {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query;
    //设置将要执行的SQL语句，并设定被绑定的数据的位置
    query.prepare("delete from `roomInfo` "
                  "where `roomId`=:roomId") ;

        //将数据绑定到指定的位置
        query.bindValue(":roomId", ri.roomId);

//qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool searchRoomInfo(int roomId)
{
    //check connection exist or not
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
        db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if(db.open()) //打开数据库连接
    {
        ;//qDebug()<<"database is established!";
    }
    else
    {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query;

    query.exec("select * from roomInfo "
    "where `roomId`=:roomId") ;

//将数据绑定到指定的位置
query.bindValue(":roomId", roomId);
query.exec();
    while(query.next())
    {
        temp.roomId=query.value(0).toInt();
        temp.location=query.value(3).toString();
        temp.roomType=query.value(2).toString();
        temp.area=query.value(7).toInt();
        temp.realNum=query.value(6).toInt();
        temp.ratingNum=query.value(14).toString();
        temp.price=query.value(8).toInt();
        temp.remark=query.value(15).toString();
        temp.floor=query.value(4).toInt();

    return true;
    }
        return false;
}
#endif
