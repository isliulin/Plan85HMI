#ifndef DEVICEDATABREAKER_H
#define DEVICEDATABREAKER_H

#include "mybase.h"

namespace Ui {
class DeviceDataBreaker;
}

class DeviceDataBreaker : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataBreaker(QWidget *parent = 0);
    ~DeviceDataBreaker();

private:
    Ui::DeviceDataBreaker *ui;
};

#endif // DEVICEDATABREAKER_H
