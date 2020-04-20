#include "maindata_trainoutline.h"
#include "ui_maindata_trainoutline.h"


MainData_TrainOutline::MainData_TrainOutline(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MainData_TrainOutline)
{
    ui->setupUi(this);

    trainoutline = new CtrlTrainOutLine(this);
    trainoutline->hide();
    trainoutlineR = new CtrlTrainOutLineReverse(this);
    trainoutlineR->hide();
    train3outlineR = new CtrlTrain3OutLineReverse(this);
    train3outlineR->hide();
    for(int i = 0; i < 2;i++)
    {
        train3outline[i] = new CtrlTrain3OutLine(this);
        train3outline[i]->hide();
        train4outline[i] = new CtrlTrain4OutLine(this);
        train4outline[i]->hide();
        train4outlineR[i] = new CtrlTrain4OutLineReverse(this);
        train4outlineR[i]->hide();
    }
}

MainData_TrainOutline::~MainData_TrainOutline()
{
    delete ui;
}

void MainData_TrainOutline::updatePage()
{
    int trainmax = database->data_CCU->M1_D1_N_RULOCO_NO;
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
 //   int curtrain = database->data_CCU->M1_D1_N_UIC_ADDR;

    trainmax = 4;

    if (trainmax > TRAINMAX)
    {
        trainmax = TRAINMAX;
    }

    HideAllTrain();

    switch(trainmax)
    {
        case 1:
            x = 0;
            y = (this->height() - trainoutline->height())/2;
            w = trainoutline->width();
            h = trainoutline->height();
            trainoutline->setGeometry(x,y,w,h);
            trainoutline->show();
            break;
        case 2:
            x = 0;
            y = (this->height() - trainoutline->height())/2;
            w = trainoutline->width();
            h = trainoutline->height();
            trainoutline->setGeometry(x,y,w,h);
            trainoutline->show();

            x = x + w;
            trainoutlineR->setGeometry(x,y,w,h);
            trainoutlineR->show();
            break;
        case 3:
            x = 0;
            y = (this->height() - train3outline[0]->height())/2;
            w = train3outline[0]->width();
            h = train3outline[0]->height();
            train3outline[0]->setGeometry(x,y,w,h);
            train3outline[0]->show();

            x = x + w;
            train3outlineR->setGeometry(x,y,w,h);
            train3outlineR->show();

            x = x + w ;
            train3outline[1]->setGeometry(x,y,w,h);
            train3outline[1]->show();
            break;
        case 4:
            x = 0;
            y = (this->height() - train4outline[0]->height())/2;
            w = train4outline[0]->width();
            h = train4outline[0]->height();

            train4outline[0]->setGeometry(x,y,w,h);
            train4outline[0]->show();

            x = x + w;
            train4outlineR[0]->setGeometry(x,y,w,h);
            train4outlineR[0]->show();

            x = x + w ;
            train4outline[1]->setGeometry(x,y,w,h);
            train4outline[1]->show();

            x = x + w ;
            train4outlineR[1]->setGeometry(x,y,w,h);
            train4outlineR[1]->show();
                break;
            default:
                break;

    }

}

void MainData_TrainOutline::HideAllTrain()
{
    trainoutline->hide();
    trainoutlineR->hide();
    train3outlineR->hide();
    for(int i = 0; i < 2;i++)
    {
        train3outline[i]->hide();
        train4outline[i]->hide();
        train4outlineR[i]->hide();
    }
}

void MainData_TrainOutline::updateData()
{
    int curtrain = database->data_CCU->M1_D1_N_UIC_ADDR;
    int trainmax = database->data_CCU->M1_D1_N_RULOCO_NO;
    QList<bool> dirction,panto,gaoya,zhuduan,parking,traction,brake;
    QList<unsigned short int>kn;
    switch(trainmax)
    {
        case 1:
            dirction.clear();
            dirction<<database->data_TCN->train[curtrain]->B_CMD_DIR_f
                    <<database->data_TCN->train[curtrain]->B_CMD_DIR_B
                    <<database->data_TCN->train[curtrain]->B_CMD_DIR_N;
            kn<<database->data_TCN->train[curtrain]->N_LOAD_VALUE;
            panto<<database->data_TCN->train[curtrain]->B_CMD_PANTO_R
                 <<database->data_TCN->train[curtrain]->B_CMD_PANTO_D;
            gaoya<<database->data_TCN->train[curtrain]->B_STATE_QS_HV1_ON
                 <<database->data_TCN->train[curtrain]->B_STATE_QS_HV1_OFF;
            zhuduan<<database->data_TCN->train[curtrain]->B_STATE_QFM_ON
                   <<database->data_TCN->train[curtrain]->B_STATE_QFM_ISO
                   <<database->data_TCN->train[curtrain]->B_STATE_QFM_K;
            parking<<database->data_TCN->train[curtrain]->B_STATE_PARK_BRK_ON
                   <<database->data_TCN->train[curtrain]->B_STATE_PARK_BRK_REL
                   <<database->data_TCN->train[curtrain]->B_STATE_PARK_BRK_I;
            traction<<"0";
            brake<< "0";

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

                break;
        default:
            break;

    }

}
