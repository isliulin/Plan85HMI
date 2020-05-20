#include "main_separation.h"
#include "ui_main_separation.h"

QString Main_Separation::separationNumber="";

Main_Separation::Main_Separation(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Separation)
{
    ui->setupUi(this);
    ctrlNumberTable=new CtrlNumberTable(this);
    ctrlNumberTable->setGeometry(440,250,this->width(),this->height());
}

Main_Separation::~Main_Separation()
{
    delete ui;
}


void Main_Separation::updatePage()
{
    separationNumber=ctrlNumberTable->getNumber();
    ui->lbl_input_value->setText(separationNumber);
}
