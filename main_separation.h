#ifndef MAIN_SEPARATION_H
#define MAIN_SEPARATION_H
#include "widgets/ctrlnumbertable.h"

#include <QWidget>
#include "mybase.h"
#include "qtimer.h"

namespace Ui {
class Main_Separation;
}

class Main_Separation : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Separation(QWidget *parent = 0);
    ~Main_Separation();
    CtrlNumberTable* ctrlNumberTable;
    static QString separationNumber;
    void updatePage();


private slots:
    void on_PB_send_pressed();

    void on_PB_testActive_pressed();

    void on_PB_testCancel_pressed();
    void timeoutEvent();

private:
    Ui::Main_Separation *ui;
    QTimer* qTimer;
};

#endif // MAIN_SEPARATION_H
