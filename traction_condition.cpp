#include "traction_condition.h"
#include "ui_traction_condition.h"

Traction_Condition::Traction_Condition(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Traction_Condition)
{
    ui->setupUi(this);
}

Traction_Condition::~Traction_Condition()
{
    delete ui;
}
