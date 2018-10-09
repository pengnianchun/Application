/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APP_CAN2_RECEIVE_H
#define	APP_CAN2_RECEIVE_H

#define WORD_WRITE(dest,data)	do{(dest)[0] = (data)&0xFF;((dest)[1]=(data)>>8)&0xFF;}while(0)
#define DWORD_WRITE(dest,data)	do{(dest)[0] = (data)&0xFF;((dest)[1]=(data)>>8)&0xFF;((dest)[2]=(data)>>16)&0xFF;((dest)[3]=(data)>>24)&0xFF;}while(0)

typedef union {

    struct {
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;
    };
    struct {
        unsigned char double1 : 2;
        unsigned char double2 : 2;
        unsigned char double3 : 2;
        unsigned char double4 : 2;
    };
    unsigned char byte;
} DATA_BIT;

/*****************�ְ�����CAN*****************/

typedef union {

    struct {
        unsigned long SPN1 : 19;
        unsigned long FMI : 5;
        unsigned long CM : 1;
        unsigned long OC : 7;
    }; //����ṹ��Ҫ��֤
    unsigned char bData[4];
} DTC;

typedef union {

    struct {
        unsigned ProtectLampStatus : 2;
        unsigned AmberWarningLampStatus : 2;
        unsigned RedStopLampState : 2;
        unsigned MalfunctionIndicatorLampStatus : 2;
        unsigned FlashProtectLamp : 2;
        unsigned FlashAmberWarningLamp : 2;
        unsigned FlashRedStopLamp : 2;
        unsigned FlashMalfunctionIndicatorLamp : 2;
        DTC DTC1;
        DTC DTC2;
        DTC DTC3;
        DTC DTC4;
        DTC DTC5;
    };
    unsigned char bData[42];
} DM1;

/*extern DM1 CAN_18FECAEF;
extern unsigned char CAN_18FECAEF_len;
extern DM1 CAN_18FECA03;
extern unsigned char CAN_18FECA03_len;
extern DM1 CAN_18FECAF5;
extern unsigned char CAN_18FECAF5_len;
extern DM1 CAN_18FECA00;
extern unsigned char CAN_18FECA00_len;
extern DM1 CAN_18FECAF3;
extern unsigned char CAN_18FECAF3_len;*/

typedef struct {
    unsigned char pack; //CAN�ּ������ݴ���
    unsigned char flag; //CAN�����������
    unsigned char len; //CAN���泤��
    unsigned char buf[50]; //CAN��������
} CAN_CACHE;
/*extern CAN_CACHE m_can; //HCU����
extern CAN_CACHE n_can; //TCU����
extern CAN_CACHE c_can; //CCU����
extern CAN_CACHE b_can; //BMS����*/

extern unsigned long SPN; //�ӻ�������ȡ�Ĺ�����
extern unsigned char FMI;

void DM(unsigned char x, DM1 id);
/*******************�ְ�����*****************/
#pragma pack(1)

typedef union {	
	
	struct {
	unsigned char AcceleratePedalAperture; //����̤�忪��
	unsigned char BrakePedalAperture; //�ƶ�̤�忪��
	DATA_BIT Status1;
	DATA_BIT Status2;
	unsigned Speed; //����
	unsigned char Reserve1;
	unsigned char VcuLife;
	};
	unsigned char byte[8];
} _CAN_0x0CFA00D0;	
	
typedef union {	
	
	struct {
	DATA_BIT Status1;
	DATA_BIT Status2;
	DATA_BIT Status3;
	unsigned MotorTopTorqueOrder;
	unsigned char Reserve1;
	unsigned MotorSpeed;
	};
	unsigned char byte[8];
} _CAN_0x0CFB00D0;	
	
typedef union {	
	
	struct {
	unsigned VCU_DTC; //����������
	unsigned char Reserve1;
	unsigned long Reserve2;
	unsigned char Reserve3 : 5;
	unsigned char FaultLevel : 3; //�������ϵȼ� 
	};
	unsigned char byte[8];
} _CAN_0x0CFC00D0;	
	
