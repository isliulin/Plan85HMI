#ifndef MAIN_DATETIME_H
#define MAIN_DATETIME_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
class Main_Datetime;
}

class Main_Datetime : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Datetime(QWidget *parent = 0);
    ~Main_Datetime();

private:
    Ui::Main_Datetime *ui;
};

#endif // MAIN_DATETIME_H
