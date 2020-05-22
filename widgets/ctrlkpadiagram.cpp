#include "ctrlkpadiagram.h"
#include "ui_ctrlkpadiagram.h"

CtrlKpaDiagram::CtrlKpaDiagram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlKpaDiagram)
{
    ui->setupUi(this);
    m_value = 0;
}

CtrlKpaDiagram::~CtrlKpaDiagram()
{
    delete ui;
}
void CtrlKpaDiagram::paintEvent(QPaintEvent *e)
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
    painter.drawArc(5, 5, 240, 240, -60*16, 300*16);

    //painter.drawEllipse(QPoint(115,115),110,110);
    painter.setBrush(Qt::red);
    pen.setWidth(0);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(125,125),7,7);
    painter.translate(this->width() / 2,this->height() / 2 );




    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawText(QRect(-50,75,30,20),"0");
    painter.drawText(QRect(-100,10,30,20),"200");
    painter.drawText(QRect(-80,-70,30,20),"400");
    painter.drawText(QRect(-15,-105,30,20),"600");
    painter.drawText(QRect(50,-70,30,20),"800");
    painter.drawText(QRect(60,10,35,20),"1000");

//    pen.setColor(RED);
//    painter.setPen(pen);
//    painter.drawText(QRect(60,-10,25,20),"70");
    painter.drawText(QRect(30,75,35,20),"1200");

    pen.setColor(YELLOW);
    painter.setPen(pen);
    font.setPixelSize(24);
    painter.setFont(font);
    painter.drawText(QRect(-35,-10,100,25),"");



    painter.rotate(30);
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
            painter.drawLine(0,105,0,118);
        }else
        {
            painter.drawLine(0,110,0,118);
        }

        int t_value = m_value>1200?1200:m_value;
        if (i == (t_value/20))
        {//draw speed pointer by speed value
            static const QPointF points[3] = {
                 QPointF(-3, 5),
                 QPointF(3,5),
                 QPointF(0, 100)
               };
            painter.setBrush(QBrush(QColor(255,255,255,128)));
            painter.setPen(QPen(QColor(255,255,255,128), 0));
            painter.drawPolygon(points, 3);
        }
        painter.rotate(5);
    }
    painter.rotate(25);


    font.setPixelSize(18);
    painter.setFont(font);
    painter.drawText(QRect(-20,75,45,20),"kPa");


}
void CtrlKpaDiagram::setSpeenometerValue(int value)
{
    m_value = value>1200?1200:value;
    this->update();
}
