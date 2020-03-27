#ifndef MAIN_WHEEL_H
#define MAIN_WHEEL_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
class Main_Wheel;
}

class Main_Wheel : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Wheel(QWidget *parent = 0);
    ~Main_Wheel();

private:
    Ui::Main_Wheel *ui;
};

#endif // MAIN_WHEEL_H
