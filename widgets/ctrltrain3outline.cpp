#include "ctrltrain3outline.h"
#include "ui_ctrltrain3outline.h"

CtrlTrain3OutLine::CtrlTrain3OutLine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTrain3OutLine)
{
    ui->setupUi(this);
}

CtrlTrain3OutLine::~CtrlTrain3OutLine()
{
    delete ui;
}
