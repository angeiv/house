#include "rentingdata.h"
#include "ui_rentingdata.h"
#include "connect_wanted.h"
#include "wantedinfo.h"
#include <QMessageBox>//add message box
#include "bookrentals.h"
//#include "mainwindow.h"
int currentIndex_2=0;//当前查询的位置
int maxIndex_2=0;//查询的最大结果
bool searchStatus_2 = false;//search status
int operateNum2=0;//which operate,add,alter

rentingdata::rentingdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentingdata)
{

    ui->setupUi(this);

    ui->btnDelete->setEnabled(false);
    //result number
    queryWantedNumber(&maxIndex_2);
    ui->lineEditCount->clear();
    ui->lineEditCount->setText(QString::number(maxIndex_2));

    //set read only
    setLineEditDisabled();

    //get all room informations
    queryWantedInfo(wt);
}
void rentingdata::setLineEditEnabled()
{
    //set alter
    ui->lineEditCustomerId->setReadOnly(true);
    ui->lineEditCustomerName->setReadOnly(false);
    ui->lineEditArea->setReadOnly(false);
    ui->lineEditCount->setReadOnly(false);
    ui->lineEditRoomType->setReadOnly(false);
    ui->lineEditPrice->setReadOnly(false);
    ui->lineEditCircumstance->setReadOnly(false);
    ui->lineEditTime->setReadOnly(false);
    ui->lineEditPhoneNumber->setReadOnly(false);
    ui->lineEditRoomId->setReadOnly(false);
    ui->textEditRemark->setReadOnly(false);
}
void rentingdata::setLineEditDisabled()
{
    //set read only
    //ui->comboBoxRenterId->setEditable(false);
   // ui->comboBoxRenterId->setEnabled(false);
    ui->lineEditArea->setReadOnly(true);
    ui->lineEditCount->setReadOnly(true);
    ui->lineEditPhoneNumber->setReadOnly(true);
    ui->lineEditPrice->setReadOnly(true);
    ui->lineEditCircumstance->setReadOnly(true);
    ui->lineEditCustomerName->setReadOnly(true);
    ui->lineEditRoomType->setReadOnly(true);
    ui->lineEditCustomerId->setReadOnly(true);
    ui->lineEditRoomId->setReadOnly(true);
    ui->textEditRemark->setReadOnly(true);
}

void rentingdata::setWantedInformation(int index)
{
    //index
    currentIndex_2=index;

    index=index-1;//room no.

    //set room information
    ui->lineEditRoomId->setText(QString::number(wt[index].roomId));
    ui->lineEditCustomerId->setText(QString::number(wt[index].customerId));
    ui->lineEditRoomType->setText(wt[index].roomType);
    ui->lineEditPhoneNumber->setText(wt[index].phoneNumber);
    ui->lineEditArea->setText(QString::number(wt[index].area));
    ui->lineEditCustomerName->setText(wt[index].customerName);
    ui->lineEditCircumstance->setText(wt[index].circumstance);
    ui->lineEditPrice->setText(QString::number(wt[index].price));
     ui->lineEditTime->setText(QString::number(wt[index].sj));
    ui->textEditRemark->setText(wt[index].remark);

}

void rentingdata::setWantedInfoNone()
{
    //set room information
    ui->lineEditCustomerId->setText(NULL);
    ui->lineEditCustomerName->setText(NULL);
    ui->lineEditPhoneNumber->setText(NULL);
    ui->lineEditRoomType->setText(NULL);
    ui->lineEditArea->setText(NULL);
    ui->lineEditRoomId->setText(NULL);
    ui->lineEditCircumstance->setText(NULL);
    ui->lineEditPrice->setText(NULL);
    ui->lineEditTime->setText(NULL);
    ui->textEditRemark->setText(NULL);

    setLineEditDisabled();
}

void rentingdata::getWantedInfo(int index)
{
    wt[index].customerId=ui->lineEditCustomerId->text().toInt();
        wt[index].customerName=ui->lineEditCustomerName->text();
        wt[index].phoneNumber=ui->lineEditPhoneNumber->text().toInt();
        wt[index].roomType=ui->lineEditRoomType->text();
        wt[index].area=ui->lineEditArea->text().toInt();
        wt[index].roomId=ui->lineEditRoomId->text().toInt();
        wt[index].circumstance=ui->lineEditCircumstance->text();
        wt[index].price=ui->lineEditPrice->text().toInt();
        wt[index].sj=ui->lineEditTime->text().toInt();
        //wt[index].rentewtd=0;//new foom have no cunstomer
        wt[index].remark=ui->textEditRemark->toPlainText();
    //qDebug()<<ri[maxIndex].roomId<<ri[maxIndex].roomType<<ri[maxIndex].floor;
}

rentingdata::~rentingdata()
{
    delete ui;
}

void rentingdata::on_btnClose_clicked()
{
    ui->btnClose->setEnabled(false);
      ui->btnSave->setEnabled(false);

      ui->btnAdd->setEnabled(true);
      ui->btnAlter->setEnabled(true);
      ui->btnDelete->setEnabled(true);

      setLineEditDisabled();
      ui->lineEditRoomId->setEnabled(true);
}

void rentingdata::on_btnAdd_clicked()
{
    operateNum2 = 1;
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);

    ui->btnAdd->setEnabled(false);
    ui->btnAlter->setEnabled(false);
    ui->btnDelete->setEnabled(false);

    setWantedInfoNone();
    setLineEditEnabled();

    ui->lineEditCustomerId->setEnabled(false);

  //  ui->comboBoxRenterId->setCurrentIndex(0);
  //  ui->comboBoxRenterId->setEnabled(false);
}

