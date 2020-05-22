#include "devicedatasiv.h"
#include "ui_devicedatasiv.h"

DeviceDataSIV::DeviceDataSIV(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataSIV)
{
    ui->setupUi(this);
}

DeviceDataSIV::~DeviceDataSIV()
{
    delete ui;
}
