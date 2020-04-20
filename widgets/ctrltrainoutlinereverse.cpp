#include "ctrltrainoutlinereverse.h"
#include "ui_ctrltrainoutlinereverse.h"

CtrlTrainOutLineReverse::CtrlTrainOutLineReverse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTrainOutLineReverse)
{
    ui->setupUi(this);
}

CtrlTrainOutLineReverse::~CtrlTrainOutLineReverse()
{
    delete ui;
}
