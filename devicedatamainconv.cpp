#include "devicedatamainconv.h"
#include "ui_devicedatamainconv.h"

DeviceDataMainConv::DeviceDataMainConv(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataMainConv)
{
    ui->setupUi(this);
}

DeviceDataMainConv::~DeviceDataMainConv()
{
    delete ui;
}
