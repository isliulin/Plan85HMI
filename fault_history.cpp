#include "fault_history.h"
#include "ui_fault_history.h"

Fault_History::Fault_History(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_History)
{
    ui->setupUi(this);
}

Fault_History::~Fault_History()
{
    delete ui;
}
