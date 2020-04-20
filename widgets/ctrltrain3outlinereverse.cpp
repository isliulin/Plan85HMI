#include "ctrltrain3outlinereverse.h"
#include "ui_ctrltrain3outlinereverse.h"

CtrlTrain3OutLineReverse::CtrlTrain3OutLineReverse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTrain3OutLineReverse)
{
    ui->setupUi(this);
}

CtrlTrain3OutLineReverse::~CtrlTrain3OutLineReverse()
{
    delete ui;
}
