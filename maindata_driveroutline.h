#ifndef MAINDATA_DRIVEROUTLINE_H
#define MAINDATA_DRIVEROUTLINE_H

#include <mybase.h>

namespace Ui {
class MainData_DriverOutline;
}

class MainData_DriverOutline : public MyBase
{
    Q_OBJECT

public:
    explicit MainData_DriverOutline(QWidget *parent = 0);
    ~MainData_DriverOutline();

private:
    Ui::MainData_DriverOutline *ui;
};

#endif // MAINDATA_DRIVEROUTLINE_H
