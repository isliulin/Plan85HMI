#include "settng_traincode.h"
#include "ui_settng_traincode.h"

Settng_TrainCode::Settng_TrainCode(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_TrainCode)
{
    ui->setupUi(this);

    NumbuttonList<<this->ui->Button_Num0<<this->ui->Button_Num1<<this->ui->Button_Num2<<this->ui->Button_Num3
                <<this->ui->Button_Num4<<this->ui->Button_Num5<<this->ui->Button_Num6<<this->ui->Button_Num7
               <<this->ui->Button_Num8<<this->ui->Button_Num9<<this->ui->Button_A<<this->ui->Button_B<<this->ui->Button_Clear;
    foreach (QPushButton* button, NumbuttonList)
    {
        connect(button,SIGNAL(pressed()),this,SLOT(setCodeEvent()));
    }
}

Settng_TrainCode::~Settng_TrainCode()
{
    delete ui;
}

void Settng_TrainCode::updatePage()
{
    this->ui->LBL_CurrentCarNum->setText(MainGetDefaultPara::getString("/TrainCode/Code"));
    this->ui->LBL_OtherCarNum->setText(MainGetDefaultPara::getString("/OtherTrainCode/Code"));
}

void Settng_TrainCode::setCodeEvent()
{

    numValue = ((QPushButton*)this->sender())->text();
    if("清除" == numValue)
    {
        this->inputValue.clear();
    }else{
        if(inputValue.length()<5)
        {
            this->inputValue += numValue;
        }else
        {
            this->inputValue.clear();
        }
    }
    this->ui->Edit_InputCarNum->setText(this->inputValue);
}

void Settng_TrainCode::on_Button_CurrentCarNum_pressed()
{
    this->ui->Button_CurrentCarNum->setStyleSheet(NButtonDOWN);
    this->ui->Button_OtherCarNum->setStyleSheet(NButtonUP);
}



void Settng_TrainCode::on_Button_OtherCarNum_pressed()
{
    this->ui->Button_CurrentCarNum->setStyleSheet(NButtonUP);
    this->ui->Button_OtherCarNum->setStyleSheet(NButtonDOWN);
}

void Settng_TrainCode::on_Button_SetCurrentCar_pressed()
{
    this->database->data_CCU->B_LOCO_NO_SET = true;
    this->ui->Button_SetOtherCar->setDisabled(true);
    this->database->data_CCU->N_LOCO_ID = this->ui->Edit_InputCarNum->text().toInt();
    this->ui->Button_SetCurrentCar->setStyleSheet(NButtonDOWN);
    timerCur = startTimer(3000);
}

void Settng_TrainCode::on_Button_SetOtherCar_pressed()
{
    this->database->data_CCU->B_PARTNER_ID_SET = true;
    this->ui->Button_SetCurrentCar->setDisabled(true);
    this->database->data_CCU->N_PARTNER_ID = this->ui->Edit_InputCarNum->text().toInt();
    this->ui->Button_SetOtherCar->setStyleSheet(NButtonDOWN);
    timerOther = startTimer(3000);

}

void Settng_TrainCode::timerEvent(QTimerEvent *e)
{
    if(timerCur == e->timerId())
    {
        killTimer(timerCur);
        this->database->data_CCU->B_LOCO_NO_SET = false;
        this->ui->Button_SetCurrentCar->setStyleSheet(NButtonUP);
        MainGetDefaultPara::set("/TrainCode/Code",this->ui->Edit_InputCarNum->text());
        this->ui->Button_SetOtherCar->setDisabled(false);
        timerCur = 0;
    }
    if(timerOther == e->timerId())
    {
        killTimer(timerOther);
        this->database->data_CCU->B_PARTNER_ID_SET = false;
        this->ui->Button_SetOtherCar->setStyleSheet(NButtonUP);
        MainGetDefaultPara::set("/OtherTrainCode/Code",this->ui->Edit_InputCarNum->text());
        this->ui->Button_SetCurrentCar->setDisabled(false);
        timerOther = 0;
    }
}

void Settng_TrainCode::hideEvent(QHideEvent *)
{
    this->database->data_CCU->B_LOCO_NO_SET = false;
    this->database->data_CCU->B_PARTNER_ID_SET = false;
}
