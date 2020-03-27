#ifndef FAULT_DOWNLOAD_H
#define FAULT_DOWNLOAD_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
class Fault_Download;
}

class Fault_Download : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_Download(QWidget *parent = 0);
    ~Fault_Download();

private:
    Ui::Fault_Download *ui;
};

#endif // FAULT_DOWNLOAD_H
