#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "housedata.h"
#include "bookrentals.h"
#include "replay.h"
//#include "customer.h"
#include "housesatisfaction.h"
#include "tongji.h"
#include "contract.h"
#include "lessee.h"
#include "sentwindow.h"
#include "lesseedata.h"
#include"rentingdata.h"
#include "qdesktopwidget.h"
#include "qdatetime.h"
#include "qtimer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //add time
    labelText = new QLabel();
    this->ui->statusBar->addPermanentWidget(labelText);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
            timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnExit_clicked()
{
    this->close();
}

void MainWindow::on_btnHouseData_clicked()
{
    housedata *hd = new housedata();
    hd->show();
}

void MainWindow::on_btnExit_2_clicked()
{
    this->close();
}

void MainWindow::on_btnExit_3_clicked()
{
    this->close();
}

void MainWindow::on_btnExit_4_clicked()
{
    this->close();
}

void MainWindow::on_btnExit_5_clicked()
{
    this->close();
}

void MainWindow::timerUpDate()
{
    QDateTime time = QDateTime::currentDateTime();

    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");

    labelText->setText(str);
}

void MainWindow::on_btnBookRentals_clicked()
{
    bookRentals *br = new bookRentals();
    br->show();
}

void MainWindow::on_btnReplay_clicked()
{
    replay *rp = new replay();
    rp->show();
}

void MainWindow::on_btnUser_clicked()
{
    rentingdata *cs = new rentingdata();
    cs->show();
}

void MainWindow::on_btnHouse_clicked()
{
    housesatisfaction *hf = new housesatisfaction();
    hf->show();
}

void MainWindow::on_btnRent_clicked()
{
    tongji *tj = new tongji();
    tj->show();
}

void MainWindow::on_btnContract_clicked()
{
    contract *ct = new contract();
    ct->show();
}

void MainWindow::on_btnLessee_2_clicked()
{
    lessee *le = new lessee();
    le->show();
}

void MainWindow::on_btnUserInfo_clicked()
{
    sentwindow *sw = new sentwindow();
    sw->show();
}

void MainWindow::on_btnLessee_clicked()
{
    lesseedata *ld = new lesseedata();
    ld->show();
}
