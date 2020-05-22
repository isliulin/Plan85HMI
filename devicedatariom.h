#ifndef DEVICEDATARIOM_H
#define DEVICEDATARIOM_H

#include "mybase.h"

class QTableWidget;
class QButtonGroup;

namespace Ui {
class DeviceDataRIOM;
}

class DeviceDataRIOM : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceDataRIOM(QWidget *parent = 0);
    ~DeviceDataRIOM();

    void initialTableView(QTableWidget *table);
    void setWidth(QTableWidget *table, bool isDo = false, bool isAx = false);
    void updateDio(QTableWidget *table, QList<bool> &state, int column);
    void updateAx(QTableWidget *table, QList<int> &state);
    void updatePage();
    void cleanContent(QTableWidget *table);
    void setTableView(QTableWidget *table,QList<QString> channelNameList, int column);
    void setViews(int page);
private slots:
    void on_btnNext_clicked();
    void onRiomButtonClicked(int);

    void on_btnPre_clicked();

private:
    Ui::DeviceDataRIOM *ui;
    QTableWidget *diTable1, *diTable2, *doTable1, *doTable2, *axTable;
    QList<QString> r1di1, r1di2, r1do1,
    //r1ax,
    r2di1, r2di2, r2di3, r2di4, r2di5, r2do1, r2do2, r2do3, r2do4;

    // record the current riom(riom1 or riom2)
    bool isRiom1;
    //record the current page
    int page;
    QButtonGroup *riomButtons;
};

#endif // DEVICEDATARIOM_H
