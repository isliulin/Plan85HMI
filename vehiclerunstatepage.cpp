#include "vehiclerunstatepage.h"
#include "ui_vehiclerunstatepage.h"
#include "crrcfault.h"
#define FAULTLEVEL1 "background-color:rgb(240,0,0);color:black;border:transparent;border-bottom:1px solid black;"
#define FAULTLEVEL2 "background-color:rgb(240,240,0);color:black;border:transparent;border-bottom:1px solid black;"
#define FAULTLEVEL3 "background-color:rgb(0,0,0);color:rgb(248,248,248);border:transparent;border-bottom:1px solid black;"
#define MAXCNTPERPAGE 7

VehicleRunStatePage::VehicleRunStatePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::VehicleRunStatePage)
{
    ui->setupUi(this);

    ctrlNetVoltage = new CtrlNetVoltage(this);
    ctrlNetVoltage->setGeometry(10,10,this->ctrlNetVoltage->width(),this->ctrlNetVoltage->height());

    ctrlNetCurrent = new CtrlNetCurrent(this);
    ctrlNetCurrent->setGeometry(105,10,this->ctrlNetCurrent->width(),this->ctrlNetCurrent->height());

    ctrlControlVoltage = new CtrlControlVoltage(this);
    ctrlControlVoltage->setGeometry(200,10,this->ctrlControlVoltage->width(),this->ctrlControlVoltage->height());

    ctrlTracBrake = new CtrlTracBrake(this);
    ctrlTracBrake->setGeometry(365,10,this->ctrlTracBrake->width(),this->ctrlTracBrake->height());

    timer3s = new QTimer();
    connect(timer3s,SIGNAL(timeout()),this,SLOT(timer3sEvent()));

    FirstFaultIndex = 0;
    labellist<<ui->LBLFault1<<ui->LBLFault2<<ui->LBLFault3<<ui->LBLFault4<<ui->LBLFault5<<ui->LBLFault6<<ui->LBLFault7;

    m_currentPageIndex  = 1;
    m_totalPageIndex = 1;
    m_currentPageFaultNum = 0;
    m_totalFaultNum = 0;

}

VehicleRunStatePage::~VehicleRunStatePage()
{
    delete ui;
}

