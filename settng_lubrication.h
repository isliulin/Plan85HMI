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
    void updatePage();
    void showEvent(QShowEvent*);
    void hideEvent(QHideEvent*);

private slots:
    void on_BTN_DisAdd_pressed();
    void on_BTN_DisSub_pressed();

    void on_BTN_TimeAdd_pressed();

    void on_BTN_TimeSub_pressed();

private:
    Ui::Settng_Lubrication *ui;
    ushort setDis,setTime;
};

#endif // SETTNG_LUBRICATION_H
