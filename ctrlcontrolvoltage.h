#ifndef CTRLCONTROLVOLTAGE_H
#define CTRLCONTROLVOLTAGE_H

#include <QWidget>

namespace Ui {
class CtrlControlVoltage;
}

class CtrlControlVoltage : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlControlVoltage(QWidget *parent = 0);
    ~CtrlControlVoltage();

private:
    Ui::CtrlControlVoltage *ui;
};

#endif // CTRLCONTROLVOLTAGE_H
