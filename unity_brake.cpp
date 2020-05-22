#include "unity_brake.h"
#include "ui_unity_brake.h"

Unity_Brake::Unity_Brake(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Unity_Brake)
{
    ui->setupUi(this);

    ctrlKpaDiagram1 = new CtrlKpaDiagram(this);
    ctrlKpaDiagram1 ->setGeometry(200,50,ctrlKpaDiagram1->width(),ctrlKpaDiagram1->height());

    ctrlKpaDiagram2 = new CtrlKpaDiagram(this);
    ctrlKpaDiagram2 ->setGeometry(500,50,ctrlKpaDiagram2->width(),ctrlKpaDiagram2->height());

    ctrlFlowDiagram = new CtrlFlowDiagram(this);
    ctrlFlowDiagram ->setGeometry(20,80,ctrlFlowDiagram->width(),ctrlFlowDiagram->height());
}

Unity_Brake::~Unity_Brake()
{
    delete ui;
}
void Unity_Brake::updatePage()
{

}

void Unity_Brake::showEvent(QShowEvent *event)
{

}
