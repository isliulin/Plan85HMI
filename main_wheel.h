#ifndef MAIN_WHEEL_H
#define MAIN_WHEEL_H
#include "widgets/ctrlnumbertable.h"

#include <QWidget>
#include "mybase.h"
#include "qtimer.h"

namespace Ui {
class Main_Wheel;
}

class Main_Wheel : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Wheel(QWidget *parent = 0);
    ~Main_Wheel();
    CtrlNumberTable* ctrlNumberTable;
    static QString wheelNumber;
    void updatePage();

private slots:
    void on_PB_store_pressed();
    void timeoutEvent();

private:
    Ui::Main_Wheel *ui;
    QTimer* qTimer;
};

#endif // MAIN_WHEEL_H
