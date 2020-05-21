#ifndef SETTNG_HANGMODE_H
#define SETTNG_HANGMODE_H

#include "mybase.h"
#include "QPushButton"

namespace Ui {
class Settng_HangMode;
}

class Settng_HangMode : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_HangMode(QWidget *parent = 0);
    ~Settng_HangMode();
    void updatePage();
    void timerEvent(QTimerEvent *e);
    void hideEvent(QHideEvent*);

private slots:
    void modePressEvent();
    void setSpeedEvent();

private:
    Ui::Settng_HangMode *ui;
    QList<QPushButton* > ModebuttonList,NumbuttonList;
    int modeIndex,timer3S;
    QString numValue,inputValue;
};

#endif // SETTNG_HANGMODE_H
