#include "settng_panto.h"
#include "ui_settng_panto.h"

#define TRAINDOWNL "border:1px solid white;image: url(:/images/images/TrainLogo.png);"
#define TRAINUPL "border:1px solid white;image: url(:/images/images/Cheti.png);"
#define TRAINDOWNR "border:1px solid white;image: url(:/images/images/TrainLogo-reverse.png);"
#define TRAINUPR "border:1px solid white;image: url(:/images/images/Cheti-reverse.png);"

#define HSOPEN "border-image: url(:/images/images/HSCutout.png);"
#define HSCLOSE "border-image: url(:/images/images/HSClose.png);"

Settng_Panto::Settng_Panto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Panto)
{
    ui->setupUi(this);
    this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
    TrainList<<this->ui->BTN_Train1<<this->ui->BTN_Train2<<this->ui->BTN_Train3<<this->ui->BTN_Train4;

    foreach (QPushButton* button, TrainList) {
        connect(button,SIGNAL(pressed()),this,SLOT(TrainSelectEvent()));
    }
    hideAllTrain();
}

Settng_Panto::~Settng_Panto()
{
    delete ui;
}

void Settng_Panto::updatePage()
{
    hideAllTrain();
    switch (this->database->data_CCU->M1_D1_N_RULOCO_NO) {
    case 0:
        show1Train();
        HSstate(this->ui->LBL_2HS1,this->database->data_TCN->train[0]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[0]->B_STATE_QS_HV1_ON);
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->N_LOCO_NO,16));
        Active(this->ui->LBL_2Active1,this->database->data_TCN->train[0]->B_STATE_CAB_ACT);
        break;
    case 1:
        show2Train();
        HSstate(this->ui->LBL_2HS1,this->database->data_TCN->train[0]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[0]->B_STATE_QS_HV1_ON);
        HSstate(this->ui->LBL_2HS2,this->database->data_TCN->train[1]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[1]->B_STATE_QS_HV1_ON);
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->N_LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->N_LOCO_NO,16));
        Active(this->ui->LBL_2Active1,this->database->data_TCN->train[0]->B_STATE_CAB_ACT);
        Active(this->ui->LBL_2Active2,this->database->data_TCN->train[1]->B_STATE_CAB_ACT);
        break;
    case 2:
        show3Train();
        HSstate(this->ui->LBL_4HS1,this->database->data_TCN->train[0]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[0]->B_STATE_QS_HV1_ON);
        HSstate(this->ui->LBL_4HS2,this->database->data_TCN->train[1]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[1]->B_STATE_QS_HV1_ON);
        HSstate(this->ui->LBL_4HS3,this->database->data_TCN->train[2]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[2]->B_STATE_QS_HV1_ON);
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->N_LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->N_LOCO_NO,16));
        this->ui->LBL_Train3Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[2]->N_LOCO_NO,16));
        Active(this->ui->LBL_4Active1,this->database->data_TCN->train[0]->B_STATE_CAB_ACT);
        Active(this->ui->LBL_4Active2,this->database->data_TCN->train[1]->B_STATE_CAB_ACT);
        Active(this->ui->LBL_4Active3,this->database->data_TCN->train[2]->B_STATE_CAB_ACT);
        break;
    case 3:
        show4Train();
        HSstate(this->ui->LBL_2HS1,this->database->data_TCN->train[0]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[0]->B_STATE_QS_HV1_ON);
        HSstate(this->ui->LBL_2HS1,this->database->data_TCN->train[1]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[1]->B_STATE_QS_HV1_ON);
        HSstate(this->ui->LBL_2HS1,this->database->data_TCN->train[2]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[2]->B_STATE_QS_HV1_ON);
        HSstate(this->ui->LBL_2HS1,this->database->data_TCN->train[3]->B_STATE_QS_HV1_OFF,this->database->data_TCN->train[3]->B_STATE_QS_HV1_ON);
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->N_LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->N_LOCO_NO,16));
        this->ui->LBL_Train3Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[2]->N_LOCO_NO,16));
        this->ui->LBL_Train4Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[3]->N_LOCO_NO,16));
        Active(this->ui->LBL_4Active1,this->database->data_TCN->train[0]->B_STATE_CAB_ACT);
        Active(this->ui->LBL_4Active2,this->database->data_TCN->train[1]->B_STATE_CAB_ACT);
        Active(this->ui->LBL_4Active3,this->database->data_TCN->train[2]->B_STATE_CAB_ACT);
        Active(this->ui->LBL_4Active4,this->database->data_TCN->train[3]->B_STATE_CAB_ACT);
        break;
    default:
        break;
    }
}

