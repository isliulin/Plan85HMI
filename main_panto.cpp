#include "main_panto.h"
#include "ui_main_panto.h"

Main_Panto::Main_Panto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Panto)
{
    ui->setupUi(this);
    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));

    funcButtons<<ui->PB_active<<ui->PB_speedAsc<<ui->PB_speedDec;
    foreach (QPushButton* button, funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(buttonsPressedEvent()));
    }
}

Main_Panto::~Main_Panto()
{
    delete ui;
}

void Main_Panto::timeoutEvent()
{
    releaseAllButtons();
}

void Main_Panto::buttonsPressedEvent()
{
    int number=((QPushButton*)this->sender())->whatsThis().toInt();
    switch(number)
    {
    case speedAsc:
        ui->PB_speedAsc->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    case speedDec:
        ui->PB_speedDec->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    case send:
        ui->PB_active->setStyleSheet(MAINBUTTONDOWN);
        unableAllButtons();
        qTimer->start(2000);
        break;
    }
}

void Main_Panto::releaseAllButtons()
{
    ui->PB_active->setStyleSheet(MAINBUTTONUP);
    ui->PB_speedAsc->setStyleSheet(MAINBUTTONUP);
    ui->PB_speedDec->setStyleSheet(MAINBUTTONUP);
    ui->PB_active->setEnabled(true);
    ui->PB_speedAsc->setEnabled(true);
    ui->PB_speedDec->setEnabled(true);
}

void Main_Panto::unableAllButtons()
{
    ui->PB_active->setEnabled(false);
    ui->PB_speedDec->setEnabled(false);
    ui->PB_speedAsc->setEnabled(false);
}
