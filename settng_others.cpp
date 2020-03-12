#include "settng_others.h"
#include "ui_settng_others.h"

Settng_Others::Settng_Others(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Others)
{
    ui->setupUi(this);
}

Settng_Others::~Settng_Others()
{
    delete ui;
}
