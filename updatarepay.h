#ifndef UPDATAREPAY_H
#define UPDATAREPAY_H

#include <QDialog>

namespace Ui {
class updatarepay;
}

class updatarepay : public QDialog
{
    Q_OBJECT

public:
    explicit updatarepay(QWidget *parent = 0);
    ~updatarepay();

private slots:
    void on_pushButton_clicked();

private:
    Ui::updatarepay *ui;
};

#endif // UPDATAREPAY_H
