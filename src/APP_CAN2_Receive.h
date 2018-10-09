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

/*****************分包处理CAN*****************/

typedef union {

    struct {
        unsigned long SPN1 : 19;
        unsigned long FMI : 5;
        unsigned long CM : 1;
        unsigned long OC : 7;
    }; //这个结构需要验证
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
    unsigned char pack; //CAN分几包数据传输
    unsigned char flag; //CAN缓存接收完标记
    unsigned char len; //CAN缓存长度
    unsigned char buf[50]; //CAN缓存数组
} CAN_CACHE;
/*extern CAN_CACHE m_can; //HCU缓存
extern CAN_CACHE n_can; //TCU缓存
extern CAN_CACHE c_can; //CCU缓存
extern CAN_CACHE b_can; //BMS缓存*/

extern unsigned long SPN; //从缓存里提取的故障码
extern unsigned char FMI;

void DM(unsigned char x, DM1 id);
/*******************分包处理*****************/
#pragma pack(1)

typedef union {	
	
	struct {
	unsigned char AcceleratePedalAperture; //加速踏板开度
	unsigned char BrakePedalAperture; //制动踏板开度
	DATA_BIT Status1;
	DATA_BIT Status2;
	unsigned Speed; //车速
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
	unsigned VCU_DTC; //整车故障码
	unsigned char Reserve1;
	unsigned long Reserve2;
	unsigned char Reserve3 : 5;
	unsigned char FaultLevel : 3; //整车故障等级 
	};
	unsigned char byte[8];
} _CAN_0x0CFC00D0;	
	
typedef union {	
	
	struct {
	unsigned char MotorTemp; //电机温度
	unsigned char MotorCtrlTemp; //电机控制器温度
	unsigned char MotorStatus; //电机状态
	unsigned char CarStatus; //车辆状态
	unsigned char MotorNum; //驱动电机个数
	unsigned char MotorMode; //运行模式
	unsigned char MotorTempWarn; //驱动电机温度报警
	unsigned char MotorCtrlTempWarn; //驱动电机控制器温度报警
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
	unsigned char Speed; //车速
	unsigned char VcuLife;//Life值
	};
	unsigned char byte[8];
} _CAN_0x18F105D0;	
	
typedef union {	
	
	struct {
	unsigned MotorTopTorqueLimit;//转速限制
	unsigned MotorCtrlTorqueInstruction;//电机控制器1转矩指令
	unsigned long Reserver1;
	};
	unsigned char byte[8];
} _CAN_0x08B1EF21;	
	
typedef union {	
	
	struct {
	unsigned char MCU_DTC;//驱动系统故障代码
	unsigned char Reserver1;
	DATA_BIT Warning1;
    DATA_BIT Warning2;
	unsigned MotorSpeed;//电机转速
	unsigned MotorTorque;//电机转矩
	};
	unsigned char byte[8];
} _CAN_0x0CB221EF;	
	
typedef union {	
	
	struct {
	unsigned char MotorCtrlTemp; //电机温度
	unsigned char MotorTemp; //电机控制器温度
	unsigned CtrlVoltage; //控制器输入电压
	unsigned CtrlCurrent; //控制器母线电流
	unsigned CtrlACCurrent; //控制器交流母线电流
	};
	unsigned char byte[8];
} _CAN_0x0CB321EF;	
	
typedef union {	
	
	struct {
	unsigned char SOC; //SOC
	unsigned Voltage; //母线电压
	unsigned Current; //母线电流
	unsigned InsulationResistance;//绝缘阻值
	unsigned char BmsLife;
	};
	unsigned char byte[8];
} _CAN_0x18F212F3;	
	
typedef union {	
	
	struct {
	unsigned LowDischargeVoltage;//动力电池最低允许放电电压
	unsigned HighChargeVoltage;//动力电池最高允许充电电压
	unsigned HighDischargeCurrent;//动力电池最大允许放电电流
	unsigned HighChargeCurrent;//动力电池最大允许充电电流
	};
	unsigned char byte[8];
} _CAN_0x18F213F3;	
	
typedef union {	
	
	struct {
	unsigned char BmsFaultCode1; //电池管理系统故障代码1
	unsigned char BmsFaultCode2; //电池管理系统故障代码2
	unsigned char BmsFaultCode3; //电池管理系统故障代码3
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
	unsigned char BMS_MAX_Cell_Voltage_CaseNum;//最高电压电池子系统号
	unsigned char BMS_MAX_Cell_Voltage_Num;//最高电压电池单体代号
	unsigned BMS_MAX_Cell_Voltage;//电池最高单体电压
	unsigned char BMS_MIN_Cell_Voltage_CaseNum;//最低电压电池子系统号
	unsigned char BMS_MIN_Cell_Voltage_Num;//最低电压电池单体代号
	unsigned BMS_MIN_Cell_Voltage;//电池最低单体电压
	};
	unsigned char byte[8];
} _CAN_0x181CD0F3;	
	
