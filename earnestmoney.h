#ifndef EARNESTMONEY_H
#define EARNESTMONEY_H

#include <QDialog>

namespace Ui {
class earnestmoney;
}

class earnestmoney : public QDialog
{
    Q_OBJECT

public:
    explicit earnestmoney(QWidget *parent = 0);
    ~earnestmoney();

private:
    Ui::earnestmoney *ui;
};

#endif // EARNESTMONEY_H
