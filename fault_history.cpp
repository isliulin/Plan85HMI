#include "fault_history.h"
#include "ui_fault_history.h"
#include "crrcfault.h"

#include "qdebug.h"

#define MAXCNTPERPAGE 15
#define COLUMN        10

Fault_History::Fault_History(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_History)
{
    ui->setupUi(this);
    totalPage=1;
    currentFaultPage=1;

    QList<QLabel *> temp;
    temp<<ui->lbl_1_1<<ui->lbl_1_2<<ui->lbl_1_3<<ui->lbl_1_4<<ui->lbl_1_5<<ui->lbl_1_6<<ui->lbl_1_7<<ui->lbl_1_8<<ui->lbl_1_9<<ui->lbl_1_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_2_1<<ui->lbl_2_2<<ui->lbl_2_3<<ui->lbl_2_4<<ui->lbl_2_5<<ui->lbl_2_6<<ui->lbl_2_7<<ui->lbl_2_8<<ui->lbl_2_9<<ui->lbl_2_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_3_1<<ui->lbl_3_2<<ui->lbl_3_3<<ui->lbl_3_4<<ui->lbl_3_5<<ui->lbl_3_6<<ui->lbl_3_7<<ui->lbl_3_8<<ui->lbl_3_9<<ui->lbl_3_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_4_1<<ui->lbl_4_2<<ui->lbl_4_3<<ui->lbl_4_4<<ui->lbl_4_5<<ui->lbl_4_6<<ui->lbl_4_7<<ui->lbl_4_8<<ui->lbl_4_9<<ui->lbl_4_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_5_1<<ui->lbl_5_2<<ui->lbl_5_3<<ui->lbl_5_4<<ui->lbl_5_5<<ui->lbl_5_6<<ui->lbl_5_7<<ui->lbl_5_8<<ui->lbl_5_9<<ui->lbl_5_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_6_1<<ui->lbl_6_2<<ui->lbl_6_3<<ui->lbl_6_4<<ui->lbl_6_5<<ui->lbl_6_6<<ui->lbl_6_7<<ui->lbl_6_8<<ui->lbl_6_9<<ui->lbl_6_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_7_1<<ui->lbl_7_2<<ui->lbl_7_3<<ui->lbl_7_4<<ui->lbl_7_5<<ui->lbl_7_6<<ui->lbl_7_7<<ui->lbl_7_8<<ui->lbl_7_9<<ui->lbl_7_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_8_1<<ui->lbl_8_2<<ui->lbl_8_3<<ui->lbl_8_4<<ui->lbl_8_5<<ui->lbl_8_6<<ui->lbl_8_7<<ui->lbl_8_8<<ui->lbl_8_9<<ui->lbl_8_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_9_1<<ui->lbl_9_2<<ui->lbl_9_3<<ui->lbl_9_4<<ui->lbl_9_5<<ui->lbl_9_6<<ui->lbl_9_7<<ui->lbl_9_8<<ui->lbl_9_9<<ui->lbl_9_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_10_1<<ui->lbl_10_2<<ui->lbl_10_3<<ui->lbl_10_4<<ui->lbl_10_5<<ui->lbl_10_6<<ui->lbl_10_7<<ui->lbl_10_8<<ui->lbl_10_9<<ui->lbl_10_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_11_1<<ui->lbl_11_2<<ui->lbl_11_3<<ui->lbl_11_4<<ui->lbl_11_5<<ui->lbl_11_6<<ui->lbl_11_7<<ui->lbl_11_8<<ui->lbl_11_9<<ui->lbl_11_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_12_1<<ui->lbl_12_2<<ui->lbl_12_3<<ui->lbl_12_4<<ui->lbl_12_5<<ui->lbl_12_6<<ui->lbl_12_7<<ui->lbl_12_8<<ui->lbl_12_9<<ui->lbl_12_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_13_1<<ui->lbl_13_2<<ui->lbl_13_3<<ui->lbl_13_4<<ui->lbl_13_5<<ui->lbl_13_6<<ui->lbl_13_7<<ui->lbl_13_8<<ui->lbl_13_9<<ui->lbl_13_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_14_1<<ui->lbl_14_2<<ui->lbl_14_3<<ui->lbl_14_4<<ui->lbl_14_5<<ui->lbl_14_6<<ui->lbl_14_7<<ui->lbl_14_8<<ui->lbl_14_9<<ui->lbl_14_10;
    labelsList.push_back(temp);
    temp.clear();

    temp<<ui->lbl_15_1<<ui->lbl_15_2<<ui->lbl_15_3<<ui->lbl_15_4<<ui->lbl_15_5<<ui->lbl_15_6<<ui->lbl_15_7<<ui->lbl_15_8<<ui->lbl_15_9<<ui->lbl_15_10;
    labelsList.push_back(temp);
    temp.clear();

}

