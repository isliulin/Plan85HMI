#include "ctrcontrolvoltage_unity.h"
#include "ui_ctrcontrolvoltage_unity.h"

CtrControlVoltage_Unity::CtrControlVoltage_Unity(QWidget *parent, int yellow1, int yellow2, int red1, int red2) :
    QWidget(parent),
    m_yellowline1(yellow1),
    m_yellowline2(yellow2),
    m_redline1(red1),
    m_redline2(red2),
    ui(new Ui::CtrControlVoltage_Unity)
{
    ui->setupUi(this);
}

CtrControlVoltage_Unity::~CtrControlVoltage_Unity()
{
    delete ui;
}
void CtrControlVoltage_Unity::setCtrlValueRect(int value1,int value2)
{
    int tvalue1 = value1/2;
    int tvalue2 = value2/2;
    if(tvalue1 > 65)
        tvalue1 = 65;
    if(tvalue2 > 65)
        tvalue2 = 65;

    ui->LBLValueRect->setGeometry(51,41,ui->LBLValueRect->width(),160-(float)tvalue1*160/65);
    ui->LBLValue->setText(QString::number(value1));

    ui->LBLValueRect2->setGeometry(106,41,ui->LBLValueRect2->width(),160-(float)tvalue2*160/65);
    ui->LBLValue2->setText(QString::number(value2));
}
