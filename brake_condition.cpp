#include "brake_condition.h"
#include "ui_brake_condition.h"

Brake_Condition::Brake_Condition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Brake_Condition)
{
    ui->setupUi(this);
}

Brake_Condition::~Brake_Condition()
{
    delete ui;
}
