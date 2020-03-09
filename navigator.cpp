#include "navigator.h"
#include "ui_navigator.h"

Navigator::Navigator(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Navigator)
{
    ui->setupUi(this);

    buttons<<this->ui->NButton1<<this->ui->NButton2<<this->ui->NButton3<<this->ui->NButton5<<this->ui->NButton4
            <<this->ui->NButton6<<this->ui->NButton7<<this->ui->NButton8<<this->ui->NButton9<<this->ui->NButton10;

    foreach (QPushButton *button, buttons)
    {
        connect(button, SIGNAL(pressed()), this, SLOT(NBpressEvent()));
    }
}

Navigator::~Navigator()
{
    delete ui;
}
void Navigator::NBpressEvent()
{
    QString BTNname = ((QPushButton *)this->sender())->objectName();
    for(int i = 0; i < buttons.size();i++)
    {
        buttons[i]->setStyleSheet(NButtonUP);
    }
    ((QPushButton *)this->sender())->setStyleSheet(NButtonDOWN);
//    if(BTNname == "NButton9")
//    {
//        emit translateLanguage();
//    }
}

void Navigator::updateLanguage()
{
    this->ui->retranslateUi(this);
}
