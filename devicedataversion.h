#ifndef DEVICEDATAVERSION_H
#define DEVICEDATAVERSION_H

#include "mybase.h"

namespace Ui {
class DeviceDataVersion;
}

class DeviceDataVersion : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataVersion(QWidget *parent = 0);
    ~DeviceDataVersion();

private:
    Ui::DeviceDataVersion *ui;
};

#endif // DEVICEDATAVERSION_H
