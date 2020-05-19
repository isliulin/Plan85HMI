#include "settng_lubrication.h"
#include "ui_settng_lubrication.h"

Settng_Lubrication::Settng_Lubrication(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Lubrication)
{
    ui->setupUi(this);
}

Settng_Lubrication::~Settng_Lubrication()
{
    delete ui;
}


void Settng_Lubrication::showEvent(QShowEvent*)
{
    this->database->data_CCU->B_FLL_SET = true;
}

void Settng_Lubrication::hideEvent(QHideEvent*)
{
    this->database->data_CCU->B_FLL_SET = false;
}

void Settng_Lubrication::updatePage()
{
    this->ui->LBL_DisReturnValue->setText(QString::number(this->database->data_CCU->M1_D1_N_FLL_DIS)+"m");
    this->ui->LBL_TimeReturnValue->setText(QString::number(this->database->data_CCU->M1_D1_N_FLL_SECONDS)+"s");
    this->ui->LBL_DisValue->setText(QString::number(this->database->data_CCU->N_FLL_DIS));
    this->ui->LBL_TimeValue->setText(QString::number(this->database->data_CCU->N_FLL_TIME,10,1));
}

void Settng_Lubrication::on_BTN_DisAdd_pressed()
{
    if(this->database->data_CCU->N_FLL_DIS<500)
    {
        this->database->data_CCU->N_FLL_DIS += 50;
    }else
    {
        this->database->data_CCU->N_FLL_DIS = 500;
    }
}

void Settng_Lubrication::on_BTN_DisSub_pressed()
{
    if(this->database->data_CCU->N_FLL_DIS>50)
    {
        this->database->data_CCU->N_FLL_DIS -= 50;
    }else
    {
        this->database->data_CCU->N_FLL_DIS = 50;
    }
}

void Settng_Lubrication::on_BTN_TimeAdd_pressed()
{
    if(this->database->data_CCU->N_FLL_TIME<15)
    {
        this->database->data_CCU->N_FLL_TIME += 1;
    }else
    {
        this->database->data_CCU->N_FLL_TIME = 15;
    }
}

void Settng_Lubrication::on_BTN_TimeSub_pressed()
{
    if(this->database->data_CCU->N_FLL_TIME>5)
    {
        this->database->data_CCU->N_FLL_TIME -= 1;
    }else
    {
        this->database->data_CCU->N_FLL_TIME = 5;
    }
}
