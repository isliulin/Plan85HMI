#ifndef UNITY_H
#define UNITY_H

#include <mybase.h>
#include "widgets/ctrlnetvoltage_unity.h"
#include "widgets/ctrlnetcurrent_unity.h"
#include "widgets/ctrcontrolvoltage_unity.h"
#include "widgets/ctrltracbrake_unity.h"
#include "widgets/ctrlspeedometer.h"
#include "widgets/ctrlflowdiagram.h"
namespace Ui {
class Unity;
}

class Unity : public MyBase
{
    Q_OBJECT

public:
    explicit Unity(QWidget *parent = 0);
    ~Unity();
    void updatePage();
    void showEvent(QShowEvent *);
private:
    Ui::Unity *ui;
    CtrControlVoltage_Unity* ctrControlVoltage_Unity;
    CtrlNetCurrent_Unity* ctrlNetCurrent_Unity;
    CtrlNetVoltage_Unity* ctrlNetVoltage_Unity;

    CtrlTracBrake_Unity* ctrlTracBrake_Unity;
    CtrlFlowDiagram* ctrlFlowDiagram;

    CtrlSpeedometer* ctrlSpeedometer1,*ctrlSpeedometer2;
};

#endif // UNITY_H
