#ifndef CTRLKPADIAGRAM_H
#define CTRLKPADIAGRAM_H

#include <QWidget>
#include <QPainter>
#include "global.h"

namespace Ui {
class CtrlKpaDiagram;
}

class CtrlKpaDiagram : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlKpaDiagram(QWidget *parent = 0);
    ~CtrlKpaDiagram();
    void setSpeenometerValue(int value);
    void paintEvent(QPaintEvent *e);
private:
    Ui::CtrlKpaDiagram *ui;
    int m_value;

};

#endif // CTRLKPADIAGRAM_H
