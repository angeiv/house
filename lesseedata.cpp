#include "lesseedata.h"
#include "ui_lesseedata.h"
#include "le_connectdatabase.h"
#include "lesseeInfo.h"
#include <QMessageBox>//add message box

int currentIndex=0;//当前查询的位置
int maxIndex=0;//查询的最大结果
bool searchStatus = false;//search status
int operateNum=0;//which operate,add,alter

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
    ui->lineEdit_Remakr->setReadOnly(false);
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
    ui->lineEdit_Remakr->setReadOnly(false);
    ui->lineEdit_TeL->setReadOnly(false);
    ui->lineEdit_WorkPlace->setReadOnly(false);

}

void lesseedata::setLesseeInformation(int index)
{

    //index
    currentIndex=index;

    index=index-1;//lessee no.

    //set lessee information
    ui->lineEdit_IdCardNo->setText(QString::number(li[index].Idcard));
    ui->lineEdit_ManNum->setText(QString::number(li[index].toll));
    ui->lineEdit_Name->setText(li[index].zuhuname);
    ui->lineEdit_Num->setText(QString::number(li[index].zuhuId));
    ui->lineEdit_Remakr->setText(li[index].remark);
    ui->lineEdit_TeL->setText(QString::number(li[index].telephone));
    ui->lineEdit_WorkPlace->setText(li[index].worklocation);

}

void lesseedata::setLesseeInfoNone()
{
    //set room information
    ui->lineEdit_IdCardNo->setText(NULL);
    ui->lineEdit_ManNum->setText(NULL);
    ui->lineEdit_Name->setText(NULL);
    ui->lineEdit_Num->setText(NULL);
    ui->lineEdit_Remakr->setText(NULL);
    ui->lineEdit_TeL->setText(NULL);
    ui->lineEdit_WorkPlace->setText(NULL);
    ui->comboBoxGender->setCurrentIndex(0);

    setLineEditDisabled();
}

void lesseedata::getLesseeInfo(int index)
{
    li[index].zuhuId=ui->lineEdit_Num->text().toInt();
    li[index].zuhuname=ui->lineEdit_Name->text();
    li[index].worklocation=ui->lineEdit_WorkPlace->text();
    li[index].telephone=ui->lineEdit_TeL->text().toInt();
    li[index].Idcard=ui->lineEdit_IdCardNo->text.toInt();
    li[index].toll=ui->lineEdit_ManNum->text().toInt();
    li[index].remark=ui->lineEdit_Remakr->toPlainText();
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
    queryLesseeNumber(&maxIndex);
    ui->lineEdit->clear();
    ui->lineEdit->setText(QString::number(maxIndex));

    //set read only
    setLineEditDisabled();

    //get all lessee informations
    queryRoomInfo(li);
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
    operateNum = 1;
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
    operateNum = 2;
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
        if(deleteLesseeInfo(ri[currentIndex - 1])) {
            QMessageBox::about(NULL,"tips","delete complete");
            //shuzu xiangguan yidong
            deleteOneLesseeInfo(li,currentIndex,&maxIndex);

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
    switch (operateNum) {
    case 2:
        //修改
        getLesseeInfo(currentIndex-1);
        status = updateLesseeInfo(li[currentIndex-1]);
        break;
    case 1:
        //添加
        getLesseeInfo(maxIndex);
        status = insertLesseeInfo(li[maxIndex],&maxIndex);
        ui->lineEdit->setText(QString::number(maxIndex));
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
    operateNum = 0;
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
    currentIndex = 1;
    ui->btnDelte->setEnabled(true);
}

void lesseedata::on_btnBefore_clicked()
{
    //前一条
    ui->btnDelte->setEnabled(true);
    if (currentIndex <= 1) {
        QMessageBox::about(this,tr("tips"),tr("already the first one"));
    }
    else {
        currentIndex = currentIndex - 1;
        setLesseeInformation(currentIndex);
    }
}

void lesseedata::on_btnLate_clicked()
{
    //后一条
    ui->btnDelte->setEnabled(true);
    if (currentIndex >= maxIndex) {
        QMessageBox::about(this,tr("tips"),tr("already the last one"));
    }
    else {
        currentIndex = currentIndex + 1;
        setLesseeInformation(currentIndex);
    }
}

void lesseedata::on_btnLast_clicked()
{
    //最后一条
    ui->btnDelte->setEnabled(true);
    setLesseeInformation(maxIndex);
    currentIndex = maxIndex;
}



//￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥
void lesseedata::on_btnCheck_clicked()
{
    //查找
    if (!searchStatus) {
        setLineEditDisabled();
        setLesseeInfoNone();
        ui->lineEdit_Num->setReadOnly(false);
        searchStatus = true;
        QMessageBox::about(NULL,"tips","please input zuhuID");
        //text
    }
    else {
        int zuhuId;
        roomId=ui->lineEdit_Num->text().toInt();
        //qDebug()<<zuhuId;
        //connect db and search

        if (searchLesseeInfo(zuhuId)) {
            //show lessee info

            //set lessee information
            ui->lineEdit_IdCardNo->setText(QString::number(temp.Idcard));
            ui->lineEdit_ManNum->setText(QString::number(temp.toll));
            ui->lineEdit_Name->setText(temp.zuhuname);
            ui->lineEdit_Num->setText(QString::number(temp.zuhuId));
            ui->lineEdit_Remakr->setText(temp.remark);
            ui->lineEdit_TeL->setText(QString::number(temp.telephone));
            ui->lineEdit_WorkPlace->setText(temp.worklocation);


            //some no result ==> msgbox
            //setLesseeInformation(currentIndex);
            ui->lineEdit_Num->setReadOnly(true);
            setLineEditDisabled();
            searchStatus = false;

            QMessageBox::about(NULL,"tips","search over,info are below");
        }
        else {
            QMessageBox::about(NULL,"tips","search over,info not found");
        }
    }
}

