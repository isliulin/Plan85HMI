#ifndef DEVICEDATAMAINCONV_H
#define DEVICEDATAMAINCONV_H

#include "mybase.h"

namespace Ui {
class DeviceDataMainConv;
}

class DeviceDataMainConv : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataMainConv(QWidget *parent = 0);
    ~DeviceDataMainConv();

private:
    Ui::DeviceDataMainConv *ui;
};

#endif // DEVICEDATAMAINCONV_H
