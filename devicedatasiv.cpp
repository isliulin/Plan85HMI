#include "devicedatasiv.h"
#include "ui_devicedatasiv.h"

#define SWITCHCLOSE "border-image: url(:/images/images/SWclose.png);"
#define SWITCHOPEN "border-image: url(:/images/images/SWopen.png);"
#define SWITCHCLOSE_V "border-image: url(:/images/images/SWcloseV.png);"
#define SWITCHOPEN_V "border-image: url(:/images/images/SWopenV.png);"
#define PHCLOSE "border-image: url(:/images/images/PHclose.png);"
#define PHOPEN "border-image: url(:/images/images/PHopen.png);"

#define CIRCLE_YELLOW "border-image: url(:/images/images/Circle.png);"
#define CIRCLE_GREEN "border-image: url(:/images/images/Circle_Green.png);"

enum trainNum
{
    uTrain1 = 0,
    uTrain2,
    uTrain3,
    uTrain4
};

DeviceDataSIV::DeviceDataSIV(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataSIV)
{
    ui->setupUi(this);

    trainLabels << ui->labelTrain1 << ui->labelTrain2 << ui->labelTrain3 << ui->labelTrain4;
    swList << ui->LBL_OND_CVS1 << ui->LBL_C_QUAI << ui->LBL_OND_CVS2 << ui->LBL_C_MT1 << ui->LBL_C_MT2
           << ui->LBL_C_BM1 << ui->LBL_C_BM2 << ui->LBL_C1_CPR << ui->LBL_C2_CPR << ui->LBL_C3_CPR
           << ui->LBL_C_SM1 << ui->LBL_C_SM2;

    hbList << ui->LBL_DJQUAI << ui->LBL_DJ_CPR << ui->LBL_PH1 << ui->LBL_PH2 << ui->LBL_PE1 << ui->LBL_PE2 << ui->LBL_PE3
           << ui->LBL_PE4;

    //default train1
    this->currentTrain = uTrain1;
    this->buttons = new QButtonGroup;
    this->buttons->addButton(ui->btnTrain1, uTrain1);
    this->buttons->addButton(ui->btnTrain2, uTrain2);
    this->buttons->addButton(ui->btnTrain3, uTrain3);
    this->buttons->addButton(ui->btnTrain4, uTrain4);
    connect(this->buttons, SIGNAL(buttonClicked(int)),this, SLOT(onButtonClicked(int)));
}

DeviceDataSIV::~DeviceDataSIV()
{
    delete ui;
}

void DeviceDataSIV::onButtonClicked(int buttonId)
{
    this->currentTrain = buttonId;
}


void DeviceDataSIV::showTrain()
{
    for (int i = 0; i < buttons->buttons().size(); i++)
    {
        if (i < this->database->data_CCU->M1_D1_N_RULOCO_NO)
        {
            buttons->button(i)->show();
            trainLabels.at(i)->show();
            trainLabels.at(i)->setText("HXD2 " + QString::number(this->database->data_TCN->train[i]->N_LOCO_NO, 16));
        }
        else
        {
            buttons->button(i)->hide();
            trainLabels.at(i)->hide();
        }
    }
}

void DeviceDataSIV::setSwitch(QLabel *label, bool close)
{
    if(close)
    {
        label->setStyleSheet(SWITCHCLOSE);
    }else
    {
        label->setStyleSheet(SWITCHOPEN);
    }
}

void DeviceDataSIV::setVSwitch(QLabel *label, bool close)
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

void DeviceDataSIV::setHBState(QLabel *label, bool close)
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

void DeviceDataSIV::setPPQUAI(QLabel *label, bool right)
{
    if(right)
    {
        label->setStyleSheet(CIRCLE_GREEN);
    }else
    {
        label->setStyleSheet(CIRCLE_YELLOW);
    }
}

void DeviceDataSIV::updatePage()
{
    QList<bool> switchStates, hbStates;

    //set switch state
    switchStates << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_BAU1 << this->database->data_TCN->train[this->currentTrain]->B_STATE_KM_QUAI
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_BAU2 << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_VT_MT1
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_VT_MT2 << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_VT_BM1
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_VT_BM2 << this->database->data_TCN->train[this->currentTrain]->B_STATE_C1_CPR
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_C2_CPR << this->database->data_TCN->train[this->currentTrain]->B_STATE_C3_CPR
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_VT_SM1 << this->database->data_TCN->train[this->currentTrain]->B_STATE_C_VT_SM2;

    if (switchStates.size() != swList.size())
    {
        logger()->error("switch size : the list size is wrong.");
        return;
    }
    else
    {
        for (int counter = 0; counter < switchStates.size(); counter++)
        {
            setSwitch(swList.at(counter), switchStates.at(counter));
        }
    }
    switchStates.clear();

    //set switch vertical icons states
    setVSwitch(ui->LBL_SEC_CVS, this->database->data_TCN->train[this->currentTrain]->B_STATE_C_SEC);

    //set hb state
    hbStates << this->database->data_TCN->train[this->currentTrain]->B_STATE_DJ_QUAI << this->database->data_TCN->train[this->currentTrain]->B_TH_CPR
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_DJ_PH1 << this->database->data_TCN->train[this->currentTrain]->B_STATE_DJ_PH2
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_DJ_PE1 << this->database->data_TCN->train[this->currentTrain]->B_STATE_DJ_PE2
            << this->database->data_TCN->train[this->currentTrain]->B_STATE_DJ_PE3 << this->database->data_TCN->train[this->currentTrain]->B_STATE_DJ_PE4;
    if (hbList.size() != hbStates.size())
    {
        logger()->error("switch size : the list size is wrong.");
        return;
    }
    else
    {
        for (int counter = 0; counter < hbList.size(); counter++)
        {
             setHBState(hbList.at(counter), hbStates.at(counter));
        }
    }
    hbStates.clear();

    //set pp quai
    setPPQUAI(ui->LBL_PPQUAI, this->database->data_TCN->train[this->currentTrain]->B_STATE_Q_PP_QUAI);
    //set conv/AFC values
    this->ui->LBL_CON1->setText(QString::number(this->database->data_TCN->train[this->currentTrain]->N_ACU1Freq_U8)+"HZ");
    this->ui->LBL_CON2->setText(QString::number(this->database->data_TCN->train[this->currentTrain]->N_ACU2Freq_U8)+"HZ");

    this->ui->LBL_AFC1->setText(QString::number(this->database->data_TCN->train[this->currentTrain]->N_CONVOilTemp1_U8+50)+"C");
    this->ui->LBL_AFC2->setText(QString::number(this->database->data_TCN->train[this->currentTrain]->N_CONVOilTemp2_U8+50)+"C");

    showTrain();
}

