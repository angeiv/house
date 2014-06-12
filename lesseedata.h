#ifndef LESSEEDATA_H
#define LESSEEDATA_H

#include <QDialog>

namespace Ui {
class lesseedata;
}

class lesseedata : public QDialog
{
    Q_OBJECT

public:
    explicit lesseedata(QWidget *parent = 0);
    ~lesseedata();

private slots:
    void on_btnAdd_clicked();

    void on_btnChange_clicked();

    void on_btnDelte_clicked();

    void on_btnSave_clicked();

    void on_btnCanel_clicked();

    void on_btnFirst_clicked();

    void on_btnBefore_clicked();

    void on_btnLate_clicked();

    void on_btnLast_clicked();

    void on_btnCheck_clicked();

    void on_pushButton_Close_clicked();

private:
    Ui::lesseedata *ui;

    void setLineEditEnabled();
    void setLineEditDisabled();
    void setLesseeInformation(int);//set the no.x lessee info
    void setLesseeInfoNone();//clear the info given
    void getLesseeInfo(int);//get lessee info to struct
};

#endif // LESSEEDATA_H
