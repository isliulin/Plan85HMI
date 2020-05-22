#ifndef CONDITION_BREAKER_H
#define CONDITION_BREAKER_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Condition_Breaker;
}

class Condition_Breaker : public MyBase
{
    Q_OBJECT

public:
    explicit Condition_Breaker(QWidget *parent = 0);
    ~Condition_Breaker();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Condition_Breaker *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;
};

#endif // CONDITION_BREAKER_H
