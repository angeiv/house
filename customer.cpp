#include "customer.h"
#include "ui_customer.h"
//#include "housedata.h"
//#include "ui_housedata.h"
#include "connectdbc.h"
#include "customerinfo.h"
#include <QMessageBox>//add message box
int currentIndex1=0;//当前查询的位置
int maxIndex1=0;//查询的最大结果
bool searchStatus1 = false;//search status
int operateNum1=0;//which operate,add,alter



Customer::~Customer()
{
    delete ui;
}
void Customer::setCustomerInfoNone()
{
    //set room information
    ui->lineEditCustomerId->setText(NULL);
    ui->lineEditName->setText(NULL);
    // ui->lineEdit->setText(NULL);
    ui->male_Button->setEnabled(true);
    ui->female_Button->setEnabled(true);
    ui->lineEditIdCard->setText(NULL);
    ui->lineEditTelephone->setText(NULL);
    ui->lineEditAddress->setText(NULL);
    // ui->lineEdit->setText(NULL);
    ui->lineEditNumber->setText(NULL);
    ui->textEditRemark->setText(NULL);

    setLineEditDisabled();
}

void Customer::getCustomerInfo(int index)
{
    ci[index].CustomerId=ui->lineEditCustomerId->text().toInt();
    ci[index].Name=ui->lineEditName->text();
    //  ci[index].Sex=ui->male_Button->text();
    if(ui->male_Button->isChecked())//item+="male";
        ci[index].Sex="male";
    if(ui->female_Button->isChecked())
        ci[index].Sex="female";
    ci[index].IdCard=ui->lineEditIdCard->text();
    ci[index].Telephone=ui->lineEditTelephone->text();
    ci[index].Address=ui->lineEditAddress->text();
    // ci[index].price=ui->lineEditPrice->text().toInt();
    ci[index].Number=ui->lineEditNumber->text().toInt();//new foom have no cunstomer
    ci[index].Remark=ui->textEditRemark->toPlainText();
    //qDebug()<<ri[maxIndex].roomId<<ri[maxIndex].roomType<<ri[maxIndex].floor;
}

Customer::Customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Customer)
{
    ui->setupUi(this);

    ui->btnDelete->setEnabled(false);
    //result number
    // queryCustomerNumber(&maxIndex);
    ui->lineEditCount->clear();
    ui->lineEditCount->setText(QString::number(maxIndex1));

    //set read only
    setLineEditDisabled();

    //get all room informations
    queryCustomerInfo(ci);

}
void Customer::setLineEditEnabled()
{
    //set alter
    //  ui->comboBoxFloor->setEditable(false);
    // ui->comboBoxFloor->setEnabled(true);
    //  ui->lineEditArea->setReadOnly(false);
    ui->lineEditCount->setReadOnly(true);
    ui->lineEditCustomerId->setReadOnly(false);
    ui->lineEditName->setReadOnly(false);
    ui->lineEditNumber->setReadOnly(false);
    ui->lineEditTelephone->setReadOnly(false);
    ui->lineEditAddress->setReadOnly(false);
    ui->lineEditIdCard->setReadOnly(false);
    ui->textEditRemark->setReadOnly(false);

    //  ui->male_Button->setEnabled();
    // ui->female_Button->setEnabled(false);


}

void Customer::setLineEditDisabled()
{
    //set read only
    // ui->comboBoxFloor->setEditable(false);
    // ui->comboBoxFloor->setEnabled(false);
    //ui->male_Button->setReadOnly(true);
    //   ui->female_Button->setReadOnly(true);
    ui->lineEditCount->setReadOnly(true);
    ui->lineEditCustomerId->setReadOnly(true);
    ui->lineEditName->setReadOnly(true);
    ui->lineEditNumber->setReadOnly(true);
    ui->lineEditTelephone->setReadOnly(true);
    ui->lineEditAddress->setReadOnly(true);
    ui->lineEditIdCard->setReadOnly(true);
    ui->textEditRemark->setReadOnly(true);

    ui->male_Button->setEnabled(true);
    ui->female_Button->setEnabled(true);
}

