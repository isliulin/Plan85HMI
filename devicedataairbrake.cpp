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

void DeviceDataAirBrake::updatePage()
{
    this->udpateNames(ui->labelMainControl, false);
    this->bcuStates(ui->labelInputCut, this->database->data_BCU->B_BCU_STATE1, this->database->data_BCU->B_BCU_STATE2);
    this->brakeValue(ui->labelBP, this->database->data_BCU->N_BP_PRES);
    this->brakeValue(ui->labelMR, this->database->data_BCU->N_MR_PRES);
    this->brakeValue(ui->labelER, this->database->data_BCU->N_ER_PRES);
    this->brakeValue(ui->labelBC1, this->database->data_BCU->N_BC1_PRES);
    this->brakeValue(ui->labelFlow, this->database->data_BCU->N_FLOW);
    this->brakeValue(ui->labelBC2, this->database->data_BCU->N_BC2_PRES);
}

void DeviceDataAirBrake::brakeValue(QLabel *label, unsigned short value)
{
    label->setText(QString::number(value));
}

void DeviceDataAirBrake::udpateNames(QLabel* label, bool judgeKey)
{
    if (judgeKey)
    {
        label->setText("主控");
    }
    else
    {
        label->setText("从控");
    }
}

void DeviceDataAirBrake::bcuStates(QLabel *label, bool state1, bool state2)
{
    int value = state1 * 2 + state2;
    switch (value)
    {
    case 0:
        label->setText("未定义");
        break;
    case 1:
        label->setText("本务切除");
        break;
    case 2:
        label->setText("本务投入");
        break;
    case 3:
        label->setText("补机切除");
        break;
    }
}
