#ifndef CTRLTRAIN4OUTLINEREVERSE_H
#define CTRLTRAIN4OUTLINEREVERSE_H

#include <QWidget>

namespace Ui {
class CtrlTrain4OutLineReverse;
}

class CtrlTrain4OutLineReverse : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTrain4OutLineReverse(QWidget *parent = 0);
    ~CtrlTrain4OutLineReverse();

private:
    Ui::CtrlTrain4OutLineReverse *ui;
};

#endif // CTRLTRAIN4OUTLINEREVERSE_H
