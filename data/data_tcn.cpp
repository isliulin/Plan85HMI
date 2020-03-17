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
    //对分时标志位做判断
    switch (CrrcMvb::getCrrcMvb()->getUnsignedChar(0xfe12,0))
    {
    case 1:
        CrrcMvb::getCrrcMvb()->copyPort(0xf112,0xfe12);//对tcn1-4分别copy数据
        CrrcMvb::getCrrcMvb()->copyPort(0xf122,0xfe22);
        CrrcMvb::getCrrcMvb()->copyPort(0xf132,0xfe32);
        CrrcMvb::getCrrcMvb()->copyPort(0xf142,0xfe42);
        break;
    case 2:
        CrrcMvb::getCrrcMvb()->copyPort(0xf212,0xfe12);//对tcn1-4分别copy数据
        CrrcMvb::getCrrcMvb()->copyPort(0xf222,0xfe22);
        CrrcMvb::getCrrcMvb()->copyPort(0xf232,0xfe32);
        CrrcMvb::getCrrcMvb()->copyPort(0xf242,0xfe42);
        break;
    case 3:
        CrrcMvb::getCrrcMvb()->copyPort(0xf312,0xfe12);//对tcn1-4分别copy数据
        CrrcMvb::getCrrcMvb()->copyPort(0xf322,0xfe22);
        CrrcMvb::getCrrcMvb()->copyPort(0xf332,0xfe32);
        CrrcMvb::getCrrcMvb()->copyPort(0xf342,0xfe42);
        break;
    case 4:
        CrrcMvb::getCrrcMvb()->copyPort(0xf412,0xfe12);//对tcn1-4分别copy数据
        CrrcMvb::getCrrcMvb()->copyPort(0xf422,0xfe22);
        CrrcMvb::getCrrcMvb()->copyPort(0xf432,0xfe32);
        CrrcMvb::getCrrcMvb()->copyPort(0xf442,0xfe42);
        break;
    case 5:
        CrrcMvb::getCrrcMvb()->copyPort(0xf512,0xfe12);//对tcn1-4分别copy数据
        CrrcMvb::getCrrcMvb()->copyPort(0xf522,0xfe22);
        CrrcMvb::getCrrcMvb()->copyPort(0xf532,0xfe32);
        CrrcMvb::getCrrcMvb()->copyPort(0xf542,0xfe42);
        break;
    case 6:
        CrrcMvb::getCrrcMvb()->copyPort(0xf612,0xfe12);//对tcn1-4分别copy数据
        CrrcMvb::getCrrcMvb()->copyPort(0xf622,0xfe22);
        CrrcMvb::getCrrcMvb()->copyPort(0xf632,0xfe32);
        CrrcMvb::getCrrcMvb()->copyPort(0xf642,0xfe42);
        break;
    default:
        // clear??
        break;

    }

    QList<int > t_train1portlist,t_train2portlist,t_train3portlist,t_train4portlist;
    t_train1portlist<<0xfe10<<0xfe11<<0xf112<<0xf212<<0xf312<<0xf412<<0xf512<<0xf612<<0xfe13;
    t_train2portlist<<0xfe20<<0xfe21<<0xf122<<0xf222<<0xf322<<0xf422<<0xf522<<0xf622<<0xfe23;
    t_train3portlist<<0xfe30<<0xfe31<<0xf132<<0xf232<<0xf332<<0xf432<<0xf532<<0xf632<<0xfe33;
    t_train4portlist<<0xfe40<<0xfe41<<0xf142<<0xf242<<0xf342<<0xf442<<0xf542<<0xf642<<0xfe43;

    QList<QList<int >>t_portlist;
    t_portlist<<t_train1portlist<<t_train2portlist<<t_train3portlist<<t_train4portlist;

    //fill TCN data
    for(int i = 0;i<4;i++)
    {
        // tcn1
        train[i]->B_CMD_ANSC1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),11,0);//过分相预告/恢复
        train[i]->B_CMD_ANSC2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),11,1);//过分相强迫
        train[i]->B_ELEC_AIR_CUT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),11,2);//空电联合切除

        train[i]->B_CMD_KEY = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,0);//主控机车
        train[i]->B_CMD_PANTO_R = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,1);//升弓
        train[i]->B_CMD_PANTO_D = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,2);//降弓
        train[i]->B_CMD_QFM_C = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,3);//主断合
        train[i]->B_CMD_QFM_K = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,4);//主断分
        train[i]->B_CMD_CPR_RUN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,5);//压缩机运行
        train[i]->B_CMD_PUMP = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,6);//强泵
        train[i]->B_CMD_MNSC = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),12,7);//手动过分相
        train[i]->B_CMD_BP_RESET = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,0);//复位按钮
        train[i]->B_CMD_EMGE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,1);//紧急按钮
        train[i]->B_CMD_SAND_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,2);//撒砂请求
        train[i]->B_CMD_DIR_N = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,3);//方向零位
        train[i]->B_CMD_DIR_f = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,4);//主控车方向1
        train[i]->B_CMD_DIR_B = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,5);//主控车方向2
        train[i]->B_TCN_DIR_BIT0 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,6);//主控车与WTB主方向BIT0
        train[i]->B_TCN_DIR_BIT1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),13,7);//主控车与WTB主方向BIT1
        train[i]->B_CMD_MSCT_T = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,0);//牵引
        train[i]->B_CMD_MSCT_B = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,1);//电制
        train[i]->B_CMD_MSCT_N = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,2);//主司控器手柄零位
        train[i]->B_STATE_TRACTION = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,3);//牵引设定
        train[i]->B_STATE_BRAKE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,4);//电制设定
        train[i]->B_CMD_PK_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,5);//停放施加
        train[i]->B_CMD_PK_OFF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,6);//停放缓解
        train[i]->B_CMD_CONS = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),14,7);//定速
        train[i]->B_FLL_START = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),15,0);//轮缘润滑
        train[i]->B_CMD_BCU_STATE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),15,1);//后备空气制动激活
        train[i]->B_PARK_BRKI_CONF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),15,2);//停放制动隔离确认
        train[i]->B_ABH_EMG = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),15,3);//大闸紧急制动施加
        train[i]->B_CMD_DDU_RESET = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),15,4);//隔离解锁
        train[i]->B_CMD_PANTO1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),15,5);//受电弓1选择
        train[i]->B_CMD_PANTO2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),15,6);//受电弓2选择
        train[i]->B_CMD_TC1_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),16,0);//车1 轴1隔离请求
        train[i]->B_CMD_TC1_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),16,1);//车1 轴2隔离请求
        train[i]->B_CMD_TC1_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),16,2);//车1 轴3隔离请求
        train[i]->B_CMD_TC1_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),16,3);//车1 轴4隔离请求
        train[i]->B_CMD_TC1_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),16,6);//车1 辅逆1隔离请求
        train[i]->B_CMD_TC1_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),16,7);//车1 辅逆2隔离请求
        train[i]->B_CMD_TC1_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),17,0);//车1 电制动隔离请求
        train[i]->B_CMD_TC1_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),17,1);//车1 受电弓1隔离请求
        train[i]->B_CMD_TC1_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),17,3);//车1 轮缘润滑隔离请求
        train[i]->B_CMD_TC1_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),17,4);//车1 轮缘润滑隔离恢复请求
        train[i]->B_CMD_TC1_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),17,5);//车1 电制动隔离取消请求
        train[i]->B_CMD_TC1_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),17,6);//车1 受电弓1隔离取消请求
        train[i]->B_CMD_TC1_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),18,0);//车1 轴1隔离取消请求
        train[i]->B_CMD_TC1_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),18,1);//车1 轴2隔离取消请求
        train[i]->B_CMD_TC1_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),18,2);//车1 轴3隔离取消请求
        train[i]->B_CMD_TC1_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),18,3);//车1 轴4隔离取消请求
        train[i]->B_CMD_TC1_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),18,6);//车1 辅逆1隔离取消请求
        train[i]->B_CMD_TC1_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),18,7);//车1 辅逆2隔离取消请求
        train[i]->B_CMD_TC2_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),19,0);//车2 轴1隔离请求
        train[i]->B_CMD_TC2_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),19,1);//车2 轴2隔离请求
        train[i]->B_CMD_TC2_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),19,2);//车2 轴3隔离请求
        train[i]->B_CMD_TC2_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),19,3);//车2 轴4隔离请求
        train[i]->B_CMD_TC2_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),19,6);//车2辅逆1隔离请求
        train[i]->B_CMD_TC2_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),19,7);//车2辅逆2隔离请求
        train[i]->B_CMD_TC2_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),20,0);//车2 电制动隔离请求
        train[i]->B_CMD_TC2_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),20,1);//车2 受电弓1隔离请求
        train[i]->B_CMD_TC2_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),20,3);//车2 轮缘润滑隔离请求
        train[i]->B_CMD_TC2_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),20,4);//车2 轮缘润滑隔离恢复请求
        train[i]->B_CMD_TC2_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),20,5);//车2 电制动隔离取消请求
        train[i]->B_CMD_TC2_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),20,6);//车2 受电弓1隔离取消请求
        train[i]->B_CMD_TC2_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),21,0);//车2 轴1隔离取消请求
        train[i]->B_CMD_TC2_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),21,1);//车2 轴2隔离取消请求
        train[i]->B_CMD_TC2_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),21,2);//车2 轴3隔离取消请求
        train[i]->B_CMD_TC2_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),21,3);//车2 轴4隔离取消请求
        train[i]->B_CMD_TC2_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),21,6);//车2辅逆1隔离取消请求
        train[i]->B_CMD_TC2_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),21,7);//车2辅逆2隔离取消请求
        train[i]->B_CMD_TC3_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),22,0);//车3 轴1隔离请求
        train[i]->B_CMD_TC3_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),22,1);//车3 轴2隔离请求
        train[i]->B_CMD_TC3_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),22,2);//车3轴3隔离请求
        train[i]->B_CMD_TC3_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),22,3);//车3 轴4隔离请求
        train[i]->B_CMD_TC3_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),22,6);//车3辅逆1隔离请求
        train[i]->B_CMD_TC3_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),22,7);//车3辅逆2隔离请求
        train[i]->B_CMD_TC3_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),23,0);//车3 电制动隔离请求
        train[i]->B_CMD_TC3_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),23,1);//车3 受电弓1隔离请求
        train[i]->B_CMD_TC3_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),23,3);//车3 轮缘润滑隔离请求
        train[i]->B_CMD_TC3_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),23,4);//车3 轮缘润滑隔离恢复请求
        train[i]->B_CMD_TC3_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),23,5);//车3 电制动隔离取消请求
        train[i]->B_CMD_TC3_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),23,6);//车3 受电弓1隔离取消请求
        train[i]->B_CMD_TC3_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),24,0);//车3 轴1隔离取消请求
        train[i]->B_CMD_TC3_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),24,1);//车3 轴2隔离取消请求
        train[i]->B_CMD_TC3_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),24,2);//车3 轴3隔离取消请求
        train[i]->B_CMD_TC3_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),24,3);//车3 轴4隔离取消请求
        train[i]->B_CMD_TC3_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),24,6);//车3辅逆1隔离取消请求
        train[i]->B_CMD_TC3_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),24,7);//车3辅逆2隔离取消请求
        train[i]->B_CMD_TC4_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),25,0);//车4 轴1隔离请求
        train[i]->B_CMD_TC4_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),25,1);//车4 轴2隔离请求
        train[i]->B_CMD_TC4_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),25,2);//车4 轴3隔离请求
        train[i]->B_CMD_TC4_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),25,3);//车1 轴4隔离请求
        train[i]->B_CMD_TC4_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),25,6);//车4辅逆1隔离请求
        train[i]->B_CMD_TC4_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),25,7);//车4辅逆2隔离请求
        train[i]->B_CMD_TC4_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),26,0);//车4 电制动隔离请求
        train[i]->B_CMD_TC4_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),26,1);//车4 受电弓1隔离请求
        train[i]->B_CMD_TC4_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),26,3);//车4 轮缘润滑隔离请求
        train[i]->B_CMD_TC4_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),26,4);//车4 轮缘润滑隔离恢复请求
        train[i]->B_CMD_TC4_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),26,5);//车4 电制动隔离取消请求
        train[i]->B_CMD_TC4_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),26,6);//车4 受电弓1隔离取消请求
        train[i]->B_CMD_TC4_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),27,0);//车4 轴1隔离取消请求
        train[i]->B_CMD_TC4_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),27,1);//车4 轴2隔离取消请求
        train[i]->B_CMD_TC4_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),27,2);//车4 轴3隔离取消请求
        train[i]->B_CMD_TC4_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),27,3);//车4 轴4隔离取消请求
        train[i]->B_CMD_TC4_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),27,6);//车4辅逆1隔离取消请求
        train[i]->B_CMD_TC4_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),27,7);//车4辅逆2隔离取消请求
        train[i]->B_CMD_LEADING_CAB_CHANGE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),28,0);//主控车停车换端
        train[i]->B_CMD_FREIGHT_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),28,1);//定压模式500kPa
        train[i]->B_CMD_PSG_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),28,2);//定压模式600kPa
        train[i]->B_STATE_BRAKEPRESS_SWITCH2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),28,3);//制动缸压力>40kPa
        train[i]->B_STATE_BRAKEPRESS_SWITCH1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(0),28,4);//制动缸压力>90kPa
        train[i]->N_DATE_TIME = CrrcMvb::getCrrcMvb()->getUnsignedInt32(t_portlist.at(i).at(0),0);//日期时间
        train[i]->N_CMD_MSCT_PERCENT = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(0),4);//牵引/制动力设定值百分比
        train[i]->N_ACTUAL_SPEED = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(0),6);//实际速度
        train[i]->N_LOAD_VALUE = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(0),8);//牵引吨位
        train[i]->N_BAT_VOLT = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(0),29);//蓄电池电压,小数点后1位，将数值乘以10
        train[i]->N_CMD_CS_VALUE = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(0),10);//目标速度、定速值

        //tcn2
        train[i]->N_MSCT_PERSENT_SET = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(1),0);//牵引/制动力设定值百分比
        train[i]->N_MSCT_PERSENT_ACT = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(1),2);//牵引/制动力实际值百分比
        train[i]->N_LOCO_NO = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(1),4);//本车机车号
        train[i]->N_LOCO_TYPE = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(1),6);//机车识别号
        train[i]->B_STATE_CAB_ACT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),8,0);//电钥匙激活
        train[i]->B_STATE_PANTO_RG = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),8,1);//受电弓1升弓
        train[i]->B_STATE_PANTO_RD = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),8,2);//受电弓1升起
        train[i]->B_STATE_PANTO_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),8,3);//受电弓1隔离
        train[i]->B_STATE_QFM_FAULT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),9,0);//主断故障
        train[i]->B_STATE_QFM_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),9,1);//主断断开且不允许闭合
        train[i]->B_STATE_QFM_K = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),9,2);//主断断开且允许闭合
        train[i]->B_STATE_QFM_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),9,3);//主断闭合
        train[i]->B_STATE_QS_HV1_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),9,4);//高压隔离开关1闭合
        train[i]->B_STATE_QS_HV1_OFF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),9,5);//高压隔离开关1断开
        train[i]->B_STATE_EMG_BRK_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,0);//紧急制动施加
        train[i]->B_STATE_EMG_BRK_I = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,1);//紧急制动隔离
        train[i]->B_STATE_PENALTY_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,2);//惩罚制动施加
        train[i]->B_STATE_PARK_BRK_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,3);//停放制动施加
        train[i]->B_STATE_PARK_BRK_REL = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,4);//停放制动缓解
        train[i]->B_STATE_PARK_BRK_I = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,5);//停放制动隔离
        train[i]->B_STATE_FLL_ISO_STATE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,6);//轮缘润滑隔离状态
        train[i]->B_STATE_EBRK_ISO_STATE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),10,7);//电制动隔离状态
        train[i]->B_STATE_AIR_BRK1_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,0);//空气制动1施加
        train[i]->B_STATE_AIR_BRK1_I = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,1);//空气制动1隔离
        train[i]->B_STATE_AIR_BRK2_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,2);//空气制动2施加
        train[i]->B_STATE_AIR_BRK2_I = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,3);//空气制动2隔离
        train[i]->B_BCU_Undefined  = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,4);//BCU未定义
        train[i]->B_BCU_UL = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,5);//BCU切除
        train[i]->B_BCU_LEAD_IN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,6);//BCU本机投入
        train[i]->B_BCU_TRAIL_IN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),11,7);//BCU补机
        train[i]->B_LOCO_A = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,0);//A节
        train[i]->B_LOCO_B = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,1);//B节
        train[i]->B_GW1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,2);//首选网关
        train[i]->B_GW2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,3);//备选网关
        train[i]->B_CMD_NO_TRACTION = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,4);//全局牵引封锁请求
        train[i]->B_CMD_NO_ELE_BRK = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,5);//全局电制封锁请求
        train[i]->B_CMD_NSC_FAULT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,6);//过分相装置故障
        train[i]->B_STATE_PARK_BRKI_CONF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),12,7);//停放制动隔离确认请求
        train[i]->B_STATE_CAB_CHANGE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),13,0);//本车停车换端激活
        train[i]->B_STATE_AXLE1_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),13,1);//轴1隔离状态
        train[i]->B_STATE_AXLE2_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),13,2);//轴2隔离状态
        train[i]->B_STATE_AXLE3_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),13,3);//轴3隔离状态
        train[i]->B_STATE_AXLE4_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),13,4);//轴4隔离状态
        train[i]->B_STATE_AUX1_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),13,5);//辅逆1隔离状态
        train[i]->B_STATE_AUX2_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(1),13,6);//辅逆2隔离状态

        //tcn3 分时6份
       train[i]->N_B1A1CoolTemp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(2),4);//1架1轴冷却水进水口温度
       train[i]->N_B1A2CoolTemp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(3),4);//1架2轴冷却水进水口温度
       train[i]->N_B2A1CoolTemp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(4),4);//2架1轴冷却水进水口温度
       train[i]->N_B2A2CoolTemp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(5),4);//2架2轴冷却水进水口温度
       train[i]->N_CONVOilTemp1_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(6),4);//变压器油温1
       train[i]->N_CONVOilTemp2_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(7),4);//变压器油温2
       train[i]->N_SXX1Voltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(2),6);//四象限1直流母线电压
       train[i]->N_SXX2Voltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(3),6);//四象限2直流母线电压
       train[i]->N_SXX3Voltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(4),6);//四象限3直流母线电压
       train[i]->N_SXX4Voltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(5),6);//四象限4直流母线电压
       train[i]->N_Voltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(6),6);//原边电压
       train[i]->N_Current_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(7),6);//原边电流
       train[i]->N_A1SetForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(2),8);//轴1设定牵引力/制动力
       train[i]->N_A2SetForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(3),8);//轴2设定牵引力/制动力
       train[i]->N_A3SetForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(4),8);//轴3设定牵引力/制动力
       train[i]->N_A4SetForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(5),8);//轴4设定牵引力/制动力
       train[i]->N_A1RealForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(2),10);//轴1实际牵引力/制动力
       train[i]->N_A2RealForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(3),10);//轴2实际牵引力/制动力
       train[i]->N_A3RealForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(4),10);//轴3实际牵引力/制动力
       train[i]->N_A4RealForce_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(5),10);//轴4实际牵引力/制动力
       train[i]->N_SXX1InputVoltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(6),10);//四象限1输入电压
       train[i]->N_SXX2InputVoltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(7),10);//四象限2输入电压
       train[i]->N_Motor1Temp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(2),12);//牵引电机1温度
       train[i]->N_Motor2Temp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(3),12);//牵引电机2温度
       train[i]->N_Motor3Temp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(4),12);//牵引电机3温度
       train[i]->N_Motor4Temp_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(5),12);//牵引电机4温度
       train[i]->N_SXX3InputVoltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(6),12);//四象限3输入电压
       train[i]->N_SXX4InputVoltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(7),12);//四象限4输入电压
       train[i]->N_ACU1Voltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(2),14);//辅助1电压
       train[i]->N_ACU2Voltage_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(3),14);//辅助2电压
       train[i]->N_ACU1Freq_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(4),14);//辅助1频率
       train[i]->N_ACU2Freq_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(5),14);//辅助2频率
       train[i]->N_SXX1InputCurrent_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(6),14);//四象限1输入电流
       train[i]->N_SXX2InputCurrent_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(7),14);//四象限2输入电流
       train[i]->N_B1A1CoolPressure_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(2),16);//1架1轴冷却水进水口压力
       train[i]->N_B1A2CoolPressure_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(3),16);//1架2轴冷却水进水口压力
       train[i]->N_B2A1CoolPressure_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(4),16);//2架1轴冷却水进水口压力
       train[i]->N_B2A2CoolPressure_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(5),16);//2架2轴冷却水进水口压力
       train[i]->N_SXX3InputCurrent_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(6),16);//四象限3输入电流
       train[i]->N_SXX4InputCurrent_U8 = CrrcMvb::getCrrcMvb()->getUnsignedInt(t_portlist.at(i).at(7),16);//四象限4输入电流
       train[i]->N_PgMcbBlockByte1_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(2),2);//受电弓封锁字节1
       train[i]->N_PgMcbBlockByte2_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(3),2);//受电弓封锁字节2
       train[i]->N_PgMcbBlockByte3_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(4),2);//受电弓封锁字节3
       train[i]->N_BreakMcbBlockByte1_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(5),2);//主断封锁字节1
       train[i]->N_BreakMcbBlockByte2_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(6),2);//主断封锁字节2
       train[i]->N_BreakMcbBlockByte3_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(7),2);//主断封锁字节3
       train[i]->N_TracDBBlockByte1_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(2),3);//牵引封锁字节1
       train[i]->N_TracDBBlockByte2_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(3),3);//牵引封锁字节2
       train[i]->N_TracDBBlockByte3_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(4),3);//牵引封锁字节3
       train[i]->N_EBBlockByte1_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(5),3);//电制封锁字节1
       train[i]->N_EBBlockByte2_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(6),3);//电制封锁字节2
       train[i]->N_EBBlockByte3_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(7),3);//电制封锁字节3
       train[i]->N_Motor1Current_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(2),18);//牵引电机1电流
       train[i]->N_Motor2Current_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(3),18);//牵引电机2电流
       train[i]->N_Motor3Current_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(4),18);//牵引电机3电流
       train[i]->N_Motor4Current_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(i).at(5),18);//牵引电机4电流

       //tcn4
       train[i]->B_STATE_MA1_CP = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),2,0);//总风压力开关1
       train[i]->B_FREIGHT_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),2,1);//风缸压力500/货车投入
       train[i]->B_PSG_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),2,2);//风缸压力600/客车投入
       train[i]->B_STATE_C_COVER_SM1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),2,3);//机械间顶盖1状态
       train[i]->B_STATE_C_COVER_SM2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),2,4);//机械间顶盖2状态
       train[i]->B_QFM_OFF_PROTECT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),2,7);//故障断主断保护
       train[i]->B_CMD_MA1_FD = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,0);//制动缸压力开关
       train[i]->B_CMD_MA2_FD = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,1);//制动缸压力开关2状态
       train[i]->B_CMD_TC1_QA_HV_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,2);//车1 高压隔离开关开（5s高电平）
       train[i]->B_CMD_TC1_QA_HV_OFF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,3);//车1 高压隔离开关关（5s高电平）
       train[i]->B_CMD_TC2_QA_HV_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,4);//车2 高压隔离开关开（5s高电平）
       train[i]->B_CMD_TC2_QA_HV_OFF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,5);//车2 高压隔离开关关（5s高电平）
       train[i]->B_CMD_TC3_QA_HV_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,6);//车3 高压隔离开关开（5s高电平）
       train[i]->B_CMD_TC3_QA_HV_OFF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),3,7);//车3 高压隔离开关关（5s高电平）
       train[i]->B_CMD_TC4_QA_HV_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,0);//车4 高压隔离开关开（5s高电平）
       train[i]->B_CMD_TC4_QA_HV_OFF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,1);//车4 高压隔离开关关（5s高电平）
       train[i]->B_STATE_YV_PAN_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,2);//受电弓隔离阀
       train[i]->B_STATE_RB_EMG = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,3);//紧急隔离塞门
       train[i]->B_STATE_RB_IS_CF1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,4);//制动缸1隔离塞门
       train[i]->B_STATE_RB_IS_CF2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,5);//制动缸2隔离塞门
       train[i]->B_STATE_RB_IS_FS = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,6);//停放隔离塞门
       train[i]->B_STATE_Z_QUAI_T = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),4,7);//库用开关测试位
       train[i]->B_STATE_Z_QUAI_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,0);//库用开关动车位
       train[i]->B_STATE_QS_GHV = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,1);//接地开关
       train[i]->B_STATE_C_VT_MT1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,2);//牵引风机1接触器状态
       train[i]->B_STATE_C_VT_MT2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,3);//牵引风机2接触器状态
       train[i]->B_STATE_C_VT_SM1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,4);//机械间风机1接触器状态
       train[i]->B_STATE_C_VT_SM2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,5);//机械间风机2接触器状态
       train[i]->B_STATE_C_VT_BM1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,6);//冷却塔风机1接触器状态
       train[i]->B_STATE_C_VT_BM2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),5,7);//冷却塔风机2接触器状态
       train[i]->B_STATE_KA_PC1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,0);//变流柜1预充电接触器1
       train[i]->B_STATE_KA_PC2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,1);//变流柜1预充电接触器2
       train[i]->B_STATE_KA_PC3 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,2);//变流柜2预充电接触器1
       train[i]->B_STATE_KA_PC4 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,3);//变流柜2预充电接触器2
       train[i]->B_STATE_KA_WORK1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,4);//变流柜1预工作接触器1
       train[i]->B_STATE_KA_WORK2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,5);//变流柜1预工作接触器2
       train[i]->B_STATE_KA_WORK3 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,6);//变流柜2预工作接触器1
       train[i]->B_STATE_KA_WORK4 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),6,7);//变流柜2预工作接触器2
       train[i]->B_STATE_C_BAU1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,0);//辅变1工作接触器
       train[i]->B_STATE_C_BAU2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,1);//辅变2工作接触器
       train[i]->B_STATE_DJ_QUAI = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,2);//辅入库断路器状态
       train[i]->B_STATE_WORK_KM_QUAI = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,3);//辅入库工作接触器状态
       train[i]->B_STATE_KM_QUAI = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,4);//辅入库接触器状态
       train[i]->B_STATE_Q_PP_QUAI = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,5);//辅入库相序检测
       train[i]->B_STATE_C_SEC = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,6);//降级接触器
       train[i]->B_STATE_KM_CPR_AUX = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),7,7);//辅助压缩机接触器状态
       train[i]->B_STATE_DJ_PE1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,0);//水泵1断路器状态
       train[i]->B_STATE_DJ_PE2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,1);//水泵2断路器状态
       train[i]->B_STATE_DJ_PE3 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,2);//水泵3断路器状态
       train[i]->B_STATE_DJ_PE4 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,3);//水泵4断路器状态
       train[i]->B_STATE_DJ_PH1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,4);//油泵1断路器状态
       train[i]->B_STATE_DJ_PH2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,5);//油泵2断路器状态
       train[i]->B_STATE_Q_TH_VT_MT1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,6);//牵引风机1断路器状态
       train[i]->B_STATE_Q_TH_VT_MT2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),8,7);//牵引风机2断路器状态
       train[i]->B_STATE_Q_TH_VT_BM1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,0);//冷却塔风机1断路器状态
       train[i]->B_STATE_Q_TH_VT_BM2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,1);//冷却塔风机2断路器状态
       train[i]->B_STATE_DJ_VT_SM1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,2);//机械间风机1断路器状态
       train[i]->B_STATE_DJ_VT_SM2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,3);//机械间风机2断路器状态
       train[i]->B_STATE_Q_REC = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,4);//压缩机低温保护继电器状态
       train[i]->B_STATE_Q_TH_CPR = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,5);//压缩机断路器状态
       train[i]->B_STATE_C1_CPR = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,6);//压缩机接触器1状态
       train[i]->B_STATE_C2_CPR = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),9,7);//压缩机接触器2状态
       train[i]->B_STATE_C3_CPR = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,0);//压缩机接触器3状态
       train[i]->B_CMD_WINTER_MODE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,1);//普通模式/冬季模式
       train[i]->B_CMD_SUMMER_MODE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,2);//夏天模式
       train[i]->B_CMD_T_CHAR_H = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,3);//牵引特性设定：恒转矩
       train[i]->B_CMD_CAB_CHANGE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,4);//自动换端
       train[i]->B_CMD_SAND_CUT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,5);//自动撒砂切除
       train[i]->B_FLL_TEST_START = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,6);//轮缘润滑测试开始
       train[i]->B_FLL_TEST_CANCEL = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),10,7);//轮缘润滑测试取消
       train[i]->B_CMD_SIM_ON = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,0);//仿真开关
       train[i]->B_STATE_PENALTY_BRK_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,1);//惩罚制动请求
       train[i]->B_STATE_QFM_OFF = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,2);//主断断开
       train[i]->B_STATE_PANTO_DN = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,3);//受电弓降下
       train[i]->B_STATE_ABH_MIN  = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,4);//大闸Minimum
       train[i]->B_STATE_ABH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,5);//大闸Service_Zone
       train[i]->B_STATE_ABH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,6);//大闸Full_Service
       train[i]->B_CMD_FIRE_ALARM_CONFIRM = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),11,7);//火灾报警确认
       train[i]->B_CMD_TRACK_BLOCK = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),12,0);//切除牵引
       train[i]->B_STATE_T_CHAR = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),12,1);//牵引特性反馈
       train[i]->B_STATE_H_HT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),12,2);//高压隔离开关状态
       train[i]->B_CMD_T_CHAR_Z = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),12,3);//牵引特性设定：准恒速
       train[i]->B_STATE_CPR_AUX_SWITCH1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),12,4);//辅助风缸压力开关
       train[i]->B_BRAKE_BACK = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,0);//后备制动激活
       train[i]->B_NO_FIRE_VALVE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,1);//无火塞门状态
       train[i]->B_BUCH_RELAY = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,2);//布赫继电器状态（报警）
       train[i]->B_STATE_SAFE_LOOP = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,3);//安全回路状态
       train[i]->B_PANTO_B_LOOP = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,4);//受电弓后控制环状态
       train[i]->B_PANTO_F_LOOP = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,5);//受电弓前控制环状态
       train[i]->B_MCB_B_LOOP = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,6);//主断路器后控制环状态
       train[i]->B_MCB_F_LOOP = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),14,7);//主断路器前控制环状态
       train[i]->B_SAND_ISO_VALVE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),15,0);//撒砂隔离阀状态
       train[i]->B_FIRE_MA_DETECT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),15,1);//防火压力检测
       train[i]->B_PHASE_DETECT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),15,2);//输入库相序检测：错误
       train[i]->B_TH_CPR = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),15,3);//压缩机断路器：断开
       train[i]->B_CPR_AUX_ISO_VALVE = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),15,4);//辅助风缸隔离塞门状态
       train[i]->B_CMD_TC1_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,0);//它车1 整流器1隔离请求
       train[i]->B_CMD_TC1_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,1);//它车1 整流器2隔离请求
       train[i]->B_CMD_TC1_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,2);//它车1 整流器3隔离请求
       train[i]->B_CMD_TC1_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,3);//它车1 整流器4隔离请求
       train[i]->B_CMD_TC1_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,4);//它车1 整流器1隔离取消请求
       train[i]->B_CMD_TC1_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,5);//它车1 整流器2隔离取消请求
       train[i]->B_CMD_TC1_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,6);//它车1 整流器3隔离取消请求
       train[i]->B_CMD_TC1_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),16,7);//它车1 整流器4隔离取消请求
       train[i]->B_CMD_TC2_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,0);//它车2 整流器1隔离请求
       train[i]->B_CMD_TC2_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,1);//它车2 整流器2隔离请求
       train[i]->B_CMD_TC2_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,2);//它车2 整流器3隔离请求
       train[i]->B_CMD_TC2_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,3);//它车2 整流器4隔离请求
       train[i]->B_CMD_TC2_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,4);//它车2 整流器1隔离取消请求
       train[i]->B_CMD_TC2_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,5);//它车2 整流器2隔离取消请求
       train[i]->B_CMD_TC2_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,6);//它车2 整流器3隔离取消请求
       train[i]->B_CMD_TC2_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),17,7);//它车2 整流器4隔离取消请求
       train[i]->B_CMD_TC3_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,0);//它车3 整流器1隔离请求
       train[i]->B_CMD_TC3_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,1);//它车3 整流器2隔离请求
       train[i]->B_CMD_TC3_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,2);//它车3 整流器3隔离请求
       train[i]->B_CMD_TC3_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,3);//它车3 整流器4隔离请求
       train[i]->B_CMD_TC3_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,4);//它车3 整流器1隔离取消请求
       train[i]->B_CMD_TC3_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,5);//它车3 整流器2隔离取消请求
       train[i]->B_CMD_TC3_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,6);//它车3 整流器3隔离取消请求
       train[i]->B_CMD_TC3_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),18,7);//它车3 整流器4隔离取消请求
       train[i]->B_CMD_TC4_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,0);//它车4 整流器1隔离请求
       train[i]->B_CMD_TC4_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,1);//它车4 整流器2隔离请求
       train[i]->B_CMD_TC4_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,2);//它车4 整流器3隔离请求
       train[i]->B_CMD_TC4_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,3);//它车4 整流器4隔离请求
       train[i]->B_CMD_TC4_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,4);//它车4 整流器1隔离取消请求
       train[i]->B_CMD_TC4_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,5);//它车4 整流器2隔离取消请求
       train[i]->B_CMD_TC4_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,6);//它车4 整流器3隔离取消请求
       train[i]->B_CMD_TC4_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),19,7);//它车4 整流器4隔离取消请求
       train[i]->B_STATE_4Q1_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,0);//整流器1隔离状态
       train[i]->B_STATE_4Q2_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,1);//整流器2隔离状态
       train[i]->B_STATE_4Q3_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,2);//整流器3隔离状态
       train[i]->B_STATE_4Q4_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,3);//整流器4隔离状态
       train[i]->B_STATE_4Q1_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,4);//整流器1手动隔离状态
       train[i]->B_STATE_4Q2_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,5);//整流器2手动隔离状态
       train[i]->B_STATE_4Q3_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,6);//整流器3手动隔离状态
       train[i]->B_STATE_4Q4_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),20,7);//整流器4手动隔离状态
       train[i]->B_STATE_AXLE1_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,0);//轴1手动隔离状态
       train[i]->B_STATE_AXLE2_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,1);//轴2手动隔离状态
       train[i]->B_STATE_AXLE3_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,2);//轴3手动隔离状态
       train[i]->B_STATE_AXLE4_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,3);//轴4手动隔离状态
       train[i]->B_STATE_AUX1_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,4);//辅逆1手动隔离状态
       train[i]->B_STATE_AUX2_ISO_M = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,5);//辅逆2手动隔离状态
       train[i]->B_CMD_TC1_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,6);//它车1 无人警惕隔离请求
       train[i]->B_CMD_TC2_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),21,7);//它车2 无人警惕隔离请求
       train[i]->B_CMD_TC3_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,0);//它车3 无人警惕隔离请求
       train[i]->B_CMD_TC4_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,1);//它车4 无人警惕隔离请求
       train[i]->B_CMD_TC1_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,2);//它车1 无人警惕隔离取消请求
       train[i]->B_CMD_TC2_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,3);//它车2 无人警惕隔离取消请求
       train[i]->B_CMD_TC3_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,4);//它车3 无人警惕隔离取消请求
       train[i]->B_CMD_TC4_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,5);//它车4 无人警惕隔离取消请求
       train[i]->B_CMD_TC1_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,6);//它车1 压缩机隔离请求
       train[i]->B_CMD_TC2_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),22,7);//它车2 压缩机隔离请求
       train[i]->B_CMD_TC3_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,0);//它车3 压缩机隔离请求
       train[i]->B_CMD_TC4_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,1);//它车4 压缩机隔离请求
       train[i]->B_CMD_TC1_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,2);//它车1 压缩机隔离取消请求
       train[i]->B_CMD_TC2_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,3);//它车2 压缩机隔离取消请求
       train[i]->B_CMD_TC3_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,4);//它车3 压缩机隔离取消请求
       train[i]->B_CMD_TC4_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,5);//它车4 压缩机隔离取消请求
       train[i]->B_STATE_DAMAN_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,6);//无人警惕隔离状态
       train[i]->B_STATE_CPR_ISO = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),23,7);//压缩机隔离状态
       train[i]->B_STATE_ELEC_AIR_CUT = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),24,0);//空电联合切除状态
       train[i]->B_NSC_DISTANCE1 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),24,1);//常规线路过分相：170m模式
       train[i]->B_NSC_DISTANCE2 = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),24,2);//货运专线过分相：265m模式
       train[i]->B_Trailer_mode = CrrcMvb::getCrrcMvb()->getBool(t_portlist.at(i).at(8),24,3);//挂车模式

    }
}
