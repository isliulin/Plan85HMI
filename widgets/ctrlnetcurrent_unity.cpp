#include "ctrlnetcurrent_unity.h"
#include "ui_ctrlnetcurrent_unity.h"

CtrlNetCurrent_Unity::CtrlNetCurrent_Unity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlNetCurrent_Unity)
{
    ui->setupUi(this);
}

CtrlNetCurrent_Unity::~CtrlNetCurrent_Unity()
{
    delete ui;
}
void CtrlNetCurrent_Unity::setCtrlValueRect(int value)
{
    if(value > 620)
        value = 620;
    ui->LBLValueRect->setGeometry(41,41,ui->LBLValueRect->width(),160-(float)value*160/620);
    ui->LBLValue->setText(QString::number(value));
}
