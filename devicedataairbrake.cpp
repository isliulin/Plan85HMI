#include "devicedataairbrake.h"
#include "ui_devicedataairbrake.h"

DeviceDataAirBrake::DeviceDataAirBrake(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataAirBrake)
{
    ui->setupUi(this);
}

DeviceDataAirBrake::~DeviceDataAirBrake()
{
    delete ui;
}
