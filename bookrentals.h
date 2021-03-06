#ifndef BOOKRENTALS_H
#define BOOKRENTALS_H

#include <QDialog>

namespace Ui {
class bookRentals;
}

class bookRentals : public QDialog
{
    Q_OBJECT

public:
    explicit bookRentals(QWidget *parent = 0);
    ~bookRentals();

private slots:
    void on_btnClose_clicked();

    void on_btnBook_clicked();

private:
    Ui::bookRentals *ui;
};

#endif // BOOKRENTALS_H
