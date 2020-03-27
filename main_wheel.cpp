#include "main_wheel.h"
#include "ui_main_wheel.h"

Main_Wheel::Main_Wheel(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Wheel)
{
    ui->setupUi(this);
}

Main_Wheel::~Main_Wheel()
{
    delete ui;
}
