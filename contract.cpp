#include "contract.h"
#include "ui_contract.h"
#include "connect_contract.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
contract::contract(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contract)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

contract::~contract()
{
    delete ui;
}

void contract::on_btnClose_clicked()
{
    this->close();
}
void contract::setcontractInformation()
{
    //index
    //currentIndex=index;

   // index=index-1;//room no.

    //set room information
    ui->lineEditBookNum->setText(QString::number(tmp.bookNo));
    ui->lineEdit_CashPledge->setText(QString::number(tmp.depoistM));
    ui->lineEdit_Houseingnum->setText(QString::number(tmp.roomId));
    ui->lineEdit_Name->setText(tmp.customerName);
    ui->lineEdit_All->setText(QString::number(tmp.moneyShould));
    ui->lineEdit_Saleman->setText(QString::number(tmp.saleman));
   // ui->dateEdit->setText(tmp.enddate);
     ui->dateEdit->setDate(tmp.enddate);
   // ui->dateEdit_2->setText(tmp.signDate);
   ui->dateEdit_2->setDate(tmp.signDate);
    ui->lineEdit_Tenancy->setText(QString::number(tmp.rentdate));
    ui->textEdit_Remark->setText(tmp.remark);

}
void contract::on_btnConclud_clicked()
{
    bool status = 1;
    setcontractInformation();
    status=insertcontractInfo(tmp);
    status=insertrepayInfo(tmp);
   status=updateRoomInfo1();
    if (status)
        QMessageBox::about(this,tr("提示"),tr("保存成功！"));
    else
        QMessageBox::about(this,tr("提示"),tr("发生了一些错误……"));
}
