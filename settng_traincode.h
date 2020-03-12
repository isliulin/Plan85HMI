#ifndef SETTNG_TRAINCODE_H
#define SETTNG_TRAINCODE_H

#include "mybase.h"

namespace Ui {
class Settng_TrainCode;
}

class Settng_TrainCode : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_TrainCode(QWidget *parent = 0);
    ~Settng_TrainCode();

private:
    Ui::Settng_TrainCode *ui;
};

#endif // SETTNG_TRAINCODE_H
