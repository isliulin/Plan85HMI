#include "devicedatabreaker.h"
#include "ui_devicedatabreaker.h"

DeviceDataBreaker::DeviceDataBreaker(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataBreaker)
{
    ui->setupUi(this);
}

DeviceDataBreaker::~DeviceDataBreaker()
{
    delete ui;
}
