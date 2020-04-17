#ifndef SETTNG_PANTO_H
#define SETTNG_PANTO_H

#include "mybase.h"
#include "QPushButton"
#include "QLabel"

namespace Ui {
class Settng_Panto;
}

class Settng_Panto : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Panto(QWidget *parent = 0);
    ~Settng_Panto();
    void updatePage();
    void timerEvent(QTimerEvent *e);

private slots:
    void TrainSelectEvent();
    void on_BTN_PANTO_Cutout_pressed();
    void on_BTN_PANTO_CancelCutout_pressed();

private:
    Ui::Settng_Panto *ui;
    QList<QPushButton*> TrainList;
    void show1Train();
    void show2Train();
    void show4Train();
    void show3Train();
    void hideAllTrain();
    int TrainIndex,timerCutout,timerCancel;
    void HSstate(QLabel* lbl,bool Open,bool Close);
    void Active(QLabel* lbl,bool Active);
};

#endif // SETTNG_PANTO_H
