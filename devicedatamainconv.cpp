#include "devicedatamainconv.h"
#include "ui_devicedatamainconv.h"

#define SWITCHCLOSE "border-image: url(:/images/images/SWclose.png);"
#define SWITCHOPEN "border-image: url(:/images/images/SWopen.png);"
#define SWITCHCLOSE_V "border-image: url(:/images/images/SWcloseV.png);"
#define SWITCHOPEN_V "border-image: url(:/images/images/SWopenV.png);"
#define PHCLOSE "border-image: url(:/images/images/PHclose.png);"
#define PHOPEN "border-image: url(:/images/images/PHopen.png);"



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

void DeviceDataMainConv::updatePage()
{
    setSwitch(ui->LBL_PC_CF1, this->database->data_TCU->T1_B_KA_PC_OK[0]);
    setSwitch(ui->LBL_IS_CF1, this->database->data_TCU->T1_B_KA_WORK_OK[0]);
    setSwitch(ui->LBL_PC_CF2, this->database->data_TCU->T1_B_KA_PC_OK[1]);
    setSwitch(ui->LBL_IS_CF2, this->database->data_TCU->T1_B_KA_WORK_OK[1]);
    setSwitch(ui->LBL_PC_CF3, this->database->data_TCU->T1_B_KA_PC_OK[2]);
    setSwitch(ui->LBL_IS_CF3, this->database->data_TCU->T1_B_KA_WORK_OK[2]);
    setSwitch(ui->LBL_PC_CF4, this->database->data_TCU->T1_B_KA_PC_OK[3]);
    setSwitch(ui->LBL_IS_CF4, this->database->data_TCU->T1_B_KA_WORK_OK[3]);
    setSwitch(ui->LBL_IS_QUAI, this->database->data_RIOM->M1_R2_B_C_IS_QUAI);
    setSwitch(ui->LBL_PC_QUAI, this->database->data_RIOM->M1_R2_B_C_PC_QUAI);
    //setHBState(ui->LBL_DJQUAI, this->database->data_RIOM->) b_dj_quai

    ui->LBL_Volta1->setText(QString::number(this->database->data_TCU->T1_N_INVT_IN_V[0]));
    ui->LBL_Volta2->setText(QString::number(this->database->data_TCU->T1_N_INVT_IN_V[1]));
    ui->LBL_Volta3->setText(QString::number(this->database->data_TCU->T1_N_INVT_IN_V[2]));
    ui->LBL_Volta4->setText(QString::number(this->database->data_TCU->T1_N_INVT_IN_V[3]));
}

void DeviceDataMainConv::setSwitch(QLabel *label, bool close)
{
    if(close)
    {
        label->setStyleSheet(SWITCHCLOSE);
    }else
    {
        label->setStyleSheet(SWITCHOPEN);
    }
}

void DeviceDataMainConv::setVSwitch(QLabel *label, bool close)
{
    if (close)
    {
        label->setStyleSheet(SWITCHCLOSE_V);
    }
    else
    {
        label->setStyleSheet(SWITCHOPEN_V);
    }
}

void DeviceDataMainConv::setHBState(QLabel *label, bool close)
{
    if (close)
    {
        label->setStyleSheet(PHCLOSE);
    }
    else
    {
        label->setStyleSheet(PHOPEN);
    }
}


