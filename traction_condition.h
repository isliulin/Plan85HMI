#ifndef TRACTION_CONDITION_H
#define TRACTION_CONDITION_H

#include <mybase.h>

namespace Ui {
class Traction_Condition;
}

class Traction_Condition : public MyBase
{
    Q_OBJECT

public:
    explicit Traction_Condition(QWidget *parent = 0);
    ~Traction_Condition();

private:
    Ui::Traction_Condition *ui;
};

#endif // TRACTION_CONDITION_H
