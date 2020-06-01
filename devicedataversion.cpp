#include "devicedataversion.h"
#include "ui_devicedataversion.h"


DeviceDataVersion::DeviceDataVersion(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataVersion)
{
    ui->setupUi(this);
    names << "MPU1" << "MPU2" << "ACU1" << "ACU2" << "TCU1" << "TCU2" << "TCU3" << "TCU4"
          << "EIU" << "DDU" << "6A" << "GW3" << "GW1" << "GW2"<< "RIOM1" << "RIOM2" << "ERM";

    nameLabels << ui->label1 << ui->label2 << ui->label3 << ui->label4 << ui->label5 << ui->label6
           << ui->label7 << ui->label8 << ui->label9 << ui->label10 << ui->label11 << ui->label12
           << ui->label13 << ui->label14 << ui->label15 << ui->label16 << ui->label17;

    xLabels << ui->label1X << ui->label2X << ui->label3X << ui->label4X << ui->label5X << ui->label6X
            << ui->label7X << ui->label8X << ui->label9X << ui->label10X << ui->label11X << ui->label12X
            << ui->label13X << ui->label14X << ui->label15X << ui->label16X << ui->label17X;

    yLabels << ui->label1Y << ui->label2Y << ui->label3Y << ui->label4Y << ui->label5Y << ui->label6Y
            << ui->label7Y << ui->label8Y << ui->label9Y << ui->label10Y << ui->label11Y << ui->label12Y
            << ui->label13Y << ui->label14Y << ui->label15Y << ui->label16Y << ui->label17Y;

    zLabels << ui->label1Z << ui->label2Z << ui->label3Z << ui->label4Z << ui->label5Z << ui->label6Z
            << ui->label7Z << ui->label8Z << ui->label9Z << ui->label10Z << ui->label11Z << ui->label12Z
            << ui->label13Z << ui->label14Z << ui->label15Z << ui->label16Z << ui->label17Z;
}

DeviceDataVersion::~DeviceDataVersion()
{
    delete ui;
}

void DeviceDataVersion::updatePage()
{

    if(this->database->data_CCU->M1_D1_N_DEVICE_NO > 0)
    {
        nameLabels.at(this->database->data_CCU->M1_D1_N_DEVICE_NO-1)->setText(names.at(this->database->data_CCU->M1_D1_N_DEVICE_NO-1));
        xLabels.at(this->database->data_CCU->M1_D1_N_DEVICE_NO-1)->setText(QString::number(this->database->data_CCU->M1_D1_N_VERSION_X));
        yLabels.at(this->database->data_CCU->M1_D1_N_DEVICE_NO-1)->setText(QString::number(this->database->data_CCU->M1_D1_N_VERSION_Y));
        zLabels.at(this->database->data_CCU->M1_D1_N_DEVICE_NO-1)->setText(QString::number(this->database->data_CCU->M1_D1_N_VERSION_Z));
    }
}
