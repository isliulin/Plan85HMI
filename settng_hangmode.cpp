#include "settng_hangmode.h"
#include "ui_settng_hangmode.h"

Settng_HangMode::Settng_HangMode(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_HangMode)
{
    ui->setupUi(this);
}

Settng_HangMode::~Settng_HangMode()
{
    delete ui;
}
