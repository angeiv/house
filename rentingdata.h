#ifndef RENTINGDATA_H
#define RENTINGDATA_H

#include <QDialog>

namespace Ui {
class rentingdata;
}

class rentingdata : public QDialog
{
    Q_OBJECT

public:
    explicit rentingdata(QWidget *parent = 0);
    ~rentingdata();

private slots:
    void on_btnClose_clicked();

private:
    Ui::rentingdata *ui;
};

#endif // RENTINGDATA_H
