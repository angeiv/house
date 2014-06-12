#ifndef RENTINFO_H
#define RENTINFO_H
#include <QDateTime>
struct rentInfo {
    int chargeNumber;
    QDate rentDate;
    int moneyShould;
    int moneyAlready;
    int arrearage;
    QString customerName;
}rentinfo[256];

#endif // RENTINFO_H
