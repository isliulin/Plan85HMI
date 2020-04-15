#ifndef CONDITION_TRACTION_H
#define CONDITION_TRACTION_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Condition_Traction;
}

class Condition_Traction : public MyBase
{
    Q_OBJECT

public:
    explicit Condition_Traction(QWidget *parent = 0);
    ~Condition_Traction();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Condition_Traction *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;
};

#endif // CONDITION_TRACTION_H
