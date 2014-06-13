#include "bookrentals.h"
#include "ui_bookrentals.h"

bookRentals::bookRentals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookRentals)
{
    ui->setupUi(this);
}

bookRentals::~bookRentals()
{
    delete ui;
}