void Customer::on_btnAdd_clicked()
{
    operateNum1 = 1;
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);

    ui->btnAdd->setEnabled(false);
    ui->btnAlter->setEnabled(false);
    ui->btnDelete->setEnabled(false);

    setCustomerInfoNone();
    setLineEditEnabled();

    // ui->comboBoxFloor->setCurrentIndex(0);
    //ui->comboBoxFloor->setEnabled(false);
}


void Customer::on_btnSearch_clicked()
{
    if (!searchStatus1) {
        setLineEditDisabled();
        setCustomerInfoNone();
        ui->lineEditCustomerId->setReadOnly(false);
        searchStatus1 = true;
        QMessageBox::about(NULL,"tips","please input CustomerID");
        //text
    }
    else {
        int CustomerId;
        CustomerId=ui->lineEditCustomerId->text().toInt();
        //qDebug()<<CustomerId;
        //connect db and search
        if (searchCustomerInfo(CustomerId)) {
            //show Customer info

            //set Customer information
            ui->lineEditCustomerId->setText(QString::number(temp1.CustomerId));
            ui->lineEditName->setText(temp1.Name);
            //  ui->lineEditRommType->setText(temp.CustomerType);
            //if(ui->male_Button->isChecked())item+="male";
            if(temp1.Sex=="male")ui->male_Button->isChecked();
            if(temp1.Sex=="female")ui->female_Button->isChecked();
            // if(ui->female_Button->isChecked())item+="female";
            ui->lineEditIdCard->setText(temp1.IdCard);
            ui->lineEditTelephone->setText(temp1.Telephone);
            ui->lineEditAddress->setText(temp1.Address);
            ui->lineEditNumber->setText(QString::number(temp1.Number));
            //ui->lineEditPrice->setText(QString::number(temp.price));
            //if (QString::number(temp1.Floor).toInt())
            // ui->comboBoxFloor->setCurrentIndex(1);
            // else
            //  ui->comboBoxFloor->setCurrentIndex(0);
            ui->textEditRemark->setText(temp1.Remark);

            //some no result ==> msgbox
            //setCustomerInformation(currentIndex);
            ui->lineEditCustomerId->setReadOnly(true);
            setLineEditDisabled();
            searchStatus1 = false;

            QMessageBox::about(NULL,"tips","search over,info are below");
        }
        else {
            QMessageBox::about(NULL,"tips","search over,info not found");
        }
    }
}


void Customer::on_btnAlter_clicked()
{
    operateNum1 = 2;
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);

    ui->btnAdd->setEnabled(false);
    ui->btnAlter->setEnabled(false);
    ui->btnDelete->setEnabled(false);

    setLineEditEnabled();

    //can not edit customerid and customer
    ui->lineEditCustomerId->setEnabled(false);
    // ui->comboBoxFloor->setEnabled(false);
}

void Customer::on_btnDelete_clicked()
{
    //QMessageBox
    if(16384 == QMessageBox::question(NULL,"question","are you sure?",
                                      QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes) ) {
        //msgbox
        //16384 == yes,65536 == no
        //delete in db
        if(deletCustomerInfo(ci[currentIndex1 - 1])) {
            QMessageBox::about(NULL,"tips","delete complete");
            //shuzu xiangguan yidong
            deleteOneCustomerInfo(ci,currentIndex1,&maxIndex1);

            //ui->lineEditCount->setText(QString::number(maxIndex));
            //queryRoomInfo(ci);
        }
        else {
            //delete error
            QMessageBox::about(NULL,"tips","delete error");
        }
    }
}

