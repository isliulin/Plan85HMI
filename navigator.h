#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QWidget>
#include "mybase.h"
#include "QPushButton"
namespace Ui {
    class Navigator;
}

class Navigator : public MyBase
{
    Q_OBJECT

public:
    explicit Navigator(QWidget *parent = 0);
    ~Navigator();
    void updateLanguage();
private:
    Ui::Navigator *ui;
    QList<QPushButton*>buttons;

private slots:
    void NBpressEvent();
signals:
    void translateLanguage();

};

#endif // NAVIGATOR_H
