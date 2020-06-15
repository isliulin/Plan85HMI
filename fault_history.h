#ifndef FAULT_HISTORY_H
#define FAULT_HISTORY_H

#include <QWidget>
#include "mybase.h"
#include "qlabel.h"

namespace Ui {
class Fault_History;
}

class Fault_History : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_History(QWidget *parent = 0);
    ~Fault_History();
    void updatePage();

private slots:
    void on_PB_up_pressed();

    void on_PB_down_pressed();

    void on_PB_up_released();

    void on_PB_down_released();

private:
    Ui::Fault_History *ui;
    QList<QList<QLabel *> > labelsList;
    int currentFaultPage;
    int totalPage;
    void updateFaultList();
    int currenFaultNumber;

};

#endif // FAULT_HISTORY_H
