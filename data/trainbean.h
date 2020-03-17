#ifndef TRAINBEAN_H
#define TRAINBEAN_H


class TrainBean
{
public:
    TrainBean();
    bool	B_CMD_ANSC1;
    bool	B_CMD_ANSC2;
    bool	B_ELEC_AIR_CUT;
    bool	B_CMD_KEY;
    bool	B_CMD_PANTO_R;
    bool	B_CMD_PANTO_D;
    bool	B_CMD_QFM_C;
    bool	B_CMD_QFM_K;
    bool	B_CMD_CPR_RUN;
    bool	B_CMD_PUMP;
    bool	B_CMD_MNSC;
    bool	B_CMD_BP_RESET;
    bool	B_CMD_EMGE;
    bool	B_CMD_SAND_RQ;
    bool	B_CMD_DIR_N;
    bool	B_CMD_DIR_f;
    bool	B_CMD_DIR_B;
    bool	B_TCN_DIR_BIT0;
    bool	B_TCN_DIR_BIT1;
    bool	B_CMD_MSCT_T;
    bool	B_CMD_MSCT_B;
    bool	B_CMD_MSCT_N;
    bool	B_STATE_TRACTION;
    bool	B_STATE_BRAKE;
    bool	B_CMD_PK_ON;
    bool	B_CMD_PK_OFF;
    bool	B_CMD_CONS;
    bool	B_FLL_START;
    bool	B_CMD_BCU_STATE;
    bool	B_PARK_BRKI_CONF;
    bool	B_ABH_EMG;
    bool	B_CMD_DDU_RESET;
    bool	B_CMD_PANTO1;
    bool	B_CMD_PANTO2;
    bool	B_CMD_TC1_AXLE1_ISO_RQ;
    bool	B_CMD_TC1_AXLE2_ISO_RQ;
    bool	B_CMD_TC1_AXLE3_ISO_RQ;
    bool	B_CMD_TC1_AXLE4_ISO_RQ;
    bool	B_CMD_TC1_AUX1_ISO_RQ;
    bool	B_CMD_TC1_AUX2_ISO_RQ;
    bool	B_CMD_TC1_EBRK_ISO_RQ;
    bool	B_CMD_TC1_PANTO_ISO_RQ;
    bool	B_CMD_TC1_FLL_ISO_RQ;
    bool	B_CMD_TC1_FLL_ISO_REL_RQ;
    bool	B_CMD_TC1_EBRK_ISO_REL_RQ;
    bool	B_CMD_TC1_PANTO_ISO_REL_RQ;
    bool	B_CMD_TC1_AXLE1_ISO_REL_RQ;
    bool	B_CMD_TC1_AXLE2_ISO_REL_RQ;
    bool	B_CMD_TC1_AXLE3_ISO_REL_RQ;
    bool	B_CMD_TC1_AXLE4_ISO_REL_RQ;
    bool	B_CMD_TC1_AUX1_ISO_REL_RQ;
    bool	B_CMD_TC1_AUX2_ISO_REL_RQ;
    bool	B_CMD_TC2_AXLE1_ISO_RQ;
    bool	B_CMD_TC2_AXLE2_ISO_RQ;
    bool	B_CMD_TC2_AXLE3_ISO_RQ;
    bool	B_CMD_TC2_AXLE4_ISO_RQ;
    bool	B_CMD_TC2_AUX1_ISO_RQ;
    bool	B_CMD_TC2_AUX2_ISO_RQ;
    bool	B_CMD_TC2_EBRK_ISO_RQ;
    bool	B_CMD_TC2_PANTO_ISO_RQ;
    bool	B_CMD_TC2_FLL_ISO_RQ;
    bool	B_CMD_TC2_FLL_ISO_REL_RQ;
    bool	B_CMD_TC2_EBRK_ISO_REL_RQ;
    bool	B_CMD_TC2_PANTO_ISO_REL_RQ;
    bool	B_CMD_TC2_AXLE1_ISO_REL_RQ;
    bool	B_CMD_TC2_AXLE2_ISO_REL_RQ;
    bool	B_CMD_TC2_AXLE3_ISO_REL_RQ;
    bool	B_CMD_TC2_AXLE4_ISO_REL_RQ;
    bool	B_CMD_TC2_AUX1_ISO_REL_RQ;
    bool	B_CMD_TC2_AUX2_ISO_REL_RQ;
    bool	B_CMD_TC3_AXLE1_ISO_RQ;
    bool	B_CMD_TC3_AXLE2_ISO_RQ;
    bool	B_CMD_TC3_AXLE3_ISO_RQ;
    bool	B_CMD_TC3_AXLE4_ISO_RQ;
    bool	B_CMD_TC3_AUX1_ISO_RQ;
    bool	B_CMD_TC3_AUX2_ISO_RQ;
    bool	B_CMD_TC3_EBRK_ISO_RQ;
    bool	B_CMD_TC3_PANTO_ISO_RQ;
    bool	B_CMD_TC3_FLL_ISO_RQ;
    bool	B_CMD_TC3_FLL_ISO_REL_RQ;
    bool	B_CMD_TC3_EBRK_ISO_REL_RQ;
    bool	B_CMD_TC3_PANTO_ISO_REL_RQ;
    bool	B_CMD_TC3_AXLE1_ISO_REL_RQ;
    bool	B_CMD_TC3_AXLE2_ISO_REL_RQ;
    bool	B_CMD_TC3_AXLE3_ISO_REL_RQ;
    bool	B_CMD_TC3_AXLE4_ISO_REL_RQ;
    bool	B_CMD_TC3_AUX1_ISO_REL_RQ;
    bool	B_CMD_TC3_AUX2_ISO_REL_RQ;
    bool	B_CMD_TC4_AXLE1_ISO_RQ;
    bool	B_CMD_TC4_AXLE2_ISO_RQ;
    bool	B_CMD_TC4_AXLE3_ISO_RQ;
    bool	B_CMD_TC4_AXLE4_ISO_RQ;
    bool	B_CMD_TC4_AUX1_ISO_RQ;
    bool	B_CMD_TC4_AUX2_ISO_RQ;
    bool	B_CMD_TC4_EBRK_ISO_RQ;
    bool	B_CMD_TC4_PANTO_ISO_RQ;
    bool	B_CMD_TC4_FLL_ISO_RQ;
    bool	B_CMD_TC4_FLL_ISO_REL_RQ;
    bool	B_CMD_TC4_EBRK_ISO_REL_RQ;
    bool	B_CMD_TC4_PANTO_ISO_REL_RQ;
    bool	B_CMD_TC4_AXLE1_ISO_REL_RQ;
    bool	B_CMD_TC4_AXLE2_ISO_REL_RQ;
    bool	B_CMD_TC4_AXLE3_ISO_REL_RQ;
    bool	B_CMD_TC4_AXLE4_ISO_REL_RQ;
    bool	B_CMD_TC4_AUX1_ISO_REL_RQ;
    bool	B_CMD_TC4_AUX2_ISO_REL_RQ;
    bool	B_CMD_LEADING_CAB_CHANGE;
    bool	B_CMD_FREIGHT_CUT_IN;
    bool	B_CMD_PSG_CUT_IN;
    bool	B_STATE_BRAKEPRESS_SWITCH2;
    bool	B_STATE_BRAKEPRESS_SWITCH1;
    int     N_DATE_TIME;
    unsigned short int 	N_CMD_MSCT_PERCENT;
    unsigned short int 	N_ACTUAL_SPEED;
    unsigned short int 	N_LOAD_VALUE;
    unsigned short int	N_BAT_VOLT;
    unsigned char 	N_CMD_CS_VALUE;

