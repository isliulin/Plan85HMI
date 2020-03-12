#ifndef SETTNG_HANGMODE_H
#define SETTNG_HANGMODE_H

#include "mybase.h"

namespace Ui {
class Settng_HangMode;
}

class Settng_HangMode : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_HangMode(QWidget *parent = 0);
    ~Settng_HangMode();

private:
    Ui::Settng_HangMode *ui;
};

#endif // SETTNG_HANGMODE_H
