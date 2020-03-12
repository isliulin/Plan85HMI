#include "widget.h"
#include "ui_widget.h"
#include "mybase.h"
#include "header.h"
#include "qtimer.h"
#include "database.h"
#include "navigator.h"
#include "vehiclerunstatepage.h"
#include "crrcmvb.h"
#include "crrcfault.h"

#ifdef QT_VERSION_5_6
#include "qdesktopwidget.h"
#endif

#include "maindata_trainoutline.h"
#include "settng_bypass.h"
#include "settng_panto.h"
#include "settng_distance.h"
#include "settng_traincode.h"
#include "settng_lubrication.h"
#include "settng_separation.h"
#include "settng_hangmode.h"
#include "settng_others.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDesktopWidget *desktop = QApplication::desktop();

    if (desktop->width() == 800 && desktop->height() == 600)
    {
        this->showFullScreen();
    }
    else
    {
        this->move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
    }

    this->database = new Database();
    MyBase::database = this->database;

    this->timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePage()));

    if(CrrcFault::initCrrcFault("fault_type_Plan85.db","fault_DB_Plan85.db"))
    {
        crrcFault = CrrcFault::getCrrcFault();
    }else
    {
        logger()->error("故障文件初始化错误");
    }




    this->navigator = new Navigator(this);
    this->navigator->setMyBase(uBottom,QString("导航栏"));
    this->navigator->show();
    connect(navigator,SIGNAL(translateLanguage()),this,SLOT(translateLanguage()));

    this->vehicleRunStatePage = new VehicleRunStatePage(this);
    this->vehicleRunStatePage->setMyBase(uMiddleTraction,QString("牵引模式"));
    this->vehicleRunStatePage->show();

    this->header = new Header(this);
    this->header->setMyBase(uTop,QString("标题栏"));
    this->header->show();

    //add maindata pages

    this->mainData_TrainOutline = new MainData_TrainOutline(this);
    this->mainData_TrainOutline->setMyBase(uMiddleMainData,QString("机车概况"));
    this->mainData_TrainOutline->hide();

    //add setting pages
    this->settng_Bypass = new Settng_Bypass(this);
    this->settng_Bypass->setMyBase(uMiddleSetting,QString("隔离"));
    this->settng_Bypass->hide();

    this->settng_Panto = new Settng_Panto(this);
    this->settng_Panto->setMyBase(uMiddleSetting,QString("受电弓"));
    this->settng_Panto->hide();

    this->settng_Distance = new Settng_Distance(this);
    this->settng_Distance->setMyBase(uMiddleSetting,QString("距离计数"));
    this->settng_Distance->hide();

    this->settng_TrainCode = new Settng_TrainCode(this);
    this->settng_TrainCode->setMyBase(uMiddleSetting,QString("车号设置"));
    this->settng_TrainCode->hide();

    this->settng_Lubrication = new Settng_Lubrication(this);
    this->settng_Lubrication->setMyBase(uMiddleSetting,QString("轮缘润滑"));
    this->settng_Lubrication->hide();

    this->settng_Separation = new Settng_Separation(this);
    this->settng_Separation->setMyBase(uMiddleSetting,QString("分相线路"));
    this->settng_Separation->hide();

    this->settng_HangMode = new Settng_HangMode(this);
    this->settng_HangMode->setMyBase(uMiddleSetting,QString("挂车模式"));
    this->settng_HangMode->hide();

    this->settng_Others = new Settng_Others(this);
    this->settng_Others->setMyBase(uMiddleSetting,QString("其他设置"));
    this->settng_Others->hide();

    this->widgets.insert(uVehicleRunStatePage,this->vehicleRunStatePage);
    this->widgets.insert(uMainData_TrainOutline,this->mainData_TrainOutline);
    this->widgets.insert(uSettng_Bypass,this->settng_Bypass);
    this->widgets.insert(uSettng_Panto,this->settng_Panto);
    this->widgets.insert(uSettng_Distance,this->settng_Distance);
    this->widgets.insert(uSettng_TrainCode,this->settng_TrainCode);
    this->widgets.insert(uSettng_Lubrication,this->settng_Lubrication);
    this->widgets.insert(uSettng_Separation,this->settng_Separation);
    this->widgets.insert(uSettng_HangMode,this->settng_HangMode);
    this->widgets.insert(uSettng_Others,this->settng_Others);


    this->header->setPageName(this->widgets[uVehicleRunStatePage]->name);
    crrcMvb = CrrcMvb::getCrrcMvb();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::updatePage()
{
    static int counter = 1;
    this->header->updatePage();
    this->widgets[MyBase::currentPage]->updatePage();

    // update comm data,some base logic
    if(counter%2 == 0)
    {
        crrcMvb->synchronizeMvbData();
    }

    // start fault scanning thread
    static int faultdelaycnt = 0;
    if ((faultdelaycnt++ > 45) && !crrcFault->isRunning())
    {
        crrcFault->start();
    }
    counter >= 100 ? (counter = 1) : (counter ++);



}
void Widget::changePage(int page)
{
    foreach (int key, this->widgets.keys())
    {
        if (key == page)
        {
            MyBase::currentPage = page;
            this->widgets[page]->show();

            this->header->setPageName(this->widgets[page]->name);

            _LOG << "change page to" << this->widgets[page]->name;
        }
        else
        {
            this->widgets[key]->hide();
        }
    }
    navigator->updateButtonsNamesByPositon(this->widgets[MyBase::currentPage]->Position);

}
void Widget::showEvent(QShowEvent *)
{
    if(MainGetDefaultPara::configureValid())
    {
#ifndef WINDOWS_MODE
        if(database->HMIPosition == 1)//config  sourcePORT and IP
        {
            system("ifconfig eth0 192.168.2.3");

            if(!crrcMvb->initializeMvb())
            {
                logger()->error("MVB板卡初始化失败");
            }
            this->database->HMIPosition = 1;
            QList<unsigned short int> tmp_list;
            tmp_list<<0x310<<0x311<<0x312<<0x313<<0x320<<0x321<<0x322<<0x323;
            this->database->getHMISourceSinkPost(tmp_list);
            //HMI-CCU

        }else if(database->HMIPosition == 2)
        {
            system("ifconfig eth0 192.168.2.4");
            if(!crrcMvb->initializeMvb())
            {
                logger()->error("MVB板卡初始化失败");
            }
            //HMI-CCU
            this->database->HMIPosition = 2;
            QList<unsigned short int> tmp_list;
            tmp_list<<0x320<<0x321<<0x322<<0x323<<0x310<<0x311<<0x312<<0x313;
            this->database->getHMISourceSinkPost(tmp_list);
        }
        //add ports
        {

        }
#endif

        if(crrcMvb->InitReadPortData())
        {
            logger()->error("MVB板卡设置操作模式失败");
        }

        timer->start(333);
    }else
    {
        logger()->error("configure.ini文件错误");
        _LOG << "fail to read configure file.";
    }

}


void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        this->close();
    }
}
void Widget::translateLanguage()
{
    QTranslator *translator = new QTranslator(0);
    static bool t_istranslate = false;
    if(t_istranslate)
    {
        qApp->removeTranslator(translator);
    }else
    {
        translator->load("language_en.qm");
        qApp->installTranslator(translator);
    }
    t_istranslate = !t_istranslate;
    foreach(int i,this->widgets.keys())
    {
        this->widgets[i]->updateLanguage();
    }

    delete translator;
}
