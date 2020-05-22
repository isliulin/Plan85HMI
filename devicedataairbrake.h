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

private:
    Ui::DeviceDataAirBrake *ui;
};

#endif // DEVICEDATAAIRBRAKE_H
