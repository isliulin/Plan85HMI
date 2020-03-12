#ifndef SETTNG_SEPARATION_H
#define SETTNG_SEPARATION_H

#include "mybase.h"

namespace Ui {
class Settng_Separation;
}

class Settng_Separation : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Separation(QWidget *parent = 0);
    ~Settng_Separation();

private:
    Ui::Settng_Separation *ui;
};

#endif // SETTNG_SEPARATION_H
