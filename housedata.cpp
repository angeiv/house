#include "housedata.h"
#include "ui_housedata.h"
#include "connectdatabase.h"
#include "roomInfo.h"
#include <QMessageBox>//add message box

int currentIndex=0;//当前查询的位置
int maxIndex=0;//查询的最大结果
bool searchStatus = false;//search status
int operateNum=0;//which operate,add,alter

void housedata::setLineEditEnabled()
{
    //set alter
    ui->comboBoxRenterId->setEditable(false);
    ui->comboBoxRenterId->setEnabled(true);
    ui->lineEditArea->setReadOnly(false);
    ui->lineEditCount->setReadOnly(false);
    ui->lineEditLocation->setReadOnly(false);
    ui->lineEditPrice->setReadOnly(false);
    ui->lineEditCircumstance->setReadOnly(false);
    ui->lineEditRealNum->setReadOnly(false);
    ui->lineEditRommType->setReadOnly(false);
    ui->lineEditRoomId->setReadOnly(false);
    ui->textEditRemark->setReadOnly(false);
}

void housedata::setLineEditDisabled()
{
    //set read only
    ui->comboBoxRenterId->setEditable(false);
    ui->comboBoxRenterId->setEnabled(false);
    ui->lineEditArea->setReadOnly(true);
    ui->lineEditCount->setReadOnly(true);
    ui->lineEditLocation->setReadOnly(true);
    ui->lineEditPrice->setReadOnly(true);
    ui->lineEditCircumstance->setReadOnly(true);
    ui->lineEditRealNum->setReadOnly(true);
    ui->lineEditRommType->setReadOnly(true);
    ui->lineEditRoomId->setReadOnly(true);
    ui->textEditRemark->setReadOnly(true);
}

void housedata::setRoomInformation(int index)
{
    //index
    currentIndex=index;

    index=index-1;//room no.

    //set room information
    ui->lineEditRoomId->setText(QString::number(ri[index].roomId));
    ui->lineEditLocation->setText(ri[index].location);
    ui->lineEditRommType->setText(ri[index].roomType);
    ui->lineEditArea->setText(QString::number(ri[index].area));
    ui->lineEditRealNum->setText(QString::number(ri[index].realNum));
    ui->lineEditCircumstance->setText(ri[index].circumstance);
    ui->lineEditPrice->setText(QString::number(ri[index].price));
    if (QString::number(ri[index].renterId).toInt())
        ui->comboBoxRenterId->setCurrentIndex(1);
    else
        ui->comboBoxRenterId->setCurrentIndex(0);
    ui->textEditRemark->setText(ri[index].remark);

}

void housedata::setRoomInfoNone()
{
    //set room information
    ui->lineEditRoomId->setText(NULL);
    ui->lineEditLocation->setText(NULL);
    ui->lineEditRommType->setText(NULL);
    ui->lineEditArea->setText(NULL);
    ui->lineEditRealNum->setText(NULL);
    ui->lineEditCircumstance->setText(NULL);
    ui->lineEditPrice->setText(NULL);
    ui->comboBoxRenterId->setCurrentIndex(0);
    ui->textEditRemark->setText(NULL);

    setLineEditDisabled();
}

void housedata::getRoomInfo(int index)
{
    ri[index].roomId=ui->lineEditRoomId->text().toInt();
    ri[index].location=ui->lineEditLocation->text();
    ri[index].roomType=ui->lineEditRommType->text();
    ri[index].area=ui->lineEditArea->text().toInt();
    ri[index].realNum=ui->lineEditRealNum->text().toInt();
    ri[index].circumstance=ui->lineEditCircumstance->text();
    ri[index].price=ui->lineEditPrice->text().toInt();
    ri[index].renterId=0;//new foom have no cunstomer
    ri[index].remark=ui->textEditRemark->toPlainText();
    //qDebug()<<ri[maxIndex].roomId<<ri[maxIndex].roomType<<ri[maxIndex].floor;
}

housedata::housedata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::housedata)
{
    ui->setupUi(this);

    ui->btnDelete->setEnabled(false);
    //result number
    queryHouseNumber(&maxIndex);
    ui->lineEditCount->clear();
    ui->lineEditCount->setText(QString::number(maxIndex));

    //set read only
    setLineEditDisabled();

    //get all room informations
    queryRoomInfo(ri);

}

housedata::~housedata()
{
    delete ui;
}

void housedata::on_btnExit_clicked()
{
    this->close();
}

//first room information
void housedata::on_btnFirst_clicked()
{
    setRoomInformation(1);
    currentIndex = 1;
    ui->btnDelete->setEnabled(true);
}

void housedata::on_btnAdd_clicked()
{
    operateNum = 1;
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);

    ui->btnAdd->setEnabled(false);
    ui->btnAlter->setEnabled(false);
    ui->btnDelete->setEnabled(false);

    setRoomInfoNone();
    setLineEditEnabled();

    ui->lineEditRoomId->setEnabled(false);

    ui->comboBoxRenterId->setCurrentIndex(0);
    ui->comboBoxRenterId->setEnabled(false);
}

