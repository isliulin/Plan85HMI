#include "settng_lubrication.h"
#include "ui_settng_lubrication.h"

Settng_Lubrication::Settng_Lubrication(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Lubrication)
{
    ui->setupUi(this);
}

Settng_Lubrication::~Settng_Lubrication()
{
    delete ui;
}
