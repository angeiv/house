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

    void on_btnAdd_clicked();

    void on_btnAlter_clicked();

    void on_btnDelete_clicked();

    void on_btnSave_clicked();

    void on_btnSearch_clicked();

    void on_btnLast_clicked();

    void on_btnLatter_clicked();

    void on_btnFormer_clicked();

    void on_btnFirst_clicked();

    void on_btnExit_clicked();

    void on_btnOrder_clicked();

private:
    Ui::rentingdata *ui;
    void setLineEditEnabled();
    void setLineEditDisabled();
    void setWantedInformation(int);//set the no.x room info
    void setWantedInfoNone();//clear the info given
    void getWantedInfo(int);//get room info to struct
};

#endif // RENTINGDATA_H
