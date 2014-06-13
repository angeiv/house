#ifndef HOUSESATISFACTION_H
#define HOUSESATISFACTION_H

#include <QDialog>

namespace Ui {
class housesatisfaction;
}

class housesatisfaction : public QDialog
{
    Q_OBJECT

public:
    explicit housesatisfaction(QWidget *parent = 0);
    ~housesatisfaction();

private:
    Ui::housesatisfaction *ui;

    void setHouseInformation();
    void setHouseYesInformation();//yi chu
    void setHouseNoInformation();//wei chu
};

#endif // HOUSESATISFACTION_H
