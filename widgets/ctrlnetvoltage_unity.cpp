#include "ctrlnetvoltage_unity.h"
#include "ui_ctrlnetvoltage_unity.h"

CtrlNetVoltage_Unity::CtrlNetVoltage_Unity(QWidget *parent, int green1, int green2, int red1, int red2, int blue) :
    QWidget(parent),
    m_greenline1(green1),
    m_greenline2(green2),
    m_redline1(red1),
    m_redline2(red2),
    m_blueline(blue),
    ui(new Ui::CtrlNetVoltage_Unity)
{
    ui->setupUi(this);
}

CtrlNetVoltage_Unity::~CtrlNetVoltage_Unity()
{
    delete ui;
}
void CtrlNetVoltage_Unity::setCtrlValueRect(int value)
{
    if(value > 32)
        value = 32;
    ui->LBLValueRect->setGeometry(41,41,ui->LBLValueRect->width(),160-(float)value*5);
    ui->LBLValue->setText(QString::number(value));

}
