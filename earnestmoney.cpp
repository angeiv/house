#include "earnestmoney.h"
#include "ui_earnestmoney.h"

earnestmoney::earnestmoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::earnestmoney)
{
    ui->setupUi(this);
}

earnestmoney::~earnestmoney()
{
    delete ui;
}
