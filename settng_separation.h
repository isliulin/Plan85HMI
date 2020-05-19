#ifndef SETTNG_SEPARATION_H
#define SETTNG_SEPARATION_H

#include "mybase.h"
#include "QPushButton"

namespace Ui {
class Settng_Separation;
}

class Settng_Separation : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Separation(QWidget *parent = 0);
    ~Settng_Separation();
    void updatePage();
    void timerEvent(QTimerEvent* e);

private slots:
    void modePressEvent();
private:
    Ui::Settng_Separation *ui;
    QList<QPushButton*> modeButtonList;
    int modeIndex,timerNormal,timerFreight,count;
    bool flag;
};

#endif // SETTNG_SEPARATION_H