void VehicleRunStatePage::updatePage()
{

    this->FaultRoll();

    ctrlNetVoltage->setCtrlValueRect(database->data_TCN->TrainLocal->N_Voltage_U8);
    ctrlNetCurrent->setCtrlValueRect(database->data_TCN->TrainLocal->N_Current_U8);
    ctrlControlVoltage->setCtrlValueRect(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->N_BAT_VOLT,
            database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->N_BAT_VOLT);

    ctrlTracBrake->setCtrlValueRect(database->data_TCN->TrainLocal->N_BAT_VOLT);

    //eg
    QList<bool> t_status;
    QList<QString> t_style;

    //方向
    t_style<<FANGXIANGZHONGLI<<FANGXIANGXIANGHOU<<FANGXIANGXIANGQIAN<<NULLIMAGE;
    t_status<<database->data_TCN->TrainLocal->B_CMD_DIR_N<<database->data_TCN->TrainLocal->B_CMD_DIR_B<<database->data_TCN->TrainLocal->B_CMD_DIR_f<<true;
    setLBLpic(ui->LBLC11,t_status,t_style);

    //分相
    t_style<<FENXIANGQU<<NULLIMAGE;
    t_status<<(database->data_CCU->M1_D1_B_NSC_START||database->data_CCU->M1_D1_B_NSC_START)<<true;
    setLBLpic(ui->LBLC21,t_status,t_style);

    //受电弓
    t_style<<PANTO12UP<<PANTO1DOWN2UP<<PANTO1UP2ISO<<PANTO1ISO2UP<<PANTO1DOWN2ISO<<PANTOISO<<PANTO1UP2DOWN<<PANTO12DOWN<<PANTO1ISO2DOWN<<NULLIMAGE;
    t_status<<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_RD&&database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_PANTO_RD)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_DN&&database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_PANTO_RD)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_RD&&database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_PANTO_ISO)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_ISO&&database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_PANTO_RD)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_DN&&database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_PANTO_ISO)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_ISO&&database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_PANTO_ISO)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_RD)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_DN)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_PANTO_ISO)
            <<true;
    setLBLpic(ui->LBLC12,t_status,t_style);

    //主断路器
    t_style<<ZHUDUANBIHE<<ZHUDUANDUANKAI<<ZHUDUANJIUXU<<ZHUDUANGELI<<NULLIMAGE;
    t_status<<(database->data_TCN->TrainLocal->B_STATE_QFM_ON)<<(database->data_TCN->TrainLocal->B_STATE_QFM_ISO)
            <<(database->data_TCN->TrainLocal->B_STATE_QFM_K)<<(database->data_TCN->TrainLocal->B_STATE_QFM_FAULT)
            <<true;
    setLBLpic(ui->LBLC13,t_status,t_style);

    t_style<<ZHUDUANBIHE<<ZHUDUANDUANKAI<<ZHUDUANJIUXU<<ZHUDUANGELI<<NULLIMAGE;
    t_status<<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_QFM_ON)<<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_QFM_ISO)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_QFM_K)<<(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->B_STATE_QFM_FAULT)
            <<true;
    setLBLpic(ui->LBLC22,t_status,t_style);

    t_style<<ZHUDUANBIHE<<ZHUDUANDUANKAI<<ZHUDUANJIUXU<<ZHUDUANGELI<<NULLIMAGE;
    t_status<<(database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_QFM_ON)<<(database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_QFM_ISO)
            <<(database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_QFM_K)<<(database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->B_STATE_QFM_FAULT)
            <<true;
    setLBLpic(ui->LBLC23,t_status,t_style);

    //牵引/电制动状态
    t_style<<QIANYIN<<ZHIDONG<<NULLIMAGE;
    t_status<<(database->data_TCN->TrainLocal->B_CMD_MSCT_T)<<(database->data_TCN->TrainLocal->B_CMD_MSCT_B)<<true;
    setLBLpic(ui->LBLC14,t_status,t_style);

    //空转
    t_style<<KONGZHUAN<<HUAXING<<NULLIMAGE;
    t_status<<(database->data_CCU->M1_D1_B_RACING)<<(database->data_CCU->M1_D1_B_SLIP)<<true;
    setLBLpic(ui->LBLC15,t_status,t_style);

    //停放制动
    t_style<<TINGFANGZHIDONGGELI<<TINGFANGZHIDONGSHIJIA<<TINGFANGZHIDONGHUANJIE<<NULLIMAGE;
    t_status<<(database->data_TCN->TrainLocal->B_STATE_PARK_BRK_I)<<(database->data_TCN->TrainLocal->B_STATE_PARK_BRK_ON)
           <<(database->data_TCN->TrainLocal->B_STATE_PARK_BRK_REL)<<true;
    setLBLpic(ui->LBLC25,t_status,t_style);

    //撒沙
    t_style<<SASHA<<NULLIMAGE;
    t_status<<(database->data_CCU->M1_D1_B_SANDING)<<true;
    setLBLpic(ui->LBLC16,t_status,t_style);

    //紧急制动 惩罚制动
    t_style<<CHENGFAZHIDONG<<JINJIZHIDONG<<NULLIMAGE;
    t_status<<(database->data_TCN->TrainLocal->B_STATE_PENALTY_ON)<<(database->data_TCN->TrainLocal->B_STATE_EMG_BRK_ON)<<true;
    setLBLpic(ui->LBLC26,t_status,t_style);

    //定速
    t_style<<DINGSUMOSHI<<NULLIMAGE;
    t_status<<(database->data_CCU->M1_D1_B_SPEED_CTL)<<true;
    setLBLpic(ui->LBLC19,t_status,t_style);

    //常用制动状态
    t_style<<CHANGYONGZHIDONGGELI<<CHANGYONGZHIDONGSHIJIA<<CHANGYONGZHIDONGHUANJIE;
    t_status<<(database->data_TCN->train[0]->B_STATE_AIR_BRK1_I || database->data_TCN->train[1]->B_STATE_AIR_BRK1_I ||
               database->data_TCN->train[2]->B_STATE_AIR_BRK1_I ||database->data_TCN->train[3]->B_STATE_AIR_BRK1_I||
               database->data_TCN->train[0]->B_STATE_AIR_BRK2_I || database->data_TCN->train[1]->B_STATE_AIR_BRK2_I ||
               database->data_TCN->train[2]->B_STATE_AIR_BRK2_I ||database->data_TCN->train[3]->B_STATE_AIR_BRK2_I)
            <<(database->data_TCN->train[0]->B_STATE_AIR_BRK1_ON || database->data_TCN->train[1]->B_STATE_AIR_BRK1_ON ||
               database->data_TCN->train[2]->B_STATE_AIR_BRK1_ON ||database->data_TCN->train[3]->B_STATE_AIR_BRK1_ON ||
               database->data_TCN->train[0]->B_STATE_AIR_BRK2_ON || database->data_TCN->train[1]->B_STATE_AIR_BRK2_ON ||
               database->data_TCN->train[2]->B_STATE_AIR_BRK2_ON ||database->data_TCN->train[3]->B_STATE_AIR_BRK2_ON)
            <<true;
    setLBLpic(ui->LBLC24,t_status,t_style);

    //级位
    setLBLtext(ui->LBLGrade,(database->data_CCU->M1_D1_N_MSCT_GRD-200),10,1);
    setLBLtext(ui->LBLSetSpeed,database->data_CCU->M1_D1_N_SET_SPEED);
    setLBLtext(ui->LBLSpeed,database->data_CCU->M1_D1_N_ACTUAL_SPEED,10);


}
void VehicleRunStatePage::FaultRoll()
{
    m_totalFaultNum = CrrcFault::getCrrcFault()->getCurrentFaultListSize();

       if(m_totalFaultNum < 1)
       {
           timer3s->stop();
           for(int i = 0; i < MAXCNTPERPAGE; i++)
           {
               labellist.at(i)->setText("");
               labellist.at(i)->setStyleSheet(FAULTLEVEL3);
           }
           return ;
       }

       if(timer3s->isActive())
       {

       }else
       {
           timer3s->start(3000);
       }
       if(m_totalFaultNum%MAXCNTPERPAGE == 0)
       {
           m_totalPageIndex = m_totalFaultNum/MAXCNTPERPAGE;
           m_currentPageFaultNum = MAXCNTPERPAGE;
       }
       else
       {
           m_totalPageIndex = m_totalFaultNum/MAXCNTPERPAGE+1;
           if(m_currentPageIndex<m_totalPageIndex)
           {
               m_currentPageFaultNum = MAXCNTPERPAGE;
           }else
           {
               m_currentPageFaultNum = m_totalFaultNum%MAXCNTPERPAGE;
           }
       }

       if(m_currentPageIndex > m_totalPageIndex)
           m_currentPageIndex = m_totalPageIndex;

       if(m_currentPageIndex < m_totalPageIndex)
       {
           for(int i = 0; i < MAXCNTPERPAGE;i++)
           {
               this->DrawFaults(i);
           }

       }else
       {
           for(int i = 0; i < MAXCNTPERPAGE; i++)
           {
               if(i < m_currentPageFaultNum)
               {
                   this->DrawFaults(i);
               }else
               {
                   labellist.at(i)->setText("");
                   labellist.at(i)->setStyleSheet(FAULTLEVEL3);
               }

           }
       }
}

