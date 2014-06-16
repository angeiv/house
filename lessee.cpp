#include "lessee.h"
#include "ui_lessee.h"
#include <QTableWidget>
#include "lesseesa_conn.h"


int lesseeNumber = 0;

void lessee::setLesseeInformation()
{
    LesseeNumber(&lesseeNumber);
    queryLessee_Info(le);
    ui->tableWidget->setRowCount(lesseeNumber);
    int num = 0;
    while(num < lesseeNumber) {
        ui->tableWidget->setItem(num,0,new QTableWidgetItem(QString::number(le[num].customerId)));
        ui->tableWidget->setItem(num,1,new QTableWidgetItem(le[num].customerName));
        ui->tableWidget->setItem(num,2,new QTableWidgetItem(le[num].nativePlace));
        ui->tableWidget->setItem(num,3,new QTableWidgetItem(le[num].phoneNumber));
        ui->tableWidget->setItem(num,4,new QTableWidgetItem(le[num].idCard));
        num++;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能对表格内容进行修改
}

lessee::lessee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lessee)
{
    ui->setupUi(this);
    setLesseeInformation();
}

lessee::~lessee()
{
    delete ui;
}
