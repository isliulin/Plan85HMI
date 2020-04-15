#ifndef UNITY_BRAKE_H
#define UNITY_BRAKE_H

#include <mybase.h>
#include "widgets/ctrlkpadiagram.h"
namespace Ui {
class Unity_Brake;
}

class Unity_Brake : public MyBase
{
    Q_OBJECT

public:
    explicit Unity_Brake(QWidget *parent = 0);
    ~Unity_Brake();
    void updatePage();
    void showEvent(QShowEvent *event);
private:
    Ui::Unity_Brake *ui;
    CtrlKpaDiagram* ctrlKpaDiagram1,*ctrlKpaDiagram2;
};

#endif // UNITY_BRAKE_H
