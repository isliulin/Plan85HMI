#ifndef MAIN_380_H
#define MAIN_380_H

#include <QWidget>
#include <mybase.h>

namespace Ui {
class Main_380;
}

class Main_380 : public MyBase
{
    Q_OBJECT

public:
    explicit Main_380(QWidget *parent = 0);
    ~Main_380();

private slots:
    void on_PB_active_pressed();

    void on_PB_cancel_pressed();

private:
    Ui::Main_380 *ui;
};

#endif // MAIN_380_H
