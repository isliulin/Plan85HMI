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

void DeviceDataNetwork::updatePage()
{
    updateState(ui->LBL_RIOM1, this->database->data_CCU->M1_D1_B_RIOM1_GW_ONLINE);
    updateState(ui->LBL_RIOM2, this->database->data_CCU->M1_D1_B_RIOM2_GW_ONLINE);
    updateState(ui->LBL_GW1, this->database->data_CCU->M1_D1_B_UIC_GW1_ONLINE);
    updateState(ui->LBL_GW2, this->database->data_CCU->M1_D1_B_UIC_GW2_ONLINE);
    updateState(ui->LBL_GW3, this->database->data_CCU->M1_D1_B_GW3_ONLINE);
    updateState(ui->LBL_TCU1, this->database->data_CCU->M1_D1_B_TCU1_ONLINE);
    updateState(ui->LBL_TCU2, this->database->data_CCU->M1_D1_B_TCU2_ONLINE);
    updateState(ui->LBL_TCU3, this->database->data_CCU->M1_D1_B_TCU3_ONLINE);
    updateState(ui->LBL_TCU4, this->database->data_CCU->M1_D1_B_TCU4_ONLINE);
    updateState(ui->LBL_ACU1, this->database->data_CCU->M1_D1_B_ACU1_ONLINE);
    updateState(ui->LBL_ACU2, this->database->data_CCU->M1_D1_B_ACU2_ONLINE);
    updateState(ui->LBL_MPU1, this->database->data_CCU->M1_D1_B_MPU1_ONLINE, this->database->data_CCU->M1_D1_B_CUR_MPU1);
    updateState(ui->LBL_MPU2, this->database->data_CCU->M1_D1_B_MPU2_ONLINE, this->database->data_CCU->M1_D1_B_CUR_MPU2);
    updateState(ui->LBL_DDU, this->database->data_CCU->M1_D1_B_DDU_ONLINE);
    updateState(ui->LBL_BCU, this->database->data_CCU->M1_D1_B_BCU_ONLINE);
    updateState(ui->LBL_CMD, this->database->data_CCU->M1_D1_B_6A_ONLINE);
    updateState(ui->LBL_ERM, this->database->data_CCU->M1_D1_B_ERM_ONLINE);
}

void DeviceDataNetwork::updateState(QLabel *label, bool onLine, bool isMaster)
{
    if (onLine)
    {
        if (isMaster)
        {
            label->setStyleSheet(GREEN);
        }
        else
        {
            label->setStyleSheet(YELLOW);
        }
    }
    else
        label->setStyleSheet(RED);
}
