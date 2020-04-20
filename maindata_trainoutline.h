#ifndef MAINDATA_TRAINOUTLINE_H
#define MAINDATA_TRAINOUTLINE_H

#include <mybase.h>
#include "widgets/ctrltrainoutline.h"
#include "widgets/ctrltrainoutlinereverse.h"
#include "widgets/ctrltrain3outline.h"
#include "widgets/ctrltrain3outlinereverse.h"
#include "widgets/ctrltrain4outline.h"
#include "widgets/ctrltrain4outlinereverse.h"

namespace Ui {
class MainData_TrainOutline;
}

class MainData_TrainOutline : public MyBase
{
    Q_OBJECT

public:
    explicit MainData_TrainOutline(QWidget *parent = 0);
    ~MainData_TrainOutline();
    void updatePage();

private:
    Ui::MainData_TrainOutline *ui;
    CtrlTrainOutLine* trainoutline;
    CtrlTrainOutLineReverse* trainoutlineR;
    CtrlTrain3OutLine* train3outline[2];
    CtrlTrain3OutLineReverse* train3outlineR;
    CtrlTrain4OutLine* train4outline[2];
    CtrlTrain4OutLineReverse* train4outlineR[2];
    void HideAllTrain();
    void updateData();
};

#endif // MAINDATA_TRAINOUTLINE_H
