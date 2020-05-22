#ifndef VEHICLERUNSTATEPAGE_H
#define VEHICLERUNSTATEPAGE_H

#include <QWidget>
#include "mybase.h"
#include "qtimer.h"
#include "widgets/ctrlnetvoltage.h"
#include "widgets/ctrlnetcurrent.h"
#include "widgets/ctrlcontrolvoltage.h"
#include "widgets/ctrltracbrake.h"
namespace Ui {
    class VehicleRunStatePage;
}

class VehicleRunStatePage : public MyBase
{
    Q_OBJECT

public:
    explicit VehicleRunStatePage(QWidget *parent = 0);
    ~VehicleRunStatePage();

    void updatePage();
    void showEvent(QShowEvent *);

private slots:
    void on_BTNMinus1_clicked();

    void on_BTNPlus1_clicked();
    void timer3sEvent();
private:
    Ui::VehicleRunStatePage *ui;

    CtrlNetVoltage* ctrlNetVoltage;
    CtrlNetCurrent* ctrlNetCurrent;
    CtrlControlVoltage* ctrlControlVoltage;
    CtrlTracBrake* ctrlTracBrake;
    QTimer *timer3s;
    int FirstFaultIndex;
    QList<QLabel*> labellist;
    void FaultRoll();

    int m_currentPageIndex,m_totalPageIndex,m_totalFaultNum,m_currentPageFaultNum;
    void DrawFaults(int i);
};

#endif // VEHICLERUNSTATEPAGE_H
