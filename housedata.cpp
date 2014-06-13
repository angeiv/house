#include "housedata.h"
#include "ui_housedata.h"
#include "connectdatabase.h"
#include "roomInfo.h"
#include <QMessageBox>//add message box

int currentIndex=0;//当前查询的位置
int maxIndex=0;//查询的最大结果
bool searchStatus = false;//search status

void housedata::setLineEditEnabled()
{
    //set alter
    ui->comboBoxFloor->setEditable(false);
    ui->comboBoxFloor->setEnabled(true);
    ui->lineEditArea->setReadOnly(false);
    ui->lineEditCount->setReadOnly(false);
    ui->lineEditLocation->setReadOnly(false);
    ui->lineEditPrice->setReadOnly(false);
    ui->lineEditRatingNum->setReadOnly(false);
    ui->lineEditRealNum->setReadOnly(false);
    ui->lineEditRommType->setReadOnly(false);
    ui->lineEditRoomId->setReadOnly(false);
    ui->textEditRemark->setReadOnly(false);
}

void housedata::setLineEditDisabled()
{
    //set read only
    ui->comboBoxFloor->setEditable(false);
    ui->comboBoxFloor->setEnabled(false);
    ui->lineEditArea->setReadOnly(true);
    ui->lineEditCount->setReadOnly(true);
    ui->lineEditLocation->setReadOnly(true);
    ui->lineEditPrice->setReadOnly(true);
    ui->lineEditRatingNum->setReadOnly(true);
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
    ui->lineEditRatingNum->setText(ri[index].ratingNum);
    ui->lineEditPrice->setText(QString::number(ri[index].price));
    if(QString::number(ri[index].floor).toInt())
        ui->comboBoxFloor->setCurrentIndex(1);
    else
        ui->comboBoxFloor->setCurrentIndex(0);
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
    ui->lineEditRatingNum->setText(NULL);
    ui->lineEditPrice->setText(NULL);
        ui->comboBoxFloor->setCurrentIndex(0);
    ui->textEditRemark->setText(NULL);

    setLineEditDisabled();
}

housedata::housedata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::housedata)
{
    ui->setupUi(this);

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
}

void housedata::on_btnAdd_clicked()
{
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);

    setLineEditEnabled();
}

void housedata::on_btnAlter_clicked()
{
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);

    setLineEditEnabled();
}

void housedata::on_btnDelete_clicked()
{
    ui->btnSave->setEnabled(true);
    ui->btnClose->setEnabled(true);
}

void housedata::on_btnClose_clicked()
{
    ui->btnClose->setEnabled(false);
    ui->btnSave->setEnabled(false);

    setLineEditDisabled();
}

void housedata::on_btnSave_clicked()
{
        QMessageBox::about(this,tr("tips"),tr("save success"));

        ui->btnClose->setEnabled(false);
        ui->btnSave->setEnabled(false);

        setLineEditDisabled();
}

void housedata::on_btnLatter_clicked()
{
    if(currentIndex >= maxIndex)
        QMessageBox::about(this,tr("tips"),tr("already the last one"));
    else
    {
        currentIndex = currentIndex + 1;
        setRoomInformation(currentIndex);
    }
}

void housedata::on_btnLast_clicked()
{
    setRoomInformation(maxIndex);
    currentIndex = maxIndex;
}

void housedata::on_btnFormer_clicked()
{
    if(currentIndex <= 1)
        QMessageBox::about(this,tr("tips"),tr("already the first one"));
    else
    {
        currentIndex = currentIndex - 1;
        setRoomInformation(currentIndex);
    }
}

void housedata::on_btnSearch_clicked()
{
    if(!searchStatus)
    {
    setLineEditDisabled();
    setRoomInfoNone();
    ui->lineEditRoomId->setReadOnly(false);
    searchStatus = true;
    //text
    }
    else
    {
        QString roomId;
        roomId=ui->lineEditRoomId->text();
        qDebug()<<roomId;
        //connect db and search
        currentIndex = currentIndex;//index
        //show room info
        //some no result ==> msgbox
        //setRoomInformation(currentIndex);
        ui->lineEditRoomId->setReadOnly(true);
        setLineEditDisabled();
        searchStatus = false;
    }
}
