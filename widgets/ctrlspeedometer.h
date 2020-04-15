#ifndef CTRLSPEEDOMETER_H
#define CTRLSPEEDOMETER_H

#include <QWidget>
#include <QPainter>
#include "global.h"

namespace Ui {
    class CtrlSpeedometer;
}

class CtrlSpeedometer : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlSpeedometer(QWidget *parent = 0);
    ~CtrlSpeedometer();
    void setSpeenometerValue(int value);
    void paintEvent(QPaintEvent *e);

private:
    Ui::CtrlSpeedometer *ui;
    int m_value;
};

#endif // CTRLSPEEDOMETER_H
