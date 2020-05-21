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
    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));
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

void Main_Wheel::on_PB_store_pressed()
{
    ui->PB_store->setStyleSheet(MAINBUTTONDOWN);
}


void Main_Wheel::timeoutEvent()
{
    ui->PB_store->setStyleSheet(MAINBUTTONUP);
}
