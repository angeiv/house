#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "userInfo.h"
#include "checkUser.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEditPwd->setEchoMode(QLineEdit::Password);
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
    if(ui->lineEditUser->text().isEmpty() || ui->lineEditPwd->text().isEmpty()) {
        QMessageBox::about(NULL,"提示","用户名或密码为空，请重试！");
        return ;
    }
    QString user,pwd;
    user = ui->lineEditUser->text();
    pwd = ui->lineEditPwd->text();

    checkUser(user);

    if((userinfo.pwd.compare(pwd)) == 0 ) {
    MainWindow *m = new MainWindow();
        m->show();
        this->hide();
    }
    else {
        QMessageBox::about(NULL,"提示","用户名或密码错误，请重试！");
        return ;
    }
}
