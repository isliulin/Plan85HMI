#include "main_simulate.h"
#include "ui_main_simulate.h"
#include "qdebug.h"

QString Main_Simulate::Main_SimulateNumberSpeed="";
QString Main_Simulate::Main_SimulateNumberVol="";

Main_Simulate::Main_Simulate(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Simulate)
{
    ui->setupUi(this);
    numberButtonsPressed();
    funcFlag=true;
    funcButtonsPressed();
    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));

}

Main_Simulate::~Main_Simulate()
{
    delete ui;
}


void Main_Simulate::updatePage()
{

}

void Main_Simulate::numberButtonsPressed()
{
    buttons<<ui->PB_N_0<<ui->PB_N_1<<ui->PB_N_2<<ui->PB_N_3<<ui->PB_N_4<<ui->PB_N_5
          <<ui->PB_N_6<<ui->PB_N_7<<ui->PB_N_8<<ui->PB_N_9<<ui->PB_N_10;
    foreach (QPushButton* button, buttons) {
        connect(button,SIGNAL(pressed()),this,SLOT(numberButtonsPressedEvent()));
    }

}

void Main_Simulate::numberButtonsPressedEvent()
{
    int number=((QPushButton*)this->sender())->whatsThis().toInt();
    if(number!=10)
    {
        if(funcFlag)
        {
            Main_SimulateNumberSpeed=Main_SimulateNumberSpeed.append(QString::number(number));
            ui->lbl_speedInput_value->setText(Main_SimulateNumberSpeed);
        }
        else
        {
            Main_SimulateNumberVol=Main_SimulateNumberVol.append(QString::number(number));
            ui->lbl_volInput_value->setText(Main_SimulateNumberVol);
        }

    }
    else
    {
        if(funcFlag)
        {
            Main_SimulateNumberSpeed="";
            ui->lbl_speedInput_value->setText("");
        }
        else
        {
            Main_SimulateNumberVol="";
            ui->lbl_volInput_value->setText("");
        }

    }

}

void Main_Simulate::funcButtonsPressed()
{
    funcButtons<<ui->PB_simulateKey<<ui->PB_orderTestActive<<ui->PB_SpeedInput
              <<ui->PB_VolInput<<ui->PB_Send;
    foreach (QPushButton* button, funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(funcButtonsPressedEvent()));
    }

}

void Main_Simulate::funcButtonsPressedEvent()
{
    int number=((QPushButton*) this->sender())->whatsThis().toInt();
    switch(number)
    {
    case simulateKey:
        qTimer->start(2000);
        ui->PB_simulateKey->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        break;
    case orderTestActive:
        qTimer->start(2000);
        ui->PB_orderTestActive->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        break;
    case speedInput:
        funcFlag=true;
        ui->PB_SpeedInput->setStyleSheet(MAINBUTTONDOWN);
        ui->PB_VolInput->setStyleSheet(MAINBUTTONUP);
        break;
    case volInput:
        funcFlag=false;
        ui->PB_SpeedInput->setStyleSheet(MAINBUTTONUP);
        ui->PB_VolInput->setStyleSheet(MAINBUTTONDOWN);
        break;
    case send:
        qTimer->start(2000);
        ui->PB_Send->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        break;
    }
}

void Main_Simulate::timeoutEvent()
{
    releaseAllButtons();
    ableAllButtons();
}

void Main_Simulate::releaseAllButtons()
{
    ui->PB_simulateKey->setStyleSheet(MAINBUTTONUP);
    ui->PB_orderTestActive->setStyleSheet(MAINBUTTONUP);
    ui->PB_Send->setStyleSheet(MAINBUTTONUP);
}

void Main_Simulate::ableAllButtons()
{
     ui->PB_simulateKey->setEnabled(true);
     ui->PB_orderTestActive->setEnabled(true);
     ui->PB_Send->setEnabled(true);

}

void Main_Simulate::unableAllButtons()
{
    ui->PB_simulateKey->setEnabled(false);
    ui->PB_orderTestActive->setEnabled(false);
    ui->PB_Send->setEnabled(false);
}
