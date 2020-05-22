#include "ctrlflowdiagram.h"
#include "ui_ctrlflowdiagram.h"

CtrlFlowDiagram::CtrlFlowDiagram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlFlowDiagram)
{
    ui->setupUi(this);
}

CtrlFlowDiagram::~CtrlFlowDiagram()
{
    delete ui;
}
void CtrlFlowDiagram::setCtrlValueRect(int value)
{
    if(value > 300)
        value = 300;
    ui->LBLValueRect->setGeometry(21,40,ui->LBLValueRect->width(),120-(float)value*120/300);
    ui->LBLValue->setText(QString::number(value));
}
