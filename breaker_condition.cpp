#include "breaker_condition.h"
#include "ui_breaker_condition.h"

Breaker_Condition::Breaker_Condition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Breaker_Condition)
{
    ui->setupUi(this);
}

Breaker_Condition::~Breaker_Condition()
{
    delete ui;
}
