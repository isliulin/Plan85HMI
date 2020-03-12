#include "settng_traincode.h"
#include "ui_settng_traincode.h"

Settng_TrainCode::Settng_TrainCode(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_TrainCode)
{
    ui->setupUi(this);
}

Settng_TrainCode::~Settng_TrainCode()
{
    delete ui;
}
