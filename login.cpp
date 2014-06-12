#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_btnExit_clicked()
{
    this->close();
}

void login::on_btnLogin_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->hide();
}
