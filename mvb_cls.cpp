#include "mvb_cls.h"
#define MUE_APP_PRINT

MUE_RESULT
mue_app_init_device
(
    void    *p_bus_ctrl
)
{
    MUE_RESULT  result;
    BITSET16    sv_device_config;
    WORD16      port_address;
    WORD16      port_address_max;
    BITSET16    pd_port_config;


    /* ----------------------------------------------------------------------
 *      *  Initialise MVB UART Emulation
 *           * ----------------------------------------------------------------------
 *                */
#ifdef MUE_APP_PRINT
    MUE_OSL_PRINTF("- mue_acc_init()\n");
#endif /* #ifdef MUE_APP_PRINT */

#ifndef USER_DEBUG_MODE
    result = mue_acc_init(p_bus_ctrl);
#endif

#ifdef MUE_APP_PRINT
    MUE_OSL_PRINTF("- mue_acc_init()=%d\n", (unsigned int)result);
#endif /* #ifdef MUE_APP_PRINT */


    /* ----------------------------------------------------------------------
 *      *  Cleanup MVB UART Emulation
 *           * ----------------------------------------------------------------------
 *                */
    if (MUE_RESULT_OK == result)
    {
#ifdef MUE_APP_PRINT
        MUE_OSL_PRINTF("- mue_acc_clean_up()\n");
#endif /* #ifdef MUE_APP_PRINT */

#ifndef USER_DEBUG_MODE
        result = mue_acc_clean_up(p_bus_ctrl);
#endif

#ifdef MUE_APP_PRINT
        MUE_OSL_PRINTF("- mue_acc_clean_up()=%d\n", (unsigned int)result);
#endif /* #ifdef MUE_APP_PRINT */

    } /* if (MUE_RESULT_OK == result) */


    /* ----------------------------------------------------------------------
 *      *  Soft reset of MVB Controller (e.g. disconnect from MVB bus)
 *           * ----------------------------------------------------------------------
 *                */
    if (MUE_RESULT_OK == result)
    {
        sv_device_config = (BITSET16)0x0000;

#ifdef MUE_APP_PRINT
        MUE_OSL_PRINTF("- mue_sv_put_device_config(0x%04X)\n", \
            (unsigned int)sv_device_config);
#endif /* #ifdef MUE_APP_PRINT */

#ifndef USER_DEBUG_MODE
        result = mue_sv_put_device_config(p_bus_ctrl, sv_device_config);
#endif
#ifdef MUE_APP_PRINT
        MUE_OSL_PRINTF("- mue_sv_put_device_config(0x%04X)=%d\n", \
            (unsigned int)sv_device_config, (unsigned int)result);
#endif /* #ifdef MUE_APP_PRINT */

    } /* if (MUE_RESULT_OK == result) */


    /* ----------------------------------------------------------------------
 *      *  Clear configuration of all MVB Process Data Ports (i.e. set to SINK)
 *           * ----------------------------------------------------------------------
 *                */
    if (MUE_RESULT_OK == result)
    {
#ifdef MUE_APP_PRINT
        MUE_OSL_PRINTF("- mue_pd_full_put_port_config(0x0000..0x0FFF)\n");
#endif /* #ifdef MUE_APP_PRINT */

#ifndef USER_DEBUG_MODE

        port_address_max = mue_pd_full_port_number_max;
        for (port_address=0; port_address<port_address_max; port_address++)
        {
            pd_port_config = (BITSET16)port_address;
            result =                        \
                mue_pd_full_put_port_config \
                (                           \
                    p_bus_ctrl,             \
                    pd_port_config          \
                );
            if (MUE_RESULT_OK != result)
            {
#ifdef MUE_APP_PRINT
                MUE_OSL_PRINTF                                     \
                    ("- mue_pd_full_put_port_config(0x%04X)=%d\n", \
                    (unsigned int)pd_port_config, (unsigned int)result);
#endif /* #ifdef MUE_APP_PRINT */
                break;
            } /* if (MUE_RESULT_OK != result) */

        } /* for (port_address=0; port_address<port_address_max; ...) */
#endif
    } /* if (MUE_RESULT_OK == result) */


    return(result);

} /* mue_app_init_device */




