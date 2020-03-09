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
    uVehicleRunStatePage = 0,
    uHeader,
    uNavigator

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
