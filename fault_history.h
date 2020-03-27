#ifndef FAULT_HISTORY_H
#define FAULT_HISTORY_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
class Fault_History;
}

class Fault_History : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_History(QWidget *parent = 0);
    ~Fault_History();

private:
    Ui::Fault_History *ui;
};

#endif // FAULT_HISTORY_H
