#include "ctrlspeedometer.h"
#include "ui_ctrlspeedometer.h"

CtrlSpeedometer::CtrlSpeedometer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlSpeedometer)
{
    ui->setupUi(this);
    m_value = 0;
}

CtrlSpeedometer::~CtrlSpeedometer()
{
    delete ui;
}
void CtrlSpeedometer::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen;
    QFont font;
    QBrush brush;

    painter.setRenderHint(QPainter::Antialiasing,true);

    pen.setColor(QColor(255,255,255));
    pen.setWidth(2);
    painter.setPen(pen);

    font.setFamily("vuArial");
    font.setPixelSize(14);
    font.setWeight(QFont::Normal);
    painter.setFont(font);



    painter.setBrush(Qt::black);
    painter.drawArc(15, 15, 200, 200, -30*16, 240*16);

    //painter.drawEllipse(QPoint(115,115),110,110);
    painter.setBrush(Qt::red);
    pen.setWidth(0);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(115,115),7,7);
    painter.translate(this->width() / 2,this->height() / 2 );




    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawText(QRect(-70,25,30,20),"0");
    //painter.drawText(QRect(-80,5,25,20),"10");
    painter.drawText(QRect(-70,-45,30,20),"300");
    //painter.drawText(QRect(-50,-70,25,20),"30");
    painter.drawText(QRect(-15,-85,30,20),"600");
    //painter.drawText(QRect(25,-70,25,20),"50");
    painter.drawText(QRect(40,-45,30,20),"900");

//    pen.setColor(RED);
//    painter.setPen(pen);
//    painter.drawText(QRect(60,-10,25,20),"70");
    painter.drawText(QRect(35,25,35,20),"1200");

    pen.setColor(YELLOW);
    painter.setPen(pen);
    font.setPixelSize(24);
    painter.setFont(font);
    painter.drawText(QRect(-35,-10,100,25),"");



    painter.rotate(60);
    pen.setWidth(2);
    //pen.setWidth(1);
    for(int i = 0; i <  61; i ++)
    {
//        if(i<35)
//        {
//            pen.setColor(QColor(190,190,190,200));
//        }else
//        {
//            pen.setColor(RED);
//        }
        pen.setColor(QColor(255,255,255));

        painter.setPen(pen);
        if(i%5 == 0)
        {
            painter.drawLine(0,85,0,98);
        }else
        {
            painter.drawLine(0,90,0,98);
        }

        int t_value = m_value>1200?1200:m_value;
        if (i == (t_value/20))
        {//draw speed pointer by speed value
            static const QPointF points[3] = {
                 QPointF(-3, 5),
                 QPointF(3,5),
                 QPointF(0, 80)
               };
            painter.setBrush(QBrush(QColor(255,0,0,128)));
            painter.setPen(QPen(QColor(255,0,0,128), 0));
            painter.drawPolygon(points, 3);
        }
        painter.rotate(4);
    }
    painter.rotate(56);

//    pen.setColor(QColor(140,140,140));
//    font.setPixelSize(45);
//    painter.setPen(pen);
//    painter.setFont(font);
//    QString t_speed;
//    t_speed.sprintf("%02d",m_value);
//    painter.drawText(QRect(-30,45,80,50),t_speed);

//    font.setPixelSize(12);
//    painter.setFont(font);
//    painter.drawText(QRect(30,75,45,20),"km/h");


}
void CtrlSpeedometer::setSpeenometerValue(int value)
{
    m_value = value>1200?1200:value;
    this->update();
}
