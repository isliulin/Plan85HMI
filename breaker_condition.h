#ifndef BREAKER_CONDITION_H
#define BREAKER_CONDITION_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Breaker_Condition;
}

class Breaker_Condition : public MyBase
{
    Q_OBJECT

public:
    explicit Breaker_Condition(QWidget *parent = 0);
    ~Breaker_Condition();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Breaker_Condition *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;
};

#endif // BREAKER_CONDITION_H
