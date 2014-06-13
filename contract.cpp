#include "contract.h"
#include "ui_contract.h"

contract::contract(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contract)
{
    ui->setupUi(this);
}

contract::~contract()
{
    delete ui;
}
