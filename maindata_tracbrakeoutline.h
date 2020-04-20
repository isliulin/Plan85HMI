#ifndef MAINDATA_TRACBRAKEOUTLINE_H
#define MAINDATA_TRACBRAKEOUTLINE_H

#include <mybase.h>

namespace Ui {
class MainData_TracBrakeOutline;
}

class MainData_TracBrakeOutline : public MyBase
{
    Q_OBJECT

public:
    explicit MainData_TracBrakeOutline(QWidget *parent = 0);
    ~MainData_TracBrakeOutline();
    void updatePage();

private:
    Ui::MainData_TracBrakeOutline *ui;
};

#endif // MAINDATA_TRACBRAKEOUTLINE_H
