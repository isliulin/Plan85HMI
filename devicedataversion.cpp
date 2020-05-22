#include "devicedataversion.h"
#include "ui_devicedataversion.h"

DeviceDataVersion::DeviceDataVersion(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataVersion)
{
    ui->setupUi(this);
}

DeviceDataVersion::~DeviceDataVersion()
{
    delete ui;
}
