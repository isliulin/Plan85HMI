#include "settng_separation.h"
#include "ui_settng_separation.h"

Settng_Separation::Settng_Separation(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Separation)
{
    ui->setupUi(this);
}

Settng_Separation::~Settng_Separation()
{
    delete ui;
}
