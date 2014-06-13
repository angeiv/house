#ifndef TONGJI_H
#define TONGJI_H

#include <QDialog>

namespace Ui {
class tongji;
}

class tongji : public QDialog
{
    Q_OBJECT

public:
    explicit tongji(QWidget *parent = 0);
    ~tongji();

private:
    Ui::tongji *ui;
};

#endif // TONGJI_H
