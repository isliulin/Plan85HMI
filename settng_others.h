#ifndef SETTNG_OTHERS_H
#define SETTNG_OTHERS_H

#include "mybase.h"

namespace Ui {
class Settng_Others;
}

class Settng_Others : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Others(QWidget *parent = 0);
    ~Settng_Others();

private:
    Ui::Settng_Others *ui;
};

#endif // SETTNG_OTHERS_H
