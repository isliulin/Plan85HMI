#include "main_380.h"
#include "ui_main_380.h"

Main_380::Main_380(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_380)
{
    ui->setupUi(this);
}

Main_380::~Main_380()
{
    delete ui;
}

void Main_380::on_PB_active_pressed()
{
    ui->PB_active->setStyleSheet(MAINBUTTONDOWN);
    ui->PB_cancel->setStyleSheet(MAINBUTTONUP);
}

void Main_380::on_PB_cancel_pressed()
{
    ui->PB_active->setStyleSheet(MAINBUTTONUP);
    ui->PB_cancel->setStyleSheet(MAINBUTTONDOWN);
}
