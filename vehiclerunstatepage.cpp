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
