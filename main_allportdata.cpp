#include "main_allportdata.h"
#include "ui_main_allportdata.h"
#include "crrcmvb.h"
#include "qpainter.h"
Main_Allportdata::Main_Allportdata(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Allportdata)
{
    ui->setupUi(this);

    RIOMPorts<<0x210<<0x211<<0x212<<0x220
            <<0x221<<0x222<<0x223<<0x218<<0x228<<0x229;

    HMIPorts<<0x300<<0x301<<0x302<<0x700
            <<0x701<<0x702<<0x703<<0x704
            <<0x710<<0x711<<0x712<<0x713
            <<0x610<<0x611<<0x800<<0x801<<0x802<<0x803;

    TCN1Ports<<0xE10<<0xE11<<0xE12<<0xE13<<0xE14
             <<0xE20<<0xE21<<0xE22<<0xE23<<0xE24;

    TCN2Ports<<0xE30<<0xE31<<0xE32<<0xE33<<0xE34
            <<0xE40<<0xE41<<0xE42<<0xE43<<0xE44<<0xEA0;

    TCN3Ports<<0xF10<<0xF11<<0xF12<<0xF13<<0xF14
            <<0xF20<<0xF21<<0xF22<<0xF23<<0xF24;

    TCN4Ports<<0xF30<<0xF31<<0xF32<<0xF33<<0xF34
             <<0xF40<<0xF41<<0xF42<<0xF43<<0xF44<<0xFA0;

    TCUPorts<<0x400<<0x401<<0x402<<0x410
            <<0x411<<0x412<<0x420<<0x421
            <<0x422<<0x430<<0x431<<0x432
            <<0x500<<0x501<<0x502<<0x503<<0X530<<0X531;

    RCUPorts<<0xFD3<<0xFD4<<0xFD5<<0xFD6<<0xFD7<<
              0xFD8<<0xFD9<<0xfd0<<0xfd1;


    OTHER1Ports<<0x103<<0x104<<0x105<<0x113
            <<0x114<<0x115<<0x136<<0x1f
            <<0x100<<0x110<<0x310<<0x320
            <<0x321<<0x322<<0x323;
    OTHER2Ports<<0xfc0<<0xfc1<<0xfc2<<0xfc3
              <<0XFB0<<0XFD2<<0xFDB<<0xFDC<<0xFDD;


    this->m_PortsList = HMIPorts;
    ui->BTNDDU->setStyleSheet(NButtonDOWN);

    buttons<<ui->BTNDDU<<ui->BTNTCN1<<ui->BTNTCN2<<ui->BTNTCN3<<ui->BTNTCN4<<ui->BTNRIOM<<ui->BTNTCU
           <<ui->BTNOTHER1<<ui->BTNOTHER2<<ui->BTNRCU;

    foreach (QPushButton *button, buttons)
    {
        connect(button, SIGNAL(clicked()), this, SLOT(ButtonsPressEvent()));
    }
}

