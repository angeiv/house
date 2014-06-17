#ifndef DEPOIST_H
#define DEPOIST_H

#include <QDialog>
#include <QSqlTableModel>
namespace Ui {
class Depoist;
}

class Depoist : public QDialog
{
    Q_OBJECT

public:
    explicit Depoist(QWidget *parent = 0);
    ~Depoist();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButton_updata_clicked();

    void on_pushButton_rollback_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_search2_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::Depoist *ui;
    QSqlTableModel *model;
};

#endif // DEPOIST_H
