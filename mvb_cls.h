#ifndef MVB_CLS_H
#define MVB_CLS_H
#include "./include/inc_all.h"
#include <QObject>
class  c_mvbSock
{
public:
    void *p_bus_ctrl;
    bool MVBisOpen;
    bool isStop ;
    MUE_RESULT MVB_Init();
    void MVB_Set_Rev_Port(UNSIGNED16 port_addr);
    void MVB_Set_Put_Port(UNSIGNED16 port_addr);
    MUE_RESULT MVB_init_port(void *p_bus_ctrl,UNSIGNED32 port_dir,UNSIGNED32 port_addr,UNSIGNED32 size);
    MUE_RESULT MVB_Start(void *p_bus_ctrl,UNSIGNED16 device_addr);
    MUE_RESULT MVB_Get_Data(WORD16 port_addr,UNSIGNED8 *status,WORD8 *data,UNSIGNED16 *cycle);
    MUE_RESULT MVB_Put_Data(WORD16 port_addr,WORD8 *data);
    void _MVBClose();
};
class M_MVBData
{
public:
    UNSIGNED16 No;
    bool MVBisOK;
};
#endif // MVB_CLS_H
