#include "maindata_tracbrakeoutline.h"
#include "ui_maindata_tracbrakeoutline.h"

MainData_TracBrakeOutline::MainData_TracBrakeOutline(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MainData_TracBrakeOutline)
{
    ui->setupUi(this);
}

MainData_TracBrakeOutline::~MainData_TracBrakeOutline()
{
    delete ui;
}

void MainData_TracBrakeOutline::updatePage()
{
    //this->database->data_TCN->train[4]->B_CMD_T_CHAR_Z
}
