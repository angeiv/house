#ifndef CONNECT_REPAY_H
#define CONNECT_REPAY_H
#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>

bool connectiondatabase1( )
{

    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db=QSqlDatabase::database("qt_sql_default_connection");
    else
            QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
    db.setHostName("localhost");//指定数据库服务器名称
    db.setDatabaseName("house"); //连接一个已存在的数据
    db.setUserName("root");      //设置登录名
    db.setPassword("root"); //设置登录密码

    if(db.open()) //打开数据库连接
    {
        qDebug()<<"database is established!";
    }
    else
    {
        qDebug()<<"build error!";
        return false;
    }

    QSqlQuery query; //定义一个QSqlQuery 类型的变量







    query.exec(QObject::tr("select * from repay"));
    QSqlRecord rec=query.record();

    while(query.next())
    {
        rec=query.record();
        int rno=rec.indexOf("roomId");//返回该列的索引
        //int rname=rec.indexOf("customername");
        QString  value1=query.value(rno).toString();//获取该列的数据值
       // QString  value2=query.value(rname).toString();
       // qDebug()<<"roomId : "<<value1<<"\t"<<"customerName :"<<value2<<"\t";
    }

    return true;
}

#endif // CONNECT_REPAY_H
