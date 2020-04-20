#include "ctrltrainoutline.h"
#include "ui_ctrltrainoutline.h"

CtrlTrainOutLine::CtrlTrainOutLine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTrainOutLine)
{
    ui->setupUi(this);
}

CtrlTrainOutLine::~CtrlTrainOutLine()
{
    delete ui;
}

void CtrlTrainOutLine::updatePagePos(int trainnum)
{

}
