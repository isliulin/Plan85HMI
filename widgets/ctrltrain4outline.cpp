#include "ctrltrain4outline.h"
#include "ui_ctrltrain4outline.h"

CtrlTrain4OutLine::CtrlTrain4OutLine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTrain4OutLine)
{
    ui->setupUi(this);
}

CtrlTrain4OutLine::~CtrlTrain4OutLine()
{
    delete ui;
}
