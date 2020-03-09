#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
    class Header;
}

class Header : public MyBase
{
    Q_OBJECT

public:
    explicit Header(QWidget *parent = 0);
    void updatePage();

    void setPageName(QString name);
    void updateLanguage();

    ~Header();

private:
    Ui::Header *ui;

private slots:
    void on_CurrentFaultBtn_pressed();
    void on_HelpItemBtn_pressed();
};

#endif // HEADER_H
