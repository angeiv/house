#ifndef REPLAY_H
#define REPLAY_H

#include <QDialog>

namespace Ui {
class replay;
}

class replay : public QDialog
{
    Q_OBJECT

public:
    explicit replay(QWidget *parent = 0);
    ~replay();

private:
    Ui::replay *ui;
};

#endif // REPLAY_H
