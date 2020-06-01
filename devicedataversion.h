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
    void updatePage();

private:
    Ui::DeviceDataVersion *ui;
    QList<int> verX, verY, verZ;
    QList<QString> names;
    QList<QLabel*> nameLabels, xLabels, yLabels, zLabels;
};

#endif // DEVICEDATAVERSION_H
