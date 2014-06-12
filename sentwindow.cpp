#include "sentwindow.h"
#include "ui_sentwindow.h"

sentwindow::sentwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sentwindow)
{
    ui->setupUi(this);
}

sentwindow::~sentwindow()
{
    delete ui;
}
