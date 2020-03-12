#include "settng_panto.h"
#include "ui_settng_panto.h"

Settng_Panto::Settng_Panto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Panto)
{
    ui->setupUi(this);
}

Settng_Panto::~Settng_Panto()
{
    delete ui;
}
