#ifndef MAIN_DATETIME_H
#define MAIN_DATETIME_H
#include  "qpushbutton.h"

#include <QWidget>
#include "mybase.h"
#include "qtimer.h"

namespace Ui {
class Main_Datetime;
}

class Main_Datetime : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Datetime(QWidget *parent = 0);
    ~Main_Datetime();
    static int year,month,day,hour,minute,second;
    void updatePage();
    QList<QPushButton *> buttons;
    QList<QLabel*> labels;
    QList<int> dateTimeValues;
    void initDateTime(QList<QLabel *> labels ,QList<int> values);
    QDateTime  dateTime;
    void updateDateTime(QLabel* label1,QLabel* label2,QString date,QString time );

    enum funcNum{
        Update=0,
        Year_Dec=1,
        Year_Asc,
        Month_Dec,
        Month_Asc,
        Day_Dec,
        Day_Asc,
        Hour_Dec,
        Hour_Asc,
        Minute_Dec,
        Minute_Asc,
        Second_Dec,
        Second_Asc
    };

    QTimer *qTimer;

private:
    Ui::Main_Datetime *ui;
private slots:
    void buttonsPressEvent();
    void on_PB_Update_pressed();
    void timeoutEvent();
};

#endif // MAIN_DATETIME_H
