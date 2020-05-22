#include "main_light.h"
#include "ui_main_light.h"

Main_Light::Main_Light(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Light)
{
    ui->setupUi(this);
    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));
}

Main_Light::~Main_Light()
{
    delete ui;
}

void Main_Light::on_PB_testActive_pressed()
{
    ui->PB_testActive->setStyleSheet(MAINBUTTONDOWN);
    ui->PB_testActive->setEnabled(false);
    qTimer->start(2000);
}


void Main_Light::timeoutEvent()
{
    ui->PB_testActive->setStyleSheet(MAINBUTTONUP);
    ui->PB_testActive->setEnabled(true);
}
