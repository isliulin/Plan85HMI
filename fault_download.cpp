#include "fault_download.h"
#include "ui_fault_download.h"

Fault_Download::Fault_Download(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_Download)
{
    ui->setupUi(this);
}

Fault_Download::~Fault_Download()
{
    delete ui;
}