void rentingdata::on_btnAlter_clicked()
{
    operateNum2 = 2;
        ui->btnSave->setEnabled(true);
        ui->btnClose->setEnabled(true);

        ui->btnAdd->setEnabled(false);
        ui->btnAlter->setEnabled(false);
        ui->btnDelete->setEnabled(false);

        setLineEditEnabled();

        //can not edit roomid and customer
        ui->lineEditCustomerId->setEnabled(false);
       // ui->comboBoxRenterId->setEnabled(false);
}

void rentingdata::on_btnDelete_clicked()
{
    //QMessageBox
       if(16384 == QMessageBox::question(NULL,"问题","你确定？",
                                         QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes) ) {
           //msgbox
           //16384 == yes,65536 == no
           //delete in db
           if(deleteWantedInfo(wt[currentIndex_2 - 1])) {
               QMessageBox::about(NULL,"提示","删除完毕！");
               //shuzu xiangguan yidong
               //deleteOneWantedInfo(wt,currentIndex_2,&maxIndex_2);

               ui->lineEditCount->setText(QString::number(maxIndex_2));
               //queryRoomInfo(ri);
           }
           else {
               //delete error
               QMessageBox::about(NULL,"提示","删除出现异常！");
           }
       }
}


void rentingdata::on_btnSave_clicked()
{
    bool status = 1;
       //some db operate
       switch (operateNum2) {
       case 2:
           //alter
           getWantedInfo(currentIndex_2-1);
           status = updateWantedInfo(wt[currentIndex_2-1]);
           break;
       case 1:
           //add
           getWantedInfo(maxIndex_2);
           status = insertWantedInfo(wt[maxIndex_2],&maxIndex_2);
           ui->lineEditCount->setText(QString::number(maxIndex_2));
           //msgbox
           break;
       default:
           break;
       }
       if (status)
           QMessageBox::about(this,tr("提示"),tr("保存成功！"));
       else
           QMessageBox::about(this,tr("提示"),tr("发生了一些错误……"));
       ui->btnClose->setEnabled(false);
       ui->btnSave->setEnabled(false);

       ui->btnAdd->setEnabled(true);
       ui->btnAlter->setEnabled(true);
       ui->btnDelete->setEnabled(true);
       ui->lineEditCustomerId->setEnabled(true);
       setLineEditDisabled();
       ui->lineEditCustomerId->setEnabled(true);
       operateNum2 = 0;
}


void rentingdata::on_btnSearch_clicked()
{
    if (!searchStatus_2) {
            setLineEditDisabled();
            setWantedInfoNone();
            ui->lineEditRoomId->setReadOnly(false);
            searchStatus_2 = true;
            QMessageBox::about(NULL,"提示","请输入房屋编号");
            //text
        }
        else {
            int customerId;
            customerId=ui->lineEditCustomerId->text().toInt();
            //qDebug()<<roomId;
            //connect db and search
            if (searchWantedInfo(customerId)) {
                //show room info

                //set room information
                ui->lineEditRoomId->setText(QString::number(tem.roomId));
                ui->lineEditCustomerId->setText(QString::number(tem.customerId));
                ui->lineEditCustomerName->setText(tem.customerName);
                ui->lineEditRoomType->setText(tem.roomType);
                ui->lineEditArea->setText(QString::number(tem.area));
                ui->lineEditTime->setText(QString::number(tem.sj));
                ui->lineEditCircumstance->setText(tem.circumstance);
                ui->lineEditPrice->setText(QString::number(tem.price));

                ui->textEditRemark->setText(tem.remark);

                //some no result ==> msgbox
                //setRoomInformation(currentIndex);
                ui->lineEditCustomerId->setReadOnly(true);
                setLineEditDisabled();
                searchStatus_2 = false;

                QMessageBox::about(NULL,"提示","查找完毕，结果如下");
            }
            else {
                QMessageBox::about(NULL,"提示","查找完毕，信息未找到");
            }
        }
}

void rentingdata::on_btnLast_clicked()
{
    ui->btnDelete->setEnabled(true);
    setWantedInformation(maxIndex_2);
    currentIndex_2 = maxIndex_2;
}

void rentingdata::on_btnLatter_clicked()
{
    ui->btnDelete->setEnabled(true);
        if (currentIndex_2 >= maxIndex_2) {
            QMessageBox::about(this,tr("提示"),tr("已经是最后一条了"));
        }
        else {
            currentIndex_2 = currentIndex_2 + 1;
            setWantedInformation(currentIndex_2);
        }
}

void rentingdata::on_btnFormer_clicked()
{
    ui->btnDelete->setEnabled(true);
        if (currentIndex_2 <= 1) {
            QMessageBox::about(this,tr("提示"),tr("已经是第一条了"));
        }
        else {
            currentIndex_2 = currentIndex_2 - 1;
            setWantedInformation(currentIndex_2);
        }
}

void rentingdata::on_btnFirst_clicked()
{
    setWantedInformation(1);
        currentIndex_2 = 1;
        ui->btnDelete->setEnabled(true);
}

void rentingdata::on_btnExit_clicked()
{
    this->close();
}

void rentingdata::on_btnOrder_clicked()
{
     bookRentals *tt=new bookRentals();
   if(!(ui->lineEditCustomerId->text().toInt()||ui->lineEditRoomId->text().toInt()))
   QMessageBox::about(this,tr("提示"),tr("客户编号和意向房屋编号不能为空"));

   else
      tt->show();
}
