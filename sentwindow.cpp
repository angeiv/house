#include "sentwindow.h"
#include "ui_sentwindow.h"
//#include "wantedinfo.h"
//#include "connect_wanted.h"
#include "wantedsati.h"
int maxIndex_3=0;
sentwindow::sentwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sentwindow)
{
    ui->setupUi(this);
    setWantedInformation();
}

sentwindow::~sentwindow()
{
    delete ui;
}
void sentwindow::setWantedInformation()
{
    WantedNumber(&maxIndex_3);
    WantedInfo(t);
    ui->tableWidget->setRowCount(maxIndex_3);
    int num = 0;
    while(num < maxIndex_3) {
        ui->tableWidget->setItem(num,0,new QTableWidgetItem(QString::number(t[num].customerId)));
        ui->tableWidget->setItem(num,1,new QTableWidgetItem(t[num].customerName));
        ui->tableWidget->setItem(num,3,new QTableWidgetItem(t[num].phoneNumber));
        ui->tableWidget->setItem(num,4,new QTableWidgetItem(t[num].roomType));
        ui->tableWidget->setItem(num,5,new QTableWidgetItem(QString::number(t[num].area)));

        ui->tableWidget->setItem(num,6,new QTableWidgetItem(t[num].circumstance));
        ui->tableWidget->setItem(num,7,new QTableWidgetItem(QString::number(t[num].price)));
        ui->tableWidget->setItem(num,8,new QTableWidgetItem(QString::number(t[num].roomId)));
        ui->tableWidget->setItem(num,9,new QTableWidgetItem(QString::number(t[num].sj)));
        ui->tableWidget->setItem(num,10,new QTableWidgetItem(t[num].remark));
        num++;
    }
}
