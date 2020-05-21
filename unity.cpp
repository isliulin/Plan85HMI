#include "unity.h"
#include "ui_unity.h"

Unity::Unity(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Unity)
{
    ui->setupUi(this);

    ctrControlVoltage_Unity = new CtrControlVoltage_Unity(this);
    ctrControlVoltage_Unity->setGeometry(200,10,this->ctrControlVoltage_Unity->width(),this->ctrControlVoltage_Unity->height());

    ctrlNetCurrent_Unity = new CtrlNetCurrent_Unity(this);
    ctrlNetCurrent_Unity->setGeometry(105,10,this->ctrlNetCurrent_Unity->width(),this->ctrlNetCurrent_Unity->height());

    ctrlNetVoltage_Unity = new CtrlNetVoltage_Unity(this);
    ctrlNetVoltage_Unity->setGeometry(10,10,this->ctrlNetVoltage_Unity->width(),this->ctrlNetVoltage_Unity->height());

    ctrlTracBrake_Unity = new CtrlTracBrake_Unity(this);
    ctrlTracBrake_Unity->setGeometry(365,10,this->ctrlTracBrake_Unity->width(),this->ctrlTracBrake_Unity->height());

    ctrlSpeedometer1 = new CtrlSpeedometer(this);
    ctrlSpeedometer1 ->setGeometry(470,20,ctrlSpeedometer1->width(),ctrlSpeedometer1->height());

    ctrlSpeedometer2 = new CtrlSpeedometer(this);
    ctrlSpeedometer2 ->setGeometry(470,250,ctrlSpeedometer2->width(),ctrlSpeedometer2->height());

    ctrlFlowDiagram = new CtrlFlowDiagram(this);
    ctrlFlowDiagram ->setGeometry(690,160,ctrlFlowDiagram->width(),ctrlFlowDiagram->height());

}

Unity::~Unity()
{
    delete ui;
}
void Unity::updatePage()
{
    static int i   = 0;
    i +=10;

    ctrlNetVoltage_Unity->setCtrlValueRect(database->data_TCN->TrainLocal->N_Voltage_U8);
    ctrlNetCurrent_Unity->setCtrlValueRect(database->data_TCN->TrainLocal->N_Current_U8);
    ctrControlVoltage_Unity->setCtrlValueRect(database->data_TCN->train[database->data_CCU->M1_D1_N_UIC_ADDR-1]->N_BAT_VOLT,
            database->data_TCN->train[database->data_CCU->M1_D1_N_OTHERUIC_ADDR-1]->N_BAT_VOLT);

    ctrlTracBrake_Unity->setCtrlValueRect(database->data_TCN->TrainLocal->N_BAT_VOLT);

    ctrlSpeedometer1->setSpeenometerValue(i);
    ctrlSpeedometer2->setSpeenometerValue(i);
    ctrlFlowDiagram->setCtrlValueRect(i);

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


}

void Unity::showEvent(QShowEvent *)
{

}
