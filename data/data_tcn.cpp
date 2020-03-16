#include "data_tcn.h"
#include "crrcmvb.h"
Data_TCN::Data_TCN()
{
    for(int i = 0;i<4;i++)
    {
        train[i] = new TrainBean();
    }
}
void Data_TCN::updateData(bool TCN1Master,bool TCN2Master)
{
    if(TCN1Master)
    {
        CrrcMvb::getCrrcMvb()->copyPort(0xfe10,0xe10);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe11,0xe11);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe12,0xe12);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe13,0xe13);

        CrrcMvb::getCrrcMvb()->copyPort(0xfe20,0xe20);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe21,0xe21);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe22,0xe22);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe23,0xe23);

        CrrcMvb::getCrrcMvb()->copyPort(0xfe30,0xe30);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe31,0xe31);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe32,0xe32);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe33,0xe33);

        CrrcMvb::getCrrcMvb()->copyPort(0xfe40,0xe40);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe41,0xe41);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe42,0xe42);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe43,0xe43);
    }else if(TCN2Master)
    {
        CrrcMvb::getCrrcMvb()->copyPort(0xfe10,0xf10);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe11,0xf11);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe12,0xf12);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe13,0xf13);

        CrrcMvb::getCrrcMvb()->copyPort(0xfe20,0xf20);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe21,0xf21);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe22,0xf22);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe23,0xf23);

        CrrcMvb::getCrrcMvb()->copyPort(0xfe30,0xf30);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe31,0xf31);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe32,0xf32);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe33,0xf33);

        CrrcMvb::getCrrcMvb()->copyPort(0xfe40,0xf40);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe41,0xf41);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe42,0xf42);
        CrrcMvb::getCrrcMvb()->copyPort(0xfe43,0xf43);
    }else
    {

    }
    QList<int > t_train1portlist,t_train2portlist,t_train3portlist,t_train4portlist;
    t_train1portlist<<0xfe10<<0xfe11<<0xfe12<<0xfe13;
    t_train2portlist<<0xfe20<<0xfe21<<0xfe22<<0xfe23;
    t_train3portlist<<0xfe30<<0xfe31<<0xfe32<<0xfe33;
    t_train4portlist<<0xfe40<<0xfe41<<0xfe42<<0xfe43;

    QList<QList<int >>t_portlist;
    t_portlist<<t_train1portlist<<t_train2portlist<<t_train3portlist<<t_train4portlist;

    //fill TCN data
    for(int i = 0;i<4;i++)
    {
        //eg  train[i].xxx = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(xx),xx,xx);
    }
}
