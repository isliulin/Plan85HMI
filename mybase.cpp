#include "mybase.h"

MyBase::MyBase(QWidget *parent) :
    QWidget(parent)
{
    if (parent != NULL)
    {
        connect(this, SIGNAL(changePage(int)), parent, SLOT(changePage(int)));
    }
}

int MyBase::currentPage = uVehicleRunStatePage;
Database *MyBase::database = NULL;

void MyBase::setMyBase(pagePosition position, QString name)
{
    if (position == uTop)
    {
        this->setGeometry(0, 0, this->width(), this->height());
    }
    else if (position == uMiddle)
    {
        this->setGeometry(0, 36, this->width(), this->height());
    }
    else if (position == uBottom)
    {
        this->setGeometry(0, 536, this->width(), this->height());
    }
    else if (position == uHuge)
    {
        this->setGeometry(0, 0, this->width(), this->height());
    }else if (position == uMiddleTraction ||
              position == uMiddleMainData ||
              position == uMiddleSetting ||
              position == uMiddleCondition ||
              position == uMiddleDeviceData ||
              position == uMiddleMain ||
              position == uMiddleFault ||
              position == uMiddleUnite)
    {
        this->setGeometry(0, 36, this->width(), this->height());
    }

    this->name = name;
    this->Position = position;

    this->hide();
}
void MyBase::updateLanguage()
{

}
void MyBase::updatePage()
{

}
void MyBase::processKeyboardEvent(keyboardIndex k)
{

}
