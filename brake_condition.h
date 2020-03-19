#ifndef BRAKE_CONDITION_H
#define BRAKE_CONDITION_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Brake_Condition;
}

class Brake_Condition : public MyBase
{
    Q_OBJECT

public:
    explicit Brake_Condition(QWidget *parent = 0);
    ~Brake_Condition();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Brake_Condition *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;
};

#endif // BRAKE_CONDITION_H
