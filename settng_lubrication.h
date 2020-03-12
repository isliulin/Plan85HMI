#ifndef SETTNG_LUBRICATION_H
#define SETTNG_LUBRICATION_H

#include "mybase.h"

namespace Ui {
class Settng_Lubrication;
}

class Settng_Lubrication : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Lubrication(QWidget *parent = 0);
    ~Settng_Lubrication();

private:
    Ui::Settng_Lubrication *ui;
};

#endif // SETTNG_LUBRICATION_H
