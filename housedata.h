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

    void on_btnFirst_clicked();

    void on_btnAdd_clicked();

    void on_btnAlter_clicked();

    void on_btnDelete_clicked();

    void on_btnClose_clicked();

    void on_btnSave_clicked();

    void on_btnLatter_clicked();

    void on_btnLast_clicked();

    void on_btnFormer_clicked();

    void on_btnSearch_clicked();

private:
    Ui::housedata *ui;

    void setLineEditEnabled();
    void setLineEditDisabled();
    void setRoomInformation(int);//set the no.x room info
    void setRoomInfoNone();//clear the info given
    void getRoomInfo();//get room info to struct
};



#endif // HOUSEDATA_H
