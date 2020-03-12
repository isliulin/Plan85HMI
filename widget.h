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

class MainData_TrainOutline;
class Settng_Bypass;
class Settng_Panto;
class Settng_Distance;
class Settng_TrainCode;
class Settng_Lubrication;
class Settng_Separation;
class Settng_HangMode;
class Settng_Others;

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
    Settng_Bypass* settng_Bypass;
    Settng_Panto* settng_Panto;
    Settng_Distance* settng_Distance;
    Settng_TrainCode* settng_TrainCode;
    Settng_Lubrication* settng_Lubrication;
    Settng_Separation* settng_Separation;
    Settng_HangMode* settng_HangMode;
    Settng_Others* settng_Others;
};

#endif // WIDGET_H
