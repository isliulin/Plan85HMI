#include "main_light.h"
#include "ui_main_light.h"

Main_Light::Main_Light(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Light)
{
    ui->setupUi(this);
}

Main_Light::~Main_Light()
{
    delete ui;
}
