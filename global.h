#ifndef GLOBAL_H
#define GLOBAL_H

#define NButtonUP    "font: 16px;color: rgb(192,192,192);background-color: rgb(0, 0, 0);border-top: 2px solid white;border-left: 2px solid white;"
#define NButtonDOWN  "font: 16px;color: rgb(0, 0, 0);background-color: rgb(240, 240, 0);border-bottom: 2px solid white;border-right: 2px solid white;"

#define BYPASSDOWN "font: 16px;color: rgb(255,255,255);background-color: rgb(0, 0, 240);border:1px solid white;"
#define BYPASSUP "font: 16px;color: rgb(255,255,255);background-color: rgb(140, 140, 140);border:1px solid white;"

#define TRAINDOWNL "border:1px solid white;image: url(:/images/images/TrainLogo.png);background-color:black;"
#define TRAINUPL "border:1px solid white;image: url(:/images/images/Cheti.png);background-color:black;"
#define TRAINDOWNR "border:1px solid white;image: url(:/images/images/TrainLogo-reverse.png);background-color:black;"
#define TRAINUPR "border:1px solid white;image: url(:/images/images/Cheti-reverse.png);background-color:black;"

//#define WINDOWS_MODE
#define QT_VERSION_5_6

#define YELLOW     "background-color:rgb(240,240,0);border:1px solid white;"
#define GREEN     "background-color:rgb(0,240,0);border:1px solid white;"
#define DARKBLUE     "background-color:rgb(0,0,240);border:1px solid white;"
#define CYAN     "background-color:rgb(0,240,240);border:1px solid white;"
#define GRAY1     "background-color:rgb(128,128,128);border:1px solid white;"
#define RED     "background-color:rgb(240,0,0);border:1px solid white;"
#define WHITE     "background-color:rgb(248,248,248);border:1px solid white;"
#define GRAY2     "background-color:rgb(192,192,192);border:1px solid white;"
#define BLACK     "background-color:rgb(0,0,0);border:1px solid lightgray;"


#define	FANGXIANGXIANGQIAN	"image: url(:/images/images/xiangqian.png);"
#define	FANGXIANGXIANGHOU	"image: url(:/images/images/xianghou.png);"
#define	FANGXIANGZHONGLI	"image: url(:/images/images/zhongli.png);"
#define	FENXIANGQU	"image: url(:/images/images/fenxiangqu.png);"
#define	PANTO12UP	"image: url(:/images/images/panto12up.png);"
#define	PANTO1UP2DOWN	"image: url(:/images/images/panto1up2down.png);"
#define	PANTO1DOWN2UP	"image: url(:/images/images/panto1down2up.png);"
#define	PANTO1UP2ISO	"image: url(:/images/images/panto1up2iso.png);"
#define	PANTO1ISO2UP	"image: url(:/images/images/panto1iso2up.png);"
#define	PANTO1DOWN2ISO	"image: url(:/images/images/panto1down2iso.png);"
#define	PANTO1ISO2DOWN	"image: url(:/images/images/panto1iso2down.png);"
#define	PANTO12DOWN	"image: url(:/images/images/panto1down2down.png);"
#define	PANTOISO	"image: url(:/images/images/pantoiso.png);"
#define	ZHUDUANBIHE	"image: url(:/images/images/zhuduanbihe.png);"
#define	ZHUDUANDUANKAI	"image: url(:/images/images/zhuduanduankai.png);"
#define	ZHUDUANGELI	"image: url(:/images/images/zhuduangeli.png);"
#define	ZHUDUANJIUXU	"image: url(:/images/images/zhuduanjiuxu.png);"
#define	QIANYIN	"image: url(:/images/images/qianyin.png);"
#define	ZHIDONG	"image: url(:/images/images/zhidong.png);"
#define	CHANGYONGZHIDONGGELI	"image: url(:/images/images/zhidonggeli.png);"
#define	CHANGYONGZHIDONGHUANJIE	"image: url(:/images/images/zhidonghuanjie.png);"
#define	CHANGYONGZHIDONGSHIJIA	"image: url(:/images/images/zhidongshijia.png);"
#define	KONGZHUAN	"image: url(:/images/images/kongzhuan.png);"
#define	HUAXING	"image: url(:/images/images/huaxing.png);"
#define	TINGFANGZHIDONGSHIJIA	"image: url(:/images/images/tingfangshijia.png);"
#define	TINGFANGZHIDONGGELI	"image: url(:/images/images/tingfanggeli.png);"
#define	TINGFANGZHIDONGHUANJIE	"image: url(:/images/images/tingfanghuanjie.png);"
#define	SASHA	"image: url(:/images/images/sasha.png);"
#define	JINJIZHIDONG	"image: url(:/images/images/jinjizhidong.png);"
#define	CHENGFAZHIDONG	"image: url(:/images/images/chengfazhidong.png);"
#define	DINGSUMOSHI	"image: url(:/images/images/dingsumoshi.png);"
#define	JINGTIZHUANGZHIZHENGCHANG	"image: url(:/images/images/jingtizhengchang.png);"
#define	JINGTIZHUANGZHIGELI	"image: url(:/images/images/jingtigeli.png);"
#define	NULLIMAGE	"background-color:rgb(0,0,0);border:1px solid lightgray;"
#define PANTOSETDOWN "image: url(:/images/images/pantoSetDOWN.png);"
#define PANTOSETUP "image: url(:/images/images/pantoSetUP.png);"
#define PANTOSETISO "image: url(:/images/images/pantoSetISO.png);"

#define MAINBUTTONUP  "font:16px;color: rgb(255,255,255);background-color: rgb(0, 0, 0);border:2px solid white;"
#define MAINBUTTONDOWN "font:16px;color: rgb(255,255,255);background-color: yellow;border:2px solid white;"
//#define

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
    uDeviceDataBreaker,
    uDeviceDataSIV,
    uDeviceDataMainConv,
    uDeviceDataNetwork,
    uDeviceDataVersion,
    uDeviceDataRIOM,
    uDeviceDataAirBrake,
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
    uUnityMode,
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