typedef union {	
	
	struct {
	unsigned char MotorTemp; //����¶�
	unsigned char MotorCtrlTemp; //����������¶�
	unsigned char MotorStatus; //���״̬
	unsigned char CarStatus; //����״̬
	unsigned char MotorNum; //�����������
	unsigned char MotorMode; //����ģʽ
	unsigned char MotorTempWarn; //��������¶ȱ���
	unsigned char MotorCtrlTempWarn; //��������������¶ȱ���
	};
	unsigned char byte[8];
} _CAN_0x0CFD00D0;	
	
typedef union {	
	
	struct {
	DATA_BIT Warning1;
	DATA_BIT Warning2;
	DATA_BIT Warning3;
	DATA_BIT Warning4;
	DATA_BIT Warning5;
	DATA_BIT Warning6;
	DATA_BIT Warning7;
	DATA_BIT Warning8;
	};
	unsigned char byte[8];
} _CAN_0x0CF100D0;	
	
typedef union {	
	
	struct {
	DATA_BIT Warning1;
	DATA_BIT Warning2;
	DATA_BIT Warning3;
	DATA_BIT Warning4;
	DATA_BIT Warning5;
	DATA_BIT Warning6;
	DATA_BIT Warning7;
	DATA_BIT Warning8;
	};
	unsigned char byte[8];
} _CAN_0x0CF200D0;	
	
typedef union {	
	
	struct {
	DATA_BIT Warning1;
	DATA_BIT Warning2;
	DATA_BIT Warning3;
	DATA_BIT Warning4;
	DATA_BIT Warning5;
	DATA_BIT Warning6;
	DATA_BIT Warning7;
	DATA_BIT Warning8;
	};
	unsigned char byte[8];
} _CAN_0x0CF300D0;	
	
typedef union {	
	
	struct {
	DATA_BIT Warning1;
	DATA_BIT Warning2;
	DATA_BIT Warning3;
	DATA_BIT Warning4;
	unsigned Reserver1;
	unsigned char Speed; //����
	unsigned char VcuLife;//Lifeֵ
	};
	unsigned char byte[8];
} _CAN_0x18F105D0;	
	
typedef union {	
	
	struct {
	unsigned MotorTopTorqueLimit;//ת������
	unsigned MotorCtrlTorqueInstruction;//���������1ת��ָ��
	unsigned long Reserver1;
	};
	unsigned char byte[8];
} _CAN_0x08B1EF21;	
	
typedef union {	
	
	struct {
	unsigned char MCU_DTC;//����ϵͳ���ϴ���
	unsigned char Reserver1;
	DATA_BIT Warning1;
    DATA_BIT Warning2;
	unsigned MotorSpeed;//���ת��
	unsigned MotorTorque;//���ת��
	};
	unsigned char byte[8];
} _CAN_0x0CB221EF;	
	
typedef union {	
	
	struct {
	unsigned char MotorCtrlTemp; //����¶�
	unsigned char MotorTemp; //����������¶�
	unsigned CtrlVoltage; //�����������ѹ
	unsigned CtrlCurrent; //������ĸ�ߵ���
	unsigned CtrlACCurrent; //����������ĸ�ߵ���
	};
	unsigned char byte[8];
} _CAN_0x0CB321EF;	
	
typedef union {	
	
	struct {
	unsigned char SOC; //SOC
	unsigned Voltage; //ĸ�ߵ�ѹ
	unsigned Current; //ĸ�ߵ���
	unsigned InsulationResistance;//��Ե��ֵ
	unsigned char BmsLife;
	};
	unsigned char byte[8];
} _CAN_0x18F212F3;	
	
typedef union {	
	
	struct {
	unsigned LowDischargeVoltage;//��������������ŵ��ѹ
	unsigned HighChargeVoltage;//�����������������ѹ
	unsigned HighDischargeCurrent;//��������������ŵ����
	unsigned HighChargeCurrent;//�������������������
	};
	unsigned char byte[8];
} _CAN_0x18F213F3;	
	
