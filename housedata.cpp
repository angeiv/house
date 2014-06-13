#include "housedata.h"
#include "ui_housedata.h"
#include "connectdatabase.h"
#include "roomInfo.h"

int currentIndex=0;//当前查询的位置
int maxIndex=0;//查询的最大结果

housedata::housedata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::housedata)
{
    roomInfo r1;
    ui->setupUi(this);
    ui->lineEditCount->setReadOnly(1);
    connectiondatabase();
    int count=0;
    queryHouseNumber(&count);
    ui->lineEditCount->clear();
    ui->lineEditCount->setText(QString::number(count));

}

housedata::~housedata()
{
    delete ui;
}

void housedata::on_btnExit_clicked()
{
    this->close();
}
