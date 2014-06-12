#ifndef CONNECTDBC_H
#define CONNECTDBC_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>

#include "customerinfo.h"
#include "login.h"
//#include "connectdatabase.h"
bool queryCustomerNumber(int *count)
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

    query.exec("select * from customer");
    *count=query.size();

    //close connection
    query.clear();//清空查询语句，并释放内存空间
    db.commit();
    db.close();   //关闭数据库连接
    //qDebug()<<"connection closed.";
    return true;
}
bool queryCustomerInfo(CustomerInfo *ci)
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

    query.exec("select * from customer");

    int num=0;
    while (query.next()) {
        ci[num].CustomerId=query.value(0).toInt();
        ci[num].Name=query.value(3).toString();
        ci[num].Address=query.value(14).toString();
        ci[num].Telephone=query.value(6).toString();
        ci[num].Sex=query.value(2).toString();
        ci[num].IdCard=query.value(7).toString();

        ci[num].Number=query.value(4).toInt();
       // ri[num].price=query.value(8).toInt();
        ci[num].Remark=query.value(15).toString();


        num++;
    }
    return true;
}


bool insertCustomerInfo(CustomerInfo ci,int *maxIndex)
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
    query.prepare("insert into customer "
                  "(customerId,customerName,nativePlace,phoneNumber,"
                  "sex,idCard,number,remark) "
                  "values(:customerId,:customerName,:nativePlace,:phoneNumber,"
                  ":sex,:idCard,:number,:remark)");

    //将数据绑定到指定的位置
    query.bindValue(":customerId", ci.CustomerId);
    query.bindValue(":customerName", ci.Name);
    query.bindValue(":sex", ci.Sex);
    query.bindValue(":idCard", ci.IdCard);
    query.bindValue(":phoneNumber", ci.Telephone);
    query.bindValue(":nativePlace", ci.Address);
    query.bindValue(":number", ci.Number);
   // query.bindValue(":fridge", ri.ratingNum);
    query.bindValue(":remark", ci.Remark);

    //qDebug()<<ci.CustomerId<<ci.Name<<ci.Sex<<ci.IdCard<<ci.Telephone<<ci.Address<<ci.Floor<<ci.Remark;
    if (query.exec()) {
        *maxIndex = *maxIndex + 1;
        return true;
    }
    else{
        return false;
    }
}

bool updateCustomerInfo(CustomerInfo ci)
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
    query.prepare("update `customer` set "
                  "`customerId`=:customerId,"
                  "`customerName`=:Name,"
                  "`sex`=:sex,"
                  "`idCard`=:idCard,"
                  "`phoneNumber`=:phoneNumber,"
                  "`nativePlace`=:nativePlace,"
                  "`number`=:number,"
                  "`remark`=:remark "
                  "where `customerId`=:customerId");


    //将数据绑定到指定的位置
    query.bindValue(":customerId", ci.CustomerId);
    query.bindValue(":customerName", ci.Name);
    query.bindValue(":sex", ci.Sex);
    query.bindValue(":idCard", ci.IdCard);
    query.bindValue(":phoneNumber", ci.Telephone);
    query.bindValue(":nativePlace", ci.Address);
    query.bindValue(":number", ci.Number);
   // query.bindValue(":fridge", ri.ratingNum);
    query.bindValue(":remark", ci.Remark);

    //qDebug()<<ci.CustomerId<<ci.Name<<ci.Sex<<ci.IdCard<<ci.Telephone<<ci.Address<<ci.Floor<<ci.Remark;
    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}

bool deletCustomerInfo(CustomerInfo ci)
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
    query.prepare("delete from `customer` "
                  "where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":customerId", ci.CustomerId);

    //qDebug()<<ci.CustomerId<<ci.Name<<ci.Sex<<ci.IdCard<<ci.Telephone<<ci.Address<<ci.Floor<<ci.Remark;
    //qDebug()<<ri.roomId<<ri.floor<<ri.roomType<<ri.location<<ri.realNum<<ri.area<<ri.price<<ri.ratingNum<<ri.remark;
    if (query.exec())
        return true;
    else
        return false;
}
bool searchCustomerInfo(int CustomerId)
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

    query.prepare("select * from `customer` where `customerId`=:customerId") ;

    //将数据绑定到指定的位置
    query.bindValue(":customerId", CustomerId);
    query.exec();
    //qDebug()<<roomId;
    if (!query.isActive()) {
        return false;
    }
    else {
        while (query.next()) {
            temp1.CustomerId=query.value(0).toInt();
            // temp.Customer=query.value(3).toString();
            temp1.Name=query.value(10).toString();
            temp1.Address=query.value(8).toString();
            temp1.Telephone=query.value(14).toString();
            temp1.Sex=query.value(7).toString();
            temp1.IdCard=query.value(6).toString();

            temp1.Number=query.value(4).toInt();
            temp1.Remark=query.value(15).toString();

                        //qDebug()<<temp.CustomerId;
            return true;
        }
        return true;
    }
}
#endif // CONNECTDBC_H