typedef union {	
	
	struct {
	unsigned char BmsFaultCode1; //��ع���ϵͳ���ϴ���1
	unsigned char BmsFaultCode2; //��ع���ϵͳ���ϴ���2
	unsigned char BmsFaultCode3; //��ع���ϵͳ���ϴ���3
	DATA_BIT Status1;
	DATA_BIT Status2;
	DATA_BIT Status3;
	DATA_BIT Status4;
	DATA_BIT Status5;
	};
	unsigned char byte[8];
} _CAN_0x18F214F3;	
	
typedef union {	
	
	struct {
	unsigned char BMS_MAX_Cell_Voltage_CaseNum;//��ߵ�ѹ�����ϵͳ��
	unsigned char BMS_MAX_Cell_Voltage_Num;//��ߵ�ѹ��ص������
	unsigned BMS_MAX_Cell_Voltage;//�����ߵ����ѹ
	unsigned char BMS_MIN_Cell_Voltage_CaseNum;//��͵�ѹ�����ϵͳ��
	unsigned char BMS_MIN_Cell_Voltage_Num;//��͵�ѹ��ص������
	unsigned BMS_MIN_Cell_Voltage;//�����͵����ѹ
	};
	unsigned char byte[8];
} _CAN_0x181CD0F3;	
	
typedef union {	
	
	struct {
	unsigned char BMS_MAX_Cell_Temp_CaseNum;//����¶���ϵͳ��
	unsigned char BMS_MAX_Cell_Temp_Num;//����¶�̽�뵥�����
	unsigned char BMS_MAX_Cell_Temp;//����¶�ֵ
	unsigned char BMS_MIN_Cell_Temp_CaseNum;//����¶���ϵͳ��
	unsigned char BMS_MIN_Cell_Temp_Num;//����¶�̽����ϵͳ����
	unsigned char BMS_MIN_Cell_Temp;//����¶�ֵ
	unsigned InsulationResistance;//��Ե��ֵ
	};
	unsigned char byte[8];
} _CAN_0x181DD0F3;	
	
typedef union {	
	
	struct {
	unsigned char BmsFaultLevel;//��߱����ȼ�
	DATA_BIT Status1;
	DATA_BIT Status2;
	DATA_BIT Status3;
	DATA_BIT Status4;
	DATA_BIT Status5;
	DATA_BIT Status6;
	unsigned char BmsFaultNum;//��ǰ���ϵͳ��������
	};
	unsigned char byte[8];
} _CAN_0x181ED0F3;	

typedef union {	
	
	struct {
	unsigned char BmsFaultLevel;//�ɳ�索����ϵͳ����
	DATA_BIT Status1;
	DATA_BIT Status2;
	DATA_BIT Status3;
	DATA_BIT Status4;
	DATA_BIT Status5;
	DATA_BIT Status6;
	unsigned char BmsFaultNum;//��ǰ���ϵͳ��������
	};
	unsigned char byte[8];
} _CAN_0x181FD0F3;	
	
extern unsigned char BmsASIC[32]; //�������ϵͳ����	
extern unsigned char CarASIC[17]; //����ʶ����
	
typedef union {	
	
	struct {
	unsigned DcacVoltage; //������ĸ�ߵ�ѹ
	unsigned DcacOutVoltage; //�����ѹ
	unsigned char DcacOutCurrent; //�������
	unsigned char DcacWorkStatus; //DCAC����״̬
	unsigned char DcacFaultLevel;//��߱����ȼ�
	unsigned char DcacFaultCode;//DCAC���ϴ���
	};
	unsigned char byte[8];
} _CAN_0x18F602A0;	
	
typedef union {	
	
	struct {
	unsigned Reserve1; //
	unsigned DcacOutVoltage; //�����ѹ
	unsigned char DcacOutCurrent; //�������
	unsigned char DcacWorkStatus; //DCAC����״̬
	unsigned char DcacFaultLevel;//��߱����ȼ�
	unsigned char DcacFaultCode;//DCAC���ϴ���
	};
	unsigned char byte[8];
} _CAN_0x0CF603A1;	
	
