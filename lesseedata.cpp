#include "lesseedata.h"
#include "ui_lesseedata.h"
#include "le_connectdatabase.h"
#include "le_customer.h"
#include <QMessageBox>//add message box

int currentIndex_le=0;//当前查询的位置
int maxIndex_le=0;//查询的最大结果
bool searchStatus_le = false;//search status
int operateNum_le=0;//which operate,add,alter

//##############################################################################################//

void lesseedata::setLineEditEnabled()
{
    //set alter
    ui->comboBoxGender->setEditable(false);
    ui->comboBoxGender->setEnabled(true);
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit_IdCardNo->setReadOnly(false);
    ui->lineEdit_ManNum->setReadOnly(false);
    ui->lineEdit_Name->setReadOnly(false);
    ui->lineEdit_Num->setReadOnly(false);
    ui->textEdit->setReadOnly(false);
    ui->lineEdit_TeL->setReadOnly(false);
    ui->lineEdit_WorkPlace->setReadOnly(false);
}

void lesseedata::setLineEditDisabled()
{
    //set read only
    ui->comboBoxGender->setEditable(false);
    ui->comboBoxGender->setEnabled(true);
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit_IdCardNo->setReadOnly(false);
    ui->lineEdit_ManNum->setReadOnly(false);
    ui->lineEdit_Name->setReadOnly(false);
    ui->lineEdit_Num->setReadOnly(false);
    ui->textEdit->setReadOnly(false);
    ui->lineEdit_TeL->setReadOnly(false);
    ui->lineEdit_WorkPlace->setReadOnly(false);

}

void lesseedata::setLesseeInformation(int index)
{

    //index
    currentIndex_le=index;

    index=index-1;//lessee no.

    //set lessee information
    ui->lineEdit_IdCardNo->setText(li[index].idCard);
    ui->lineEdit_ManNum->setText(QString::number(li[index].number));
    ui->lineEdit_Name->setText(li[index].customerName);
    ui->lineEdit_Num->setText(QString::number(li[index].customerId));
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //ui->lineEdit_Remakr->setText(li[index].remark);
    ui->lineEdit_TeL->setText(li[index].phoneNumber);
    ui->lineEdit_WorkPlace->setText(li[index].nativePlace);

}

void lesseedata::setLesseeInfoNone()
{
    //set lessee information
    ui->lineEdit_IdCardNo->setText(NULL);
    ui->lineEdit_ManNum->setText(NULL);
    ui->lineEdit_Name->setText(NULL);
    ui->lineEdit_Num->setText(NULL);
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //ui->lineEdit_Remakr->setText(NULL);
    ui->lineEdit_TeL->setText(NULL);
    ui->lineEdit_WorkPlace->setText(NULL);
    ui->comboBoxGender->setCurrentIndex(0);

    setLineEditDisabled();
}

void lesseedata::getLesseeInfo(int index)
{
    li[index].customerId=ui->lineEdit_Num->text().toInt();
    li[index].customerName=ui->lineEdit_Name->text();
    li[index].nativePlace=ui->lineEdit_WorkPlace->text();
    li[index].phoneNumber=ui->lineEdit_TeL->text();



    //D:\Qt\MyQt\house\le_connectdatabase.h:152: error: multiple definition of `temp'
    li[index].idCard=ui->lineEdit_IdCardNo->text();
    li[index].number=ui->lineEdit_ManNum->text().toInt();



    //D:\Qt\MyQt\house\le_connectdatabase.h:152: error: multiple definition of `temp'
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //li[index].remark=ui->lineEdit_Remakr->text();
    //qDebug()<<ri[maxIndex].roomId<<ri[maxIndex].roomType<<ri[maxIndex].floor;
}

//##############################################################################################//

lesseedata::lesseedata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lesseedata)
{
    ui->setupUi(this);

    ui->btnDelte->setEnabled(false);
    //result number
    queryLesseeNumber(&maxIndex_le);
    ui->lineEdit->clear();
    ui->lineEdit->setText(QString::number(maxIndex_le));

    //set read only
    setLineEditDisabled();

    //get all lessee informations
    queryLesseeInfo(li);
}

lesseedata::~lesseedata()
{
    delete ui;
}

//##############################################################################################//

void lesseedata::on_pushButton_Close_clicked()
{
    //关闭
    this->close();
}

void lesseedata::on_btnAdd_clicked()
{
    //添加
    operateNum_le = 1;
    ui->btnSave->setEnabled(true);
    ui->btnCanel->setEnabled(true);

    ui->btnAdd->setEnabled(false);
    ui->btnChange->setEnabled(false);
    ui->btnDelte->setEnabled(false);

    setLesseeInfoNone();
    setLineEditEnabled();

    ui->comboBoxGender->setCurrentIndex(0);
    ui->comboBoxGender->setEnabled(false);
}

void lesseedata::on_btnChange_clicked()
{
    //修改
    operateNum_le = 2;
    ui->btnSave->setEnabled(true);
    ui->btnCanel->setEnabled(true);

    ui->btnAdd->setEnabled(false);
    ui->btnChange->setEnabled(false);
    ui->btnDelte->setEnabled(false);

    setLineEditEnabled();

    ui->lineEdit_Num->setEnabled(false);
    ui->comboBoxGender->setEnabled(false);
}

