#include "housingstatisticsreport.h"
#include "ui_housingstatisticsreport.h"

Housingstatisticsreport::Housingstatisticsreport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Housingstatisticsreport)
{
    ui->setupUi(this);
}

Housingstatisticsreport::~Housingstatisticsreport()
{
    delete ui;
}
