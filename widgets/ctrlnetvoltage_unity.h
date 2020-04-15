#ifndef CTRLNETVOLTAGE_UNITY_H
#define CTRLNETVOLTAGE_UNITY_H

#include <QWidget>

namespace Ui {
class CtrlNetVoltage_Unity;
}

class CtrlNetVoltage_Unity : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlNetVoltage_Unity(QWidget *parent = 0, int green1 = 120, int green2 = 50,
                                  int red1 = 70, int red2 = 40, int blue = 60);
    ~CtrlNetVoltage_Unity();
    void setCtrlValueRect(int value);
private:
    Ui::CtrlNetVoltage_Unity *ui;
    int m_greenline1,m_greenline2,m_redline1,m_redline2,m_blueline;

};

#endif // CTRLNETVOLTAGE_UNITY_H