void VehicleRunStatePage::showEvent(QShowEvent *)
{

}

void VehicleRunStatePage::on_BTNMinus1_clicked()
{
    if(this->database->data_CCU->N_SIM_SPEED>0)
    this->database->data_CCU->N_SIM_SPEED--;
}

void VehicleRunStatePage::on_BTNPlus1_clicked()
{
    this->database->data_CCU->N_SIM_SPEED++;
}
void VehicleRunStatePage::DrawFaults(int i)
{
    QString Num = QString::number(i+(m_currentPageIndex-1)*MAXCNTPERPAGE+1);
    this->labellist.at(i)->setText(CrrcFault::getCrrcFault()->getCurrentFaultName(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    if(CrrcFault::getCrrcFault()->getCurrentFaultLevel(i+(m_currentPageIndex-1)*MAXCNTPERPAGE) == "1")
        this->labellist.at(i)->setStyleSheet(FAULTLEVEL1);
    else if(CrrcFault::getCrrcFault()->getCurrentFaultLevel(i+(m_currentPageIndex-1)*MAXCNTPERPAGE) == "2")
        this->labellist.at(i)->setStyleSheet(FAULTLEVEL2);
    else if(CrrcFault::getCrrcFault()->getCurrentFaultLevel(i+(m_currentPageIndex-1)*MAXCNTPERPAGE) == "3")
        this->labellist.at(i)->setStyleSheet(FAULTLEVEL3);
}
void VehicleRunStatePage::timer3sEvent()
{
    m_currentPageIndex++;
    if(m_currentPageIndex > m_totalPageIndex)
        m_currentPageIndex = 1;
}
