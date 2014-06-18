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
  tmp.bookNo=  ui->lineEditBookNum->text().toInt();
    tmp.depoistM=ui->lineEdit_CashPledge->text().toInt();
   tmp.roomId= ui->lineEdit_Houseingnum->text().toInt();
    tmp.customerName=ui->lineEdit_Name->text();
   tmp.moneyShould= ui->lineEdit_All->text().toInt();
    tmp.saleman=ui->lineEdit_Saleman->text().toInt();
   // ui->dateEdit->setText(tmp.enddate);
    tmp.enddate= ui->dateEdit->date();
   // ui->dateEdit_2->setText(tmp.signDate);
   tmp.signDate=ui->dateEdit_2->date();
   tmp.rentdate= ui->lineEdit_Tenancy->text().toInt();
    tmp.remark=ui->textEdit_Remark->toPlainText();

}
void contract::on_btnConclud_clicked()
{
    bool status = 1;
    setcontractInformation();
    status=insertcontractInfo(tmp);
 status=insertrepayInfo(tmp);
 status=updateRoomInfo1(tmp);
    if (status)
        QMessageBox::about(this,tr("提示"),tr("保存成功！"));
    else
        QMessageBox::about(this,tr("提示"),tr("发生了一些错误……"));
}
