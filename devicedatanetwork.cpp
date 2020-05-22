#include "devicedatanetwork.h"
#include "ui_devicedatanetwork.h"

DeviceDataNetwork::DeviceDataNetwork(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataNetwork)
{
    ui->setupUi(this);
}

DeviceDataNetwork::~DeviceDataNetwork()
{
    delete ui;
}
