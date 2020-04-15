#ifndef CTRCONTROLVOLTAGE_UNITY_H
#define CTRCONTROLVOLTAGE_UNITY_H

#include <QWidget>

namespace Ui {
class CtrControlVoltage_Unity;
}

class CtrControlVoltage_Unity : public QWidget
{
    Q_OBJECT

public:
    explicit CtrControlVoltage_Unity(QWidget *parent = 0,int yellow1 = 120, int yellow2 = 50,
                                     int red1 = 170, int red2 = 40);
    ~CtrControlVoltage_Unity();
    void setCtrlValueRect(int value1,int value2);

private:
    Ui::CtrControlVoltage_Unity *ui;
    int m_yellowline1,m_yellowline2,m_redline1,m_redline2;
};

#endif // CTRCONTROLVOLTAGE_UNITY_H
