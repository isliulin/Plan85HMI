#include "main_wheel.h"
#include "ui_main_wheel.h"

QString Main_Wheel::wheelNumber="";

Main_Wheel::Main_Wheel(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Wheel)
{
    ui->setupUi(this);
    ctrlNumberTable=new CtrlNumberTable(this);
    ctrlNumberTable->setGeometry(430,230,this->width(),this->height());
}

Main_Wheel::~Main_Wheel()
{
    delete ui;
}

void Main_Wheel::updatePage()
{
    wheelNumber=ctrlNumberTable->getNumber();
    ui->lbl_input_value->setText(wheelNumber);
}