typedef union {	
	
	struct {
	unsigned DcacVoltage; //������ĸ�ߵ�ѹ
	unsigned DcacOutVoltage; //�����ѹ
	unsigned char DcacOutCurrent; //�������
	unsigned char DcacWorkStatus; //DCAC����״̬
	unsigned char DcacFaultLevel;//��߱����ȼ�
	unsigned char DcacFaultCode;//DCAC���ϴ���
	};
	unsigned char byte[8];
} _CAN_0x0C6CD7A4;	
	
typedef union {	
	
	struct {
	unsigned DcacVoltage; //������ĸ�ߵ�ѹ
	unsigned DcacOutVoltage; //�����ѹ
	unsigned char DcacOutCurrent; //�������
	unsigned char DcacWorkStatus; //DCAC����״̬
	unsigned char DcacFaultLevel;//��߱����ȼ�
	unsigned char DcacFaultCode;//DCAC���ϴ���
	};
	unsigned char byte[8];
} _CAN_0x18F86251;	

#pragma pack()

extern _CAN_0x0CFA00D0 	CAN_0x0CFA00D0;
extern _CAN_0x0CFB00D0 	CAN_0x0CFB00D0;
extern _CAN_0x0CFC00D0 	CAN_0x0CFC00D0;
extern _CAN_0x0CFD00D0 	CAN_0x0CFD00D0;
extern _CAN_0x0CF100D0 	CAN_0x0CF100D0;
extern _CAN_0x0CF200D0 	CAN_0x0CF200D0;
extern _CAN_0x0CF300D0 	CAN_0x0CF300D0;
extern _CAN_0x18F105D0 	CAN_0x18F105D0;
extern _CAN_0x08B1EF21 	CAN_0x08B1EF21;
extern _CAN_0x0CB221EF 	CAN_0x0CB221EF;
extern _CAN_0x0CB321EF 	CAN_0x0CB321EF;
extern _CAN_0x18F212F3 	CAN_0x18F212F3;
extern _CAN_0x18F213F3 	CAN_0x18F213F3;
extern _CAN_0x18F214F3 	CAN_0x18F214F3;
extern _CAN_0x181CD0F3 	CAN_0x181CD0F3;
extern _CAN_0x181DD0F3 	CAN_0x181DD0F3;
extern _CAN_0x181ED0F3 	CAN_0x181ED0F3;
extern _CAN_0x181FD0F3  CAN_0x181FD0F3;
extern _CAN_0x18F602A0 	CAN_0x18F602A0;
extern _CAN_0x0CF603A1 	CAN_0x0CF603A1;
extern _CAN_0x0C6CD7A4 	CAN_0x0C6CD7A4;
extern _CAN_0x18F86251 	CAN_0x18F86251;

extern unsigned int BAT_Cell_Voltage[6][40]; //��ص����ѹ
extern unsigned char BAT_Cell_Temp[6][8]; //��ص����¶�

void CAN_DATA_Init(void);

#if MODE_FV
extern unsigned char Accelerator; //����̤��

extern unsigned char Speed_lim_mode;//����ģʽ

extern unsigned char water_temp;//ˮ��

extern unsigned int  Engine_oil_press;//����ѹ��
extern unsigned char water_level;//ˮλ

extern unsigned char Wait_start;//�ȴ�����
extern unsigned char Maintain_warn;//ά������
extern unsigned char Stop_warn;//ͣ������
extern unsigned char Engine_warn;//����������

extern unsigned int EngineSpeed;//������ת��

extern unsigned char barometric_pressure; //��ѹѹ�� 0.5Kpa
extern unsigned char ambient_air_temperature; //��Χ�����¶�
extern unsigned char air_pressure; //����ѹ�� 0.5Kpa

extern unsigned int  fuel_rate;   //Сʱȼ��������
extern unsigned int  instantaneous_fuel; //˲̬ȼ�;�����

extern unsigned int  speed_st; //����̤��
#endif

#endif	/* APP_CAN2_RECEIVE_H */

