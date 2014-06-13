#include "contract.h"
#include "ui_contract.h"

contract::contract(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contract)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

contract::~contract()
{
    delete ui;
}

void contract::on_btnClose_clicked()
{
    this->close();
}
