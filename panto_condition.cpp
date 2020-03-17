#include "panto_condition.h"
#include "ui_panto_condition.h"

Panto_Condition::Panto_Condition(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Panto_Condition)
{
    ui->setupUi(this);
    oc = new Operating_Condition(this);
    oc->hide();
    curPage = 0;
}

Panto_Condition::~Panto_Condition()
{
    delete ui;
}

void Panto_Condition::updatePage()
{
    faultString.clear();

    faultString<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"
                  << "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"
                     << "z"<< "x"<< "xq"<< "xa"<< "xq"<< "xa"<< "xq"<< "da"<< "dq"<< "da"<< "dq"<< "da"<< "qd"<< "a"<< "q"<< "a"
                        << "dq"<< "da"<< "dq"<< "da"<< "q"<< "a"<< "q"<< "sa"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a"<< "q"<< "a";

    int remainder = faultString.size() % 16;
    totalPage = faultString.size()/16;
    if (remainder > 0)
    {
        totalPage = totalPage + 1;
    }

    if (curPage == totalPage -1)
    {
        oc->updateLineText(faultString, curPage, curPage*16 , faultString.size());
    }
    else
    {
        if (totalPage == 0)
        {
            oc->updateLineText(faultString, curPage, 0 , 0);
        }else
        {
            oc->updateLineText(faultString, curPage, curPage*16 , (curPage+1)*16);
        }
    }
    oc->show();
}

void Panto_Condition::on_BTN_Page_clicked()
{

    if (curPage == totalPage - 1)
    {
        return;
    }
    curPage++;
    this->updatePage();
}
