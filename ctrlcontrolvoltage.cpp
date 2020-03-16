#include "ctrlcontrolvoltage.h"
#include "ui_ctrlcontrolvoltage.h"

CtrlControlVoltage::CtrlControlVoltage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlControlVoltage)
{
    ui->setupUi(this);
}

CtrlControlVoltage::~CtrlControlVoltage()
{
    delete ui;
}
