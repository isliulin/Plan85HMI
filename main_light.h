#ifndef MAIN_LIGHT_H
#define MAIN_LIGHT_H

#include <QWidget>
#include "mybase.h"
#include "qtimer.h"

namespace Ui {
class Main_Light;
}

class Main_Light : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Light(QWidget *parent = 0);
    ~Main_Light();

private slots:
    void on_PB_testActive_pressed();
    void timeoutEvent();


private:
    Ui::Main_Light *ui;
    QTimer* qTimer;
};

#endif // MAIN_LIGHT_H
