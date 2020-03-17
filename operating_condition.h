#ifndef OPERATING_CONDITION_H
#define OPERATING_CONDITION_H

#include <mybase.h>
#include "qlabel.h"

namespace Ui {
class Operating_Condition;
}

class Operating_Condition : public MyBase
{
    Q_OBJECT

public:
    explicit Operating_Condition(QWidget *parent = 0);
    ~Operating_Condition();
    void updatePageNum();
    void updateLineText(QList<QString >lt,int curpage,int start, int end);

private:
    Ui::Operating_Condition *ui;
    QList<QLabel* >pageNum;
    QList<QLabel* >lineText;

};

#endif // OPERATING_CONDITION_H
