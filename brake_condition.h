#ifndef BRAKE_CONDITION_H
#define BRAKE_CONDITION_H

#include <QWidget>

namespace Ui {
class Brake_Condition;
}

class Brake_Condition : public QWidget
{
    Q_OBJECT

public:
    explicit Brake_Condition(QWidget *parent = 0);
    ~Brake_Condition();

private:
    Ui::Brake_Condition *ui;
};

#endif // BRAKE_CONDITION_H