void Settng_Panto::show1Train()
{
    this->ui->LBL_2Train1->show();
    this->ui->LBL_2Train1->setGeometry(255,130,this->ui->LBL_2Train1->width(),this->ui->LBL_2Train1->height());
    this->ui->LBL_2HS1->show();
    this->ui->LBL_2HS1->setGeometry(406,170,this->ui->LBL_2HS1->width(),this->ui->LBL_2HS1->height());
    this->ui->LBL_2PANTO1->show();
    this->ui->LBL_2PANTO1->setGeometry(339,124,this->ui->LBL_2PANTO1->width(),this->ui->LBL_2PANTO1->height());
    this->ui->LBL_2Active1->hide();
    this->ui->LBL_2Active1->setGeometry(299,190,this->ui->LBL_2Active1->width(),this->ui->LBL_2Active1->height());
    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
}

void Settng_Panto::show2Train()
{
    //2Car1
    this->ui->LBL_2Train1->show();
    this->ui->LBL_2Train1->setGeometry(109,130,this->ui->LBL_2Train1->width(),this->ui->LBL_2Train1->height());
    this->ui->LBL_2HS1->show();
    this->ui->LBL_2HS1->setGeometry(270,170,this->ui->LBL_2HS1->width(),this->ui->LBL_2HS1->height());
    this->ui->LBL_2PANTO1->show();
    this->ui->LBL_2PANTO1->setGeometry(193,124,this->ui->LBL_2PANTO1->width(),this->ui->LBL_2PANTO1->height());
    this->ui->LBL_2Active1->hide();
    this->ui->LBL_2Active1->setGeometry(153,190,this->ui->LBL_2Active1->width(),this->ui->LBL_2Active1->height());
    //2Car2
    this->ui->LBL_2Train2->show();
    this->ui->LBL_2Train2->setGeometry(400,130,this->ui->LBL_2Train2->width(),this->ui->LBL_2Train2->height());
    this->ui->LBL_2HS2->show();
    this->ui->LBL_2HS2->setGeometry(480,170,this->ui->LBL_2HS2->width(),this->ui->LBL_2HS2->height());
    this->ui->LBL_2PANTO2->show();
    this->ui->LBL_2PANTO2->setGeometry(562,124,this->ui->LBL_2PANTO2->width(),this->ui->LBL_2PANTO2->height());
    this->ui->LBL_2Active2->hide();
    this->ui->LBL_2Active2->setGeometry(628,190,this->ui->LBL_2Active2->width(),this->ui->LBL_2Active2->height());

    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
    this->ui->BTN_Train2->show();
    this->ui->LBL_Train2Num->show();
}

