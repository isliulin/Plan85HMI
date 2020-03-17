#ifndef MAIN_LIGHT_H
#define MAIN_LIGHT_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
class Main_Light;
}

class Main_Light : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Light(QWidget *parent = 0);
    ~Main_Light();

private:
    Ui::Main_Light *ui;
};

#endif // MAIN_LIGHT_H
