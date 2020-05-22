#include "main_datetime.h"
#include "ui_main_datetime.h"

int Main_Datetime::year=0;
int Main_Datetime::month=0;
int Main_Datetime::day=0;
int Main_Datetime::hour=0;
int Main_Datetime::minute=0;
int Main_Datetime::second=0;

Main_Datetime::Main_Datetime(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Datetime)
{
    ui->setupUi(this);
    QDate date=QDate::currentDate();
    year=date.year();
    month=date.month();
    day=date.day();
    QTime time=QTime::currentTime();
    hour=time.hour();
    minute=time.minute();
    second=time.second();
    labels<<ui->lbl_Set_Year<<ui->lbl_Set_Month<<ui->lbl_Set_Day
         <<ui->lbl_Set_Hour<<ui->lbl_Set_Minute<<ui->lbl_Set_Second;
    dateTimeValues<<year<<month<<day<<hour<<minute<<second;
    initDateTime(labels,dateTimeValues);
    buttons<<ui->PB_Year_Dec<<ui->PB_Year_Asc<<ui->PB_Month_Dec<<ui->PB_Month_Asc
          <<ui->PB_Day_Dec<<ui->PB_Day_Asc<<ui->PB_Hour_Dec<<ui->PB_Hour_Asc
         <<ui->PB_Minute_Des<<ui->PB_Minute_Asc<<ui->PB_Second_Dec<<ui->PB_Second_Asc
        <<ui->PB_Update;
    foreach (QPushButton* button, buttons) {
        connect(button,SIGNAL(pressed()),this,SLOT(buttonsPressEvent()));
    }

    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timeoutEvent()));

}

Main_Datetime::~Main_Datetime()
{
    delete ui;
}

void Main_Datetime::updatePage()
{
    dateTime = QDateTime::currentDateTime();
    updateDateTime(ui->lbl_SYS_date,ui->lbl_SYS_time,dateTime.date().toString("yyyy:MM:dd"),dateTime.time().toString());
}

void Main_Datetime::initDateTime(QList<QLabel *> labels, QList<int> values)
{
    if(labels.length()!=values.length())
    {
        qDebug()<<"main_datetime.cpp initDateTime function lables.length!= values.length!";
        return;
    }
    for(int i=0;i<labels.length();i++)
    {
        labels.at(i)->setText(QString::number(values.at(i)));
    }
}

void Main_Datetime::updateDateTime(QLabel *label1, QLabel *label2, QString date, QString time)
{
    label1->setText(date);
    label2->setText(time);
}

void Main_Datetime::buttonsPressEvent()
{
    int number=((QPushButton *) this->sender())->whatsThis().toInt();
    switch(number)
    {
    case Update:
        break;
    case Year_Dec:
        if(year>1)
            year--;
        ui->lbl_Set_Year->setText(QString::number(year));
        break;
    case Year_Asc:
        year++;
        ui->lbl_Set_Year->setText(QString::number(year));
        break;
    case Month_Dec:
        if(month>1)
            month--;
        ui->lbl_Set_Month->setText(QString::number(month));
        break;
    case Month_Asc:
        if(month<12)
            month++;
        ui->lbl_Set_Month->setText(QString::number(month));
        break;
    case Day_Dec:
        if(day>1)
            day--;
        ui->lbl_Set_Day->setText(QString::number(day));
        break;
    case Day_Asc:
        if(day<31)
            day++;
        ui->lbl_Set_Day->setText(QString::number(day));
        break;
    case Hour_Dec:
        if(hour>0)
            hour--;
        ui->lbl_Set_Hour->setText(QString::number(hour));
        break;
    case Hour_Asc:
        if(hour<23)
            hour++;
        ui->lbl_Set_Hour->setText(QString::number(hour));
        break;
    case Minute_Dec:
        if(minute>0)
            minute--;
        ui->lbl_Set_Minute->setText(QString::number(minute));
        break;
    case Minute_Asc:
        if(minute<59)
            minute++;
        ui->lbl_Set_Minute->setText(QString::number(minute));
        break;
    case Second_Dec:
        if(second>0)
            second--;
        ui->lbl_Set_Second->setText(QString::number(second));
        break;
    case Second_Asc:
        if(second<59)
            second++;
        ui->lbl_Set_Second->setText(QString::number(second));
        break;
    }
}

void Main_Datetime::on_PB_Update_pressed()
{
    ui->PB_Update->setStyleSheet(MAINBUTTONDOWN);
    qTimer->start(2000);
}

void Main_Datetime::timeoutEvent()
{
    ui->PB_Update->setStyleSheet(MAINBUTTONUP);
}
