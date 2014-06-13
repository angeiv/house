#include "tongji.h"
#include "ui_tongji.h"

tongji::tongji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tongji)
{
    ui->setupUi(this);
}

tongji::~tongji()
{
    delete ui;
}
