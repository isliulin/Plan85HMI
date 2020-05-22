#ifndef CONDITION_BRAKE_H
#define CONDITION_BRAKE_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Condition_Brake;
}

class Condition_Brake : public MyBase
{
    Q_OBJECT

public:
    explicit Condition_Brake(QWidget *parent = 0);
    ~Condition_Brake();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Condition_Brake *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;
};

#endif // CONDITION_BRAKE_H
