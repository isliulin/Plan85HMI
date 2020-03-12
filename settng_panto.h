#ifndef SETTNG_PANTO_H
#define SETTNG_PANTO_H

#include "mybase.h"

namespace Ui {
class Settng_Panto;
}

class Settng_Panto : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Panto(QWidget *parent = 0);
    ~Settng_Panto();

private:
    Ui::Settng_Panto *ui;
};

#endif // SETTNG_PANTO_H
