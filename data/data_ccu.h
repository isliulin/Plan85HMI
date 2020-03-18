#ifndef DATA_CCU_H
#define DATA_CCU_H

class Data_CCU
{
public:
    Data_CCU();
    void updateData();
    //DDU-MPU
    //0x300
    bool B_TC1_BOGIE1_ISO_RQ,B_TC1_4Q1_ISO_RQ,B_TC1_4Q2_ISO_RQ,B_TC1_AXLE1_ISO_RQ,B_TC1_AXLE2_ISO_RQ,B_TC1_AXLE3_ISO_RQ,
    B_TC1_AUX1_ISO_RQ,B_TC1_BOGIE2_ISO_RQ,B_TC1_4Q3_ISO_RQ,B_TC1_4Q4_ISO_RQ,B_TC1_AXLE4_ISO_RQ,B_TC1_AUX2_ISO_RQ,B_TC1_QA_HV_ON,
    B_TC1_QA_HV_OFF,B_TC1_BOGIE1_ISO_REL_RQ,B_TC1_4Q1_ISO_REL_RQ,B_TC1_4Q2_ISO_REL_RQ,B_TC1_AXLE1_ISO_REL_RQ,B_TC1_AXLE2_ISO_REL_RQ,
    B_TC1_AXLE3_ISO_REL_RQ,B_TC1_AUX1_ISO_REL_RQ,B_TC1_BOGIE2_ISO_REL_RQ,B_TC1_4Q3_ISO_REL_RQ,B_TC1_4Q4_ISO_REL_RQ,B_TC1_AXLE4_ISO_REL_RQ,
    B_TC1_AUX2_ISO_REL_RQ,B_TC1_DAMAN_ISO_RQ,B_TC1_EBRK_ISO_RQ,B_TC1_CPR_ISO_RQ,B_TC1_FLL_ISO_RQ,B_TC1_PANTO_ISO_RQ,B_TC1_FAULT_RESET,
    B_TC1_DAMAN_ISO_REL_RQ,B_TC1_EBRK_ISO_REL_RQ,B_TC1_CPR_ISO_REL_RQ,B_TC1_FLL_ISO_REL_RQ,B_TC1_PANTO_ISO_REL_RQ

    ,B_TC2_BOGIE1_ISO_RQ,B_TC2_4Q1_ISO_RQ,B_TC2_4Q2_ISO_RQ,B_TC2_AXLE1_ISO_RQ,B_TC2_AXLE2_ISO_RQ,B_TC2_AXLE3_ISO_RQ,
    B_TC2_AUX1_ISO_RQ,B_TC2_BOGIE2_ISO_RQ,B_TC2_4Q3_ISO_RQ,B_TC2_4Q4_ISO_RQ,B_TC2_AXLE4_ISO_RQ,B_TC2_AUX2_ISO_RQ,B_TC2_QA_HV_ON,
    B_TC2_QA_HV_OFF,B_TC2_BOGIE1_ISO_REL_RQ,B_TC2_4Q1_ISO_REL_RQ,B_TC2_4Q2_ISO_REL_RQ,B_TC2_AXLE1_ISO_REL_RQ,B_TC2_AXLE2_ISO_REL_RQ,
    B_TC2_AXLE3_ISO_REL_RQ,B_TC2_AUX1_ISO_REL_RQ,B_TC2_BOGIE2_ISO_REL_RQ,B_TC2_4Q3_ISO_REL_RQ,B_TC2_4Q4_ISO_REL_RQ,B_TC2_AXLE4_ISO_REL_RQ,
    B_TC2_AUX2_ISO_REL_RQ,B_TC2_DAMAN_ISO_RQ,B_TC2_EBRK_ISO_RQ,B_TC2_CPR_ISO_RQ,B_TC2_FLL_ISO_RQ,B_TC2_PANTO_ISO_RQ,B_TC2_FAULT_RESET,
    B_TC2_DAMAN_ISO_REL_RQ,B_TC2_EBRK_ISO_REL_RQ,B_TC2_CPR_ISO_REL_RQ,B_TC2_FLL_ISO_REL_RQ,B_TC2_PANTO_ISO_REL_RQ

