#include "ctrlnetcurrent.h"
#include "ui_ctrlnetcurrent.h"

CtrlNetCurrent::CtrlNetCurrent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlNetCurrent)
{
    ui->setupUi(this);
}

CtrlNetCurrent::~CtrlNetCurrent()
{
    delete ui;
}
