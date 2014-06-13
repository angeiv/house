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

bool connectiondatabase()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL"); //从MySql驱动程序中获取一个MySql数据库
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
    return true;
}

//
bool queryHouseNumber( int *count)
{
    QSqlQuery query; //定义一个QSqlQuery 类型的变量

    query.exec("select * from roomInfo");
    *count=query.size();

    return true;
}

bool queryRoomInfo(roomInfo *ri,int index)
{
    QSqlQuery query;

    query.exec("select * from roomInfo");

    QSqlRecord record = query.record();
/*    record.indexOf(index);
        *ri->roomId=query.value(0).toInt();
        ri->location=query.value(3).toString();
        ri->roomType=query.value(2).toString();
        ri->area=query.value(7).toInt();
        ri->realNum=query.value(6).toInt();
        ri->ratingNum=query.value(5).toInt();
        ri->price=query.value(8).toInt();
    }*/
    return true;
}

bool query()
{
    QSqlQuery query; //定义一个QSqlQuery 类型的变量

    //创建数据库表，并填充数据
/*    query.exec("drop table student");
    query.exec(QObject::tr("create table student(sno varchar(10) not null primary key,sname varchar(20) not null,sclass varchar(10) not null)"));
    query.exec(QObject::tr("insert into student(sno,sname, sclass) values('2009001','lilei','0901')"));
    query.exec(QObject::tr("insert into student(sno,sname, sclass) values('2009002','lucy','0902')"));
    query.exec(QObject::tr("insert into student(sno,sname, sclass) values('2009003','mike','0903')"));
*/
    //执行数据库查询语句
    /*query.exec("select * from student");
    qDebug()<<"sno              sname         sclass";
    while(query.next())
    {
        qDebug()<<query.value(0).toString()<<"      "<<query.value(1).toString()<<"      "<<query.value(2).toString();
    }*/


    /*
    //定义QSqlQuery对象时使用含参构造函数，传入查询语句和数据库
    QSqlQuery query("select sname from student",db);
    QSqlRecord rec=query.record();
    while(query.next())
    {
        rec=query.record();
        int snamecol=rec.indexOf("sname");
        QString  value=query.value(snamecol).toString();
        qDebug()<<"sname : "<<value;
    }
    */

    /*
    QSqlQuery query;
    //执行指定的SQl语句
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    while(query.next())
    {
        rec=query.record();
        int snocol=rec.indexOf("sno");
        QString  value=query.value(snocol).toString();
        qDebug()<<"sno : "<<value;
    }
    */

    /*QSqlQuery query;
    query.prepare("select * from student where sname=:sname"); //设置将要执行的SQL查询语句， :sname为是要被绑定数据的位置
    query.bindValue(":sname","lucy"); //绑定数据到指定的位置
    query.exec();
    QSqlRecord rec=query.record();
    while(query.next())
    {
        rec=query.record();
        int snocol=rec.indexOf("sno");
        int snamecol=rec.indexOf("sname");
        int sclasscol=rec.indexOf("sclass");
        QString  value1=query.value(snocol).toString();
        QString  value2=query.value(snamecol).toString();
        QString  value3=query.value(sclasscol).toString();
        qDebug()<<"sno : "<<value1<<"\t"<<"sname : "<<value2<<"\t"<<"sclass : "<<value3;
    }
    */

    /*QSqlQuery query;
    query.prepare("insert into student (sno,sname, sclass) values(:sno,:sname,:sclass)"); //设置将要执行的SQL语句，并设定被绑定的数据的位置

    //将数据绑定到指定的位置
    query.bindValue(":sno", "2009004");
    query.bindValue(":sname", "Bart");
    query.bindValue(":sclass", "0903");
    query.exec();
    query.exec("select * from student where sname='Bart'");
    QSqlRecord rec=query.record();
    while(query.next())
    {
         rec=query.record();
         int snocol=rec.indexOf("sno");
         int snamecol=rec.indexOf("sname");
         int sclasscol=rec.indexOf("sclass");
         QString  value1=query.value(snocol).toString();
         QString  value2=query.value(snamecol).toString();
         QString  value3=query.value(sclasscol).toString();
         qDebug()<<"sno : "<<value1<<"\t"<<"sname : "<<value2<<"\t"<<"sclass : "<<value3;
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    //移动到第一条语句，如果移动成功则输出此条记录
    if(query.first())
    {
         rec=query.record();
         int snocol=rec.indexOf("sno");
         qDebug()<<"sno : "<<query.value(snocol).toString();
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    //移动到最后一条语句，如果移动成功则输出此条记录
    if(query.last())
    {
         rec=query.record();
         int snocol=rec.indexOf("sno");
         qDebug()<<"sno : "<<query.value(snocol).toString();
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    //移动到下一条语句，如果移动成功则输出此条记录
    while(query.next())
    {
        rec=query.record();
        int snocol=rec.indexOf("sno");
        qDebug()<<"sno : "<<query.value(snocol).toString();
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    //移动到查询结果的最后一条记录处，
    if(query.last())
    {
             //输出最后一条记录
         rec=query.record();
         int snocol=rec.indexOf("sno");
         qDebug()<<"sno : "<<query.value(snocol).toString();
              //由后向前依次输出记录
         while(query.previous())
         {
             rec=query.record();
             int snocol=rec.indexOf("sno");
             qDebug()<<"sno : "<<query.value(snocol).toString();
          }
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    //移动到查询结果的第二条记录处，移动成功，则输出记录内容。
    if(query.seek(1))
    {
         rec=query.record();
         int snocol=rec.indexOf("sno");
         qDebug()<<"sno : "<<query.value(snocol).toString();
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    while(query.next()) //输出查询结果的所有记录
    {
        rec=query.record();
        int snocol=rec.indexOf("sno");
        qDebug()<<"sno : "<<query.value(snocol).toString();
        query.clear(); //清空查询结果，并释放系统资源
    }*/

    /*QSqlQuery query;
    query.exec("select * from student");
    if(query.isActive())
    {
         qDebug()<<"this query is active!";
    }
    else
    {
         qDebug()<<"this query is not active!";
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    //判断当前记录是否有效，
    if(query.isValid())
    {
        qDebug()<<"Valid record!";
    }
    else
    {
        qDebug()<<"Invalid record!";
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    QSqlRecord rec=query.record();
    int snocol=rec.indexOf("sno");
    if(query.first())
    {
        //判断当前列是否为空
        if(query.isNull(snocol))
        {
            qDebug()<<"this field is null!";
        }
        else
        {
            qDebug()<<"this field is not null!";
        }
    }*/

    /*QSqlQuery query;
    query.exec("select sno from student");
    //获取查询结果中记录的个数
    int size=query.size();
    qDebug()<<"the number of the records is :"<<size;*/

    //QSqlQuery query;

    query.exec("select * from student");
    QSqlRecord rec=query.record();

//    qDebug()<<"count"<<cou;
    while(query.next())
    {
        rec=query.record();
        int snocol=rec.indexOf("sno");
        int snamecol=rec.indexOf("sname");
        int sclasscol=rec.indexOf("sclass");

        //获取当前记录中某一列的值
        QString  value1=query.value(snocol).toString();
        QString  value2=query.value(snamecol).toString();
        QString  value3=query.value(sclasscol).toString();
        qDebug()<<"sno : "<<value1<<"\t"<<"sname : "<<value2<<"\t"<<"sclass : "<<value3;
    }

    return true;
}
#endif // CONNECTDATABASE_H
