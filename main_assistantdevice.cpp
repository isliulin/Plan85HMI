#include "main_assistantdevice.h"
#include "ui_main_assistantdevice.h"
#include "qdebug.h"


Main_AssistantDevice::Main_AssistantDevice(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_AssistantDevice)
{
    ui->setupUi(this);
    funcButtons<<ui->PB_AirPressTest<<ui->PB_CoolWindTest_1<<ui->PB_CoolWindTest_2
              <<ui->PB_MwindTest_1<<ui->PB_MwindTest_2<<ui->PB_TractWindTest_1
             <<ui->PB_TractWindTest_2;
    foreach (QPushButton* button, funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(funcButtonsPressEvent()));
    }

    qTimer =new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));
}

Main_AssistantDevice::~Main_AssistantDevice()
{
    delete ui;
}

void Main_AssistantDevice::updatePage()
{

}

void Main_AssistantDevice::funcButtonsPressEvent()
{
    int number =((QPushButton*)this->sender())->whatsThis().toInt();
    switch(number)
    {
    case AirPressTest:
        ui->PB_AirPressTest->setStyleSheet(MAINBUTTONDOWN);
        qTimer->start(2000);
        unableAllButtons();
        break;
    case MwindTest_1:
        ui->PB_MwindTest_1->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    case MwindTest_2:
        ui->PB_MwindTest_2->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    case CoolWindTest_1:
        ui->PB_CoolWindTest_1->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    case CoolWindTest_2:
        ui->PB_CoolWindTest_2->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    case TractWindTest_1:
        ui->PB_TractWindTest_1->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    case TractWindTest_2:
        ui->PB_TractWindTest_2->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    }
}


void Main_AssistantDevice::timeoutEvent()
{
    releaseAllbuttons();
    ableAllButtons();
}

void Main_AssistantDevice::releaseAllbuttons()
{
    foreach (QPushButton* button, funcButtons) {
        button->setStyleSheet(MAINBUTTONUP);
    }
}

void Main_AssistantDevice::unableAllButtons()
{
    foreach (QPushButton* button, funcButtons) {
        button->setEnabled(false);
    }
}

void Main_AssistantDevice::ableAllButtons()
{
    foreach (QPushButton* button, funcButtons) {
        button->setEnabled(true);
    }
}
