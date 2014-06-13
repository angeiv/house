#include "housesatisfaction.h"
#include "ui_housesatisfaction.h"

housesatisfaction::housesatisfaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::housesatisfaction)
{
    ui->setupUi(this);
}

housesatisfaction::~housesatisfaction()
{
    delete ui;
}