    ,B_TC3_BOGIE1_ISO_RQ,B_TC3_4Q1_ISO_RQ,B_TC3_4Q2_ISO_RQ,B_TC3_AXLE1_ISO_RQ,B_TC3_AXLE2_ISO_RQ,B_TC3_AXLE3_ISO_RQ,
    B_TC3_AUX1_ISO_RQ,B_TC3_BOGIE2_ISO_RQ,B_TC3_4Q3_ISO_RQ,B_TC3_4Q4_ISO_RQ,B_TC3_AXLE4_ISO_RQ,B_TC3_AUX2_ISO_RQ,B_TC3_QA_HV_ON,
    B_TC3_QA_HV_OFF,B_TC3_BOGIE1_ISO_REL_RQ,B_TC3_4Q1_ISO_REL_RQ,B_TC3_4Q2_ISO_REL_RQ,B_TC3_AXLE1_ISO_REL_RQ,B_TC3_AXLE2_ISO_REL_RQ,
    B_TC3_AXLE3_ISO_REL_RQ,B_TC3_AUX1_ISO_REL_RQ,B_TC3_BOGIE2_ISO_REL_RQ,B_TC3_4Q3_ISO_REL_RQ,B_TC3_4Q4_ISO_REL_RQ,B_TC3_AXLE4_ISO_REL_RQ,
    B_TC3_AUX2_ISO_REL_RQ,B_TC3_DAMAN_ISO_RQ,B_TC3_EBRK_ISO_RQ,B_TC3_CPR_ISO_RQ,B_TC3_FLL_ISO_RQ,B_TC3_PANTO_ISO_RQ,B_TC3_FAULT_RESET,
    B_TC3_DAMAN_ISO_REL_RQ,B_TC3_EBRK_ISO_REL_RQ,B_TC3_CPR_ISO_REL_RQ,B_TC3_FLL_ISO_REL_RQ,B_TC3_PANTO_ISO_REL_RQ

    ,B_TC4_BOGIE1_ISO_RQ,B_TC4_4Q1_ISO_RQ,B_TC4_4Q2_ISO_RQ,B_TC4_AXLE1_ISO_RQ,B_TC4_AXLE2_ISO_RQ,B_TC4_AXLE3_ISO_RQ,
    B_TC4_AUX1_ISO_RQ,B_TC4_BOGIE2_ISO_RQ,B_TC4_4Q3_ISO_RQ,B_TC4_4Q4_ISO_RQ,B_TC4_AXLE4_ISO_RQ,B_TC4_AUX2_ISO_RQ,B_TC4_QA_HV_ON,
    B_TC4_QA_HV_OFF,B_TC4_BOGIE1_ISO_REL_RQ,B_TC4_4Q1_ISO_REL_RQ,B_TC4_4Q2_ISO_REL_RQ,B_TC4_AXLE1_ISO_REL_RQ,B_TC4_AXLE2_ISO_REL_RQ,
    B_TC4_AXLE3_ISO_REL_RQ,B_TC4_AUX1_ISO_REL_RQ,B_TC4_BOGIE2_ISO_REL_RQ,B_TC4_4Q3_ISO_REL_RQ,B_TC4_4Q4_ISO_REL_RQ,B_TC4_AXLE4_ISO_REL_RQ,
    B_TC4_AUX2_ISO_REL_RQ,B_TC4_DAMAN_ISO_RQ,B_TC4_EBRK_ISO_RQ,B_TC4_CPR_ISO_RQ,B_TC4_FLL_ISO_RQ,B_TC4_PANTO_ISO_RQ,B_TC4_FAULT_RESET,
    B_TC4_DAMAN_ISO_REL_RQ,B_TC4_EBRK_ISO_REL_RQ,B_TC4_CPR_ISO_REL_RQ,B_TC4_FLL_ISO_REL_RQ,B_TC4_PANTO_ISO_REL_RQ

    ,B_LAMP_TEST,B_FLL_TEST_START,B_FLL_TEST_CANCEL,B_DEPOT_380_ACT,B_DEPOT_380_DEACT,B_CPR_TEST,B_VT_BM1_ST,B_VT_BM2_ST,B_SIM_ON
    ,B_NORMAL_MODE,B_SUMMER_MODE,B_AXLE_23TON,B_AXLE_25TON,B_VT_MT1_ST,B_VT_MT2_ST,B_VT_SM1_ST,B_VT_SM2_ST,B_P300CHECK0,B_P300CHECK1;

