#include "housesatisfaction.h"
#include "ui_housesatisfaction.h"
#include <QTableWidget>
#include "housesa_conn.h"

int houseNumber = 0;

void housesatisfaction::setHouseInformation()
{
    HouseNumber(&houseNumber);
    queryHouseInfo(ho);
    ui->tableWidget->setRowCount(houseNumber);
    int num = 0;
    while(num < houseNumber) {
        ui->tableWidget->setItem(num,0,new QTableWidgetItem(QString::number(ho[num].roomId)));
        ui->tableWidget->setItem(num,1,new QTableWidgetItem(ho[num].roomType));
        ui->tableWidget->setItem(num,2,new QTableWidgetItem(ho[num].location));
        ui->tableWidget->setItem(num,3,new QTableWidgetItem(QString::number(ho[num].area)));
        ui->tableWidget->setItem(num,4,new QTableWidgetItem(QString::number(ho[num].realNum)));
        ui->tableWidget->setItem(num,5,new QTableWidgetItem(ho[num].circumstance));
        ui->tableWidget->setItem(num,6,new QTableWidgetItem(QString::number(ho[num].price)));
        ui->tableWidget->setItem(num,7,new QTableWidgetItem(ho[num].remark));
        num++;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能对表格内容进行修改
}

void housesatisfaction::setHouseYesInformation()
{
    int count = 0;
    int num = 0;
    while(num < houseNumber) {
        if(ho[num].renterId)
            count++;//yichu wangfu shumu
    num++;
    }
    ui->tableWidget_2->setRowCount(count);

    count = 0;
    num = 0;

    while(num < houseNumber) {
        if(ho[num].renterId) {
        ui->tableWidget_2->setItem(count,0,new QTableWidgetItem(QString::number(ho[num].roomId)));
        ui->tableWidget_2->setItem(count,1,new QTableWidgetItem(ho[num].roomType));
        ui->tableWidget_2->setItem(count,2,new QTableWidgetItem(ho[num].location));
        ui->tableWidget_2->setItem(count,3,new QTableWidgetItem(QString::number(ho[num].area)));
        ui->tableWidget_2->setItem(count,4,new QTableWidgetItem(QString::number(ho[num].realNum)));
        ui->tableWidget_2->setItem(count,5,new QTableWidgetItem(ho[num].circumstance));
        ui->tableWidget_2->setItem(count,6,new QTableWidgetItem(QString::number(ho[num].price)));
        ui->tableWidget_2->setItem(count,7,new QTableWidgetItem(ho[num].remark));
        count++;
        }
        num++;
    }
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能对表格内容进行修改
}

void housesatisfaction::setHouseNoInformation()
{
    int count = 0;
    int num = 0;
    while(num < houseNumber) {
        if(!ho[num].renterId )
            count++;//weichu wangfu shumu
    num++;
    }
    ui->tableWidget_3->setRowCount(count);

    count = 0;
    num = 0;

    while(num < houseNumber) {
        if(!ho[num].renterId) {
        ui->tableWidget_3->setItem(count,0,new QTableWidgetItem(QString::number(ho[num].roomId)));
        ui->tableWidget_3->setItem(count,1,new QTableWidgetItem(ho[num].roomType));
        ui->tableWidget_3->setItem(count,2,new QTableWidgetItem(ho[num].location));
        ui->tableWidget_3->setItem(count,3,new QTableWidgetItem(QString::number(ho[num].area)));
        ui->tableWidget_3->setItem(count,4,new QTableWidgetItem(QString::number(ho[num].realNum)));
        ui->tableWidget_3->setItem(count,5,new QTableWidgetItem(ho[num].circumstance));
        ui->tableWidget_3->setItem(count,6,new QTableWidgetItem(QString::number(ho[num].price)));
        ui->tableWidget_3->setItem(count,7,new QTableWidgetItem(ho[num].remark));
        count++;
        }
        num++;
    }
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能对表格内容进行修改
}

housesatisfaction::housesatisfaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::housesatisfaction)
{
    ui->setupUi(this);
    setHouseInformation();
    setHouseYesInformation();
    setHouseNoInformation();
}

housesatisfaction::~housesatisfaction()
{
    delete ui;
}
