#include "fault_current.h"
#include "ui_fault_current.h"
#include "crrcfault.h"
#include "qdebug.h"

#define MAXCNTPERPAGE 15
#define COLUMN        10

Fault_Current::Fault_Current(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_Current)
{
    ui->setupUi(this);
    totalPage=1;
    currentFaultPage=1;

    QList<QLabel *> temp;
    temp<<ui->lbl_1_1<<ui->lbl_1_2<<ui->lbl_1_3<<ui->lbl_1_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_2_1<<ui->lbl_2_2<<ui->lbl_2_3<<ui->lbl_2_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_3_1<<ui->lbl_3_2<<ui->lbl_3_3<<ui->lbl_3_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_4_1<<ui->lbl_4_2<<ui->lbl_4_3<<ui->lbl_4_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_5_1<<ui->lbl_5_2<<ui->lbl_5_3<<ui->lbl_5_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_6_1<<ui->lbl_6_2<<ui->lbl_6_3<<ui->lbl_6_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_7_1<<ui->lbl_7_2<<ui->lbl_7_3<<ui->lbl_7_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_8_1<<ui->lbl_8_2<<ui->lbl_8_3<<ui->lbl_8_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_9_1<<ui->lbl_9_2<<ui->lbl_9_3<<ui->lbl_9_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_10_1<<ui->lbl_10_2<<ui->lbl_10_3<<ui->lbl_10_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_11_1<<ui->lbl_11_2<<ui->lbl_11_3<<ui->lbl_11_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_12_1<<ui->lbl_12_2<<ui->lbl_12_3<<ui->lbl_12_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_13_1<<ui->lbl_13_2<<ui->lbl_13_3<<ui->lbl_13_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_14_1<<ui->lbl_14_2<<ui->lbl_14_3<<ui->lbl_14_4;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_15_1<<ui->lbl_15_2<<ui->lbl_15_3<<ui->lbl_15_4;
    labelsList.push_back(temp);
    temp.clear();

}

Fault_Current::~Fault_Current()
{
    delete ui;
}

void Fault_Current::updatePage()
{
    int totalNumber=CrrcFault::getCrrcFault()->getCurrentFaultListSize();

    totalPage=totalNumber/MAXCNTPERPAGE;

    if(totalPage==0)
        totalPage=1;

    if(totalNumber%MAXCNTPERPAGE!=0)
    {
        totalPage++;
        currenFaultNumber=totalNumber%MAXCNTPERPAGE;
    }
    else
    {
        currenFaultNumber=MAXCNTPERPAGE;
    }

    ui->lbl_totalPage->setText(QString::number(totalPage));
    ui->lbl_currentPage->setText(QString::number(currentFaultPage));
    if(totalNumber!=0)
        updateFaultList();
}

void Fault_Current::updateFaultList()
{
    if(currentFaultPage!=totalPage)
    {
        for(int i=0;i<MAXCNTPERPAGE;i++)
        {
                labelsList.at(i).at(0)->setText(CrrcFault::getCrrcFault()->getCurrentFaultCode(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(1)->setText(CrrcFault::getCrrcFault()->getCurrentFaultDate(i+(currentFaultPage-1)*MAXCNTPERPAGE)+" "+
                                                CrrcFault::getCrrcFault()->getCurrentFaultTime(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(2)->setText(CrrcFault::getCrrcFault()->getCurrentFaultDescription(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(3)->setText(CrrcFault::getCrrcFault()->getCurrentFaultLevel(i+(currentFaultPage-1)*MAXCNTPERPAGE));

        }
    }
    else
    {
        for(int i=0;i<MAXCNTPERPAGE;i++)
        {

            if(i<currenFaultNumber)
            {
                labelsList.at(i).at(0)->setText(CrrcFault::getCrrcFault()->getCurrentFaultCode(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(1)->setText(CrrcFault::getCrrcFault()->getCurrentFaultDate(i+(currentFaultPage-1)*MAXCNTPERPAGE)+" "+
                                                CrrcFault::getCrrcFault()->getCurrentFaultTime(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(2)->setText(CrrcFault::getCrrcFault()->getCurrentFaultDescription(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(3)->setText(CrrcFault::getCrrcFault()->getCurrentFaultLevel(i+(currentFaultPage-1)*MAXCNTPERPAGE));

            }
            else
            {
                for(int j=0;j<COLUMN;j++)
                {
                     labelsList.at(i).at(j)->setText("");
                }
            }

        }
    }
}

void Fault_Current::on_PB_up_pressed()
{
    if(currentFaultPage>1)
        currentFaultPage--;
    ui->PB_up->setStyleSheet(NButtonDOWN);
}

void Fault_Current::on_PB_down_pressed()
{
    if(totalPage>currentFaultPage)
        currentFaultPage++;
    ui->PB_down->setStyleSheet(NButtonDOWN);
}

void Fault_Current::on_PB_up_released()
{
    ui->PB_up->setStyleSheet(NButtonUP);
}

void Fault_Current::on_PB_down_released()
{
    ui->PB_down->setStyleSheet(NButtonUP);
}