void housedata::on_btnAlter_clicked()
{
    operateNum = 2;
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);

    ui->btnAdd->setEnabled(false);
    ui->btnAlter->setEnabled(false);
    ui->btnDelete->setEnabled(false);

    setLineEditEnabled();

    //can not edit roomid and customer
    ui->lineEditRoomId->setEnabled(false);
    ui->comboBoxRenterId->setEnabled(false);
}

void housedata::on_btnDelete_clicked()
{
    //QMessageBox
    if(16384 == QMessageBox::question(NULL,"问题","你确定？",
                                      QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes) ) {
        //msgbox
        //16384 == yes,65536 == no
        //delete in db
        if(deleteRoomInfo(ri[currentIndex - 1])) {
            QMessageBox::about(NULL,"提示","删除完毕！");
            //shuzu xiangguan yidong
            deleteOneRoomInfo(ri,currentIndex,&maxIndex);

            ui->lineEditCount->setText(QString::number(maxIndex));
            //queryRoomInfo(ri);
        }
        else {
            //delete error
            QMessageBox::about(NULL,"提示","删除出现异常！");
        }
    }
}

void housedata::on_btnClose_clicked()
{
    ui->btnClose->setEnabled(false);
    ui->btnSave->setEnabled(false);

    ui->btnAdd->setEnabled(true);
    ui->btnAlter->setEnabled(true);
    ui->btnDelete->setEnabled(true);

    setLineEditDisabled();
    ui->lineEditRoomId->setEnabled(true);
}

void housedata::on_btnSave_clicked()
{
    bool status = 1;
    //some db operate
    switch (operateNum) {
    case 2:
        //alter
        getRoomInfo(currentIndex-1);
        status = updateRoomInfo(ri[currentIndex-1]);
        break;
    case 1:
        //add
        getRoomInfo(maxIndex);
        status = insertRoomInfo(ri[maxIndex],&maxIndex);
        ui->lineEditCount->setText(QString::number(maxIndex));
        //set room id,maxindex has already +1
        ri[maxIndex-1].roomId=ri[maxIndex-2].roomId+1;
        ui->lineEditRoomId->setText(QString::number(ri[maxIndex-1].roomId));
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
    ui->lineEditRoomId->setEnabled(true);
    setLineEditDisabled();
    ui->lineEditRoomId->setEnabled(true);
    operateNum = 0;
}

void housedata::on_btnLatter_clicked()
{
    ui->btnDelete->setEnabled(true);
    if (currentIndex >= maxIndex) {
        QMessageBox::about(this,tr("提示"),tr("已经是最后一条了"));
    }
    else {
        currentIndex = currentIndex + 1;
        setRoomInformation(currentIndex);
    }
}

void housedata::on_btnLast_clicked()
{
    ui->btnDelete->setEnabled(true);
    setRoomInformation(maxIndex);
    currentIndex = maxIndex;
}

void housedata::on_btnFormer_clicked()
{
    ui->btnDelete->setEnabled(true);
    if (currentIndex <= 1) {
        QMessageBox::about(this,tr("提示"),tr("已经是第一条了"));
    }
    else {
        currentIndex = currentIndex - 1;
        setRoomInformation(currentIndex);
    }
}

void housedata::on_btnSearch_clicked()
{
    if (!searchStatus) {
        setLineEditDisabled();
        setRoomInfoNone();
        ui->lineEditRoomId->setReadOnly(false);
        searchStatus = true;
        //text
        QMessageBox::about(NULL,"提示","请输入房屋编号，再点击查找");
    }
    else {
        int roomId;
        roomId=ui->lineEditRoomId->text().toInt();
        //qDebug()<<roomId;
        //connect db and search
        if (searchRoomInfo(roomId)) {
            //show room info

            //set room information
            ui->lineEditRoomId->setText(QString::number(temp.roomId));
            ui->lineEditLocation->setText(temp.location);
            ui->lineEditRommType->setText(temp.roomType);
            ui->lineEditArea->setText(QString::number(temp.area));
            ui->lineEditRealNum->setText(QString::number(temp.realNum));
            ui->lineEditCircumstance->setText(temp.circumstance);
            ui->lineEditPrice->setText(QString::number(temp.price));
            if (QString::number(temp.renterId).toInt())
                ui->comboBoxRenterId->setCurrentIndex(1);
            else
                ui->comboBoxRenterId->setCurrentIndex(0);
            ui->textEditRemark->setText(temp.remark);

            //some no result ==> msgbox
            //setRoomInformation(currentIndex);
            ui->lineEditRoomId->setReadOnly(true);
            setLineEditDisabled();
            searchStatus = false;

            QMessageBox::about(NULL,"提示","查找完毕，结果如下");
        }
        else {
            QMessageBox::about(NULL,"提示","查找完毕，信息未找到");
        }
    }
}
