#ifndef SETTNG_OTHERS_H
#define SETTNG_OTHERS_H

#include "mybase.h"
#include "QPushButton"

namespace Ui {
class Settng_Others;
}

class Settng_Others : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Others(QWidget *parent = 0);
    ~Settng_Others();
    void updatePage();
    void timerEvent(QTimerEvent *e);

private slots:
    void modePressEvent();
    void setWeightEvent();
private:
    Ui::Settng_Others *ui;
    QList<QPushButton* > ModebuttonList,NumbuttonList;
    int modeIndex,timerSave;
    QString numValue,inputValue;
};

#endif // SETTNG_OTHERS_H
