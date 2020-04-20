#ifndef CTRLTRAIN3OUTLINE_H
#define CTRLTRAIN3OUTLINE_H

#include <QWidget>

namespace Ui {
class CtrlTrain3OutLine;
}

class CtrlTrain3OutLine : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTrain3OutLine(QWidget *parent = 0);
    ~CtrlTrain3OutLine();

private:
    Ui::CtrlTrain3OutLine *ui;
};

#endif // CTRLTRAIN3OUTLINE_H
