#include "ctrlnumbertable.h"
#include "ui_ctrlnumbertable.h"
#include "qdebug.h"

QString CtrlNumberTable::numbers="";

CtrlNumberTable::CtrlNumberTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlNumberTable)
{
    ui->setupUi(this);
    buttons<<ui->PB_N_0<<ui->PB_N_1<<ui->PB_N_2<<ui->PB_N_3<<ui->PB_N_4
          <<ui->PB_N_5<<ui->PB_N_6<<ui->PB_N_7<<ui->PB_N_8<<ui->PB_N_9<<ui->PB_N_10;

    foreach (QPushButton* button, buttons) {
        connect(button,SIGNAL(pressed()),this,SLOT(buttonsPressedEvent()));
    }

}

CtrlNumberTable::~CtrlNumberTable()
{
    delete ui;
}
void CtrlNumberTable::buttonsPressedEvent()
{
    int pressedNum=((QPushButton*)this->sender())->whatsThis().toInt();
    if(pressedNum!=10)
    {
        numbers.append(QString::number(pressedNum));
    }
    else
    {
        //numbers.remove(numbers.length()-1,1);
        numbers="";
    }

}

QString CtrlNumberTable::getNumber()
{
    return CtrlNumberTable::numbers;
}
