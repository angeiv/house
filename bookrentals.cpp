#include "bookrentals.h"
#include "ui_bookrentals.h"
#include "QDate"
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
//#include "connect_book.h"
#include <QMessageBox>

bookRentals::bookRentals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookRentals)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

bookRentals::~bookRentals()
{
    delete ui;
}

void bookRentals::on_btnClose_clicked()
{
    this->close();
}

void bookRentals::on_btnBook_clicked()
{
    QSqlQuery query;
    QString item;
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
        //return false;
    }
     //return true;

    if(ui->lineEdit_Cli->text().isEmpty()||ui->lineEditroomId->text().isEmpty())
    {

         QMessageBox::about(NULL,"提示","预定客户和房屋编号不能为空！");
    }
    else
    {
        item="insert into book values('";
        item+=ui->lineEditBookNo->text();
        item+="','";

       // if(ui->male_button->isChecked())item+="male";
        //if(ui->female_button->isChecked())item+="female";
        //item+="','";
        item+=ui->lineEdit_Cli->text();
        item+="','";
        item+=ui->lineEditroomId->text();
        item+="','";
        item+=ui->lineEdit_bookMoney->text();
        item+="','";
        item+=ui->lineEdit_VTime->text();
        item+="','";



        item+=ui->lineEdit_BookMonth->text();
        item+="','";
        item+=ui->dateEdit->text();
        item+="','";
        item+=ui->dateEdit_2->text();
        item+="','";
        item+=ui->lineEdit_Saleman->text();
        item+="')";
        qDebug()<<item;
        if(query.exec(item))
        {
             QMessageBox::about(NULL,"提示","预定成功！");
        }
    }

    item="";
   // setEnabled(btnBook);

}
