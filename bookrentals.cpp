#include "bookrentals.h"
#include "ui_bookrentals.h"
#include "QDate"

bookRentals::bookRentals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookRentals)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

bookRentals::~bookRentals()
{
    delete ui;
}

void bookRentals::on_btnClose_clicked()
{
    this->close();
}
