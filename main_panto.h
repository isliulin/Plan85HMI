#ifndef MAIN_PANTO_H
#define MAIN_PANTO_H

#include <QWidget>
#include "mybase.h"
#include "qpushbutton.h"
#include "qtimer.h"

namespace Ui {
class Main_Panto;
}

class Main_Panto : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Panto(QWidget *parent = 0);
    ~Main_Panto();

private:
    Ui::Main_Panto *ui;
    QList<QPushButton*> funcButtons;
    QTimer *qTimer;
    enum funcNumber{
        speedAsc=1,
        speedDec,
        send,
    };
    void releaseAllButtons();
    void unableAllButtons();
private slots:
    void timeoutEvent();
    void buttonsPressedEvent();
};

#endif // MAIN_PANTO_H
