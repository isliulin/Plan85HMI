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
    qTimer=new  QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));
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

void Main_Separation::on_PB_send_pressed()
{
    ui->PB_send->setStyleSheet(MAINBUTTONDOWN);
    ui->PB_send->setEnabled(false);
    qTimer->start(2000);
}

void Main_Separation::on_PB_testActive_pressed()
{
    ui->PB_testActive->setStyleSheet(MAINBUTTONDOWN);
    ui->PB_testCancel->setStyleSheet(MAINBUTTONUP);
}

void Main_Separation::on_PB_testCancel_pressed()
{
    ui->PB_testActive->setStyleSheet(MAINBUTTONUP);
    ui->PB_testCancel->setStyleSheet(MAINBUTTONDOWN);
}

void Main_Separation::timeoutEvent()
{
    ui->PB_send->setStyleSheet(MAINBUTTONUP);
    ui->PB_send->setEnabled(true);
}
