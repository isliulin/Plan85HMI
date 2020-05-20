#ifndef CTRLNUMBERTABLE_H
#define CTRLNUMBERTABLE_H
#include "qpushbutton.h"
#include "qlabel.h"
#include <QWidget>

namespace Ui {
class CtrlNumberTable;
}

class CtrlNumberTable : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlNumberTable(QWidget *parent = 0);
    ~CtrlNumberTable();
    QList<QPushButton *> buttons;
    static QString numbers;
    QString getNumber();

private:
    Ui::CtrlNumberTable *ui;
private slots:
    void buttonsPressedEvent();
};

#endif // CTRLNUMBERTABLE_H
