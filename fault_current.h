#ifndef FAULT_CURRENT_H
#define FAULT_CURRENT_H

#include <QWidget>
#include "mybase.h"
#include "qlabel.h"

namespace Ui {
class Fault_Current;
}

class Fault_Current : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_Current(QWidget *parent = 0);
    ~Fault_Current();
    void updatePage();

private slots:
    void on_PB_up_pressed();

    void on_PB_down_pressed();

    void on_PB_up_released();

    void on_PB_down_released();

private:
    Ui::Fault_Current *ui;
    QList< QList<QLabel *> > labelsList;
    int currentFaultPage;
    int totalPage;
    void updateFaultList();
    int currenFaultNumber;

};

#endif // FAULT_CURRENT_H
