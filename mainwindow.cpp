#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "housedata.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
