#include "vehiclerunstatepage.h"
#include "ui_vehiclerunstatepage.h"

#define FAULTLEVEL1 "background-color:rgb(240,0,0);color:black;border:transparent;"
#define FAULTLEVEL2 "background-color:rgb(240,240,0);color:black;border:transparent;"
#define FAULTLEVEL3 "background-color:rgb(0,0,0);color:rgb(248,248,248);border:transparent;"

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

}

VehicleRunStatePage::~VehicleRunStatePage()
{
    delete ui;
}

void VehicleRunStatePage::updatePage()
{
    ui->LBLFault1->setStyleSheet(FAULTLEVEL1);
    ui->LBLFault2->setStyleSheet(FAULTLEVEL2);
    ui->LBLFault3->setStyleSheet(FAULTLEVEL3);
    static int i   = 0;
    i +=10;
    ctrlNetVoltage->setCtrlValueRect(i/10);
    ctrlNetCurrent->setCtrlValueRect(i);
    ctrlControlVoltage->setCtrlValueRect(i,i);
    ctrlTracBrake->setCtrlValueRect(i/10,i/10%2,i/10%3);

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

//    //常用制动状态
//    t_style<<CHANGYONGZHIDONGSHIJIA<<CHANGYONGZHIDONGGELI<<CHANGYONGZHIDONGHUANJIE<<NULLIMAGE;
//    t_status<<(database->data_TCN->TrainLocal->B_CMD_MSCT_T)<<(database->data_TCN->TrainLocal->B_CMD_MSCT_B)<<true;
//    setLBLpic(ui->LBLC14,t_status,t_style);


}
void VehicleRunStatePage::showEvent(QShowEvent *)
{

}

void VehicleRunStatePage::on_BTNMinus1_clicked()
{

}

void VehicleRunStatePage::on_BTNPlus1_clicked()
{

}
