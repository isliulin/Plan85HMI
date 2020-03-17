#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QWidget>
#include <QMap>
#include "log4qt/logger.h"
#include "global.h"

namespace Ui {
    class Widget;
}
class MyBase;
class Header;
class QTimer;
class Database;
class Navigator;
class VehicleRunStatePage;
class CrrcMvb;
class CrrcFault;
class Simulation;

class MainData_TrainOutline;
class MainData_DriverOutline;
class Settng_Bypass;
class Settng_Panto;
class Settng_Distance;
class Settng_TrainCode;
class Settng_Lubrication;
class Settng_Separation;
class Settng_HangMode;
class Settng_Others;
class Main_Simulate;
class Main_AssistantDevice;
class Main_380;
class Main_Light;
class Main_Lubrication;
class Main_Panto;
class Main_Separation;
class Main_Wheel;
class Main_Datetime;
class Fault_Current;
class Fault_History;
class Fault_Download;
class Panto_Condition;

class Widget : public QWidget
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER

public:
    explicit Widget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *);
    QMap<int, MyBase *> widgets;

    ~Widget();

public slots:
    void changePage(int page);
    void updatePage();
    void translateLanguage();

private:
    Ui::Widget *ui;
    QTimer* timer;
    Database* database;
    Navigator* navigator;
    VehicleRunStatePage* vehicleRunStatePage;
    Header *header;
    CrrcMvb* crrcMvb;
    CrrcFault* crrcFault;

    MainData_TrainOutline* mainData_TrainOutline;
    MainData_DriverOutline* mainData_DriverOutline;
    Settng_Bypass* settng_Bypass;
    Settng_Panto* settng_Panto;
    Settng_Distance* settng_Distance;
    Settng_TrainCode* settng_TrainCode;
    Settng_Lubrication* settng_Lubrication;
    Settng_Separation* settng_Separation;
    Settng_HangMode* settng_HangMode;
    Settng_Others* settng_Others;
    Main_Simulate* main_Simulate;
    Main_AssistantDevice* main_AssistantDevice;
    Main_380* main_380;
    Main_Light* main_Light;
    Main_Lubrication* main_Lubrication;
    Main_Panto* main_Panto;
    Main_Separation* main_Separation;
    Main_Wheel* main_Wheel;
    Main_Datetime* main_Datetime;
    Fault_Current* fault_Current;
    Fault_History* fault_History;
    Fault_Download* fault_Download;

    Simulation* simulation;

    Panto_Condition* panto_Condition;
};

#endif // WIDGET_H
