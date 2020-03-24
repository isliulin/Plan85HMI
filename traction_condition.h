#ifndef TRACTION_CONDITION_H
#define TRACTION_CONDITION_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Traction_Condition;
}

class Traction_Condition : public MyBase
{
    Q_OBJECT

public:
    explicit Traction_Condition(QWidget *parent = 0);
    ~Traction_Condition();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Traction_Condition *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;
};

#endif // Traction_Condition_H