    unsigned short int 	N_MSCT_PERSENT_SET;
    unsigned short int	N_MSCT_PERSENT_ACT;
    unsigned short int	N_LOCO_NO;
    unsigned short int	N_LOCO_TYPE;
    bool	B_STATE_CAB_ACT
    ;bool	B_STATE_PANTO_RG
    ;bool	B_STATE_PANTO_RD
    ;bool	B_STATE_PANTO_ISO
    ;bool	B_STATE_QFM_FAULT
    ;bool	B_STATE_QFM_ISO
    ;bool	B_STATE_QFM_K
    ;bool	B_STATE_QFM_ON
    ;bool	B_STATE_QS_HV1_ON
    ;bool	B_STATE_QS_HV1_OFF
    ;bool	B_STATE_EMG_BRK_ON
    ;bool	B_STATE_EMG_BRK_I
    ;bool	B_STATE_PENALTY_ON
    ;bool	B_STATE_PARK_BRK_ON
    ;bool	B_STATE_PARK_BRK_REL
    ;bool	B_STATE_PARK_BRK_I
    ;bool	B_STATE_FLL_ISO_STATE
    ;bool	B_STATE_EBRK_ISO_STATE
    ;bool	B_STATE_AIR_BRK1_ON
    ;bool	B_STATE_AIR_BRK1_I
    ;bool	B_STATE_AIR_BRK2_ON
    ;bool	B_STATE_AIR_BRK2_I
    ;bool	B_BCU_Undefined
    ;bool	B_BCU_UL
    ;bool	B_BCU_LEAD_IN
    ;bool	B_BCU_TRAIL_IN
    ;bool	B_LOCO_A
    ;bool	B_LOCO_B
    ;bool	B_GW1
    ;bool	B_GW2
    ;bool	B_CMD_NO_TRACTION
    ;bool	B_CMD_NO_ELE_BRK
    ;bool	B_CMD_NSC_FAULT
    ;bool	B_STATE_PARK_BRKI_CONF
    ;bool	B_STATE_CAB_CHANGE
    ;bool	B_STATE_AXLE1_ISO
    ;bool	B_STATE_AXLE2_ISO
    ;bool	B_STATE_AXLE3_ISO
    ;bool	B_STATE_AXLE4_ISO
    ;bool	B_STATE_AUX1_ISO
    ;bool	B_STATE_AUX2_ISO;

