#include "settng_separation.h"
#include "ui_settng_separation.h"

Settng_Separation::Settng_Separation(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Separation)
{
    ui->setupUi(this);
    modeButtonList<<this->ui->BTN_NormalLine<<this->ui->BTN_FreightLine;
    foreach (QPushButton* button, modeButtonList) {
        connect(button,SIGNAL(pressed()),this,SLOT(modePressEvent()));
    }
}

Settng_Separation::~Settng_Separation()
{
    delete ui;
}

void Settng_Separation::updatePage()
{
    if(this->database->data_CCU->M1_D1_B_NSC_DISTANCE1)
    {
        this->ui->BTN_NormalLine->setStyleSheet(NButtonDOWN);
    }else if(this->database->data_CCU->M1_D1_B_NSC_DISTANCE2)
    {
        this->ui->BTN_FreightLine->setStyleSheet(NButtonDOWN);
    }else
    {
        this->ui->BTN_NormalLine->setStyleSheet(NButtonUP);
        this->ui->BTN_FreightLine->setStyleSheet(NButtonUP);
    }

}

void Settng_Separation::modePressEvent()
{
    for(int i =0;i<modeButtonList.size();i++)
    {
        modeButtonList.at(i)->setStyleSheet(NButtonUP);
    }
    modeIndex = ((QPushButton *)this->sender())->whatsThis().toInt();
    switch (modeIndex) {
    case 1:
        if(!this->database->data_CCU->M1_D1_B_NSC_DISTANCE1)
        {
            this->database->data_CCU->B_NSC_DISTANCE1 = true;
            this->database->data_CCU->B_NSC_DISTANCE2 = false;
        }else
        {
        }
        break;
    case 2:
        if(!this->database->data_CCU->M1_D1_B_NSC_DISTANCE2)
        {
            this->database->data_CCU->B_NSC_DISTANCE1 = false;
            this->database->data_CCU->B_NSC_DISTANCE2 = true;
        }else
        {
        }
        break;
    default:
        break;
    }
}
