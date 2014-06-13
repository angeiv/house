#include "tongji.h"
#include "ui_tongji.h"
#include "rentInfoQuery.h"
#include <QTableWidget>

tongji::tongji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tongji)
{
    ui->setupUi(this);

    int rentnum = 0;
    queryRentNumber(&rentnum);
    queryRentInfo(rentinfo);
    ui->tableWidget->setRowCount(rentnum);
    int num = 0;
    while(num < rentnum) {
        ui->tableWidget->setItem(num,0,new QTableWidgetItem(QString::number(rentinfo[num].chargeNumber)));
        int year,mon;
        year = rentinfo[num].rentDate.year();
        mon = rentinfo[num].rentDate.month();
        ui->tableWidget->setItem(num,1,new QTableWidgetItem(QString::number(year)));
        ui->tableWidget->setItem(num,2,new QTableWidgetItem(QString::number(mon)));
        ui->tableWidget->setItem(num,3,new QTableWidgetItem(QString::number(rentinfo[num].moneyShould)));
        ui->tableWidget->setItem(num,4,new QTableWidgetItem(QString::number(rentinfo[num].moneyAlready)));
        ui->tableWidget->setItem(num,5,new QTableWidgetItem(QString::number(rentinfo[num].arrearage)));
        ui->tableWidget->setItem(num,6,new QTableWidgetItem(rentinfo[num].customerName));
        num++;
    }
}

tongji::~tongji()
{
    delete ui;
}
