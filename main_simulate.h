#ifndef MAIN_SIMULATE_H
#define MAIN_SIMULATE_H
#include "mybase.h"
#include "qpushbutton.h"
#include "qtimer.h"

#include <QWidget>

namespace Ui {
class Main_Simulate;
}

class Main_Simulate : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Simulate(QWidget *parent = 0);
    ~Main_Simulate();
    void updatePage();
    QList<QPushButton *> buttons;
    void  numberButtonsPressed();
    static QString Main_SimulateNumberSpeed;
    static QString Main_SimulateNumberVol;
    bool funcFlag;
    void funcButtonsPressed();
    QList<QPushButton*> funcButtons;
    enum funcNumber{
        simulateKey=11,
        orderTestActive,
        speedInput,
        volInput,
        send
    };

    QTimer *qTimer;

private:
    Ui::Main_Simulate *ui;
    void releaseAllButtons();
    void unableAllButtons();
    void ableAllButtons();
private slots:
    void numberButtonsPressedEvent();
    void funcButtonsPressedEvent();
    void timeoutEvent();
};

#endif // MAIN_SIMULATE_H
