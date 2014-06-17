#ifndef REPAYMANAGEMENT_H
#define REPAYMANAGEMENT_H

#include <QDialog>
#include <QSqlTableModel>
namespace Ui {
class Repaymanagement;
}

class Repaymanagement : public QDialog
{
    Q_OBJECT

public:
    explicit Repaymanagement(QWidget *parent = 0);
    ~Repaymanagement();

private slots:
    void on_pushButtonupdata_clicked();

    void on_pushButton_rollback_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_search2_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::Repaymanagement *ui;
    QSqlTableModel *model;
};

#endif // REPAYMANAGEMENT_H
