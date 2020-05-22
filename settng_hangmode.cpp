#include "settng_hangmode.h"
#include "ui_settng_hangmode.h"

Settng_HangMode::Settng_HangMode(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_HangMode)
{
    ui->setupUi(this);
    ModebuttonList<<this->ui->Button_HangModeActive<<this->ui->Button_HangModeCancel;
    foreach (QPushButton* button, ModebuttonList) {
        connect(button,SIGNAL(pressed()),this,SLOT(modePressEvent()));
    }

    NumbuttonList<<this->ui->Button_Num0<<this->ui->Button_Num1<<this->ui->Button_Num2<<this->ui->Button_Num3
                   <<this->ui->Button_Num4<<this->ui->Button_Num5<<this->ui->Button_Num6<<this->ui->Button_Num7
                     <<this->ui->Button_Num8<<this->ui->Button_Num9<<this->ui->Button_Clear<<this->ui->Button_SendData;
    foreach (QPushButton* button, NumbuttonList) {
        connect(button,SIGNAL(pressed()),this,SLOT(setSpeedEvent()));
    }
}

Settng_HangMode::~Settng_HangMode()
{
    delete ui;
}

void Settng_HangMode::updatePage()
{

}

void Settng_HangMode::modePressEvent()
{
    for(int i =0;i<ModebuttonList.size();i++)
    {
        ModebuttonList.at(i)->setStyleSheet(NButtonUP);
    }

    modeIndex = ((QPushButton *)this->sender())->whatsThis().toInt();
    switch(modeIndex)
    {
    case 1:
        if(!this->database->data_CCU->M1_D1_B_MESG_BYTE1_BIT5)
        {
            this->database->data_CCU->B_TRAILER_MODE = true;
            this->ui->Button_HangModeActive->setStyleSheet(NButtonDOWN);
        }else
        {
            this->ui->Button_HangModeActive->setStyleSheet(NButtonUP);
        }
        break;
    case 2:
        if(this->database->data_CCU->M1_D1_B_MESG_BYTE1_BIT5)
        {
            this->database->data_CCU->B_TRAILER_MODE = false;
            this->ui->Button_HangModeCancel->setStyleSheet(NButtonDOWN);
        }else
        {
            this->ui->Button_HangModeCancel->setStyleSheet(NButtonUP);
        }
        break;
    default:
        break;
    }

}

void Settng_HangMode::setSpeedEvent()
{
    numValue = ((QPushButton*)this->sender())->text();
    if("数据发送" == numValue)
    {
        if(this->database->data_CCU->M1_D1_B_MESG_BYTE1_BIT5)
        {
            this->database->data_CCU->N_TRAILER_MODE_SPEED = inputValue.toInt();
        }else
        {
            this->database->data_CCU->N_TRAILER_MODE_SPEED = 0;
        }

    }else if("清除" == numValue)
    {
        this->inputValue.clear();
    }else{
        if(inputValue.length()<4)
        {
            this->inputValue += numValue;
        }else
        {

        }
    }
    this->ui->Edit_InputSpeed->setText(this->inputValue);


}
