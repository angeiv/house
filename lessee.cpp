#include "lessee.h"
#include "ui_lessee.h"

lessee::lessee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lessee)
{
    ui->setupUi(this);
}

lessee::~lessee()
{
    delete ui;
}
