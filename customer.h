#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QWidget *parent = 0);
    ~Customer();

private slots:
    void on_btnAdd_clicked();

    void on_btnSearch_clicked();

    void on_btnAlter_clicked();

    void on_btnDelete_clicked();

    void on_btnClose_clicked();

    void on_btnSave_clicked();

    void on_btnExit_clicked();

    void on_btnFirst_clicked();

    void on_btnLast_clicked();

    void on_btnFormer_clicked();

    void on_btnLatter_clicked();

private:
    Ui::Customer *ui;
    void setLineEditEnabled();
    void setLineEditDisabled();
    void setCustomerInformation(int);//set the no.x room info
    void setCustomerInfoNone();//clear the info given
    void getCustomerInfo(int);//ge

};

#endif // CUSTOMER_H
