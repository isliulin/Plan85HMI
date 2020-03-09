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
    this->ui->LBLDate->setText(QDateTime::currentDateTime().date().toString("yyyy-MM-dd"));
    this->ui->LBLTime->setText(QDateTime::currentDateTime().time().toString("hh:mm:ss"));

}
void Header::setPageName(QString name)
{
    this->ui->LBLPagename->setText(name);
}
void Header::updateLanguage()
{
    this->ui->retranslateUi(this);
}
