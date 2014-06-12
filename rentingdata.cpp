#include "rentingdata.h"
#include "ui_rentingdata.h"

rentingdata::rentingdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentingdata)
{
    ui->setupUi(this);
}

rentingdata::~rentingdata()
{
    delete ui;
}

void rentingdata::on_btnClose_clicked()
{
    this->close();
}
