#include "navigator.h"
#include "ui_navigator.h"

Navigator::Navigator(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Navigator)
{
    ui->setupUi(this);

    buttons<<this->ui->NButton1<<this->ui->NButton2<<this->ui->NButton3<<this->ui->NButton4<<this->ui->NButton5
            <<this->ui->NButton6<<this->ui->NButton7<<this->ui->NButton8<<this->ui->NButton9<<this->ui->NButton10;

    foreach (QPushButton *button, buttons)
    {
        connect(button, SIGNAL(pressed()), this, SLOT(NBpressEvent()));
    }

    buttonIndexList<<uMainData_TrainOutline<<uSettng_Bypass<<uCondition_PantoUp<<
                 uDeviceData_breaker<<uMain_Simulate<<uNULL<<uNULL<<uNULL<<uFault_Current<<uUniteMode;
    buttonNameList<<"主要\n数据"<<"机车\n设置"<<"运行\n条件"<<"设备\n数据"<<"维护\n测试"
                    <<""<<""<<""<<"故障\n查询"<<"合屏\n模式";
    m_oldposition = m_position = uMiddleTraction;
    m_ButtonIndex = 0;
}

Navigator::~Navigator()
{
    delete ui;
}
void Navigator::NBpressEvent()
{
    m_ButtonIndex = ((QPushButton *)this->sender())->whatsThis().toInt();
    for(int i = 0; i < buttons.size();i++)
    {
        buttons[i]->setStyleSheet(NButtonUP);
    }


    buttonIndexList.clear();
    switch (m_position)
    {
        case uMiddleTraction:
        buttonIndexList<<uMainData_TrainOutline<<uSettng_Bypass<<uCondition_PantoUp<<uDeviceData_breaker<<
                     uMain_Simulate<<uNULL<<uNULL<<uNULL<<uFault_Current<<uUniteMode;
        break;
        case uMiddleMainData:
        buttonIndexList<<uMainData_TrainOutline<<uMainData_DriverOutline<<uMainData_TracBrakeOutline<<uNULL<<
                     uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uVehicleRunStatePage;
        break;
        case uMiddleSetting:
        buttonIndexList<<uSettng_Bypass<<uSettng_Panto<<uSettng_Distance<<uSettng_TrainCode<<
                     uSettng_Lubrication<<uSettng_Separation<<uSettng_HangMode<<uSettng_Others<<uNULL<<uVehicleRunStatePage;
        break;
    }
    changePage(buttonIndexList.at(((QPushButton *)this->sender())->whatsThis().toInt()));
}
void Navigator::updateButtonsNamesByPositon(enum pagePosition p)
{
    buttonNameList.clear();
    m_position = p;
    switch (p)
    {
        case uMiddleTraction:
        buttonNameList<<"主要\n数据"<<"机车\n设置"<<"运行\n条件"<<"设备\n数据"<<"维护\n测试"
                        <<""<<""<<""<<"故障\n查询"<<"合屏\n模式";
        break;
        case uMiddleMainData:
        buttonNameList<<"机车\n概述"<<"驱动\n概述"<<"牵引\n制动"<<""<<""
                        <<""<<""<<""<<""<<"主界面";
        break;
        case uMiddleSetting:
        buttonNameList<<"隔离"<<"受电弓"<<"距离\n计数"<<"车号\n设置"<<"轮缘\n润滑"
                        <<"分相\n线路"<<"挂车\n模式"<<"其他\n设置"<<""<<"主界面";
        break;
    }
    for(int i = 0; i < buttons.size();i++)
    {
        buttons[i]->setText(buttonNameList.at(i));
    }
    if(m_oldposition != m_position)//当前界面的类型和原先不同(界面Position变化时)，按钮按下保留在第一个按钮的位置
    {
        if(m_position == uMiddleTraction)
        {
            //回到牵引模式界面，无按钮按下
            for(int i = 0; i < buttons.size();i++)
            {
                buttons[i]->setStyleSheet(NButtonUP);
            }

        }else
        {
            ui->NButton1->setStyleSheet(NButtonDOWN);
        }
    }else
    {
        buttons[m_ButtonIndex]->setStyleSheet(NButtonDOWN);
    }
    m_oldposition = m_position;

}

void Navigator::updateLanguage()
{
    this->ui->retranslateUi(this);
}