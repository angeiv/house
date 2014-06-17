#include "depoist.h"
#include "ui_depoist.h"

#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QString>
#include "connect_depoist.h"
Depoist::Depoist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Depoist)
{
    ui->setupUi(this);
    connectiondatabase( );
    model =new QSqlTableModel(this);
    model->setTable("depoist");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
}

Depoist::~Depoist()
{
    delete ui;
}

void Depoist::on_pushButtonAdd_clicked()
{
    int rowNum =model->rowCount();
    int userno =10;
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),userno);
}

void Depoist::on_pushButton_updata_clicked()
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

void Depoist::on_pushButton_rollback_clicked()
{
    model->revertAll();
}

void Depoist::on_pushButton_delete_clicked()
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

void Depoist::on_pushButton_search2_clicked()
{
    model->setTable("depoist");
    model->select();
}

void Depoist::on_pushButton_search_clicked()
{
    QString name =ui->lineEdit->text();
    model->setFilter(QObject::tr("roomId = '%1'").arg(name));
    model->select();
}