typedef union {	
	
	struct {
	unsigned char BMS_MAX_Cell_Temp_CaseNum;//最高温度子系统号
	unsigned char BMS_MAX_Cell_Temp_Num;//最高温度探针单体代号
	unsigned char BMS_MAX_Cell_Temp;//最高温度值
	unsigned char BMS_MIN_Cell_Temp_CaseNum;//最低温度子系统号
	unsigned char BMS_MIN_Cell_Temp_Num;//最低温度探针子系统代号
	unsigned char BMS_MIN_Cell_Temp;//最低温度值
	unsigned InsulationResistance;//绝缘阻值
	};
	unsigned char byte[8];
} _CAN_0x181DD0F3;	
	
typedef union {	
	
	struct {
	unsigned char BmsFaultLevel;//最高报警等级
	DATA_BIT Status1;
	DATA_BIT Status2;
	DATA_BIT Status3;
	DATA_BIT Status4;
	DATA_BIT Status5;
	DATA_BIT Status6;
	unsigned char BmsFaultNum;//当前电池系统故障总数
	};
	unsigned char byte[8];
} _CAN_0x181ED0F3;	

typedef union {	
	
	struct {
	unsigned char BmsFaultLevel;//可充电储能子系统个数
	DATA_BIT Status1;
	DATA_BIT Status2;
	DATA_BIT Status3;
	DATA_BIT Status4;
	DATA_BIT Status5;
	DATA_BIT Status6;
	unsigned char BmsFaultNum;//当前电池系统故障总数
	};
	unsigned char byte[8];
} _CAN_0x181FD0F3;	
	
extern unsigned char BmsASIC[32]; //动力电池系统编码	
extern unsigned char CarASIC[17]; //车辆识别码
	
typedef union {	
	
	struct {
	unsigned DcacVoltage; //控制器母线电压
	unsigned DcacOutVoltage; //输出电压
	unsigned char DcacOutCurrent; //输出电流
	unsigned char DcacWorkStatus; //DCAC工作状态
	unsigned char DcacFaultLevel;//最高报警等级
	unsigned char DcacFaultCode;//DCAC故障代码
	};
	unsigned char byte[8];
} _CAN_0x18F602A0;	
	
typedef union {	
	
	struct {
	unsigned Reserve1; //
	unsigned DcacOutVoltage; //输出电压
	unsigned char DcacOutCurrent; //输出电流
	unsigned char DcacWorkStatus; //DCAC工作状态
	unsigned char DcacFaultLevel;//最高报警等级
	unsigned char DcacFaultCode;//DCAC故障代码
	};
	unsigned char byte[8];
} _CAN_0x0CF603A1;	
	
typedef union {	
	
	struct {
	unsigned DcacVoltage; //控制器母线电压
	unsigned DcacOutVoltage; //输出电压
	unsigned char DcacOutCurrent; //输出电流
	unsigned char DcacWorkStatus; //DCAC工作状态
	unsigned char DcacFaultLevel;//最高报警等级
	unsigned char DcacFaultCode;//DCAC故障代码
	};
	unsigned char byte[8];
} _CAN_0x0C6CD7A4;	
	
typedef union {	
	
	struct {
	unsigned DcacVoltage; //控制器母线电压
	unsigned DcacOutVoltage; //输出电压
	unsigned char DcacOutCurrent; //输出电流
	unsigned char DcacWorkStatus; //DCAC工作状态
	unsigned char DcacFaultLevel;//最高报警等级
	unsigned char DcacFaultCode;//DCAC故障代码
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

extern unsigned int BAT_Cell_Voltage[6][40]; //电池单体电压
extern unsigned char BAT_Cell_Temp[6][8]; //电池单体温度

void CAN_DATA_Init(void);

#if MODE_FV
extern unsigned char Accelerator; //油门踏板

extern unsigned char Speed_lim_mode;//限速模式

extern unsigned char water_temp;//水温

extern unsigned int  Engine_oil_press;//机油压力
extern unsigned char water_level;//水位

extern unsigned char Wait_start;//等待启动
extern unsigned char Maintain_warn;//维护报警
extern unsigned char Stop_warn;//停机报警
extern unsigned char Engine_warn;//发动机故障

extern unsigned int EngineSpeed;//发动机转速

extern unsigned char barometric_pressure; //增压压力 0.5Kpa
extern unsigned char ambient_air_temperature; //周围空气温度
extern unsigned char air_pressure; //进气压力 0.5Kpa

extern unsigned int  fuel_rate;   //小时燃油消耗率
extern unsigned int  instantaneous_fuel; //瞬态燃油经济性

extern unsigned int  speed_st; //油门踏板
#endif

#endif	/* APP_CAN2_RECEIVE_H */

