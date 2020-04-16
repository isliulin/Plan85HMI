#ifndef CTRLFLOWDIAGRAM_H
#define CTRLFLOWDIAGRAM_H

#include <QWidget>

namespace Ui {
class CtrlFlowDiagram;
}

class CtrlFlowDiagram : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlFlowDiagram(QWidget *parent = 0);
    ~CtrlFlowDiagram();
    void setCtrlValueRect(int value);

private:
    Ui::CtrlFlowDiagram *ui;
};

#endif // CTRLFLOWDIAGRAM_H
