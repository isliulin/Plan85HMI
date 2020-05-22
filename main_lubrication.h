#ifndef MAIN_LUBRICATION_H
#define MAIN_LUBRICATION_H

#include <QWidget>
#include <mybase.h>
#include "qtimer.h"

namespace Ui {
class Main_Lubrication;
}

class Main_Lubrication : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Lubrication(QWidget *parent = 0);
    ~Main_Lubrication();

private slots:
    void on_PB_runningActive_pressed();

    void on_PB_cancel_pressed();
    void timeoutEvent();

private:
    Ui::Main_Lubrication *ui;
    QTimer* qTimer;
};

#endif // MAIN_LUBRICATION_H
