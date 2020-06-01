#include "devicedatabreaker.h"
#include "ui_devicedatabreaker.h"
#include "data/data_tcn.h"
#include <QButtonGroup>

enum trainNum
{
    uTrain1 = 0,
    uTrain2,
    uTrain3,
    uTrain4
};

DeviceDataBreaker::DeviceDataBreaker(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataBreaker)
{
    ui->setupUi(this);

    //the values labels
    labels << ui->labelC1CPR << ui->labelC2CPR << ui->labelC3CPR << ui->labelDJCPR << ui->labelREC
           << ui->labelCVTBM1 << ui->labelCVTBM2 << ui->labelCVTMT1 << ui->labelCVTMT2 << ui->labelCVTSM1 << ui->labelCVTSM2
           << ui->labelDJPE1 << ui->labelDJPE2 << ui->labelDJPE3 << ui->labelDJPE4 << ui->labelDJPH1 << ui->labelDJPH2
           << ui->labelDJVTSM1 << ui->labelDJVTSM2 << ui->labelQTHVTBM1 << ui->labelQTHVTBM2 << ui->labelQTHVTMT1 << ui->labelQTHVTMT2;

    trainLabels << ui->labelTrain1 << ui->labelTrain2 << ui->labelTrain3 << ui->labelTrain4;
    this->tcn = new Data_TCN;

    //default train1
    this->currentTrain = uTrain1;
    this->buttons = new QButtonGroup;
    this->buttons->addButton(ui->btnTrain1, uTrain1);
    this->buttons->addButton(ui->btnTrain2, uTrain2);
    this->buttons->addButton(ui->btnTrain3, uTrain3);
    this->buttons->addButton(ui->btnTrain4, uTrain4);
    connect(this->buttons, SIGNAL(buttonClicked(int)),this, SLOT(onButtonClicked(int)));
}

DeviceDataBreaker::~DeviceDataBreaker()
{
    delete ui;
}

void DeviceDataBreaker::updatePage()
{
    QList<bool> trainValues;

    trainValues << this->tcn->train[this->currentTrain]->B_STATE_C1_CPR << this->tcn->train[this->currentTrain]->B_STATE_C2_CPR
            << this->tcn->train[this->currentTrain]->B_STATE_C3_CPR << this->tcn->train[this->currentTrain]->B_STATE_Q_TH_CPR
            << this->tcn->train[this->currentTrain]->B_STATE_Q_REC << this->tcn->train[this->currentTrain]->B_STATE_C_VT_BM1
            << this->tcn->train[this->currentTrain]->B_STATE_C_VT_BM2 << this->tcn->train[this->currentTrain]->B_STATE_C_VT_MT1
            << this->tcn->train[this->currentTrain]->B_STATE_C_VT_MT2 << this->tcn->train[this->currentTrain]->B_STATE_C_VT_SM1
            << this->tcn->train[this->currentTrain]->B_STATE_C_VT_SM2 << this->tcn->train[this->currentTrain]->B_STATE_DJ_PE1
            << this->tcn->train[this->currentTrain]->B_STATE_DJ_PE2 << this->tcn->train[this->currentTrain]->B_STATE_DJ_PE3
            << this->tcn->train[this->currentTrain]->B_STATE_DJ_PE4 << this->tcn->train[this->currentTrain]->B_STATE_DJ_PH1
            << this->tcn->train[this->currentTrain]->B_STATE_DJ_PH2 << this->tcn->train[this->currentTrain]->B_STATE_DJ_VT_SM1
            << this->tcn->train[this->currentTrain]->B_STATE_DJ_VT_SM2 << this->tcn->train[this->currentTrain]->B_STATE_Q_TH_VT_BM1
            << this->tcn->train[this->currentTrain]->B_STATE_Q_TH_VT_BM2 << this->tcn->train[this->currentTrain]->B_STATE_Q_TH_VT_MT1
            << this->tcn->train[this->currentTrain]->B_STATE_Q_TH_VT_MT2;

    if (labels.size() != trainValues.size())
    {
        logger()->error("the list size is wrong.");
        return;
    }
    else
    {
        for (int counter = 0; counter < labels.size(); counter++)
        {
            showSignalState(labels.at(counter), trainValues.at(counter));
        }
    }
    trainValues.clear();
    showTrain();
}


void DeviceDataBreaker::showSignalState(QLabel *label, bool signal)
{
    if (signal)
    {
        label->setStyleSheet(GREEN);
    }
    else
    {
        label->setStyleSheet(RED);
    }

}

void DeviceDataBreaker::onButtonClicked(int buttonId)
{
    this->currentTrain = buttonId;
}


void DeviceDataBreaker::showTrain()
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
