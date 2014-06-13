#include "replay.h"
#include "ui_replay.h"

replay::replay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::replay)
{
    ui->setupUi(this);
}

replay::~replay()
{
    delete ui;
}
