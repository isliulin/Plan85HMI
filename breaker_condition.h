#ifndef BREAKER_CONDITION_H
#define BREAKER_CONDITION_H

#include <QWidget>

namespace Ui {
class Breaker_Condition;
}

class Breaker_Condition : public QWidget
{
    Q_OBJECT

public:
    explicit Breaker_Condition(QWidget *parent = 0);
    ~Breaker_Condition();

private:
    Ui::Breaker_Condition *ui;
};

#endif // BREAKER_CONDITION_H
