#include "repaymanagement.h"

#include "ui_repaymanagement.h"
#
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QString>
#include "connect_repay.h"
Repaymanagement::Repaymanagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Repaymanagement)
{
    ui->setupUi(this);
    connectiondatabase1( );
    model =new QSqlTableModel(this);
    model->setTable("repay");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
}

Repaymanagement::~Repaymanagement()
{
    delete ui;
}

void Repaymanagement::on_pushButtonupdata_clicked()
{
    model->database().transaction();
    if(model->submitAll()){
        model->database().commit();
    }
    else {
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),tr("数据库错误：1").arg(model->lastError().text()));
    }
}

void Repaymanagement::on_pushButton_rollback_clicked()
{
     model->revertAll();
}

void Repaymanagement::on_pushButton_delete_clicked()
{
    int curRow =ui->tableView->currentIndex().row();
    model->removeRow(curRow);
    int ok=QMessageBox::warning(this,tr("删除当前行"),tr("你确定删除当前行么？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll();
    }
    else model->submitAll();
}

void Repaymanagement::on_pushButton_return_clicked()
{

}

void Repaymanagement::on_pushButton_search2_clicked()
{
    model->setTable("repay");
    model->select();
}

void Repaymanagement::on_pushButton_search_clicked()
{
    QString name =ui->lineEdit->text();
    model->setFilter(QObject::tr("roomId = '%1'").arg(name));
    model->select();
}
