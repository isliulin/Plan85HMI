#include "main_lubrication.h"
#include "ui_main_lubrication.h"

Main_Lubrication::Main_Lubrication(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Lubrication)
{
    ui->setupUi(this);
    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));
}

Main_Lubrication::~Main_Lubrication()
{
    delete ui;
}

void Main_Lubrication::on_PB_runningActive_pressed()
{
    ui->PB_runningActive->setStyleSheet(MAINBUTTONDOWN);
    qTimer->start(2000);
    ui->PB_cancel->setEnabled(false);
    ui->PB_runningActive->setEnabled(false);
}

void Main_Lubrication::on_PB_cancel_pressed()
{
    ui->PB_cancel->setStyleSheet(MAINBUTTONDOWN);
    ui->PB_cancel->setEnabled(false);
    ui->PB_runningActive->setEnabled(false);
    qTimer->start(2000);
}

void Main_Lubrication::timeoutEvent()
{
    ui->PB_cancel->setStyleSheet(MAINBUTTONUP);
    ui->PB_runningActive->setStyleSheet(MAINBUTTONUP);
    ui->PB_cancel->setEnabled(true);
    ui->PB_runningActive->setEnabled(true);
}


