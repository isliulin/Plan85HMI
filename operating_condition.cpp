#include "operating_condition.h"
#include "ui_operating_condition.h"

Operating_Condition::Operating_Condition(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Operating_Condition)
{
    ui->setupUi(this);

    pageNum<< this->ui->LBL_Num1<< this->ui->LBL_Num2<< this->ui->LBL_Num3<< this->ui->LBL_Num4
              << this->ui->LBL_Num5<< this->ui->LBL_Num6<< this->ui->LBL_Num7<< this->ui->LBL_Num8
              << this->ui->LBL_Num9<< this->ui->LBL_Num10<< this->ui->LBL_Num11<< this->ui->LBL_Num12
              << this->ui->LBL_Num13<< this->ui->LBL_Num14<< this->ui->LBL_Num15<< this->ui->LBL_Num16
              << this->ui->LBL_Num17<< this->ui->LBL_Num18<< this->ui->LBL_Num19<< this->ui->LBL_Num20
              << this->ui->LBL_Num21<< this->ui->LBL_Num22<< this->ui->LBL_Num23<< this->ui->LBL_Num24
              << this->ui->LBL_Num25<< this->ui->LBL_Num26<< this->ui->LBL_Num27<< this->ui->LBL_Num28
              << this->ui->LBL_Num29<< this->ui->LBL_Num30<< this->ui->LBL_Num31<< this->ui->LBL_Num32;

    lineText<< this->ui->LBL_Line1<< this->ui->LBL_Line2<< this->ui->LBL_Line3<< this->ui->LBL_Line4
                 << this->ui->LBL_Line5<< this->ui->LBL_Line6<< this->ui->LBL_Line7<< this->ui->LBL_Line8
                 << this->ui->LBL_Line9<< this->ui->LBL_Line10<< this->ui->LBL_Line11<< this->ui->LBL_Line12
                 << this->ui->LBL_Line13<< this->ui->LBL_Line14<< this->ui->LBL_Line15<< this->ui->LBL_Line16;
}

Operating_Condition::~Operating_Condition()
{
    delete ui;
}

void Operating_Condition::updateLineText(QList<QString> lt, int curpage, int start, int end)
{
    for (int i = 0; i< lineText.size(); i++)
    {
        lineText[i]->setText("");
    }

    for(int i = 0; i < end - start; i++)
    {
        lineText[i]->setText(lt.at(start + i));
    }

    if (curpage == 0)
    {
        for(int i = 0; i< 32; i++)
        {
            pageNum[i]->setText(QString::number(i + 1));
        }
    }
    else
    {
        for(int i = 0; i< 32; i++)
        {
            if (i < 16)
            {
                pageNum[i]->setText(QString::number( i + 17));
            }else
            {
                pageNum[i]->setText(QString::number( i - 15));
            }
        }
    }

}
