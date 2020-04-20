#ifndef CTRLTRAIN4OUTLINE_H
#define CTRLTRAIN4OUTLINE_H

#include <QWidget>

namespace Ui {
class CtrlTrain4OutLine;
}

class CtrlTrain4OutLine : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTrain4OutLine(QWidget *parent = 0);
    ~CtrlTrain4OutLine();

private:
    Ui::CtrlTrain4OutLine *ui;
};

#endif // CTRLTRAIN4OUTLINE_H
