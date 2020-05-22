#ifndef SETTNG_TRAINCODE_H
#define SETTNG_TRAINCODE_H
#include "MainGetDefaultPara.h"

#include "mybase.h"
#include "QPushButton"

namespace Ui {
class Settng_TrainCode;
}

class Settng_TrainCode : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_TrainCode(QWidget *parent = 0);
    ~Settng_TrainCode();
    void updatePage();
    void timerEvent(QTimerEvent* e);
    void hideEvent(QHideEvent*);

private slots:
    void setCodeEvent();
    void on_Button_CurrentCarNum_pressed();
    void on_Button_OtherCarNum_pressed();
    void on_Button_SetCurrentCar_pressed();
    void on_Button_SetOtherCar_pressed();

private:
    Ui::Settng_TrainCode *ui;
    QList<QPushButton*> NumbuttonList;
    QString inputValue,numValue;
    int timerCur,timerOther;
};

#endif // SETTNG_TRAINCODE_H