Fault_History::~Fault_History()
{
    delete ui; 
}


void Fault_History::updatePage()
{
    int totalNumber=CrrcFault::getCrrcFault()->getHistoryFaultListSize();
    if(totalNumber<0)
        return;
    totalPage=totalNumber/MAXCNTPERPAGE;
    if(totalNumber%MAXCNTPERPAGE!=0)
    {
        totalPage++;
        currenFaultNumber=totalNumber%MAXCNTPERPAGE;
    }
    else
    {
        currenFaultNumber=MAXCNTPERPAGE;
    }

    ui->lbl_totalNumber->setText(QString::number(totalPage));
    ui->lbl_number->setText(QString::number(currentFaultPage));
    if(totalNumber!=0)
        updateFaultList();

}

void Fault_History::on_PB_up_pressed()
{
    if(currentFaultPage>1)
        currentFaultPage--;
    ui->PB_up->setStyleSheet(NButtonDOWN);
}

void Fault_History::on_PB_down_pressed()
{
    if(totalPage>currentFaultPage)
        currentFaultPage++;
    ui->PB_down->setStyleSheet(NButtonDOWN);
}


void Fault_History::updateFaultList()
{

    if(currentFaultPage!=totalPage)
    {
        for(int i=0;i<MAXCNTPERPAGE;i++)
        {
             labelsList.at(i).at(0)->setText(QString::number(i+(currentFaultPage-1)*MAXCNTPERPAGE+1));
             labelsList.at(i).at(1)->setText(CrrcFault::getCrrcFault()->getHistoryFaultCode(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(2)->setText(CrrcFault::getCrrcFault()->getHistoryFaultStartDate(i+(currentFaultPage-1)*MAXCNTPERPAGE)+
                                                CrrcFault::getCrrcFault()->getHistoryFaultStartTime(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(3)->setText(CrrcFault::getCrrcFault()->getHistoryFaultName(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(4)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Speed(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(5)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Voltage(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(6)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Current(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(7)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Direction(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(8)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Grade(i+(currentFaultPage-1)*MAXCNTPERPAGE));
             labelsList.at(i).at(9)->setText(CrrcFault::getCrrcFault()->getHistoryFaultLevel(i+(currentFaultPage-1)*MAXCNTPERPAGE));

        }
    }
    else
    {
        for(int i=0;i<MAXCNTPERPAGE;i++)
        {

            if(i<currenFaultNumber)
            {
                labelsList.at(i).at(0)->setText(QString::number(i+(currentFaultPage-1)*MAXCNTPERPAGE+1));
                labelsList.at(i).at(1)->setText(CrrcFault::getCrrcFault()->getHistoryFaultCode(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(2)->setText(CrrcFault::getCrrcFault()->getHistoryFaultStartDate(i+(currentFaultPage-1)*MAXCNTPERPAGE)+
                                                CrrcFault::getCrrcFault()->getHistoryFaultStartTime(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(3)->setText(CrrcFault::getCrrcFault()->getHistoryFaultName(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(4)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Speed(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(5)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Voltage(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(6)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Current(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(7)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Direction(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(8)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Grade(i+(currentFaultPage-1)*MAXCNTPERPAGE));
                labelsList.at(i).at(9)->setText(CrrcFault::getCrrcFault()->getHistoryFaultLevel(i+(currentFaultPage-1)*MAXCNTPERPAGE));
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

void Fault_History::on_PB_up_released()
{
    ui->PB_up->setStyleSheet(NButtonUP);
}

void Fault_History::on_PB_down_released()
{
    ui->PB_down->setStyleSheet(NButtonUP);
}
