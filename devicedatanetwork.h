#ifndef DEVICEDATANETWORK_H
#define DEVICEDATANETWORK_H

#include "mybase.h"

namespace Ui {
class DeviceDataNetwork;
}

class DeviceDataNetwork : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataNetwork(QWidget *parent = 0);
    ~DeviceDataNetwork();
    void updateState(QLabel *label, bool onLine, bool isMaster = true);
    void updatePage();

private:
    Ui::DeviceDataNetwork *ui;
};

#endif // DEVICEDATANETWORK_H