    unsigned short int	N_B1A1CoolTemp_U8;
    unsigned short int	N_B1A2CoolTemp_U8;
    unsigned short int	N_B2A1CoolTemp_U8;
    unsigned short int	N_B2A2CoolTemp_U8;
    unsigned short int	N_CONVOilTemp1_U8;
    unsigned short int	N_CONVOilTemp2_U8;
    unsigned short int	N_SXX1Voltage_U8;
    unsigned short int	N_SXX2Voltage_U8;
    unsigned short int	N_SXX3Voltage_U8;
    unsigned short int	N_SXX4Voltage_U8;
    unsigned short int	N_Voltage_U8;
    unsigned short int	N_Current_U8;
    unsigned short int	N_A1SetForce_U8;
    unsigned short int	N_A2SetForce_U8;
    unsigned short int	N_A3SetForce_U8;
    unsigned short int	N_A4SetForce_U8;
    unsigned short int	N_A1RealForce_U8;
    unsigned short int	N_A2RealForce_U8;
    unsigned short int	N_A3RealForce_U8;
    unsigned short int	N_A4RealForce_U8;
    unsigned short int	N_SXX1InputVoltage_U8;
    unsigned short int	N_SXX2InputVoltage_U8;
    unsigned short int	N_Motor1Temp_U8;
    unsigned short int	N_Motor2Temp_U8;
    unsigned short int	N_Motor3Temp_U8;
    unsigned short int	N_Motor4Temp_U8;
    unsigned short int	N_SXX3InputVoltage_U8;
    unsigned short int	N_SXX4InputVoltage_U8;
    unsigned short int	N_ACU1Voltage_U8;
    unsigned short int	N_ACU2Voltage_U8;
    unsigned short int	N_ACU1Freq_U8;
    unsigned short int	N_ACU2Freq_U8;
    unsigned short int	N_SXX1InputCurrent_U8;
    unsigned short int	N_SXX2InputCurrent_U8;
    unsigned short int	N_B1A1CoolPressure_U8;
    unsigned short int	N_B1A2CoolPressure_U8;
    unsigned short int	N_B2A1CoolPressure_U8;
    unsigned short int	N_B2A2CoolPressure_U8;
    unsigned short int	N_SXX3InputCurrent_U8;
    unsigned short int	N_SXX4InputCurrent_U8;
    unsigned char	N_PgMcbBlockByte1_U8;
    unsigned char	N_PgMcbBlockByte2_U8;
    unsigned char	N_PgMcbBlockByte3_U8;
    unsigned char	N_BreakMcbBlockByte1_U8;
    unsigned char	N_BreakMcbBlockByte2_U8;
    unsigned char	N_BreakMcbBlockByte3_U8;
    unsigned char	N_TracDBBlockByte1_U8;
    unsigned char	N_TracDBBlockByte2_U8;
    unsigned char	N_TracDBBlockByte3_U8;
    unsigned char	N_EBBlockByte1_U8;
    unsigned char	N_EBBlockByte2_U8;
    unsigned char	N_EBBlockByte3_U8;
    unsigned char	N_Motor1Current_U8;
    unsigned char	N_Motor2Current_U8;
    unsigned char	N_Motor3Current_U8;
    unsigned char	N_Motor4Current_U8;
    bool	B_STATE_MA1_CP
    ;bool	B_FREIGHT_CUT_IN
    ;bool	B_PSG_CUT_IN
    ;bool	B_STATE_C_COVER_SM1
    ;bool	B_STATE_C_COVER_SM2
    ;bool	B_QFM_OFF_PROTECT
    ;bool	B_CMD_MA1_FD
    ;bool	B_CMD_MA2_FD
    ;bool	B_CMD_TC1_QA_HV_ON
    ;bool	B_CMD_TC1_QA_HV_OFF
    ;bool	B_CMD_TC2_QA_HV_ON
    ;bool	B_CMD_TC2_QA_HV_OFF
    ;bool	B_CMD_TC3_QA_HV_ON
    ;bool	B_CMD_TC3_QA_HV_OFF
    ;bool	B_CMD_TC4_QA_HV_ON
    ;bool	B_CMD_TC4_QA_HV_OFF
    ;bool	B_STATE_YV_PAN_ISO
    ;bool	B_STATE_RB_EMG
    ;bool	B_STATE_RB_IS_CF1
    ;bool	B_STATE_RB_IS_CF2
    ;bool	B_STATE_RB_IS_FS
    ;bool	B_STATE_Z_QUAI_T
    ;bool	B_STATE_Z_QUAI_M
    ;bool	B_STATE_QS_GHV
    ;bool	B_STATE_C_VT_MT1
    ;bool	B_STATE_C_VT_MT2
    ;bool	B_STATE_C_VT_SM1
    ;bool	B_STATE_C_VT_SM2
    ;bool	B_STATE_C_VT_BM1
    ;bool	B_STATE_C_VT_BM2
    ;bool	B_STATE_KA_PC1
    ;bool	B_STATE_KA_PC2
    ;bool	B_STATE_KA_PC3
    ;bool	B_STATE_KA_PC4
    ;bool	B_STATE_KA_WORK1
    ;bool	B_STATE_KA_WORK2
    ;bool	B_STATE_KA_WORK3
    ;bool	B_STATE_KA_WORK4
    ;bool	B_STATE_C_BAU1
    ;bool	B_STATE_C_BAU2
    ;bool	B_STATE_DJ_QUAI
    ;bool	B_STATE_WORK_KM_QUAI
    ;bool	B_STATE_KM_QUAI
    ;bool	B_STATE_Q_PP_QUAI
    ;bool	B_STATE_C_SEC
    ;bool	B_STATE_KM_CPR_AUX
    ;bool	B_STATE_DJ_PE1
    ;bool	B_STATE_DJ_PE2
    ;bool	B_STATE_DJ_PE3
    ;bool	B_STATE_DJ_PE4
    ;bool	B_STATE_DJ_PH1
    ;bool	B_STATE_DJ_PH2
    ;bool	B_STATE_Q_TH_VT_MT1
    ;bool	B_STATE_Q_TH_VT_MT2
    ;bool	B_STATE_Q_TH_VT_BM1
    ;bool	B_STATE_Q_TH_VT_BM2
    ;bool	B_STATE_DJ_VT_SM1
    ;bool	B_STATE_DJ_VT_SM2
    ;bool	B_STATE_Q_REC
    ;bool	B_STATE_Q_TH_CPR
    ;bool	B_STATE_C1_CPR
    ;bool	B_STATE_C2_CPR
    ;bool	B_STATE_C3_CPR
    ;bool	B_CMD_WINTER_MODE
    ;bool	B_CMD_SUMMER_MODE
    ;bool	B_CMD_T_CHAR_H
    ;bool	B_CMD_CAB_CHANGE
    ;bool	B_CMD_SAND_CUT
    ;bool	B_FLL_TEST_START
    ;bool	B_FLL_TEST_CANCEL
    ;bool	B_CMD_SIM_ON
    ;bool	B_STATE_PENALTY_BRK_RQ
    ;bool	B_STATE_QFM_OFF
    ;bool	B_STATE_PANTO_DN
    ;bool	B_STATE_ABH_MIN
    ;bool	B_STATE_ABH_SERV_Z
    ;bool	B_STATE_ABH_FULL_SERV
    ;bool	B_CMD_FIRE_ALARM_CONFIRM
    ;bool	B_CMD_TRACK_BLOCK
    ;bool	B_STATE_T_CHAR
    ;bool	B_STATE_H_HT
    ;bool	B_CMD_T_CHAR_Z
    ;bool	B_STATE_CPR_AUX_SWITCH1
    ;bool	B_BRAKE_BACK
    ;bool	B_NO_FIRE_VALVE
    ;bool	B_BUCH_RELAY
    ;bool	B_STATE_SAFE_LOOP
    ;bool	B_PANTO_B_LOOP
    ;bool	B_PANTO_F_LOOP
    ;bool	B_MCB_B_LOOP
    ;bool	B_MCB_F_LOOP
    ;bool	B_SAND_ISO_VALVE
    ;bool	B_FIRE_MA_DETECT
    ;bool	B_PHASE_DETECT
    ;bool	B_TH_CPR
    ;bool	B_CPR_AUX_ISO_VALVE
    ;bool	B_CMD_TC1_4Q1_ISO_RQ
    ;bool	B_CMD_TC1_4Q2_ISO_RQ
    ;bool	B_CMD_TC1_4Q3_ISO_RQ
    ;bool	B_CMD_TC1_4Q4_ISO_RQ
    ;bool	B_CMD_TC1_4Q1_ISO_REL_RQ
    ;bool	B_CMD_TC1_4Q2_ISO_REL_RQ
    ;bool	B_CMD_TC1_4Q3_ISO_REL_RQ
    ;bool	B_CMD_TC1_4Q4_ISO_REL_RQ
    ;bool	B_CMD_TC2_4Q1_ISO_RQ
    ;bool	B_CMD_TC2_4Q2_ISO_RQ
    ;bool	B_CMD_TC2_4Q3_ISO_RQ
    ;bool	B_CMD_TC2_4Q4_ISO_RQ
    ;bool	B_CMD_TC2_4Q1_ISO_REL_RQ
    ;bool	B_CMD_TC2_4Q2_ISO_REL_RQ
    ;bool	B_CMD_TC2_4Q3_ISO_REL_RQ
    ;bool	B_CMD_TC2_4Q4_ISO_REL_RQ
    ;bool	B_CMD_TC3_4Q1_ISO_RQ
    ;bool	B_CMD_TC3_4Q2_ISO_RQ
    ;bool	B_CMD_TC3_4Q3_ISO_RQ
    ;bool	B_CMD_TC3_4Q4_ISO_RQ
    ;bool	B_CMD_TC3_4Q1_ISO_REL_RQ
    ;bool	B_CMD_TC3_4Q2_ISO_REL_RQ
    ;bool	B_CMD_TC3_4Q3_ISO_REL_RQ
    ;bool	B_CMD_TC3_4Q4_ISO_REL_RQ
    ;bool	B_CMD_TC4_4Q1_ISO_RQ
    ;bool	B_CMD_TC4_4Q2_ISO_RQ
    ;bool	B_CMD_TC4_4Q3_ISO_RQ
    ;bool	B_CMD_TC4_4Q4_ISO_RQ
    ;bool	B_CMD_TC4_4Q1_ISO_REL_RQ
    ;bool	B_CMD_TC4_4Q2_ISO_REL_RQ
    ;bool	B_CMD_TC4_4Q3_ISO_REL_RQ
    ;bool	B_CMD_TC4_4Q4_ISO_REL_RQ
    ;bool	B_STATE_4Q1_ISO
    ;bool	B_STATE_4Q2_ISO
    ;bool	B_STATE_4Q3_ISO
    ;bool	B_STATE_4Q4_ISO
    ;bool	B_STATE_4Q1_ISO_M
    ;bool	B_STATE_4Q2_ISO_M
    ;bool	B_STATE_4Q3_ISO_M
    ;bool	B_STATE_4Q4_ISO_M
    ;bool	B_STATE_AXLE1_ISO_M
    ;bool	B_STATE_AXLE2_ISO_M
    ;bool	B_STATE_AXLE3_ISO_M
    ;bool	B_STATE_AXLE4_ISO_M
    ;bool	B_STATE_AUX1_ISO_M
    ;bool	B_STATE_AUX2_ISO_M
    ;bool	B_CMD_TC1_DAMAN_ISO_RQ
    ;bool	B_CMD_TC2_DAMAN_ISO_RQ
    ;bool	B_CMD_TC3_DAMAN_ISO_RQ
    ;bool	B_CMD_TC4_DAMAN_ISO_RQ
    ;bool	B_CMD_TC1_DAMAN_ISO_REL_RQ
    ;bool	B_CMD_TC2_DAMAN_ISO_REL_RQ
    ;bool	B_CMD_TC3_DAMAN_ISO_REL_RQ
    ;bool	B_CMD_TC4_DAMAN_ISO_REL_RQ
    ;bool	B_CMD_TC1_CPR_ISO_RQ
    ;bool	B_CMD_TC2_CPR_ISO_RQ
    ;bool	B_CMD_TC3_CPR_ISO_RQ
    ;bool	B_CMD_TC4_CPR_ISO_RQ
    ;bool	B_CMD_TC1_CPR_ISO_REL_RQ
    ;bool	B_CMD_TC2_CPR_ISO_REL_RQ
    ;bool	B_CMD_TC3_CPR_ISO_REL_RQ
    ;bool	B_CMD_TC4_CPR_ISO_REL_RQ
    ;bool	B_STATE_DAMAN_ISO
    ;bool	B_STATE_CPR_ISO
    ;bool	B_STATE_ELEC_AIR_CUT
    ;bool	B_NSC_DISTANCE1
    ;bool	B_NSC_DISTANCE2
    ;bool	B_Trailer_mode;

};

#endif // TRAINBEAN_H
