#ifndef CTRLTRAIN3OUTLINEREVERSE_H
#define CTRLTRAIN3OUTLINEREVERSE_H

#include <QWidget>

namespace Ui {
class CtrlTrain3OutLineReverse;
}

class CtrlTrain3OutLineReverse : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTrain3OutLineReverse(QWidget *parent = 0);
    ~CtrlTrain3OutLineReverse();

private:
    Ui::CtrlTrain3OutLineReverse *ui;
};

#endif // CTRLTRAIN3OUTLINEREVERSE_H
