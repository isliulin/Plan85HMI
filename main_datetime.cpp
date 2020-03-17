#include "main_datetime.h"
#include "ui_main_datetime.h"

Main_Datetime::Main_Datetime(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Datetime)
{
    ui->setupUi(this);
}

Main_Datetime::~Main_Datetime()
{
    delete ui;
}
