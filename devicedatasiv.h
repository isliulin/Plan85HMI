#ifndef DEVICEDATASIV_H
#define DEVICEDATASIV_H

#include "mybase.h"

namespace Ui {
class DeviceDataSIV;
}

class DeviceDataSIV : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataSIV(QWidget *parent = 0);
    ~DeviceDataSIV();

private:
    Ui::DeviceDataSIV *ui;
};

#endif // DEVICEDATASIV_H
