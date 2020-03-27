#include "maindata_driveroutline.h"
#include "ui_maindata_driveroutline.h"

MainData_DriverOutline::MainData_DriverOutline(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MainData_DriverOutline)
{
    ui->setupUi(this);
}

MainData_DriverOutline::~MainData_DriverOutline()
{
    delete ui;
}