Main_Allportdata::~Main_Allportdata()
{
    delete ui;
}
void Main_Allportdata::updatePage()
{
    this->update();
}
void Main_Allportdata::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(11);
    painter.setFont(font);
    painter.setPen(QPen(Qt::white,2));
    painter.setBrush(QBrush(Qt::transparent));

    // draw title
    for(int i = 0; i < 34 ; i++)
    {

        QString text1;
        QRect rect1;
        if(i == 0)
        {
            text1 = "port";
            rect1 = QRect(1,2,34,25);
            painter.drawRect(rect1);

        }else if(i == 33)
        {
            text1 = "cycle";
            rect1 = QRect(20*32+35,2,40,25);

        }else
        {
            QString tmp;
            tmp.sprintf("%02d",i-1);
            text1 = tmp;
            rect1 = QRect(i*20+14,2,20,25);

        }


        if(i%2==1)
        {
            painter.drawRect(QRect(i*20+14,2,40,25));
        }
        painter.drawText(rect1,Qt::AlignCenter,text1);

    }



    //draw data
    for(int j = 0 ;j < 18 ;j++)
    {
        for(int i = 0; i < 34 ; i++)
        {
            QString text2;
            QRect rect2,rect3;

            if(j%3 == 0)// set pen color
            {
                painter.setPen(QPen(QColor(255,128,0),2));
            }else if(j%3 == 1)
            {
                painter.setPen(QPen(Qt::lightGray,2));
            }else
            {
                painter.setPen(QPen(QColor(255, 255, 0),2));
            }
            //portaddress
            if(i == 0)
            {
                if(j<m_PortsList.size())
                {
                    QString tmp;
                    tmp.sprintf("%03x",m_PortsList[j]);

                    text2 = tmp.toUpper();
                }else
                {
                    text2 = "";
                }
                rect2 = QRect(1,2+(j+1)*24,34,25);
                painter.drawRect(rect2);
                painter.drawText(rect2,Qt::AlignCenter,text2);
            }else if(i == 33)//cycle
            {
                painter.save();
                painter.setPen(QPen(Qt::white,2));

                if(j<m_PortsList.size())
                {
                    QString tmp;
                    tmp.sprintf("%02d",CrrcMvb::getCrrcMvb()->getPortCycle(m_PortsList[j]));


                    if(CrrcMvb::getCrrcMvb()->isPortTimeout(m_PortsList[j]))
                    {
                        painter.setBrush(QBrush(Qt::red));
                    }else
                    {
                        painter.setBrush(QBrush(Qt::transparent));
                    }
                    text2 = tmp.toUpper();
                }else
                {
                    painter.setBrush(QBrush(Qt::transparent));
                    text2 = "";
                }
                rect2 = QRect(32*20+35,2+(j+1)*24,41,25);

                painter.drawRect(rect2);
                painter.drawText(rect2,Qt::AlignCenter,text2);
                painter.restore();

            }else//data
            {
                QString tmp;

                if(j<m_PortsList.size())
                {
                    tmp.sprintf("%02x",CrrcMvb::getCrrcMvb()->getUnsignedChar(m_PortsList[j],i-1));

                    text2 = tmp.toUpper();
                }else
                {
                    text2 = "";
                }
                rect3 = QRect(i*20+14,2+(j+1)*24,20,25);
                painter.drawText(rect3,Qt::AlignCenter,text2);
            }


            if(i%2==1)
            {
                painter.drawRect(QRect(i*20+14,2+(j+1)*24,40,25));
            }

        }
    }




}
void Main_Allportdata::ButtonsPressEvent()
{
    QString BtnName = ((QPushButton *)this->sender())->text();
    if(BtnName == "DDU/ERM")
    {
        this->m_PortsList = HMIPorts;
    }else if(BtnName == "TCN1_1")
    {
        this->m_PortsList = TCN1Ports;

    }else if(BtnName == "TCN1_2")
    {
        this->m_PortsList = TCN2Ports;

    }else if(BtnName == "TCN2_1")
    {
        this->m_PortsList = TCN3Ports;

    }else if(BtnName == "TCN2_2")
    {
        this->m_PortsList = TCN4Ports;

    }else if(BtnName == "RIOM")
    {
        this->m_PortsList = RIOMPorts;

    }else if(BtnName == "TCU")
    {
        this->m_PortsList = TCUPorts;

    }else if(BtnName == "OTHER1")
    {
        this->m_PortsList = OTHER1Ports;

    }else if(BtnName == "OTHER2")
    {
        this->m_PortsList = OTHER2Ports;

    }else if(BtnName == "RCU")
    {
        this->m_PortsList = RCUPorts;

    }


    for(int i = 0; i < buttons.size();i++)
    {
       buttons[i]->setStyleSheet(NButtonUP);
    }
    ((QPushButton *)this->sender())->setStyleSheet(NButtonDOWN);


}
