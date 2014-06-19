#ifndef SENTWINDOW_H
#define SENTWINDOW_H

#include <QDialog>

namespace Ui {
class sentwindow;
}

class sentwindow : public QDialog
{
    Q_OBJECT

public:
    explicit sentwindow(QWidget *parent = 0);
    ~sentwindow();

private:
    Ui::sentwindow *ui;
    void setWantedInformation();
};

#endif // SENTWINDOW_H
