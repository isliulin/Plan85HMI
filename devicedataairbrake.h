#ifndef DEVICEDATAAIRBRAKE_H
#define DEVICEDATAAIRBRAKE_H

#include "mybase.h"

namespace Ui {
class DeviceDataAirBrake;
}

class DeviceDataAirBrake : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataAirBrake(QWidget *parent = 0);
    ~DeviceDataAirBrake();
    void brakeValue(QLabel* label, unsigned short int value);
    void updatePage();
    void udpateNames(QLabel* label, bool judgeKey);
    void bcuStates(QLabel *label, bool state1, bool state2);

private:
    Ui::DeviceDataAirBrake *ui;
};

#endif // DEVICEDATAAIRBRAKE_H
