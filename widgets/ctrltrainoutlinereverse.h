#ifndef CTRLTRAINOUTLINEREVERSE_H
#define CTRLTRAINOUTLINEREVERSE_H

#include <QWidget>

namespace Ui {
class CtrlTrainOutLineReverse;
}

class CtrlTrainOutLineReverse : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTrainOutLineReverse(QWidget *parent = 0);
    ~CtrlTrainOutLineReverse();

private:
    Ui::CtrlTrainOutLineReverse *ui;
};

#endif // CTRLTRAINOUTLINEREVERSE_H
