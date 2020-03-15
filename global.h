#ifndef GLOBAL_H
#define GLOBAL_H

#define NButtonUP    "font: 16px;color: rgb(192,192,192);background-color: rgb(0, 0, 0);border-top: 2px solid white;border-left: 2px solid white;"
#define NButtonDOWN  "font: 16px;color: rgb(0, 0, 0);background-color: rgb(240, 240, 0);border-bottom: 2px solid white;border-right: 2px solid white;"

//#define WINDOWS_MODE
#define QT_VERSION_5_6

#define YELLOW     "color:rgb(240,240,0);"
#define GREEN     "color:rgb(0,240,0);"
#define DARKBLUE     "color:rgb(0,0,240);"
#define CYAN     "color:rgb(0,240,240);"
#define GRAY1     "color:rgb(128,128,128);"
#define RED     "color:rgb(240,0,0);"
#define WHITE     "color:rgb(248,248,248);"
#define GRAY2     "color:rgb(192,192,192);"
#define BLACK     "color:rgb(0,0,0);"

#define	FANGXIANGXIANGQIAN	"border-image: url(:/images/images/xiangqian.png);"
#define	FANGXIANGXIANGHOU	"border-image: url(:/images/images/xianghou.png);"
#define	FANGXIANGZHONGLI	"border-image: url(:/images/images/zhongli.png);"
#define	FENXIANGQU	"border-image: url(:/images/images/fenxiangqu.png);"
#define	PANTO12UP	"border-image: url(:/images/images/panto12up.png);"
#define	PANTO1UP2DOWN	"border-image: url(:/images/images/panto1up2down.png);"
#define	PANTO1DOWN2UP	"border-image: url(:/images/images/panto1down2up.png);"
#define	PANTO1UP2ISO	"border-image: url(:/images/images/panto1up2iso.png);"
#define	PANTO1ISO2UP	"border-image: url(:/images/images/panto1iso2up.png);"
#define	PANTO1DOWN2ISO	"border-image: url(:/images/images/panto1down2iso.png);"
#define	PANTO1ISO2DOWN	"border-image: url(:/images/images/panto1iso2down.png);"
#define	PANTO12DOWN	"border-image: url(:/images/images/panto1down2down.png);"
#define	PANTOISO	"border-image: url(:/images/images/pantoiso.png);"
#define	ZHUDUANBIHE	"border-image: url(:/images/images/zhuduanbihe.png);"
#define	ZHUDUANDUANKAI	"border-image: url(:/images/images/zhuduanduankai.png);"
#define	ZHUDUANGELI	"border-image: url(:/images/images/zhuduangeli.png);"
#define	ZHUDUANJIUXU	"border-image: url(:/images/images/zhuduanjiuxu.png);"
#define	QIANYIN	"border-image: url(:/images/images/qianyin.png);"
#define	ZHIDONG	"border-image: url(:/images/images/zhidong.png);"
#define	CHANGYONGZHIDONGGELI	"border-image: url(:/images/images/zhidonggeli.png);"
#define	CHANGYONGZHIDONGHUANJIE	"border-image: url(:/images/images/zhidonghuanjie.png);"
#define	CHANGYONGZHIDONGSHIJIA	"border-image: url(:/images/images/zhidongshijia.png);"
#define	KONGZHUAN	"border-image: url(:/images/images/kongzhuan.png);"
#define	HUAXING	"border-image: url(:/images/images/huaxing.png);"
#define	TINGFANGZHIDONGSHIJIA	"border-image: url(:/images/images/tingfangshijia.png);"
#define	TINGFANGZHIDONGHUANJIE	"border-image: url(:/images/images/tingfanghuanjie.png);"
#define	SASHA	"border-image: url(:/images/images/sasha.png);"
#define	JINJIZHIDONG	"border-image: url(:/images/images/jinjizhidong.png);"
#define	CHEFAZHIDONG	"border-image: url(:/images/images/chengfazhidong.png);"
#define	DINGSUMOSHI	"border-image: url(:/images/images/dingsumoshi.png);"
#define	JINGTIZHUANGZHIZHENGCHANG	"border-image: url(:/images/images/jingtizhengchang.png);"
#define	JINGTIZHUANGZHIGELI	"border-image: url(:/images/images/jingtigeli.png);"


#include <stdlib.h>

#ifndef WINDOWS_MODE

#endif

enum pagePosition
{
    uTop = 0,
    uMiddle,
    uBottom,
    uHuge,
    //按照导航区的种类，设置多种界面模式。所有模式来源于“牵引”模式下的导航按钮
    uMiddleTraction,//牵引模式
    uMiddleBrake,//制动模式
    uMiddleMainData,//主要数据
    uMiddleSetting,//机车设置
    uMiddleCondition,//运行条件
    uMiddleDeviceData,//设备数据
    uMiddleMain,//维护测试
    uMiddleFault,//故障查询
    uMiddleUnite,//合屏模式
};
enum pageIndex
{
    uNULL = 0,
    uVehicleRunStatePage,
    uHeader,
    uNavigator,
    //主要数据
    uMainData_TrainOutline,
    uMainData_DriverOutline,
    uMainData_TracBrakeOutline,
    //机车设置
    uSettng_Bypass,
    uSettng_Panto,
    uSettng_Distance,
    uSettng_TrainCode,
    uSettng_Lubrication,
    uSettng_Separation,
    uSettng_HangMode,
    uSettng_Others,
    //运行条件
    uCondition_PantoUp,
    uCondition_Breaker,
    uCondition_Traction,
    uCondition_Brake,
    //设备数据
    uDeviceData_breaker,
    uDeviceData_ACU,
    uDeviceData_MainConv,
    uDeviceData_Online,
    uDeviceData_Version,
    uDeviceData_IO,
    uDeviceData_AirBrake,
    //维护测试
    uMain_Simulate,
    uMain_AssistantDevice,
    uMain_380,
    uMain_Light,
    uMain_Lubrication,
    uMain_Panto,
    uMain_Separation,
    uMain_Wheel,
    uMain_Datetime,
    //故障查询
    uFault_Current,
    uFault_History,
    uFault_Download,

    //合屏模式
    uUniteMode,
    //制动模式
    uBrakeMode
};
enum keyboardIndex{
    key_NULL = 0,
    key_1,
    key_2,
    key_3,
    key_4,
    key_5,
    key_6,
    key_7,
    key_8,
    key_9,
    key_0,
    key_F1,
    key_F2,
    key_F3,
    key_F4,
    key_F5,
    key_F6,
    key_C,
    key_Left,
    key_Right,
    key_Up,
    key_Down,
    key_Enter,
    key_Power,
    key_Flag,
    key_i,
    key_File,
    key_Set,
    key_Brightness,
    key_Contrast,
    key_Dir,
    key_Spear1,
    key_Spear2,
};
#define _LOG qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << __FILE__ << __LINE__

#endif // GLOBAL_H
