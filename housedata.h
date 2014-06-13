#ifndef HOUSEDATA_H
#define HOUSEDATA_H

#include <QDialog>

namespace Ui {
class housedata;
}

class housedata : public QDialog
{
    Q_OBJECT

public:
    explicit housedata(QWidget *parent = 0);
    ~housedata();

private slots:
    void on_btnExit_clicked();

private:
    Ui::housedata *ui;
};

#endif // HOUSEDATA_H
