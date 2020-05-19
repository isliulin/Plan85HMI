#include "settng_distance.h"
#include "ui_settng_distance.h"

Settng_Distance::Settng_Distance(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Distance)
{
    ui->setupUi(this);
}

Settng_Distance::~Settng_Distance()
{
    delete ui;
}

void Settng_Distance::updatePage()
{
    this->ui->LBL_MSCount->setText(QString::number(this->database->data_CCU->M1_D1_N_MCB_ON_COUNTER));
    this->ui->LBL_TotalDis->setText(QString::number(this->database->data_CCU->M1_D1_N_TOTAL_DISTANCE));
    this->ui->LBL_ShuttleDis->setText(QString::number(this->database->data_CCU->M1_D1_N_TRIP_COUNTER));
}

void Settng_Distance::on_BTN_Reset_pressed()
{
    this->database->data_CCU->B_MILEAGE_RESET = true;
    timer3S = startTimer(3000);
    this->ui->BTN_Reset->setStyleSheet(NButtonDOWN);
}

void Settng_Distance::timerEvent(QTimerEvent *)
{
    this->ui->BTN_Reset->setStyleSheet(NButtonUP);
    killTimer(timer3S);
    this->database->data_CCU->B_MILEAGE_RESET = false;
}
