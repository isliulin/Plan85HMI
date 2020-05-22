#ifndef MAIN_ASSISTANTDEVICE_H
#define MAIN_ASSISTANTDEVICE_H
#include <mybase.h>
#include "qpushbutton.h"
#include "qtimer.h"

#include <QWidget>

namespace Ui {
class Main_AssistantDevice;
}

class Main_AssistantDevice : public MyBase
{
    Q_OBJECT

public:
    explicit Main_AssistantDevice(QWidget *parent = 0);
    ~Main_AssistantDevice();
    void updatePage();


private:
    Ui::Main_AssistantDevice *ui;
    QList<QPushButton*> funcButtons;
    QTimer *qTimer;
    enum funcNumber{
        AirPressTest=1,
        MwindTest_1,
        MwindTest_2,
        CoolWindTest_1,
        CoolWindTest_2,
        TractWindTest_1,
        TractWindTest_2
    };

    void releaseAllbuttons();
    void unableAllButtons();
    void ableAllButtons();

private slots:
    void funcButtonsPressEvent();
    void timeoutEvent();
};

#endif // MAIN_ASSISTANTDEVICE_H