    unsigned short N_SIM_SPEED,N_SIM_LINE_VOLT;
    unsigned char N_DDU_LIFE;
    //0x301
    unsigned short N_YEAR;
    unsigned char N_MONTH,N_DAY,N_HOUR,N_MINUTE,N_SECOND;

    bool B_FLL_SET,B_TIME_SET,B_BRK_CHAR_Z,B_WHEEL_DIA_SET,B_TRAC_CHAR_H,B_TRAC_CHAR_Z,B_BRK_CHAR_H,B_LOCO_NO_SET,
    B_PARTNER_ID_SET,B_SEQUENCE_TEST,B_AIR_ELE_SET_LOCK,B_AIR_ELE_SET_UNION,B_SAND_CUT,B_DIS_SET,B_MILEAGE_RESET,B_SAND_CUT_REL;

    unsigned short N_SPEED_SET,N_WHEEL_DIA,N_LOAD,N_FLL_DIS,N_FLL_TIME;

    unsigned char N_DIS_VALUE,N_DDU_VX,N_DDU_VY,N_DDU_VZ;

    bool B_FIR_ALARM_CONFIRM,B_LOAD_SET,B_DAMAN_TEST,B_ANSC_TEST,B_MSCT_BOXING_SET,B_P301CHECK0,B_P301CHECK1;
    //0x302
    bool B_NSC_DISTANCE1,B_NSC_DISTANCE2,B_NSC_SET,B_DOUBLE_PG,B_TRAILER_MODE,B_DADMAN_SET,B_P302CHECK0,B_P302CHECK1;

    unsigned char N_DADMAN_TIMESAPCE,N_DADMAN_TIMEALARM,N_TRAILER_MODE_SPEED,N_DOUBLE_PG_SPEED;

    unsigned int N_LOCO_ID,N_PARTNER_ID;
    //MPU-DDU
    //0x710
    unsigned short M1_D1_N_BAT_VOLT,M1_D1_N_TEBE_EFFORT,M1_D1_N_ACTUAL_SPEED,M1_D1_N_SET_SPEED,M1_D1_N_MSCT_GRD,M1_D1_N_WHEEL_DIA;

    unsigned char M1_D1_N_BAT_TMP,M1_D1_N_RULOCO_NO,M1_D1_N_UIC_ADDR,M1_D1_N_MCB_ON_COUNTER,M1_D1_N_MPU_LIFE;

