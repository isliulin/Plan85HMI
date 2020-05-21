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
    count = 0;
}

Settng_Separation::~Settng_Separation()
{
    delete ui;
}

void Settng_Separation::updatePage()
{

    if(this->database->data_CCU->M1_D1_B_NSC_DISTANCE1)
    {
        this->ui->LBL_ReturnMode->setText("普通线路");
    }else if(this->database->data_CCU->M1_D1_B_NSC_DISTANCE2)
    {
        this->ui->LBL_ReturnMode->setText("货运专线");
    }else
    {
        this->ui->LBL_ReturnMode->setText("");
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
        this->ui->BTN_NormalLine->setStyleSheet(NButtonDOWN);
        timerNormal = startTimer(3000);
        this->database->data_CCU->B_NSC_DISTANCE1 = true;
        break;
    case 2:
        this->ui->BTN_FreightLine->setStyleSheet(NButtonDOWN);
        timerFreight = startTimer(3000);
        this->database->data_CCU->B_NSC_DISTANCE2 = true;
        break;
    default:
        break;
    }
}

void Settng_Separation::timerEvent(QTimerEvent *e)
{
    if(timerNormal == e->timerId())
    {
        killTimer(timerNormal);
        this->ui->BTN_NormalLine->setStyleSheet(NButtonUP);
        this->database->data_CCU->B_NSC_DISTANCE1 = false;
        timerNormal = 0;
    }else if(timerFreight == e->timerId())
    {
        killTimer(timerFreight);
        this->ui->BTN_FreightLine->setStyleSheet(NButtonUP);
        this->database->data_CCU->B_NSC_DISTANCE2 = false;
        timerFreight = 0;
    }
}