MUE_RESULT
mue_app_init_port
(
    void        *p_bus_ctrl,
    BITSET16    pd_port_config
)
{
    MUE_RESULT  result;
    WORD16      pd_port_address;
    WORD8       pd_port_data[MUE_PD_FULL_PORT_SIZE_MAX];
                /* ----------------------------------------------------------
 *              *  NOTE:
 *        	*  "pd_port_data" is a buffer of 32 bytes, which
 *              *  is the max. size of a MVB Process Data port.
 *              * ----------------------------------------------------------
 *              */


    /* ----------------------------------------------------------------------
 *      *  Configure MVB Process Data Port
 *           * ----------------------------------------------------------------------
 *                */
#ifdef MUE_APP_PRINT
    MUE_OSL_PRINTF("- mue_pd_full_put_port_config(0x%04X)\n", \
        (unsigned int)pd_port_config);
#endif /* #ifdef MUE_APP_PRINT */
#ifndef USER_DEBUG_MODE

    result =                        \
        mue_pd_full_put_port_config \
        (                           \
            p_bus_ctrl,             \
            pd_port_config          \
        );
#endif
#ifdef MUE_APP_PRINT
    MUE_OSL_PRINTF("- mue_pd_full_put_port_config(0x%04X)=%d\n", \
        (unsigned int)pd_port_config, (unsigned int)result);
#endif /* #ifdef MUE_APP_PRINT */


    /* ----------------------------------------------------------------------
 *      *  Set all bytes of port data to 0x00
 *           * ----------------------------------------------------------------------
 *                */
#ifndef USER_DEBUG_MODE

    if (MUE_RESULT_OK == result)
    {
        pd_port_address = \
            (WORD16)(pd_port_config & mue_pd_full_port_config_la_mask);
        memset((void*)pd_port_data, 0, mue_pd_full_port_size_max);

#ifdef MUE_APP_PRINT
        MUE_OSL_PRINTF("- mue_pd_full_put_port_data(0x%03X)\n", \
            (unsigned int)pd_port_address);
#endif /* #ifdef MUE_APP_PRINT */

        result =                            \
            mue_pd_full_put_port_data       \
            (                               \
                p_bus_ctrl,                 \
                pd_port_address,            \
                mue_pd_full_port_size_max,  \
                pd_port_data                \
            );

#ifdef MUE_APP_PRINT
        MUE_OSL_PRINTF("- mue_pd_full_put_port_data(0x%03X)=%d\n", \
            (unsigned int)pd_port_address, (unsigned int)result);
#endif /* #ifdef MUE_APP_PRINT */

    } /* if (MUE_RESULT_OK == result) */

#endif
    return(result);

} /* mue_app_init_port */

//初始化mvb设备
MUE_RESULT c_mvbSock::MVB_Init()
{
    MUE_RESULT  result;
    static UNSIGNED32   bus_id = 0;
    p_bus_ctrl = (void*)&bus_id;
    result = mue_app_init_device(p_bus_ctrl);
    if(result == MUE_RESULT_OK){
		MVBisOpen = true;
	}else{
		MVBisOpen = false;
	}
    return result;
}

void c_mvbSock::MVB_Set_Rev_Port(UNSIGNED16 port_addr)
{

}

void c_mvbSock::MVB_Set_Put_Port(UNSIGNED16 port_addr)
{

}
//初始化端口
MUE_RESULT c_mvbSock::MVB_init_port(void *p_bus_ctrl,UNSIGNED32 port_dir,UNSIGNED32 port_addr,UNSIGNED32 size)
{
    BITSET16    pd_port_config;
    MUE_RESULT  result = MUE_RESULT_OK;
    pd_port_config = (BITSET16)(port_addr | size | port_dir);
    result = mue_app_init_port (p_bus_ctrl,  pd_port_config );

    if(result != MUE_RESULT_OK){
        return MUE_RESULT_ERROR;
    }
    return MUE_RESULT_OK;
}
//开始mvb工作
MUE_RESULT c_mvbSock::MVB_Start(void *p_ctrl,UNSIGNED16 device_addr)
{
    UNSIGNED16 sv_device_config = 0;
    MUE_RESULT  result = MUE_RESULT_ERROR;
#ifndef USER_DEBUG_MODE

    sv_device_config = (BITSET16)(device_addr | 0x8000 | 0x4000 | 0x1000);
    result = mue_sv_put_device_config(p_ctrl, sv_device_config);
#endif
    if(result == MUE_RESULT_OK){
        isStop = false;
    }else{
        isStop = true;
    }
    return result;
}
//通过mvb端口获取数据
MUE_RESULT c_mvbSock::MVB_Get_Data(WORD16 port_addr,UNSIGNED8 *status,WORD8 *data,UNSIGNED16 *cycle)
{
    MUE_RESULT  result = MUE_RESULT_ERROR;
    UNSIGNED8 pbus = 0;
    void *pbus_ctrl = NULL;
    pbus_ctrl = (void *)&pbus;

    if(isStop == true){
        return MUE_RESULT_ERROR;
    }
#ifndef USER_DEBUG_MODE

    result = mue_pd_full_get_port_data (pbus_ctrl,port_addr,(BOOLEAN1)FALSE,32,  \
                    status, data, cycle);
#endif
    return result;
}
//mvb发送数据
MUE_RESULT c_mvbSock::MVB_Put_Data(WORD16 port_addr,WORD8 *data)
{
    if(isStop == true)
        return MUE_RESULT_ERROR;
    MUE_RESULT  result;
#ifndef USER_DEBUG_MODE
    result =  mue_pd_full_put_port_data(p_bus_ctrl,port_addr, 32, data);
#endif
    return result;
}

void c_mvbSock::_MVBClose()
{
    isStop = true;
}
