#ifndef HOUSINGSTATISTICSREPORT_H
#define HOUSINGSTATISTICSREPORT_H

#include <QDialog>

namespace Ui {
class Housingstatisticsreport;
}

class Housingstatisticsreport : public QDialog
{
    Q_OBJECT

public:
    explicit Housingstatisticsreport(QWidget *parent = 0);
    ~Housingstatisticsreport();

private:
    Ui::Housingstatisticsreport *ui;
};

#endif // HOUSINGSTATISTICSREPORT_H
