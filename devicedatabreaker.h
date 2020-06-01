#ifndef DEVICEDATABREAKER_H
#define DEVICEDATABREAKER_H

#include "mybase.h"
class QLabel;
class QButtonGroup;
namespace Ui {
class DeviceDataBreaker;
}

class DeviceDataBreaker : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataBreaker(QWidget *parent = 0);
    ~DeviceDataBreaker();
    void updatePage();
    void showSignalState(QLabel *label, bool);
    void showTrain();

private:
    Ui::DeviceDataBreaker *ui;
    //label list
    QList<QLabel*> labels, trainLabels;

    Data_TCN *tcn;
    int currentTrain;
    QButtonGroup *buttons;

private slots:
    void onButtonClicked(int);
};

#endif // DEVICEDATABREAKER_H
