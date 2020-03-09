#include "header.h"
#include "ui_header.h"
#include "qdatetime.h"
#include "qdebug.h"
Header::Header(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Header)
{
    ui->setupUi(this);
}

Header::~Header()
{
    delete ui;
}
void Header::updatePage()
{
    this->ui->DateTime->setText(QDateTime::currentDateTime().date().toString("yyyy-MM-dd")+"\n"+QDateTime::currentDateTime().time().toString("hh:mm:ss"));
}
void Header::setPageName(QString name)
{
    this->ui->PageName->setText(name);
}


void Header::on_HelpItemBtn_pressed()
{

}

void Header::on_CurrentFaultBtn_pressed()
{

}
void Header::updateLanguage()
{
    this->ui->retranslateUi(this);
}
