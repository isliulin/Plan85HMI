#ifndef PANTO_CONDITION_H
#define PANTO_CONDITION_H

#include <mybase.h>
#include "operating_condition.h"

namespace Ui {
class Panto_Condition;
}

class Panto_Condition : public MyBase
{
    Q_OBJECT

public:
    explicit Panto_Condition(QWidget *parent = 0);
    ~Panto_Condition();
    void updatePage();

private slots:
    void on_BTN_Page_clicked();

private:
    Ui::Panto_Condition *ui;
    Operating_Condition *oc;
    QList<Operating_Condition *> operating_Condition;
    QList<QString > faultString;
    int curPage,totalPage;

};

#endif // PANTO_CONDITION_H
