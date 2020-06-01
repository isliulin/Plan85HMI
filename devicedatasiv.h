#ifndef DEVICEDATASIV_H
#define DEVICEDATASIV_H

#include "mybase.h"
class QLabel;
class QButtonGroup;

namespace Ui {
class DeviceDataSIV;
}

class DeviceDataSIV : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataSIV(QWidget *parent = 0);
    ~DeviceDataSIV();
    void setSwitch(QLabel *label, bool close);
    void setVSwitch(QLabel *label, bool close);
    void setHBState(QLabel *label, bool close);
    void setPPQUAI (QLabel* label, bool right);

    void showTrain();
    void updatePage();
private:
    Ui::DeviceDataSIV *ui;
    //label list
    QList<QLabel*> trainLabels, swList, hbList;

    Data_TCN *tcn;
    int currentTrain;
    QButtonGroup *buttons;

private slots:
    void onButtonClicked(int);
};

#endif // DEVICEDATASIV_H