void lesseedata::on_btnDelte_clicked()
{
    //删除
    //QMessageBox
    if(16384 == QMessageBox::question(NULL,"question","are you sure?",
                                      QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes) ) {
        //msgbox
        //16384 == yes,65536 == no
        //delete in db
        if(deleteLesseeInfo(li[currentIndex_le - 1])) {
            QMessageBox::about(NULL,"tips","delete complete");
            //shuzu xiangguan yidong
            deleteOneLesseeInfo(li,currentIndex_le,&maxIndex_le);

            //ui->lineEditCount->setText(QString::number(maxIndex));
            //queryRoomInfo(ri);
        }
        else {
            //delete error
            QMessageBox::about(NULL,"tips","delete error");
        }
    }
}





//￥￥￥￥￥￥￥￥
void lesseedata::on_btnSave_clicked()
{
    //保存
    bool status = 1;
    //some db operate
    switch (operateNum_le) {
    case 2:
        //修改
        getLesseeInfo(currentIndex_le-1);
        status = updateLesseeInfo(li[currentIndex_le-1]);
        break;
    case 1:
        //添加
        getLesseeInfo(maxIndex_le);
        status = insertLesseeInfo(li[maxIndex_le],&maxIndex_le);
        ui->lineEdit->setText(QString::number(maxIndex_le));
        //msgbox
        break;
    default:
        break;
    }
    if (status)
        QMessageBox::about(this,tr("tips"),tr("save success"));
    else
        QMessageBox::about(this,tr("tips"),tr("some error occur"));
    ui->btnCanel->setEnabled(false);
    ui->btnSave->setEnabled(false);

    ui->btnAdd->setEnabled(true);
    ui->btnChange->setEnabled(true);
    ui->btnDelte->setEnabled(true);

    setLineEditDisabled();
    ui->lineEdit_Num->setEnabled(true);
    operateNum_le = 0;
}





void lesseedata::on_btnCanel_clicked()
{
    //取消
    ui->btnCanel->setEnabled(false);
    ui->btnSave->setEnabled(false);

    ui->btnAdd->setEnabled(true);
    ui->btnChange->setEnabled(true);
    ui->btnDelte->setEnabled(true);

    setLineEditDisabled();
    ui->lineEdit_Num->setEnabled(true);
}

void lesseedata::on_btnFirst_clicked()
{
    //第一条
    setLesseeInformation(1);
    currentIndex_le = 1;
    ui->btnDelte->setEnabled(true);
}

void lesseedata::on_btnBefore_clicked()
{
    //前一条
    ui->btnDelte->setEnabled(true);
    if (currentIndex_le <= 1) {
        QMessageBox::about(this,tr("tips"),tr("already the first one"));
    }
    else {
        currentIndex_le = currentIndex_le - 1;
        setLesseeInformation(currentIndex_le);
    }
}

void lesseedata::on_btnLate_clicked()
{
    //后一条
    ui->btnDelte->setEnabled(true);
    if (currentIndex_le >= maxIndex_le) {
        QMessageBox::about(this,tr("tips"),tr("already the last one"));
    }
    else {
        currentIndex_le = currentIndex_le + 1;
        setLesseeInformation(currentIndex_le);
    }
}

void lesseedata::on_btnLast_clicked()
{
    //最后一条
    ui->btnDelte->setEnabled(true);
    setLesseeInformation(maxIndex_le);
    currentIndex_le = maxIndex_le;
}



//￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥
void lesseedata::on_btnCheck_clicked()
{
    //查找
    if (!searchStatus_le) {
        setLineEditDisabled();
        setLesseeInfoNone();
        ui->lineEdit_Num->setReadOnly(false);
        searchStatus_le = true;
        QMessageBox::about(NULL,"tips","please input customerId");
        //text
    }
    else {
        int customerId;
        customerId=ui->lineEdit_Num->text().toInt();
        //qDebug()<<zuhuId;
        //connect db and search

        if (searchLesseeInfo(customerId)) {
            //show lessee info

            //set lessee information
            ui->lineEdit_IdCardNo->setText(temp_le.idCard);
            ui->lineEdit_ManNum->setText(QString::number(temp_le.number));
            ui->lineEdit_Name->setText(temp_le.customerName);
            ui->lineEdit_Num->setText(QString::number(temp_le.customerId));


            //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            //ui->lineEdit_Remakr->setText(temp_le.remark);
            ui->lineEdit_TeL->setText(temp_le.phoneNumber);
            ui->lineEdit_WorkPlace->setText(temp_le.nativePlace);


            //some no result ==> msgbox
            //setLesseeInformation(currentIndex);
            ui->lineEdit_Num->setReadOnly(true);
            setLineEditDisabled();
            searchStatus_le = false;

            QMessageBox::about(NULL,"tips","search over,info are below");
        }
        else {
            QMessageBox::about(NULL,"tips","search over,info not found");
        }
    }
}

