#include "vehiclerunstatepage.h"
#include "ui_vehiclerunstatepage.h"

#define FAULTLEVEL1 "background-color:rgb(240,0,0);color:black;border:transparent;"
#define FAULTLEVEL2 "background-color:rgb(240,240,0);color:black;border:transparent;"
#define FAULTLEVEL3 "background-color:rgb(0,0,0);color:rgb(248,248,248);border:transparent;"

VehicleRunStatePage::VehicleRunStatePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::VehicleRunStatePage)
{
    ui->setupUi(this);

    ctrlNetVoltage = new CtrlNetVoltage(this);
    ctrlNetVoltage->setGeometry(10,10,this->ctrlNetVoltage->width(),this->ctrlNetVoltage->height());

    ctrlNetCurrent = new CtrlNetCurrent(this);
    ctrlNetCurrent->setGeometry(105,10,this->ctrlNetCurrent->width(),this->ctrlNetCurrent->height());

    ctrlControlVoltage = new CtrlControlVoltage(this);
    ctrlControlVoltage->setGeometry(200,10,this->ctrlControlVoltage->width(),this->ctrlControlVoltage->height());

    ctrlTracBrake = new CtrlTracBrake(this);
    ctrlTracBrake->setGeometry(365,10,this->ctrlTracBrake->width(),this->ctrlTracBrake->height());

}

VehicleRunStatePage::~VehicleRunStatePage()
{
    delete ui;
}

void VehicleRunStatePage::updatePage()
{
    ui->LBLFault1->setStyleSheet(FAULTLEVEL1);
    ui->LBLFault2->setStyleSheet(FAULTLEVEL2);
    ui->LBLFault3->setStyleSheet(FAULTLEVEL3);
    static int i   = 0;
    i +=10;
    ctrlNetVoltage->setCtrlValueRect(i/10);
    ctrlNetCurrent->setCtrlValueRect(i);
    ctrlControlVoltage->setCtrlValueRect(i,i);
    ctrlTracBrake->setCtrlValueRect(i/10,i/10%2,i/10%3);

    //eg
    //database->data_TCN->train[i]->xxx

}
void VehicleRunStatePage::showEvent(QShowEvent *)
{

}

void VehicleRunStatePage::on_BTNMinus1_clicked()
{

}

void VehicleRunStatePage::on_BTNPlus1_clicked()
{

}
