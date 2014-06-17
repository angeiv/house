#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qlabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnExit_clicked();

    void on_btnHouseData_clicked();

    void on_btnExit_2_clicked();

    void on_btnExit_3_clicked();

    void on_btnExit_4_clicked();

    void on_btnExit_5_clicked();

    void timerUpDate();

    void on_btnBookRentals_clicked();

    void on_btnReplay_clicked();

    void on_btnUser_clicked();

    void on_btnHouse_clicked();

    void on_btnRent_clicked();

    void on_btnContract_clicked();

    void on_btnLessee_2_clicked();

    void on_btnUserInfo_clicked();

    void on_btnLessee_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *labelText;

};

#endif // MAINWINDOW_H
