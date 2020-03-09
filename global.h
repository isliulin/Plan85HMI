#ifndef GLOBAL_H
#define GLOBAL_H

#define NButtonUP    "font: 20px, \"微软雅黑\";color: white;background-color: rgb(0, 100, 255);border-top: 2px solid white;border-left: 2px solid white;"
#define NButtonDOWN  "font: 20px, \"微软雅黑\";color: white;background-color: rgb(0, 0, 255);border-top: 2px solid  rgb(0, 0, 255);border-left: 2px solid  rgb(0, 0, 255);border-bottom: 2px solid white;border-right: 2px solid white;"

//#define WINDOWS_MODE
#define QT_VERSION_5_6


#include <stdlib.h>

#ifndef WINDOWS_MODE

#endif

enum pagePosition
{
    uTop = 0,
    uMiddle,
    uBottom,
    uHuge,
    uLargeMiddle
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
