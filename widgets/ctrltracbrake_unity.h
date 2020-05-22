#ifndef CTRLTRACBRAKE_UNITY_H
#define CTRLTRACBRAKE_UNITY_H

#include <QWidget>
#include "global.h"

namespace Ui {
class CtrlTracBrake_Unity;
}

class CtrlTracBrake_Unity : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTracBrake_Unity(QWidget *parent = 0);
    ~CtrlTracBrake_Unity();
    void setCtrlValueRect(int value);

private:
    Ui::CtrlTracBrake_Unity *ui;
};

#endif // CTRLTRACBRAKE_UNITY_H
