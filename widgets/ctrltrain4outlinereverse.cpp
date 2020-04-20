#include "ctrltrain4outlinereverse.h"
#include "ui_ctrltrain4outlinereverse.h"

CtrlTrain4OutLineReverse::CtrlTrain4OutLineReverse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTrain4OutLineReverse)
{
    ui->setupUi(this);
}

CtrlTrain4OutLineReverse::~CtrlTrain4OutLineReverse()
{
    delete ui;
}
