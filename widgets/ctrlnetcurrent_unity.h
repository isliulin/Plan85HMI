#ifndef CTRLNETCURRENT_UNITY_H
#define CTRLNETCURRENT_UNITY_H

#include <QWidget>

namespace Ui {
class CtrlNetCurrent_Unity;
}

class CtrlNetCurrent_Unity : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlNetCurrent_Unity(QWidget *parent = 0);
    ~CtrlNetCurrent_Unity();
    void setCtrlValueRect(int value);

private:
    Ui::CtrlNetCurrent_Unity *ui;
};

#endif // CTRLNETCURRENT_UNITY_H
