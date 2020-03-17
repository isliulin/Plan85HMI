#include "main_panto.h"
#include "ui_main_panto.h"

Main_Panto::Main_Panto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Panto)
{
    ui->setupUi(this);
}

Main_Panto::~Main_Panto()
{
    delete ui;
}
