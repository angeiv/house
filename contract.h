#ifndef CONTRACT_H
#define CONTRACT_H

#include <QDialog>

namespace Ui {
class contract;
}

class contract : public QDialog
{
    Q_OBJECT

public:
    explicit contract(QWidget *parent = 0);
    ~contract();

private slots:
    void on_btnClose_clicked();

    void on_btnConclud_clicked();

private:
    Ui::contract *ui;
    void setcontractInformation();
};

#endif // CONTRACT_H
