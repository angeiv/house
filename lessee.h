#ifndef LESSEE_H
#define LESSEE_H

#include <QDialog>

namespace Ui {
class lessee;
}

class lessee : public QDialog
{
    Q_OBJECT

public:
    explicit lessee(QWidget *parent = 0);
    ~lessee();

private:
    Ui::lessee *ui;
    void setLesseeInformation();
};

#endif // LESSEE_H
