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
    void updatePage();
    void setSwitch(QLabel *label, bool close);
    void setVSwitch(QLabel *label, bool close);
    void setHBState(QLabel *label, bool close);

private:
    Ui::DeviceDataMainConv *ui;
};

#endif // DEVICEDATAMAINCONV_H
