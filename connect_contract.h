#ifndef CONNECT_CONTRACT_H
#define CONNECT_CONTRACT_H
#include "contractinfo.h"
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
bool insertcontractInfo(Contract tmp)
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
    query.prepare("insert into contract "
                  "(bookNo,customerName,roomId,depoistM,endDate,rentDate,"
                  "moneyShould,signDate,salesMan,remark) "
                  "values(:bookNo,:customerName,:roomId,:depoistM,:endDate,:rentDate,"
                  ":moneyShould,:signDate,:salesMan,:remark)");

    //将数据绑定到指定的位置
    query.bindValue(":bookNo", tmp.bookNo);
    query.bindValue(":customerName", tmp.customerName);
    query.bindValue(":roomId", tmp.roomId);
    query.bindValue(":depoistM", tmp.depoistM);
    query.bindValue(":endDate", tmp.enddate);
    query.bindValue(":rentDate", tmp.rentdate);
    query.bindValue(":moneyShould", tmp.moneyShould);
    query.bindValue(":signDate", tmp.signDate);
    query.bindValue(":salesMan", tmp.saleman);
    query.bindValue(":remark", tmp.remark);
    qDebug()<<tmp.signDate;
    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec()) {
        return true;
    }
    else{
        return false;
    }
}

bool insertrepayInfo(Contract tmp)
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
    query.prepare("insert into repay "
                  "(roomId,customerName,moneyShould,monthNo)"

                  "values(:roomId,:customerName,:moneyShould,:monthNo)");


    //将数据绑定到指定的位置
    query.bindValue(":roomId", tmp.roomId);
    query.bindValue(":customerName",tmp.customerName);
    query.bindValue(":moneyShould", tmp.moneyShould);
    query.bindValue(":monthNo", tmp.rentdate);


    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}
bool updateRoomInfo1(Contract tmp)
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
    query.prepare("update house.roomInfo,house.wanted "
                  "set roomInfo.rentId = wanted.customerId "
                  "where wanted.customerName = :customerName "
                  "and roomInfo.roomId = wanted.roomId");


    //将数据绑定到指定的位置

    query.bindValue(":customerName", tmp.customerName);


    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}

#endif // CONNECT_CONTRACT_H
