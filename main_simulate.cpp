#include "main_simulate.h"
#include "ui_main_simulate.h"
#include "qdebug.h"

Main_Simulate::Main_Simulate(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Simulate)
{
    ui->setupUi(this);
}

Main_Simulate::~Main_Simulate()
{
    delete ui;
}


void Main_Simulate::updatePage()
{
    //qDebug()<<"this is simulate";
}
