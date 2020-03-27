#include "settng_others.h"
#include "ui_settng_others.h"

Settng_Others::Settng_Others(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Others)
{
    ui->setupUi(this);
    this->ui->BTN_NormalMode->setStyleSheet(NButtonUP);
    this->ui->BTN_SummerMode->setStyleSheet(NButtonUP);

    ModebuttonList<<this->ui->BTN_NormalMode<<this->ui->BTN_SummerMode;
    foreach (QPushButton* button, ModebuttonList)
    {
    connect(button,SIGNAL(pressed()),this,SLOT(modePressEvent()));
    }

    NumbuttonList<<this->ui->Button_Num0<<this->ui->Button_Num1<<this->ui->Button_Num2<<this->ui->Button_Num3
                <<this->ui->Button_Num4<<this->ui->Button_Num5<<this->ui->Button_Num6<<this->ui->Button_Num7
               <<this->ui->Button_Num8<<this->ui->Button_Num9<<this->ui->Button_Clear<<this->ui->Button_Save;
    foreach (QPushButton* button, NumbuttonList)
    {
        connect(button,SIGNAL(pressed()),this,SLOT(setWeightEvent()));
    }
}

Settng_Others::~Settng_Others()
{
    delete ui;
}

void Settng_Others::updatePage()
{
    //模式状态
    if(this->database->data_CCU->M1_D1_B_NORMAL_MODE)
    {
        this->ui->LBL_Tips2->setText("当前模式：普通模式");
        this->ui->BTN_NormalMode->setStyleSheet(NButtonDOWN);
        this->ui->BTN_SummerMode->setStyleSheet(NButtonUP);
    }else if(this->database->data_CCU->M1_D1_B_SUMMER_MODE)
    {
        this->ui->LBL_Tips2->setText("当前模式：夏季模式");
        this->ui->BTN_NormalMode->setStyleSheet(NButtonUP);
        this->ui->BTN_SummerMode->setStyleSheet(NButtonDOWN);
    }else
    {
        this->ui->LBL_Tips2->setText("当前模式：～模式");
        this->ui->BTN_NormalMode->setStyleSheet(NButtonUP);
        this->ui->BTN_SummerMode->setStyleSheet(NButtonUP);
    }
    //牵引吨位
    this->ui->LBL_WeightValue->setText(QString::number(this->database->data_CCU->M1_D1_N_LOAD));

}

void Settng_Others::modePressEvent()
{
    modeIndex = ((QPushButton*)this->sender())->whatsThis().toInt();
    switch (modeIndex)
    {
    case 1:
        this->database->data_CCU->B_NORMAL_MODE = true;
        this->database->data_CCU->B_SUMMER_MODE = false;
        break;
    case 2:
        this->database->data_CCU->B_NORMAL_MODE = false;
        this->database->data_CCU->B_SUMMER_MODE = true;
    default:
        break;
    }

}

void Settng_Others::setWeightEvent()
{
    numValue = ((QPushButton*)this->sender())->text();
    if("存储" == numValue)
    {
        this->database->data_CCU->B_LOAD_SET = true;
        this->database->data_CCU->N_LOAD = inputValue.toInt();
        this->ui->Button_Save->setStyleSheet(NButtonDOWN);
        this->timerSave = startTimer(5000);

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
    this->ui->Edit_InputWeight->setText(this->inputValue);

}

void Settng_Others::timerEvent(QTimerEvent *e)
{
    if(timerSave == e->timerId())
    {
        killTimer(timerSave);
        this->ui->Button_Save->setStyleSheet(NButtonUP);
        this->database->data_CCU->N_LOAD = 0;
        this->database->data_CCU->B_LOAD_SET = false;
    }
}