    bool M1_D1_B_NSC_START,M1_D1_B_NSC_END,M1_D1_B_STATE_CAB_ACTIVE,M1_D1_B_SANDING,M1_D1_B_RACING,M1_D1_B_SLIP,M1_D1_B_SPEED_CTL,
    M1_D1_B_SIM_MODE,M1_D1_B_NORMAL_MODE,M1_D1_B_SUMMER_MODE,M1_D1_B_AXLE_23TON,M1_D1_B_AXLE_25TON,M1_D1_B_DEPOT_SIM,M1_D1_B_DEPOT_MOVE,
    M1_D1_B_LEAD_CUTIN,M1_D1_B_LEAD_CUTOUT,M1_D1_B_TRAIL_CUTOUT,M1_D1_B_SAND_CUT,M1_D1_B_STATE_FORWARD,M1_D1_B_STATE_BACK,M1_D1_B_STATE_NEUTRAL,
    M1_D1_B_AXLE2_MOVE,M1_D1_B_STATE_T_CHAR,M1_D1_B_DADMAN_ALARM,M1_D1_B_HEAT,M1_D1_B_SEQ_TEST,M1_D1_B_CAB_CHANGE,M1_D1_B_BRK_CHAR_SET,M1_D1_B_AIR_ELE,
    M1_D1_B_CUR_MPU1,M1_D1_B_CUR_MPU2,M1_D1_B_MPU1_ONLINE,M1_D1_B_MPU2_ONLINE,M1_D1_B_ACU1_ONLINE,M1_D1_B_ACU2_ONLINE,M1_D1_B_TCU1_ONLINE,M1_D1_B_TCU2_ONLINE,
    M1_D1_B_BCU_ONLINE,M1_D1_B_DDU_ONLINE,M1_D1_B_TCU3_ONLINE,M1_D1_B_RIOM1_GW_ONLINE,M1_D1_B_RIOM2_GW_ONLINE,M1_D1_B_TCU4_ONLINE,M1_D1_B_UIC_GW1_ONLINE,
    M1_D1_B_UIC_GW2_ONLINE,M1_D1_B_6A_ONLINE,M1_D1_B_RIOM1_DI1_ONLINE,M1_D1_B_RIOM1_DI2_ONLINE,M1_D1_B_RIOM1_DO1_ONLINE,M1_D1_B_RIOM1_AX1_ONLINE,M1_D1_B_ERM_ONLINE,
    M1_D1_B_GW1_MAS,M1_D1_B_GW2_MAS,M1_D1_B_Batt_Low,M1_D1_B_CP_650kp,M1_D1_B_NSC_DISTANCE1,M1_D1_B_NSC_DISTANCE2,M1_D1_B_DOUBLE_PG,M1_D1_B_TRAILER_MODE,
    M1_D1_B_RIOM2_DI1_ONLINE,M1_D1_B_RIOM2_DI2_ONLINE,M1_D1_B_RIOM2_DI3_ONLINE,M1_D1_B_RIOM2_DI4_ONLINE,M1_D1_B_RIOM2_DI5_ONLINE,M1_D1_B_RIOM2_DO1_ONLINE,
    M1_D1_B_RIOM2_DO2_ONLINE,M1_D1_B_RIOM2_DO3_ONLINE,M1_D1_B_RIOM2_DO4_ONLINE,M1_D1_B_GW3_ONLINE,M1_D1_B_P710CHECK0,M1_D1_B_P710CHECK1;
    //0x711
    unsigned short M1_D1_N_LOAD,M1_D1_N_FLL_DIS,M1_D1_N_FLL_SECONDS,M1_D1_N_YEAR;

    unsigned char M1_D1_N_MONTH,M1_D1_N_DATE,M1_D1_N_HOUR,M1_D1_N_MINUTE,M1_D1_N_SECOND,M1_D1_N_DEVICE_NO,M1_D1_N_VERSION_A,
    M1_D1_N_VERSION_X,M1_D1_N_VERSION_Y,M1_D1_N_VERSION_Z,M1_D1_N_DADMAN_TIME,M1_D1_N_FLL_TIME;

    unsigned int M1_D1_N_TRIP_COUNTER,M1_D1_N_TOTAL_DISTANCE;

    bool M1_D1_B_P711CHECK0,M1_D1_B_P711CHECK1;
    //0x712
    unsigned char M1_D1_N_DADMAN_TIMESPACE,M1_D1_N_DADMAN_ALARMTIME;

    unsigned int M1_D1_N_PARTNER_ID;

   unsigned short M1_D1_ATO_N_MSCT_GRD;

   bool M1_D1_ATO_N_MODE_ATO,M1_D1_N_MESG_FLAG,M1_D1_B_MESG_BYTE1_BIT0,M1_D1_B_MESG_BYTE1_BIT1,M1_D1_B_MESG_BYTE1_BIT2,M1_D1_B_MESG_BYTE1_BIT3,
   M1_D1_B_MESG_BYTE1_BIT4,M1_D1_B_MESG_BYTE1_BIT5,M1_D1_B_MESG_BYTE1_BIT6,M1_D1_B_MESG_BYTE1_BIT7,M1_D1_B_MESG_BYTE2_BIT0,M1_D1_B_MESG_BYTE2_BIT1,
   M1_D1_B_MESG_BYTE2_BIT2,M1_D1_B_MESG_BYTE2_BIT3,M1_D1_B_MESG_BYTE2_BIT4,M1_D1_B_MESG_BYTE2_BIT5,M1_D1_B_MESG_BYTE2_BIT6,M1_D1_B_MESG_BYTE2_BIT7,
   M1_D1_B_P712CHECK0,M1_D1_B_P712CHECK1;

};

#endif // DATA_CCU_H