void Settng_Panto::show3Train()
{
    //3Car1
    this->ui->LBL_4Train1->show();
    this->ui->LBL_4Train1->setGeometry(121,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4HS1->show();
    this->ui->LBL_4HS1->setGeometry(234,173,this->ui->LBL_4HS1->width(),this->ui->LBL_4HS1->height());
    this->ui->LBL_4PANTO1->show();
    this->ui->LBL_4PANTO1->setGeometry(176,133,this->ui->LBL_4PANTO1->width(),this->ui->LBL_4PANTO1->height());
    this->ui->LBL_4Active1->hide();
    this->ui->LBL_4Active1->setGeometry(150,180,this->ui->LBL_4Active1->width(),this->ui->LBL_4Active1->height());
    //3Car2
    this->ui->LBL_4Train2->show();
    this->ui->LBL_4Train2->setGeometry(305,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4HS2->show();
    this->ui->LBL_4HS2->setGeometry(350,173,this->ui->LBL_4HS1->width(),this->ui->LBL_4HS1->height());
    this->ui->LBL_4PANTO2->show();
    this->ui->LBL_4PANTO2->setGeometry(406,133,this->ui->LBL_4PANTO2->width(),this->ui->LBL_4PANTO2->height());
    this->ui->LBL_4Active2->hide();
    this->ui->LBL_4Active2->setGeometry(354,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    //3Car3
    this->ui->LBL_4Train3->show();
    this->ui->LBL_4Train3->setGeometry(501,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4HS3->show();
    this->ui->LBL_4HS3->setGeometry(614,173,this->ui->LBL_4HS3->width(),this->ui->LBL_4HS3->height());
    this->ui->LBL_4PANTO3->show();
    this->ui->LBL_4PANTO3->setGeometry(556,133,this->ui->LBL_4PANTO3->width(),this->ui->LBL_4PANTO3->height());
    this->ui->LBL_4Active3->hide();
    this->ui->LBL_4Active3->setGeometry(430,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
    this->ui->BTN_Train2->show();
    this->ui->LBL_Train2Num->show();
    this->ui->BTN_Train3->show();
    this->ui->LBL_Train3Num->show();
}

void Settng_Panto::show4Train()
{
    //4Car1
    this->ui->LBL_4Train1->show();
    this->ui->LBL_4Train1->setGeometry(21,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4HS1->show();
    this->ui->LBL_4HS1->setGeometry(134,173,this->ui->LBL_4HS1->width(),this->ui->LBL_4HS1->height());
    this->ui->LBL_4PANTO1->show();
    this->ui->LBL_4PANTO1->setGeometry(76,133,this->ui->LBL_4PANTO1->width(),this->ui->LBL_4PANTO1->height());
    this->ui->LBL_4Active1->hide();
    this->ui->LBL_4Active1->setGeometry(50,180,this->ui->LBL_4Active1->width(),this->ui->LBL_4Active1->height());
    //4Car2
    this->ui->LBL_4Train2->show();
    this->ui->LBL_4Train2->setGeometry(205,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4HS2->show();
    this->ui->LBL_4HS2->setGeometry(250,173,this->ui->LBL_4HS1->width(),this->ui->LBL_4HS1->height());
    this->ui->LBL_4PANTO2->show();
    this->ui->LBL_4PANTO2->setGeometry(306,133,this->ui->LBL_4PANTO2->width(),this->ui->LBL_4PANTO2->height());
    this->ui->LBL_4Active2->hide();
    this->ui->LBL_4Active2->setGeometry(354,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    //4Car3
    this->ui->LBL_4Train3->show();
    this->ui->LBL_4Train3->setGeometry(401,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4HS3->show();
    this->ui->LBL_4HS3->setGeometry(514,173,this->ui->LBL_4HS3->width(),this->ui->LBL_4HS3->height());
    this->ui->LBL_4PANTO3->show();
    this->ui->LBL_4PANTO3->setGeometry(456,133,this->ui->LBL_4PANTO3->width(),this->ui->LBL_4PANTO3->height());
    this->ui->LBL_4Active3->hide();
    this->ui->LBL_4Active3->setGeometry(430,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    //4Car4
    this->ui->LBL_4Train4->show();
    this->ui->LBL_4Train4->setGeometry(590,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4HS4->show();
    this->ui->LBL_4HS4->setGeometry(634,173,this->ui->LBL_4HS1->width(),this->ui->LBL_4HS1->height());
    this->ui->LBL_4PANTO4->show();
    this->ui->LBL_4PANTO4->setGeometry(691,133,this->ui->LBL_4PANTO1->width(),this->ui->LBL_4PANTO1->height());
    this->ui->LBL_4Active4->hide();
    this->ui->LBL_4Active4->setGeometry(738,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());

    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
    this->ui->BTN_Train2->show();
    this->ui->LBL_Train2Num->show();
    this->ui->BTN_Train3->show();
    this->ui->LBL_Train3Num->show();
    this->ui->BTN_Train4->show();
    this->ui->LBL_Train4Num->show();
}

void Settng_Panto::hideAllTrain()
{
    //2Car1
    this->ui->LBL_2Train1->hide();
    this->ui->LBL_2HS1->hide();
    this->ui->LBL_2PANTO1->hide();
    this->ui->LBL_2Active1->hide();
    //2Car2
    this->ui->LBL_2Train2->hide();
    this->ui->LBL_2HS2->hide();
    this->ui->LBL_2PANTO2->hide();
    this->ui->LBL_2Active2->hide();
    //4Car1
    this->ui->LBL_4Train1->hide();
    this->ui->LBL_4HS1->hide();
    this->ui->LBL_4PANTO1->hide();
    this->ui->LBL_4Active1->hide();
    //4Car2
    this->ui->LBL_4Train2->hide();
    this->ui->LBL_4HS2->hide();
    this->ui->LBL_4PANTO2->hide();
    this->ui->LBL_4Active2->hide();
    //4Car3
    this->ui->LBL_4Train3->hide();
    this->ui->LBL_4HS3->hide();
    this->ui->LBL_4PANTO3->hide();
    this->ui->LBL_4Active3->hide();
    //4Car4
    this->ui->LBL_4Train4->hide();
    this->ui->LBL_4HS4->hide();
    this->ui->LBL_4PANTO4->hide();
    this->ui->LBL_4Active4->hide();
    //TrainButton&Label
    this->ui->BTN_Train1->hide();
    this->ui->BTN_Train2->hide();
    this->ui->BTN_Train3->hide();
    this->ui->BTN_Train4->hide();
    this->ui->LBL_Train1Num->hide();
    this->ui->LBL_Train2Num->hide();
    this->ui->LBL_Train3Num->hide();
    this->ui->LBL_Train4Num->hide();
}

void Settng_Panto::TrainSelectEvent()
{
    for(int i=0;i<TrainList.size();i++)
    {
        if(0 == i%2)
        {
            TrainList.at(i)->setStyleSheet(TRAINUPL);
        }else
        {
            TrainList.at(i)->setStyleSheet(TRAINUPR);
        }
    }

   TrainIndex = ((QPushButton*)this->sender())->whatsThis().toInt();

   switch(TrainIndex)
   {
   case 0:
       this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
       break;
   case 1:
       this->ui->BTN_Train2->setStyleSheet(TRAINDOWNR);
       break;
   case 2:
       this->ui->BTN_Train3->setStyleSheet(TRAINDOWNL);
       break;
   case 3:
       this->ui->BTN_Train4->setStyleSheet(TRAINDOWNR);
       break;
   }

}

void Settng_Panto::HSstate(QLabel *lbl, bool Open, bool Close)
{
    if(Open && !Close)
    {
        lbl->setStyleSheet(HSOPEN);
    }else if(!Open && Close)
    {
        lbl->setStyleSheet(HSCLOSE);
    }
}

void Settng_Panto::Active(QLabel *lbl,bool Active)
{
    if(Active)
    {
        lbl->show();
    }else
    {
        lbl->hide();
    }
}

void Settng_Panto::on_BTN_PANTO_Cutout_pressed()
{
    timerCutout = startTimer(3000);
    switch (TrainIndex) {
    case 0:
        this->database->data_CCU->B_TC1_PANTO_ISO_RQ = true;
        break;
    case 1:
        this->database->data_CCU->B_TC2_PANTO_ISO_RQ = true;
        break;
    case 2:
        this->database->data_CCU->B_TC3_PANTO_ISO_RQ = true;
        break;
    case 3:
        this->database->data_CCU->B_TC4_PANTO_ISO_RQ = true;
        break;
    default:
        break;
    }
    this->ui->BTN_PANTO_Cutout->setStyleSheet(NButtonDOWN);
}

void Settng_Panto::on_BTN_PANTO_CancelCutout_pressed()
{
    timerCancel = startTimer(3000);
    switch (TrainIndex) {
    case 0:
        this->database->data_CCU->B_TC1_PANTO_ISO_REL_RQ = true;
        break;
    case 1:
        this->database->data_CCU->B_TC2_PANTO_ISO_REL_RQ = true;
        break;
    case 2:
        this->database->data_CCU->B_TC3_PANTO_ISO_REL_RQ = true;
        break;
    case 3:
        this->database->data_CCU->B_TC4_PANTO_ISO_REL_RQ = true;
        break;
    default:
        break;
    }
    this->ui->BTN_PANTO_CancelCutout->setStyleSheet(NButtonDOWN);
}

void Settng_Panto::timerEvent(QTimerEvent *e)
{
    if(timerCutout == e->timerId())
    {
        killTimer(timerCutout);
        switch (TrainIndex) {
        case 0:
            this->database->data_CCU->B_TC1_PANTO_ISO_RQ = false;
            break;
        case 1:
            this->database->data_CCU->B_TC2_PANTO_ISO_RQ = false;
            break;
        case 2:
            this->database->data_CCU->B_TC3_PANTO_ISO_RQ = false;
            break;
        case 3:
            this->database->data_CCU->B_TC4_PANTO_ISO_RQ = false;
            break;
        default:
            break;
        }
        this->ui->BTN_PANTO_Cutout->setStyleSheet(NButtonUP);
        timerCutout = 0;
    }
    if(timerCancel == e->timerId())
    {
        killTimer(timerCancel);
        switch (TrainIndex) {
        case 0:
            this->database->data_CCU->B_TC1_PANTO_ISO_REL_RQ = false;
            break;
        case 1:
            this->database->data_CCU->B_TC2_PANTO_ISO_REL_RQ = false;
            break;
        case 2:
            this->database->data_CCU->B_TC3_PANTO_ISO_REL_RQ = false;
            break;
        case 3:
            this->database->data_CCU->B_TC4_PANTO_ISO_REL_RQ = false;
            break;
        default:
            break;
        }
        this->ui->BTN_PANTO_CancelCutout->setStyleSheet(NButtonUP);
        timerCancel = 0;
    }
}
