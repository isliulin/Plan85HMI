#include "ctrltracbrake_unity.h"
#include "ui_ctrltracbrake_unity.h"

CtrlTracBrake_Unity::CtrlTracBrake_Unity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTracBrake_Unity)
{
    ui->setupUi(this);
}

CtrlTracBrake_Unity::~CtrlTracBrake_Unity()
{
    delete ui;
}
void CtrlTracBrake_Unity::setCtrlValueRect(int value, bool trac, bool brake)
{
    QString t_style;
    if(trac)
    {
        t_style = DARKBLUE;
    }else if(brake)
    {
        t_style = RED;
    }
    else
    {
        return;
    }
    ui->LBLBackground->setStyleSheet(t_style);

    if(value > 100)
        value = 100;
    ui->LBLValueRect->setGeometry(36,41,ui->LBLValueRect->width(),160-(float)value*160/100);
    ui->LBLValue->setText(QString::number(value));
}
