#ifndef CONDITION_PANTOUP_H
#define CONDITION_PANTOUP_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Condition_PantoUp;
}

class Condition_PantoUp : public MyBase
{
    Q_OBJECT

public:
    explicit Condition_PantoUp(QWidget *parent = 0);
    ~Condition_PantoUp();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Condition_PantoUp *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;

};

#endif // CONDITION_PANTOUP_H