void Customer::on_btnClose_clicked()
{
    ui->btnClose->setEnabled(false);
    ui->btnSave->setEnabled(false);

    ui->btnAdd->setEnabled(true);
    ui->btnAlter->setEnabled(true);
    ui->btnDelete->setEnabled(true);

    setLineEditDisabled();
    ui->lineEditCustomerId->setEnabled(true);
}

void Customer::on_btnSave_clicked()
{
    bool status = 1;
    //some db operate
    switch (operateNum1) {
    case 2:
        //alter
        getCustomerInfo(currentIndex1-1);
        status = updateCustomerInfo(ci[currentIndex1-1]);
        break;
    case 1:
        //add
        getCustomerInfo(maxIndex1);
        status = insertCustomerInfo(ci[maxIndex1],&maxIndex1);
        ui->lineEditCount->setText(QString::number(maxIndex1));
        //msgbox
        break;
    default:
        break;
    }
}
void Customer::on_btnExit_clicked()
{


    this->close();

}

void Customer::on_btnFirst_clicked()
{
    setCustomerInformation(1);
    currentIndex1 = 1;
    ui->btnDelete->setEnabled(true);
}

void Customer::on_btnLast_clicked()
{
    ui->btnDelete->setEnabled(true);
    setCustomerInformation(maxIndex1);
    currentIndex1 = maxIndex1;
}

void Customer::on_btnFormer_clicked()
{
    ui->btnDelete->setEnabled(true);
    if (currentIndex1 <= 1) {
        QMessageBox::about(this,tr("tips"),tr("already the first one"));
    }
    else {
        currentIndex1 = currentIndex1 - 1;
        setCustomerInformation(currentIndex1);
    }
}

void Customer::on_btnLatter_clicked()
{
    ui->btnDelete->setEnabled(true);
    if (currentIndex1 >= maxIndex1) {
        QMessageBox::about(this,tr("tips"),tr("already the last one"));
    }
    else {
        currentIndex1 = currentIndex1 + 1;
        setCustomerInformation(currentIndex1);
    }
}
void Customer::setCustomerInformation(int index)
{
    //index
    currentIndex1=index;

    index=index-1;//room no.

    //set room information
    ui->lineEditCustomerId->setText(QString::number(ci[index].CustomerId));

    // if(ui->male_Button->isChecked())setText(ci[index].Sex);
    // if(ui->female_Button->isChecked())setText(ci[index].Sex);
    ui->lineEditIdCard->setText(ci[index].IdCard);
    ui->lineEditTelephone->setText(ci[index].Telephone);
    ui->lineEditAddress->setText(ci[index].Address);
    ui->lineEditCustomerId->setText(QString::number(temp1.CustomerId));
    ui->lineEditName->setText(temp1.Name);
    //  ui->lineEditRommType->setText(temp.CustomerType);
    //if(ui->male_Button->isChecked())item+="male";
    // if(ui->female_Button->isChecked())item+="female";

    if(temp1.Sex=="male")ui->male_Button->isChecked();
    if(temp1.Sex=="female")ui->female_Button->isChecked();
    ui->lineEditNumber->setText(QString::number(ci[index].Number));
    //ui->lineEditPrice->setText(QString::number(temp.price));
    //if (QString::number(temp1.Floor).toInt())
    // ui->comboBoxFloor->setCurrentIndex(1);
    // else
    //  ui->comboBoxFloor->setCurrentIndex(0);
    ui->textEditRemark->setText(temp1.Remark);

    //some no result ==> msgbox
    //setCustomerInformation(currentIndex);
    ui->lineEditCustomerId->setReadOnly(true);
    //  ui->lineEdit->setText(ci[index].ratingNum);
    // ui->lineEditPrice->setText(QString::number(ci[index].price));
    // if (QString::number(ci[index].Floor).toInt())
    // ui->comboBoxFloor->setCurrentIndex(1);
    //else
    //  ui->comboBoxFloor->setCurrentIndex(0);
    //    ui->textEditRemark->setText(ci[index].Remark);
}
