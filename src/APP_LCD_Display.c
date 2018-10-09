#include "APP_System.h"
//include "APP_FONT.h"
#include "APP_CHAR.h"
#include "show_zh_21x20.h"
#include "APP_String.h"
#include "APP_LOGO.h"

unsigned char Index = 0;
unsigned char t = 0;
unsigned char t_add = 0;
unsigned char frmID = 0;
unsigned char f_index = 0;
unsigned char menuid = 0;
unsigned char AV_CH = 0;
unsigned char color_old[24] = {};

void print_SZ(unsigned int x, unsigned int y, //显示坐标位置 
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 8, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 8, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    }
}

void print_SZ_1(unsigned int x, unsigned int y, //显示坐标位置//高清数字
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
}

void print_SZ_2(unsigned int x, unsigned int y, //显示坐标位置//高清数字
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_2[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_2[bcd[i]], color, BLACK);
        }
    }
}

/*
void print_SZ_4(unsigned int x, unsigned int y, //显示坐标位置 //放大4倍数字
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPPZOOM_4(x + i * 16, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPPZOOM_4(x + i * 16, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    }
}
 */

void disp_rectange(unsigned int x, unsigned int y, //画方框
        unsigned int w,
        unsigned char wdat,
        unsigned int h,
        unsigned char hdat,
        unsigned char color1) {
    LCD_DrawRect(x, y, w, wdat, color1);
    LCD_DrawRect(x, y + h - wdat, w, wdat, color1);
    LCD_DrawRect(x, y, hdat, h, color1);
    LCD_DrawRect(x + w - hdat, y, hdat, h, color1);
}

void print_D(unsigned int x, unsigned int y, //以2进制显示
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 2;
        dat = dat / 2;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = color1;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = color1;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
}

void print_H(unsigned int x, unsigned int y, //以16进制显示
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 16;
        dat = dat / 16;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                //color = BLACK;
                color = color1;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                //color = BLACK;
                color = color1;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
    LCD_DrawImage1BPP(x - sum * 16, y, BMP_SZ_1[0], color, BLACK);
    LCD_DrawImage1BPP(x + 16 - sum * 16, y + 8, BMP_ASIC_11x20[120 - 32], color, BLACK);
}

#if 1

void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //没有文字，字数填0，字模为BMP_BLANK       
        unsigned char witdh, //字体宽度
        __prog__ const unsigned char **img, //字符串首地址
        unsigned char fcolor, //字体前景色
        unsigned char bcolor //字体背景色
        ) {
    unsigned char i;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh * i, y, img[i], fcolor, bcolor);
    }
}

/*void LCD_DrawImageSBPP1(unsigned int x, unsigned int y,
        __prog__ const unsigned char **img, //字符串首地址
        unsigned char fcolor, //字体前景色
        unsigned char bcolor //字体背景色
        ) {
    unsigned char i, witd = 0;
    witdh = 0;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh, y, img[i], fcolor, bcolor);
        witd = *(img[i] + 1) * 7;
        witdh += witd;
    }
}*/
#endif

unsigned int LCD_DrawImageString_21x20(unsigned int x, unsigned int y, const unsigned char *s, unsigned char fColor, unsigned char bColor) {
    unsigned int v, witdh = 0;
    if (s != NULL) {
        while (*s) {
            if (*s < 0x80) {
                LCD_DrawImage1BPP_11x20(x, y, BMP_ASIC_11x20[*s], fColor, bColor);
                s++;
                x += 11;
                witdh += 11;
            } else {
                v = *s - 0x80;
                v *= 128;
                s++;
                v += *s - 0x80;
                LCD_DrawImage1BPP_21x20(x, y, BMP_zh21x20[v], fColor, bColor);
                s++;
                x += 21;
                witdh += 21;
            }
        }
    }
    return witdh;
}

typedef struct {
    const unsigned char *img; //报警文字
    unsigned char squence;
    unsigned char condition;
    unsigned int position; //动态数据显示位置
    unsigned int dat; //变动的数据
    unsigned char sum; //显示数据的位数
} CAN_WARN_LIST;

#define CAN_LIST_NUMBER 130
CAN_WARN_LIST list[CAN_LIST_NUMBER] = {
    { qbmklx, 0}, //	前部模块离线
    { dbmklx, 1}, //	顶部模块离线
    { hbmklx, 2}, //	后部模块离线
    { zmwg, 3}, //	中门未关报警
    { qmwg, 4}, //	前门未关报警
    { xdcdyd, 5}, //	蓄电池电压低  
    { chagre, 6}, //	正在充电，禁止行车   
    { hcmwg, 7}, //	后仓门未关报警   
    { clcs, 8}, //	车辆超速
    { qmyjfbj, 9}, //	前门应急阀报警
    { qmyjfkg, 10}, //	前门应急阀开关
    { zmyjfbj, 11}, //	中门应急阀报警
    { zmyjfkg, 12}, //	中门应急阀开关
    { zpl, 13}, //	左偏离
    { ypl, 14}, //	右偏离
    { pzbjyx, 15}, //	碰撞预警有效
    { reserve, 16}, //	备用
    { reserve, 17}, //	备用
    { djxtxx14, 18}, //	驱动电机温度报警
    { djxtxx15, 19}, //	驱动电机控制器温度报警
    { djxtxx16, 20}, //	电机控制器母线硬件过流
    { djxtxx17, 21}, //	电机控制器低压供电故障报警
    { djxtxx18, 22}, //	电机控制器模块故障
    { djxtxx19, 23}, //	电机控制器CAN通信故障
    { djxtxx20, 24}, //	电机控制器离线
    { djxtxx21, 25}, //	电机控制器母线硬件过压
    { djxtxx22, 26}, //	电机控制器相电流过流
    { djxtxx23, 27}, //	电机控制器相电流硬件过流
    { djxtxx24, 28}, //	电机控制器母线过流
    { djxtxx25, 29}, //	电机控制器综合故障报警
    { djxtxx26, 30}, //	电机控制器过热报警
    { djxtxx27, 31}, //	电机控制器欠压报警
    { djxtxx28, 32}, //	电机控制器过压报警
    { djxtxx29, 33}, //	电机超速
    { djxtxx30, 34}, //	电机堵转
    { djxtxx31, 35}, //	电机过载
    { djxtxx32, 36}, //	电机过热报警
    { djxtxx33, 37}, //	电机缺相报警
    { djxtxx34, 38}, //	电机旋变报警
    { zcxtxx16, 39}, //	制动踏板故障
    { zcxtxx17, 40}, //	加速踏板故障
    { zcxtxx18, 41}, //	档位信号错误报警
    { zcxtxx19, 42}, //	制动系统报警
    { zcxtxx20, 43}, //	气泵高温报警
    { bmsxtxx28, 44}, //	温度差异报警
    { bmsxtxx29, 45}, //	电池高温报警
    { bmsxtxx30, 46}, //	车载储能装置类型过压报警
    { bmsxtxx31, 47}, //	车载储能装置类型欠压报警
    { bmsxtxx32, 48}, //	SOC低报警
    { bmsxtxx33, 49}, //	单体电池过压报警
    { bmsxtxx34, 50}, //	单体电池欠压报警
    { bmsxtxx35, 51}, //	SOC过高报警
    { bmsxtxx36, 52}, //	SOC跳变报警
    { bmsxtxx37, 53}, //	可充电储能系统不匹配报警
    { bmsxtxx38, 54}, //	电池单体一致性差报警
    { bmsxtxx39, 55}, //	绝缘报警
    { bmsxtxx40, 56}, //	车载储能装置类型过充
    { bmsxtxx41, 57}, //	高压互锁状态报警
    { bmsxtxx42, 58}, //	电池低温报警
    { ktxtxx1, 59}, //	DCDC输出过压
    { ktxtxx2, 60}, //	DCDC输入过压
    { ktxtxx3, 61}, //	DCDC输入欠压
    { ktxtxx4, 62}, //	DCDC通信故障
    { ktxtxx5, 63}, //	DCDC离线
    { ktxtxx6, 64}, //	DCDC过热
    { ktxtxx7, 65}, //	DCDC短路
    { ktxtxx8, 66}, //	DCDC过流
    { ktxtxx9, 67}, //	DCDC限流
    { ktxtxx10, 68}, //	气泵DCAC输入欠压
    { ktxtxx11, 69}, //	气泵DCAC通信故障
    { ktxtxx12, 70}, //	气泵DCAC离线
    { ktxtxx13, 71}, //	DCDC综合故障
    { ktxtxx14, 72}, //	气泵DCAC综合故障
    { ktxtxx15, 73}, //	气泵DCAC短路
    { ktxtxx16, 74}, //	气泵DCAC过流
    { ktxtxx17, 75}, //	气泵DCAC缺相
    { ktxtxx18, 76}, //	气泵DCAC输入过压
    { ktxtxx19, 77}, //	气泵DCAC综合报警
    { ktxtxx20, 78}, //	气泵DCAC过载
    { ktxtxx21, 79}, //	气泵DCAC过热
    { ktxtxx22, 80}, //	高压油泵DCAC缺相
    { ktxtxx23, 81}, //	高压油泵DCAC输入过压
    { ktxtxx24, 82}, //	高压油泵DCAC输入欠压
    { ktxtxx25, 83}, //	高压油泵DCAC通信故障
    { ktxtxx26, 84}, //	高压油泵DCAC离线
    { ktxtxx27, 85}, //	高压油泵DCAC过载
    { ktxtxx28, 86}, //	高压油泵DCAC过热
    { ktxtxx29, 87}, //	高压油泵DCAC短路
    { ktxtxx30, 88}, //	高压油泵DCAC过流
    { ktxtxx31, 89}, //	高压油泵DCAC综合报警
    { ktxtxx32, 90}, //	低压油泵DCAC缺相
    { ktxtxx33, 91}, //	低压油泵DCAC输入过压
    { ktxtxx34, 92}, //	低压油泵DCAC输入欠压
    { ktxtxx35, 93}, //	低压油泵DCAC通信故障
    { ktxtxx36, 94}, //	低压油泵DCAC离线
    { ktxtxx37, 95}, //	低压油泵DCAC过载
    { ktxtxx38, 96}, //	低压油泵DCAC过热
    { ktxtxx39, 97}, //	低压油泵DCAC短路
    { ktxtxx40, 98}, //	低压油泵DCAC过流
    { ktxtxx41, 99}, //	低压油泵DCAC过热
    { ktxtxx42, 100}, //	低压油泵DCAC综合报警
    { dcxtxx1, 101}, //	电池总电压过高
    { dcxtxx2, 102}, //	测温点温差过大
    { dcxtxx3, 103}, //	电池温度过高
    { dcxtxx4, 104}, //	BMS通信故障
    { dcxtxx5, 105}, //	BMS离线
    { dcxtxx6, 106}, //	单体电压过低
    { dcxtxx7, 107}, //	单体电压过高
    { dcxtxx8, 108}, //	SOC过低
    { dcxtxx9, 109}, //	电池总电压过低
    { dcxtxx10, 110}, //	电池温度过低
    { dcxtxx11, 111}, //	瞬态放电电流过大
    { dcxtxx12, 112}, //	稳态放电电流过大
    { dcxtxx13, 113}, //	单体压差过大
    { dcxtxx14, 114}, //	电池绝缘故障
    { dcxtxx15, 115}, //	瞬态充电电流过大
    { dcxtxx16, 116}, //	稳态充电电流过大
    { dcxtxx17, 117}, //	SOC过高
    { dcxtxx18, 118}, //	电流传感器故障
    { dcxtxx19, 119}, //	温度传感器故障
    { dcxtxx20, 120}, //	电池综合报警
    { zcxtxx21, 121}, //	整车互锁模式
    { zcxtxx22, 122}, //	整车强制降功率模式
    {NULL}
};

static void CAN_WARN_DYNAMIC_UPDATE(CAN_WARN_LIST list, unsigned int x, unsigned int y) {//滚动显示动态变化的数据
    if (list.condition)
        print_SZ_2(x + list.position, y, list.dat, list.sum, 0, YELLOW);
}

static void CAN_WARN_UPDATE(void) {
    list[0].condition = (Fcan_count == CAN_TIME);
    list[1].condition = (Mcan_count == CAN_TIME);
    list[2].condition = (Rcan_count == CAN_TIME);
    list[3].condition = (SPEED > 5 && LED2);
    list[4].condition = (SPEED > 5 && LED1);
    list[5].condition = (BAT24V_count == BAT24_TIME);
    list[6].condition = (LED7);
    list[7].condition = (rKL15);
    list[8].condition = (SPEED > 69);
    list[9].condition = 0;
    list[10].condition = 0;
    list[11].condition = 0;
    list[12].condition = 0;
    list[13].condition = 0;
    list[14].condition = 0;
    list[15].condition = 0;
    list[16].condition = 0;
    list[17].condition = 0;
    list[18].condition = CAN_0x0CFD00D0.MotorTempWarn;
    list[19].condition = CAN_0x0CFD00D0.MotorCtrlTempWarn;
    list[20].condition = CAN_0x0CF100D0.Warning4.double4;
    list[21].condition = CAN_0x0CF100D0.Warning4.double3;
    list[22].condition = CAN_0x0CF100D0.Warning4.double2;
    list[23].condition = CAN_0x0CF100D0.Warning4.bit2;
    list[24].condition = CAN_0x0CF100D0.Warning4.bit1;
    list[25].condition = CAN_0x0CF100D0.Warning5.double4;
    list[26].condition = CAN_0x0CF100D0.Warning5.double3;
    list[27].condition = CAN_0x0CF100D0.Warning5.double2;
    list[28].condition = CAN_0x0CF100D0.Warning5.double1;
    list[29].condition = CAN_0x0CF100D0.Warning6.double4;
    list[30].condition = CAN_0x0CF100D0.Warning6.double3;
    list[31].condition = CAN_0x0CF100D0.Warning6.double2;
    list[32].condition = CAN_0x0CF100D0.Warning6.double1;
    list[33].condition = CAN_0x0CF100D0.Warning7.double4;
    list[34].condition = CAN_0x0CF100D0.Warning7.double3;
    list[35].condition = CAN_0x0CF100D0.Warning8.double4;
    list[36].condition = CAN_0x0CF100D0.Warning8.double3;
    list[37].condition = CAN_0x0CF100D0.Warning8.double2;
    list[38].condition = CAN_0x0CF100D0.Warning8.double1;
    list[39].condition = CAN_0x0CF100D0.Warning1.double4;
    list[40].condition = CAN_0x0CF100D0.Warning1.double3;
    list[41].condition = CAN_0x0CF100D0.Warning1.double2;
    list[42].condition = CAN_0x0CF100D0.Warning2.double2;
    list[43].condition = CAN_0x0CF100D0.Warning2.double1;
    list[44].condition = CAN_0x181ED0F3.Status1.bit1;
    list[45].condition = CAN_0x181ED0F3.Status1.bit2;
    list[46].condition = CAN_0x181ED0F3.Status1.bit3;
    list[47].condition = CAN_0x181ED0F3.Status1.bit4;
    list[48].condition = CAN_0x181ED0F3.Status1.bit5;
    list[49].condition = CAN_0x181ED0F3.Status1.bit6;
    list[50].condition = CAN_0x181ED0F3.Status1.bit7;
    list[51].condition = CAN_0x181ED0F3.Status1.bit8;
    list[52].condition = CAN_0x181ED0F3.Status2.bit1;
    list[53].condition = CAN_0x181ED0F3.Status2.bit2;
    list[54].condition = CAN_0x181ED0F3.Status2.bit3;
    list[55].condition = CAN_0x181ED0F3.Status2.bit4;
    list[56].condition = CAN_0x181ED0F3.Status2.bit5;
    list[57].condition = CAN_0x181ED0F3.Status2.bit6;
    list[58].condition = CAN_0x181ED0F3.Status2.bit7;
    list[59].condition = CAN_0x0CF200D0.Warning1.double4;
    list[60].condition = CAN_0x0CF200D0.Warning1.double3;
    list[61].condition = CAN_0x0CF200D0.Warning1.double2;
    list[62].condition = CAN_0x0CF200D0.Warning1.bit2;
    list[63].condition = CAN_0x0CF200D0.Warning1.bit1;
    list[64].condition = CAN_0x0CF200D0.Warning2.double4;
    list[65].condition = CAN_0x0CF200D0.Warning2.double3;
    list[66].condition = CAN_0x0CF200D0.Warning2.double2;
    list[67].condition = CAN_0x0CF200D0.Warning2.double1;
    list[68].condition = CAN_0x0CF200D0.Warning3.double4;
    list[69].condition = CAN_0x0CF200D0.Warning3.bit6;
    list[70].condition = CAN_0x0CF200D0.Warning3.bit5;
    list[71].condition = CAN_0x0CF200D0.Warning3.double2;
    list[72].condition = CAN_0x0CF200D0.Warning3.double1;
    list[73].condition = CAN_0x0CF200D0.Warning4.double4;
    list[74].condition = CAN_0x0CF200D0.Warning4.double3;
    list[75].condition = CAN_0x0CF200D0.Warning4.double2;
    list[76].condition = CAN_0x0CF200D0.Warning4.double1;
    list[77].condition = CAN_0x0CF200D0.Warning5.double3;
    list[78].condition = CAN_0x0CF200D0.Warning5.double2;
    list[79].condition = CAN_0x0CF200D0.Warning5.double1;
    list[80].condition = CAN_0x0CF200D0.Warning6.double4;
    list[81].condition = CAN_0x0CF200D0.Warning6.double3;
    list[82].condition = CAN_0x0CF200D0.Warning6.double2;
    list[83].condition = CAN_0x0CF200D0.Warning6.bit2;
    list[84].condition = CAN_0x0CF200D0.Warning6.bit1;
    list[85].condition = CAN_0x0CF200D0.Warning7.double4;
    list[86].condition = CAN_0x0CF200D0.Warning7.double3;
    list[87].condition = CAN_0x0CF200D0.Warning7.double2;
    list[88].condition = CAN_0x0CF200D0.Warning7.double1;
    list[89].condition = CAN_0x0CF200D0.Warning8.double1;
    list[90].condition = CAN_0x0CF300D0.Warning6.double4;
    list[91].condition = CAN_0x0CF300D0.Warning6.double3;
    list[92].condition = CAN_0x0CF300D0.Warning6.double2;
    list[93].condition = CAN_0x0CF300D0.Warning6.bit2;
    list[94].condition = CAN_0x0CF300D0.Warning6.bit1;
    list[95].condition = CAN_0x0CF300D0.Warning7.double4;
    list[96].condition = CAN_0x0CF300D0.Warning7.double3;
    list[97].condition = CAN_0x0CF300D0.Warning7.double2;
    list[98].condition = CAN_0x0CF300D0.Warning7.double1;
    list[99].condition = CAN_0x0CF300D0.Warning8.double4;
    list[100].condition = CAN_0x0CF300D0.Warning8.double1;
    list[101].condition = CAN_0x0CF300D0.Warning1.double4;
    list[102].condition = CAN_0x0CF300D0.Warning1.double3;
    list[103].condition = CAN_0x0CF300D0.Warning1.double2;
    list[104].condition = CAN_0x0CF300D0.Warning1.bit2;
    list[105].condition = CAN_0x0CF300D0.Warning1.bit1;
    list[106].condition = CAN_0x0CF300D0.Warning2.double4;
    list[107].condition = CAN_0x0CF300D0.Warning2.double3;
    list[108].condition = CAN_0x0CF300D0.Warning2.double2;
    list[109].condition = CAN_0x0CF300D0.Warning2.double1;
    list[110].condition = CAN_0x0CF300D0.Warning3.double4;
    list[111].condition = CAN_0x0CF300D0.Warning3.double3;
    list[112].condition = CAN_0x0CF300D0.Warning3.double2;
    list[113].condition = CAN_0x0CF300D0.Warning3.double1;
    list[114].condition = CAN_0x0CF300D0.Warning4.double4;
    list[115].condition = CAN_0x0CF300D0.Warning4.double3;
    list[116].condition = CAN_0x0CF300D0.Warning4.double2;
    list[117].condition = CAN_0x0CF300D0.Warning4.double1;
    list[118].condition = CAN_0x0CF300D0.Warning5.double4;
    list[119].condition = CAN_0x0CF300D0.Warning5.double3;
    list[120].condition = CAN_0x0CF300D0.Warning5.double2;
    list[121].condition = CAN_0x0CFA00D0.Status2.bit6;
    list[122].condition = CAN_0x0CFA00D0.Status2.bit5;
}
#define BLANK  300

static void CAN_WARN(unsigned int x, unsigned int y,
        CAN_WARN_LIST list[]
        ) {
    static unsigned char i = 0;
    unsigned int witdh = 0;
    CAN_WARN_UPDATE();
    for (; i < CAN_LIST_NUMBER; i++) {
        if (list[i].condition) {
            witdh = LCD_DrawImageString_21x20(x, y, list[i].img, YELLOW, BLACK);       
            LCD_DrawRect(x + witdh, y - 8, BLANK - witdh, 36, BLACK);
            CAN_WARN_DYNAMIC_UPDATE(list[i], x, y);
            i++;
            break;
        }
    }
    if (i >= CAN_LIST_NUMBER) {
        alarm_update_flag = 0;
        LCD_DrawRect(x, y - 8, BLANK, 36, BLACK);
        i = 0;
    }
}

typedef struct {
    unsigned char flag[5];
    const unsigned char *p1[5];
    unsigned char color[5];
} _print_dat;

static void print_string(unsigned int x, unsigned int y, //显示坐标位置 
        unsigned char dat, //显示的数据 
        _print_dat print_dat) {
    unsigned char i = 0;
    for (i = 0; i < 5; i++) {
        if (dat == print_dat.flag[i]) {
            LCD_DrawImageString_21x20(x, y, print_dat.p1[i], print_dat.color[i], BLACK);
            return;
        }
    }
}

void disp_FONT_baojingNew(unsigned int x, unsigned int y) {
    if (alarm_update_flag == 0) {
        alarm_update_flag = 1;
        CAN_WARN(x, y + 8, list);
    }
}

void disp_miles() {//显示里程
#if DrawBus
    print_SZ_1(10, 318 + 15 + 38 + 2, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(10 + 16, 318 + 15 + 38 * 2 + 2, single_miles, 5, 1, WHITE);
#else
    print_SZ_1(2 + 64 + 4 + 10, 440 - 2 + 13 - 5, total_miles / 10, 7, 0, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30 - 16, 440 - 2 + 13 - 5, single_miles, 5, 1, WHITE);
#endif    
}

void disp_time(unsigned int x, unsigned int y, DATE dtimer) {
    unsigned char color = 0;
    static unsigned char color_back = 0;
    if (color_back && (t == 0)) {
        if (t_add) {//小时设置，十位
            timer.hour = timer.hour + 0x10;
            if ((timer.hour >> 4) > 2) {
                timer.hour = timer.hour & 0x0f;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, BLACK);

    if (color_back && (t == 1)) {
        if (t_add) {//小时设置，个位
            timer.hour = timer.hour + 0x01;
            if ((timer.hour & 0x0f) > 9) {
                timer.hour = timer.hour & 0xf0;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, BLACK);

    if (color_back && (t == 2)) {
        if (t_add) {//分钟设置，十位
            timer.minute = timer.minute + 0x10;
            if ((timer.minute >> 4) > 5) {
                timer.minute = timer.minute & 0x0f;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, BLACK);

    if (color_back && (t == 3)) {
        if (t_add) {//分钟设置，个位
            timer.minute = timer.minute + 0x01;
            if ((timer.minute & 0x0f) > 9) {
                timer.minute = timer.minute & 0xf0;
            }
            DS3231_SetTime(&timer);
            t_add = 0;
        }
        LCD_DrawImage1BPP(x + 28 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, GRAY);
    } else LCD_DrawImage1BPP(x + 28 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, BLACK);

    if (F500ms_LCD) color = WHITE;
    else color = BLACK;
    LCD_DrawImage1BPP(x + 28 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //冒号 

    if (time_flag) {
        color_back = FLASH;
    } else {
        color_back = 0;
        t = 0;
    }

    /*****************年月日在子界面显示**********************/
    if (frmID == 1 || DrawBus) {
        LCD_DrawImage1BPP(x + 260, y, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(x + 260 + 16, y, BMP_SZ_1[0], WHITE, BLACK); //0

        if (color_back && (t == 4)) {
            if (t_add) {//年设置，十位
                timer.year = timer.year + 0x10;
                if ((timer.year >> 4) > 9) {
                    timer.year = timer.year & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 2, y, BMP_SZ_1[(dtimer.year >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 5)) {
            if (t_add) {//年设置，个位
                timer.year = timer.year + 0x01;
                if ((timer.year & 0x0f) > 9) {
                    timer.year = timer.year & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 3, y, BMP_SZ_1[dtimer.year & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 3, y, BMP_SZ_1[dtimer.year & 0x0f], WHITE, BLACK);

        LCD_DrawImage1BPP(x + 260 + 16 * 4, y, BMP_SZ_1[17], WHITE, BLACK); //-

        if (color_back && (t == 6)) {
            if (t_add) {//月设置，十位
                timer.month = timer.month + 0x10;
                if ((timer.month >> 4) > 1) {
                    timer.month = timer.month & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 5, y, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 5, y, BMP_SZ_1[(dtimer.month >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 7)) {
            if (t_add) {//月设置，个位
                timer.month = timer.month + 0x01;
                if ((timer.month & 0x0f) > 9) {
                    timer.month = timer.month & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 6, y, BMP_SZ_1[dtimer.month & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 6, y, BMP_SZ_1[dtimer.month & 0x0f], WHITE, BLACK);

        LCD_DrawImage1BPP(x + 260 + 16 * 7, y, BMP_SZ_1[17], WHITE, BLACK); //-

        if (color_back && (t == 8)) {
            if (t_add) {//日设置，十位
                timer.day = timer.day + 0x10;
                if ((timer.day >> 4) > 3) {
                    timer.day = timer.day & 0x0f;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 8, y, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 8, y, BMP_SZ_1[(dtimer.day >> 4)&0x0f], WHITE, BLACK);

        if (color_back && (t == 9)) {
            if (t_add) {//日设置，个位
                timer.day = timer.day + 0x01;
                if ((timer.day & 0x0f) > 9) {
                    timer.day = timer.day & 0xf0;
                }
                DS3231_SetTime(&timer);
                t_add = 0;
            }
            LCD_DrawImage1BPP(x + 260 + 16 * 9, y, BMP_SZ_1[dtimer.day & 0x0f], WHITE, GRAY);
        } else LCD_DrawImage1BPP(x + 260 + 16 * 9, y, BMP_SZ_1[dtimer.day & 0x0f], WHITE, BLACK);

    }
    /*
    LCD_DrawImage1BPPZOOM_4(610, 440, BMP_SZ[2], WHITE, BLACK); //2
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 1, 440, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 2, 440, BMP_SZ[(dtimer.year >> 4)&0x0f], WHITE, BLACK); //年
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 3, 440, BMP_SZ[dtimer.year & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 4, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 5, 440, BMP_SZ[(dtimer.month >> 4)&0x0f], WHITE, BLACK); //月
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 6, 440, BMP_SZ[dtimer.month & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 7, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 8, 440, BMP_SZ[(dtimer.day >> 4)&0x0f], WHITE, BLACK); //日
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 9, 440, BMP_SZ[dtimer.day & 0x0f], WHITE, BLACK);
     */
}

#if DrawBus

void BMP_Men_Guan(unsigned int x, unsigned int y, unsigned char color) {
    //门外框
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //门中线
    LCD_DrawRect(x + 36, y + 2, 1, 81, color);
    //门下踏板
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);
    //门左内框
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, color);
    //门右内框
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, color);
}

void BMP_Men_Kai(unsigned int x, unsigned int y, unsigned char color) {
    //门外框
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //门下踏板
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);
    //门中线
    LCD_DrawRect(x + 36, y + 2, 1, 81, BLACK);
    //门左内框
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, BLACK);
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, BLACK);
}

void BMP_BUS(unsigned int x, unsigned int y) {
    unsigned char i;
    disp_rectange(x + 209, y, 178, 2, 10, 2, WHITE);

    LCD_DrawRect(x, y + 8, 471, 2, WHITE); //上外框长
    LCD_DrawRect(x, y + 8, 2, 92, WHITE); //外框高
    LCD_DrawImage1BPP(x, y + 8 + 92, Bmp_Xiahuaxian, WHITE, BLACK); //后下划线
    LCD_DrawRect(x + 54, y + 8 + 105, 471 - 54 + 12, 2, WHITE); //下外框长
    LCD_DrawRect(x + 8, y + 8 + 12, 471 - 8, 2, WHITE); //内框长
    LCD_DrawRect(x + 8, y + 8 + 12, 2, 92 - 12, WHITE); //内框高
    LCD_DrawRect(x + 471 + 10, y + 8 + 105 - 34, 2, 34, WHITE); //车头下长

    LCD_DrawImage1BPP(x + 91, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎1
    LCD_DrawImage1BPP(x + 91 + 227, y + 76, Bmp_Luntai, WHITE, BLACK); //轮胎2

    BMP_Men_Guan(x + 195, y + 27, WHITE);

    BMP_Men_Guan(x + 184 + 215, y + 27, WHITE);

    LCD_DrawImage1BPP(x + 471, y + 6, Bmp_Chetou1, WHITE, BLACK); //车头1
    LCD_DrawImage1BPP(x + 471 + 24, y + 6 + 13, Bmp_Chetou2, WHITE, BLACK); //车头2
    LCD_DrawRect(x + 471 + 12, y + 6 + 13, 12, 2, WHITE);
    LCD_DrawRect(x + 471 + 12, y + 6 + 13 + 5, 12, 2, WHITE);

    //小窗户1
    disp_rectange(x + 8 + 3, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    //小窗户2
    disp_rectange(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 50, 32, 1, WHITE); //散热孔
    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 28 + 50, 32, 1, WHITE); //
    for (i = 0; i < 9; i++) {
        LCD_DrawRect(x + 8 + 3 + 15 + 4 * i, y + 8 + 12 + 3 + 50, 1, 28, WHITE); //
    }

    //中窗户1
    disp_rectange(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //中窗户2
    disp_rectange(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //前窗户1
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //前窗户
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);
}
#endif

#if MODE_FV

void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    static int update_press1 = 0;
    unsigned int press2 = 90; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    static int update_press2 = 0;
    /*if (ADR[1] < 10) press1 = 0;
    else if (ADR[1] <= 52) press1 = (ADR[1] - 10)*0.48;
    else if (ADR[1] <= 124) press1 = (ADR[1] - 52)*0.56 + 20;
    else if (ADR[1] <= 155) press1 = (ADR[1] - 124)*0.65 + 60;
    else press1 = (ADR[1] - 155)*0.69 + 80;*/
    if (ADV[2] < 500)
        press1 = 0;
    else if (ADV[2] > 3000)
        press1 = 100;
    else
        press1 = (ADV[2] - 500) / 25;

    if (ADV[3] < 500)
        press2 = 0;
    else if (ADV[3] > 3000)
        press2 = 100;
    else
        press2 = (ADV[3] - 500) / 25;

    //阻尼
    PRESS[0] = press1;
    if (press1 > update_press1) update_press1 += 2;
    else if (press1 < update_press1)update_press1--;
    else update_press1 = press1;

    if (update_press1 > 60) color = GREEN;
    else color = RED;
    if (update_press1 > 100) update_press1 = 100;
    print_SZ_1(33 - 7 - 16, 410 + 13 - 5 - 10, update_press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380 + 13 - 5 - 10, Bmp_QY1, color, BLACK); //气压1图标
    LCD_DrawRect(38, 108 + 12 - 5 - 10, 44, (260 - update_press1 * 2.6), BLACK); //260/100  
    if (update_press1 % 5 == 0) {
        LCD_DrawRect(38, (368 + 12 - 5 - 10 - update_press1 * 2.6), 44, (update_press1 * 2.6), color);
    } else {
        LCD_DrawRect(38, (368 + 12 - 5 - 10 - update_press1 * 2.6), 44, (update_press1 * 2.6 + 1), color);
    }

    /*if (ADR[2] < 10) press2 = 0;
    else if (ADR[2] <= 52) press2 = (ADR[2] - 10)*0.48;
    else if (ADR[2] <= 124) press2 = (ADR[2] - 52)*0.56 + 20;
    else if (ADR[2] <= 155) press2 = (ADR[2] - 124)*0.65 + 60;
    else press2 = (ADR[2] - 155)*0.69 + 80;*/

    PRESS[1] = press2;
    //阻尼
    if (press2 > update_press2) update_press2 += 2;
    else if (press2 < update_press2)update_press2--;
    else update_press2 = press2;

    if (update_press2 > 60) color = GREEN;
    else color = RED;
    if (update_press2 > 100) update_press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380 + 13 - 5 - 10, Bmp_QY2, color, BLACK); //气压2图标
    print_SZ_1(712 - 7 - 16, 410 + 13 - 5 - 10, update_press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 108 + 12 - 5 - 10, 44, (260 - update_press2 * 2.6), BLACK); //260/100  
    if (update_press2 % 5 == 0) {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6), color);
    } else {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6 + 1), color);
    }

}
#endif

/*void bmp_update(unsigned char num,//位置
        __prog__ const unsigned char *bmp,
        unsigned char flag,//条件
        unsigned char color1,
        unsigned char color2) {
    unsigned char color = GRAY;
    if (flag)
        color = color1;
    else
        color = color2;
    if (color_old[num] != color) {
        color_old[num] = color;
        LCD_DrawImage1BPP(8 + 66 * num, 10 + 59 * (num / 12), bmp, color, BLACK);
    }
}

typedef struct{
    __prog__ const unsigned char *bmp;
    unsigned char flag;
    unsigned char color1;
    unsigned char color2;
}BMP_UPDATE;*/

void disp_BMP_baojing(void) {
    unsigned char color = GRAY;
    /*BMP_UPDATE BmpUpdate[24] = {
        {Bmp_baojing[0], fKL7, YELLOW, GRAY},
        {Bmp_baojing[4], fKL6 && (SPEED > 5), RED, GRAY},
        {Bmp_baojing[3], mKL5, RED, GRAY},
        {Bmp_baojing[7], !fKL4, RED, GRAY},
        {Bmp_baojing[5], CAN_0x181ED0F3.Status2.bit4, RED, GRAY},
        {Bmp_baojing[2], mKL7, RED, GRAY},
        {Bmp_baojing[12], Flash[Flash_500ms].Status, YELLOW, GRAY},
        {Bmp_baojing[9], CAN_0x0CB221EF.Warning1.bit8, RED, GRAY},
        {Bmp_baojing[7], mKL5, RED, GRAY},
        {Bmp_baojing[14], CAN_0x18F214F3.Status5.bit1, RED, GRAY},
        {Bmp_baojing[13], 0, RED, GRAY},
        {Bmp_baojing[1], mKL7, RED, GRAY},
   
        {Bmp_baojing[0], fKL7, YELLOW, GRAY},
        {Bmp_baojing[4], fKL6 && (SPEED > 5), RED, GRAY},
        {Bmp_baojing[3], mKL5, RED, GRAY},
        {Bmp_baojing[7], !fKL4, RED, GRAY},
        {Bmp_baojing[5], CAN_0x181ED0F3.Status2.bit4, RED, GRAY},
        {Bmp_baojing[2], mKL7, RED, GRAY},
        {Bmp_baojing[12], fKL7, YELLOW, GRAY},
        {Bmp_baojing[9], fKL6 && (SPEED > 5), RED, GRAY},
        {Bmp_baojing[7], CAN_0x0CB221EF.Warning1.bit8, RED, GRAY},
        {Bmp_baojing[14], !fKL4, RED, GRAY},
        {Bmp_baojing[13], CAN_0x181ED0F3.Status2.bit4, RED, GRAY},
        {Bmp_baojing[1], !mKL8, RED, GRAY}
        
    };
    
    for(i = 0;i < 24;i++){
        bmp_update(i, BmpUpdate[i].bmp, BmpUpdate[i].flag, BmpUpdate[i].color1, BmpUpdate[i].color2);
    }*/
    if (fKL7)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        //LCD_DrawImage1BPP(8, 10, Bmp_baojing[0], color, BLACK); //ASR
    }

    if (fKL6 && (SPEED > 5))
        color = RED;
    else
        color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        //LCD_DrawImage1BPP(8 + 66, 10, Bmp_baojing[4], color, BLACK); //安全带
    }

    if (rKL15)
        color = RED;
    else
        color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(8 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //后舱门
    }

    if (!fKL4)
        color = RED;
    else
        color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(8 + 66 * 3, 10, Bmp_baojing[7], color, BLACK); //左前刹车片
        LCD_DrawImage1BPP_11x20(8 + 66 * 3 + 17, 10 + 15, BMP_ASIC_11x20[76], color, BLACK);
        print_SZ(8 + 66 * 3 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x181ED0F3.Status2.bit4)
        color = RED;
    else
        color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(8 + 66 * 4, 10, Bmp_baojing[5], color, BLACK); //绝缘报警
    }

    if (rKL1)
        color = RED;
    else
        color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(8 + 66 * 5, 10, Bmp_baojing[2], color, BLACK); //水位

    }

    if (CAN_0x0CFB00D0.Status1.double4 == 0)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        //LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[12], color, BLACK); //门铃
        LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[11], color, BLACK); //高压动力切断
    }

    if (CAN_0x0CB221EF.Warning1.bit8)
        color = RED;
    else
        color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(8 + 66 * 7, 10, Bmp_baojing[9], color, BLACK); //电机故障

    }

    if (!fKL5)
        color = RED;
    else
        color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(8 + 66 * 8, 10, Bmp_baojing[7], color, BLACK); //右前刹车片
        LCD_DrawImage1BPP_11x20(8 + 66 * 8 + 17, 10 + 15, BMP_ASIC_11x20[82], color, BLACK);
        print_SZ(8 + 66 * 8 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x18F214F3.Status5.bit1)
        color = RED;
    else
        color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(8 + 66 * 9, 10, Bmp_baojing[14], color, BLACK); //动力电池故障
    }

    if (IN33)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(8 + 66 * 10, 10, Bmp_baojing[1], color, BLACK); //ABS
    }

    if (IN34)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        //LCD_DrawImage1BPP(8 + 66 * 11, 10, Bmp_baojing[1], color, BLACK); //ABS
    }
    /****************************第二行图片****************************************/
    if (CAN_0x0CFB00D0.Status1.double4 == 0)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        //LCD_DrawImage1BPP(140 + 66 * 0, 74 - 5, Bmp_baojing[11], color, BLACK); //高压动力切断
    }

    /*if (Tradition && !Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chuantong, color, BLACK); //传统
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }

    if (!Tradition && Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chadian, color, BLACK); //插电
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }

    if (!Tradition && !Hybrid && Electric) color = GREEN;
    else color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, color, BLACK); //纯电
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //模式
        }
    }

    if (!Tradition && !Hybrid && !Electric) {
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, BLACK, BLACK); //纯电
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, BLACK, BLACK); //模式
    }*/

    if (!mKL8)
        color = RED;
    else
        color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        //LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[7], color, BLACK); //左后刹车片
        //LCD_DrawImage1BPP_11x20(140 + 66 * 1 + 19, 74 - 5 + 15, BMP_ASIC_11x20[76], color, BLACK);
        //print_SZ(140 + 66 * 1 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (CAN_0x0CFA00D0.Status1.bit8)
        color = GREEN;
    else
        color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        LCD_DrawImage1BPP(140 + 66 * 2, 74 - 5, Bmp_baojing[12], color, BLACK); //电刹车        
    }
    /*if (fKL8 || fKL10 || mKL6)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 - 22, 1, 1, 0, color);
    
    if (mKL8 || rKL9 || rKL7)
        color = RED;
    else 
        color = GRAY;
    print_SZ(140 + 66 * 2 + 54 - 1, 74 - 5 + 18 + 16, 2, 1, 0, color);*/
    ////////////////////////////////////////////////////////////////

    if (CAN_0x0CFA00D0.Status2.bit8)
        color = GREEN;
    else
        color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 3 - 1, 74 + 12 - 5, Bmp_READY, color, BLACK); //ready
    }

    if (0)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        //档位
    }

    if (CAN_0x0CFC00D0.FaultLevel)
        color = RED;
    else
        color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(140 + 66 * 5, 74 - 5, Bmp_baojing[8], color, BLACK); //整车报警
    }

    if (!mKL9)
        color = RED;
    else
        color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        //LCD_DrawImage1BPP(140 + 66 * 6, 74 - 5, Bmp_baojing[7], color, BLACK); //右后摩擦片
        //LCD_DrawImage1BPP_11x20(140 + 66 * 6 + 19, 74 - 5 + 15, BMP_ASIC_11x20[82], color, BLACK);
        //print_SZ(140 + 66 * 6 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (0)
        color = RED;
    else
        color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(140 + 66 * 7, 74 - 5, Bmp_baojing[8], color, BLACK); //整车状态
    }

    if (0)
        color = RED;
    else
        color = GRAY;
    if (color_old[20] != color) {
        color_old[20] = color;
        //LCD_DrawImage1BPP(140 + 66 * 8, 74 - 5, Bmp_baojing[10], color, BLACK); //
    }

}
#if 0

void disp_FONT_baojing(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0; //, Comm_i = 0, Comm_j = 0, FLAG;
    if (alarm_update_flag == 0) { //3S 更新一次 
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBMKLX, YELLOW, BLACK); //前部
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DBMKLX, YELLOW, BLACK); //顶部
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, HBMKLX, YELLOW, BLACK); //后部
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (CAN_0x0C04A1A7.FaultLevel) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DJXTGZ, YELLOW, BLACK); //电机系统故障
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (CAN_0x0C06A1A7.VCUOilPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBWDBJ, YELLOW, BLACK); //油泵温度报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池高温报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUAirPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBWDBJ, YELLOW, BLACK); //气泵温度报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体过压报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //高压电池1故障
                    print_SZ_2(x + 84, y + 8, 1, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUOverSpeed) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //超速报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池组过压报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //高压电池2故障
                    print_SZ_2(x + 84, y + 8, 2, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGG, YELLOW, BLACK); //单体电压过高
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池组欠压报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGD, YELLOW, BLACK); //单体电压过低
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 9:
                al_index = 10;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体欠压报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit3) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGG, YELLOW, BLACK); //SOC过高
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 10:
                al_index = 11;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电枪高温报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Qiang, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 63 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 63 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit4) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGD, YELLOW, BLACK); //SOC过低
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 11:
                al_index = 12;
                if (CAN_0x1818D0F3.BMSFlag1.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCTXGZ, YELLOW, BLACK); //电池通讯故障
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                /*if (VCU_FaultCode == 145 || VCU_FaultCode == 215) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //放电电流报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (CAN_0x18EF4BEF.CAP_offline_Warning == 1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DRLX, YELLOW, BLACK); //电容离线
                    LCD_DrawRect(x + 84, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYQY, YELLOW, BLACK); //总电压欠压
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                /*if (VCU_FaultCode == 146 || VCU_FaultCode == 216) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电电流报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYGY, YELLOW, BLACK); //总电压过压
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                /*if (VCU_FaultCode == 144 || VCU_FaultCode == 214) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //单体电压差异报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JHGZ, YELLOW, BLACK); //均衡故障
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                /*if (VCU_FaultCode == 151 || VCU_FaultCode == 221) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //温度差异报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池升温过高
                    LCD_DrawImageSBPP(x + 42, y + 8, 21, SWGG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC低报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YWBJ, YELLOW, BLACK); //烟雾报警
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                /*if (VCU_FaultCode == 316) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC高报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JYBJ, YELLOW, BLACK); //绝缘报警
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC差异报警
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CDDL, YELLOW, BLACK); //充电电流过大
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                /*if (VCU_FaultCode == 220 || VCU_FaultCode == 150) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池低温报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, FDDL, YELLOW, BLACK); //放电电流过大
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (CAN_0x1818D0F3.BMSFlag3.bit6) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Charging, YELLOW, BLACK); //正在充电，禁止行车    
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                /*if (BAT_COOL_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池冷却系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Lengque, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCWD, YELLOW, BLACK); //电池温度过高
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                /*if (VCU_FaultCode == 310 || VCU_FaultCode == 311 || VCU_FaultCode == 312) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiare, YELLOW, BLACK); //加热故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, WCGD, YELLOW, BLACK); //温差过大
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                /*if (Concentrated_Lubrication.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JZRH, YELLOW, BLACK); //集中润滑报警
                    LCD_DrawImage1BPP(x + 84, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYHS, YELLOW, BLACK); //高压互锁
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                /*if (VCU_FaultCode == 163 || VCU_FaultCode == 233) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit2) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCTB, YELLOW, BLACK); //SOC跳变
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                /*if (BMS_ChargeGun_Comm == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //充电通讯报警
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit3 || CAN_0x181CD0F3.BMSFlag4.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, CNXTBJ, YELLOW, BLACK); //储能系统报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                /*if (fKL8) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yanwu, YELLOW, BLACK); //烟雾报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTYCBJ, YELLOW, BLACK); //单体压差报警
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 28;
                /*if (BMS_Warn_Type == 1 || BMS_Warn_Type == 2 || BMS_Warn_Type == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //动力电池故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCDL, YELLOW, BLACK); //DCDC短路
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                /*if (VCU_FaultCode == 168) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhilu, YELLOW, BLACK); //支路电压差异报警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCGR, YELLOW, BLACK); //DCDC过热
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池火灾预警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK); //DCDC输入欠压
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, QY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                /*if (VCU_FaultCode == 314) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chunnengxitong, YELLOW, BLACK); //储能系统不匹配
                    LCD_DrawRect(x + 147, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK); //DCDC输入过压
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 31:
                al_index = 32;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC跳变
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tiaobian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSC, YELLOW, BLACK); //DCDC输出状态
                    LCD_DrawImage1BPP(x + 44 + 42, y + 8, BMP_Zhuangtai, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 32:
                al_index = 33;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池火灾预警
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK); //气泵输入欠压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, QY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 33:
                al_index = 34;
                if (rKL11 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HCMWG, YELLOW, BLACK); //后舱门未关                   
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 34:
                al_index = 35;
                /*if (!mKL12 && KT_SIGNAL) {
                    LCD_DrawImageSBPP(x, y + 8, 42, ZLBJ, YELLOW, BLACK); //重力报警
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK); //气泵输入过压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 35:
                al_index = 36;
                /*for (; Comm_j < 4;) {
                    for (; Comm_i < 8 && !FLAG; Comm_i++) {
                        if (((BMU_Comm_Status[Comm_j].byte >> Comm_i) & 0x01) == 0)
                            FLAG = 1;
                    }
                    if (Comm_i >= 8) {
                        Comm_i = 0;
                        Comm_j++;
                    }
                    if (FLAG) break;
                }
                if (FLAG) {
                    FLAG = 0;
                    LCD_DrawRect(x, y, 200, 36, BLACK); //清除显示区域
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //第x箱电池离线
                    print_SZ(x + 21, y + 12, Comm_j * 8 + Comm_i, 2, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 21 + 16, y + 8, BMP_Xiang_BMS, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 16 + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 16 + 21 + 42, y + 8, BMP_Lixian, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 16 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
                if (Comm_j >= 4) {
                    Comm_j = 0;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK); //气泵低压电源
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Dianyuan, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 36:
                al_index = 37;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK); //气泵瞬时过流
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 37:
                al_index = 38;
                /*if (BMS_FireFaultCode > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //电池火灾预警故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGR, YELLOW, BLACK); //气泵过热
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 38:
                al_index = 39;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBDL, YELLOW, BLACK); //气泵短路
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 39:
                al_index = 40;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 40:
                al_index = 41;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGY, YELLOW, BLACK); //气泵过载
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 41:
                al_index = 42;
                /*if (VCU_FaultCode >= 170 && VCU_FaultCode <= 179) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_v, YELLOW, BLACK); //VCU通讯故障
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_u, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBQX, YELLOW, BLACK); //气泵缺相
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 42:
                al_index = 43;
                if (LED2 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZMWG, YELLOW, BLACK); //中门未关                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 43:
                al_index = 44;
                if (LED1 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWG, YELLOW, BLACK); //前门未关                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 44:
                al_index = 45;
                /*if (OILDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //油泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK); //气泵输入过压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 45:
                al_index = 46;
                /*if (AIRDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //气泵系统故障
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK); //气泵输入过压
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 46:
                al_index = 47;
                /*if (VCU_Status3.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CLYS, YELLOW, BLACK); //车辆已锁
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK); //气泵低压电源
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Yali, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Dianyuan, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 47:
                al_index = 48;
                /*if (DCDC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8 - 2, BMP_DCDC, YELLOW, BLACK); //DCDC系统故障
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 65 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK); //气泵瞬时过流
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 48:
                al_index = 49;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGR, YELLOW, BLACK); //气泵过热
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 49:
                al_index = 50;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //蓄电池电压低
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 21 + 42 + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawRect(x + 21 + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 50:
                al_index = 51;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBDL, YELLOW, BLACK); //气泵短路
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 51:
                al_index = 52;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGY, YELLOW, BLACK); //气泵过载
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 52:
                al_index = 53;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBQX, YELLOW, BLACK); //气泵缺相
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 53:
                al_index = 54;
                if (fKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWGFKBJ, YELLOW, BLACK); //前门外阀盖开报警
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 54:
                al_index = 55;
                if (fKL10) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMYJFBJ, YELLOW, BLACK); //前门应急阀报警
                    LCD_DrawRect(x + 21 * 7, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 55:
                al_index = 56;
                if (mKL4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, NYJFGKBJ, YELLOW, BLACK); //内应急阀盖开报警
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 56:
                al_index = 57;
                if (mKL6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMCNYJFBJ, YELLOW, BLACK); //前门车内应急阀报警
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 57:
                al_index = 58;
                if (mKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMCNYJFBJ, YELLOW, BLACK); //中门车内应急阀报警
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 58:
                al_index = 59;
                if (rKL7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFGKBJ, YELLOW, BLACK); //中门外应急阀盖开报警
                    //LCD_DrawRect(x + 21 * 10, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 59:
                al_index = 60;
                if (rKL9) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFBJ, YELLOW, BLACK); //中门外应急阀报警
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            default:
                al_index = 0;
                LCD_DrawRect(x, y, 250, 36, BLACK); //清除显示区域
                break;
        }
    }

}
#endif

void updata_Dangwei(unsigned int x, unsigned int y) {//0 : N;  1：D;  2 :R;  3：P
    unsigned char gear = 0;
    if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 0) gear = 0;
    else if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 1) gear = 1;
    else if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 2) gear = 2;
    else if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 3) gear = 3;
    else gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //档位更新 
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = CAN_0x18F212F3.SOC * 0.4;
    /*if(F_DISP && (soc < BMS_SOC * 0.4)){//带增加的效果
        F_DISP=0;
        soc++;
    }
    if(F_DISP && (soc > BMS_SOC * 0.4)){
        F_DISP=0;
        soc--;
    }*/
    if (soc >= 100) soc = 100;
    if (soc > 25) color = GREEN;
    else if (soc > 0 && soc <= 25) color = RED;
    else color = BLACK;
    print_SZ_1(x, y, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(x - 360 + 2, y + 2, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//当soc为100时会出错//此时函数溢出
        LCD_DrawRect((x - 360 + 2 + soc * 3.31), y + 2, (331 - soc * 3.31), 28, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y, float factor) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = 0 * factor;
    if (DCDY >= 800)
        DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //电池电压数值 x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(x - 358, y + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    if (DCDY < 800 && frmID == 0)//当为100时会出错
        LCD_DrawRect((x - 358 + DCDY * 3.31 * 0.125), y + 2, (331 - DCDY * 3.31 * 0.125), 28, BLACK);
}

void updata_DCDL(unsigned int x, unsigned int y, float factor, unsigned int offset) {
    unsigned int DCDL = 100;
    DCDL = 0 * factor;
    if (DCDL < offset) {
        DCDL = offset - DCDL;
        if (DCDL > 500) DCDL = 500;
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ASIC_11x20[45 - 32], WHITE, BLACK);
        if (DCDL > 0 && frmID == 0)
            LCD_DrawRect((225 + 2 + 164 - DCDL * 1.64 * 0.2), 150 + 5 + 2 + 60, (DCDL * 1.64 * 0.2 + 1), 28, GREEN);
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, (164 - DCDL * 1.64 * 0.2), 28, BLACK); // 165/100         
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, 165, 28, BLACK);
        }
    } else {
        DCDL = DCDL - offset;
        if (DCDL > 500) DCDL = 500;
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 4, BMP_ASIC_11x20[43 - 32], WHITE, BLACK);
        print_SZ_1(x, y, DCDL, 3, 0, WHITE);
        if (DCDL > 3 && frmID == 0)
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // 如果长度为0，会出错
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        }
    }
}

void updata_DAT(unsigned int x, unsigned int y, //带符号数值
        unsigned long dat, //显示的数据 
        float factor, //比例
        unsigned int offset,
        unsigned char color1, //颜色
        unsigned char sum, //显示数据的几位
        unsigned char dot //显示小数点的位数       
        ) {//偏移量
    //unsigned char color = WHITE;
    unsigned int DAT = 100;
    DAT = dat * factor;
    if (DAT < offset) {
        print_SZ_1(x, y, offset - DAT, sum, dot, color1);
        LCD_DrawImage1BPP_11x20(x - 16, y + 7, BMP_ASIC_11x20[45], color1, BLACK);
    } else {
        LCD_DrawImage1BPP_11x20(x - 16, y + 7, BMP_ASIC_11x20[43], BLACK, BLACK);
        print_SZ_1(x, y, DAT - offset, sum, dot, color1); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
    }
}

static void frmpage(void (*frame)(unsigned char index, unsigned char page), void (*update)(unsigned char index), unsigned char page) {
    static unsigned char index_page = 1;
    if (f_index == 0) { //只更新一次
        f_index = 1;
        frame(index_page, page);
    } else if (f_index == 1) {
        f_index = 1;
        update(index_page);
    } else {
        f_index = 0;
    }
    if (key_AV) {
        key_AV = 0;
        index_page--;
        f_index = 0;
        if (index_page == 0) {
            index_page = 1;
            frmID = 1;
        }
    }
    if (key_up) {
        key_up = 0;
        index_page++;
        f_index = 0;
        if (index_page > page) {
            index_page = 1;
            frmID = 1;
        }
    }
    if (key_set) {//返回主界面
        key_set = 0;
        frmID = 0;
        f_index = 0;
        Index = 0;
        index_page = 1;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

//主界面

/*********************************************************
//函数名: void mainFrame(void)
//功能: 显示主界面不需要更新的内容,界面格式
//参数: 无
 *********************************************************/

void mainFrame(void) {
    unsigned int i;
    LCD_Clear();
    LCD_DrawRect(0, 0, 800, 1, GRAY);
    LCD_DrawRect(0, 64 - 5, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64 - 5, GRAY);
    }
    //新增加的符号片框架2016/11/1
    LCD_DrawRect(136, 128 - 10, 528, 1, GRAY);
    for (i = 1; i < 10; i++) {
        LCD_DrawRect(70 + 66 * i, 64 - 5, 1, 64 - 5, GRAY);
    }
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }

#if DrawBus
    LCD_DrawRect(0, 430 + 15, 800, 2, GREEN); //底部横线 

    BMP_BUS(150, 150 + 40); //画BUS

    LCD_DrawImage1BPP(170, 145, BMP_SOC, WHITE, BLACK); //SOC

    disp_rectange(225, 150 + 5 - 10, 335, 2, 32, 2, WHITE);
    for (i = 0; i < 3; i++)
        LCD_DrawRect(225 + 83 + 83 * i, 145 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 - 10, 100, 3, 0, WHITE); //100
    LCD_DrawImage1BPP(650, 145, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageString_21x20(10, 365 + 15 - 50 + 10, lc, YELLOW, BLACK); //里程
    LCD_DrawImageString_21x20(125, 318 + 15 + 38 + 8, string_km, WHITE, BLACK); //单位 Km
    LCD_DrawImageString_21x20(125, 318 + 15 + 38 * 2 + 8, string_km, WHITE, BLACK); //单位 Km

    LCD_DrawImageString_21x20(165, 365 + 15 - 50 + 10, gydc, YELLOW, BLACK); //高压电池
    LCD_DrawImage1BPP_11x20(265, 318 + 15 + 38 + 8, BMP_ASIC_11x20['V'], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(265, 318 + 15 + 38 * 2 + 8, BMP_ASIC_11x20['A'], WHITE, BLACK); //A

    LCD_DrawImageString_21x20(295, 365 + 15 - 50 + 10, dtdy, YELLOW, BLACK); //单体电压
    LCD_DrawImage1BPP_11x20(395, 318 + 15 + 38 + 8, BMP_ASIC_11x20['V'], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(395, 318 + 15 + 38 * 2 + 8, BMP_ASIC_11x20['A'], WHITE, BLACK); //V

    LCD_DrawImageString_21x20(420, 365 + 15 - 50 + 10, dtwd, YELLOW, BLACK); //单体温度
    LCD_DrawImageString_21x20(420 + 90, 318 + 15 + 10 + 38, string_t, WHITE, BLACK); //℃
    LCD_DrawImageString_21x20(420 + 90, 318 + 15 + 10 + 38 * 2, string_t, WHITE, BLACK); //℃

    LCD_DrawImageString_21x20(540, 365 + 15 - 50 + 10, dj_kzq, YELLOW, BLACK); //电机/控制器
    LCD_DrawImageString_21x20(640, 365 + 15 - 50 + 10 + 38, string_t, WHITE, BLACK); //℃
    LCD_DrawImageString_21x20(640, 365 + 15 - 50 + 10 + 38 * 2, string_t, WHITE, BLACK); //℃

    LCD_DrawImageString_21x20(670, 365 + 15 - 50 + 10, zs_dtc, YELLOW, BLACK); //转速/DTC
    LCD_DrawImageString_21x20(670 + 100 - 16, 365 + 15 - 50 + 10 + 38, string_rpm, WHITE, BLACK); //Rpm

    //LCD_DrawImageString_21x20(670, 365 + 15 - 50 + 10 + 38 * 2, string_rpm, WHITE, BLACK); //Rpm

    disp_rectange(5, 365 + 15 - 50, 150, 1, 115, 1, GREEN);
    disp_rectange(5 + 140 + 15, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 270 + 15, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 400 + 10, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 530 + 5, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 660 + 5, 365 + 15 - 50, 130 - 5, 1, 115, 1, GREEN);

#elif MODE_FV
    //动力电池电流 电压 SOC 外观
    LCD_DrawRect(0, 430 + 10 + 2, 800, 2, GREEN); //底部横线 

    LCD_DrawImage1BPP(175, 160 + 13 - 5 - 10, BMP_Voltage, WHITE, BLACK); //电压
    disp_rectange(225, 150 + 5 + 13 - 5 - 10, 335, 2, 32, 2, WHITE);
    LCD_DrawRect(225 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 13 - 5 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 13 - 5 - 10, 800, 3, 0 WHITE); //8
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660, 155 + 13 - 5 - 10, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPP(170, 150 + 5 + 60 + 13 - 5 - 10, BMP_SOC, WHITE, BLACK); //SOC
    disp_rectange(225, 150 + 5 + 60 + 13 - 5 - 10, 335, 2, 32, 2, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60 + 13 - 5 - 10, 2, 10, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 13 - 5 - 10, 100, 3, 0, WHITE); //1
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 13 - 5 - 10, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 13 - 5 - 10, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8, ZGDY, WHITE, BLACK); //最高电压
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36, zddy, WHITE, BLACK); //最低电压
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36, BMP_v, WHITE, BLACK); //℃

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8, dcdl, WHITE, BLACK); //电池电流
    LCD_DrawImage1BPP(615 - 22, 260 + 8, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8 + 36, zgwd, WHITE, BLACK); //最高温度
    LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36, BMP_T, WHITE, BLACK); //V

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36 * 2, djkzq, WHITE, BLACK); //电机
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8 + 36 * 2, djzs, WHITE, BLACK); //电机转速
    //LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36 * 2, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(615 - 34, 260 + 8 + 36 * 2, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36 * 3, djwd, WHITE, BLACK); //电机温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 3, BMP_T, WHITE, BLACK); //℃

    //LCD_DrawImageSBPP(225 + 83 + 83 + 2, 260 + 8 + 36 * 3, 63, FDJQH, WHITE, BLACK);
    LCD_DrawImageSBPP(615 - 34, 260 + 8 + 36 * 3, 11, CHAR_LH, WHITE, BLACK); //LH


    LCD_DrawRect(180 - 20, 260, 1, 180 + 2, WHITE);
    LCD_DrawRect(225 + 83 + 83, 260, 1, 180 - 36 + 2, WHITE);
    LCD_DrawRect(615, 260, 1, 180 + 2, WHITE);
    for (i = 0; i < 5; i++) {
        LCD_DrawRect(180 - 20, 260 + 36 * i, 350 + 85 + 20, 1, WHITE);
    }

    //气压柱1外观
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 51, 3, WHITE); //
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 3, 135, WHITE);
    LCD_DrawRect(84, 100 + 13 - 5 - 10, 3, 135, WHITE);

    LCD_DrawRect(33, 235 + 13 - 5 - 10, 3, 135, RED);
    LCD_DrawRect(84, 235 + 13 - 5 - 10, 3, 138, RED);
    LCD_DrawRect(33, 370 + 13 - 5 - 10, 51, 3, RED); //

    //标尺
    LCD_DrawImage1BPP(13 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21 - 5, 225 + 13 - 5 - 10, BMP_SZ_2[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21 - 5, 360 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0

    LCD_DrawImageSBPP(33 - 7 + 32 + 16, 410 + 13 - 5, 11, CHAR_MPA, WHITE, BLACK); //Mpa

    //气压柱2外观
    LCD_DrawRect(712, 100 + 13 - 5 - 10, 51, 3, WHITE);
    LCD_DrawRect(712, 100 + 13 - 5 - 10, 3, 135, WHITE);
    LCD_DrawRect(712 + 51, 100 + 13 - 5 - 10, 3, 135, WHITE);

    LCD_DrawRect(712, 235 + 13 - 5 - 10, 3, 135, RED);
    LCD_DrawRect(712 + 51, 235 + 13 - 5 - 10, 3, 138, RED);
    LCD_DrawRect(712, 370 + 13 - 5 - 10, 51, 3, RED); //

    LCD_DrawImage1BPP(770, 95 + 13 - 5 - 10, BMP_SZ_2[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225 + 13 - 5 - 10, BMP_SZ_2[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0 

    LCD_DrawImageSBPP(712 - 7 + 32 + 16, 410 + 13 - 5, 11, CHAR_MPA, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km

#elif MODE_EV
    LCD_DrawRect(0, 430 + 8, 800, 1, GREEN); //底部横线
    //动力电池电流 电压 SOC 外观
    LCD_DrawImage1BPP(175, 160, BMP_Voltage, WHITE, BLACK); //电压
    LCD_DrawRect(225, 150 + 5, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35, 335, 2, WHITE);
    LCD_DrawRect(225, 155, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 155, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14, 800, 3, 0, WHITE); //800
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14, BMP_SZ[0], WHITE, BLACK); //0   
    LCD_DrawImage1BPP(660, 155, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPP(175, 160 + 60, BMP_Current, WHITE, BLACK); //电流
    LCD_DrawRect(225, 150 + 5 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 83 + 1, 155 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 - 12, 155 - 14 + 60 + 7, 8, 2, WHITE); //-
    print_SZ(225 - 4, 155 - 14 + 60, 500, 3, 0, WHITE); //5
    //LCD_DrawImage1BPP(225 + 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 12, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0

    LCD_DrawImage1BPP(225 + 83 + 83 - 4, 145 + 60 - 4, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawRect(225 + 83 + 83, 155 + 60, 2, 32, WHITE);

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60, 500, 3, 0, WHITE); //5
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60, BMP_A, WHITE, BLACK);

    LCD_DrawImage1BPP(170, 150 + 5 + 60 + 60, BMP_SOC, WHITE, BLACK); //SOC
    LCD_DrawRect(225, 150 + 5 + 60 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 150 + 35 + 60 + 60, 335, 2, WHITE);
    LCD_DrawRect(225, 155 + 60 + 60, 2, 32, WHITE);
    LCD_DrawRect(225 + 83, 145 + 60 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145 + 60 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145 + 60 + 60, 2, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 155 + 60 + 60, 2, 32, WHITE);
    LCD_DrawImage1BPP(225 - 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 + 60 + 60, 100, 3, 0, WHITE); //1
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 - 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    //LCD_DrawImage1BPP(225 + 83 + 83 + 83 + 84 + 4, 155 - 14 + 60 + 60, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPP(660, 155 + 60 + 60, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageString_21x20(60, 365 - 50 + 10 + 8, dtdy, WHITE, BLACK); //单体电压
    LCD_DrawImage1BPP_11x20(15 + 130, 318 + 38 + 8 + 8, BMP_ASIC_11x20[86], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(15 + 130, 318 + 38 * 2 + 8 + 8, BMP_ASIC_11x20[86], WHITE, BLACK); //V

    LCD_DrawImageString_21x20(70 + 550, 365 - 50 + 10 + 8, dtwd, WHITE, BLACK); //单体温度
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //℃
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38 * 2, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageString_21x20(180 - 20 + 2, 365 - 50 + 10 + 8, djkzq, WHITE, BLACK); //电机控制器
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8, BMP_T, WHITE, BLACK); //℃

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 365 - 50 + 10 + 8, djzs, WHITE, BLACK); //电机转速
    LCD_DrawImageString_21x20(615 - 34, 365 - 50 + 10 + 8, char_rpm, WHITE, BLACK); //RPM

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 365 - 50 + 10 + 8 + 38, xdcdy, WHITE, BLACK); //电机转矩
    LCD_DrawImage1BPP_11x20(615 - 22, 365 - 50 + 10 + 8 + 38, BMP_ASIC_11x20[86], WHITE, BLACK); //V


    LCD_DrawImageString_21x20(180 - 20 + 2, 365 - 50 + 10 + 8 + 38, djwd, WHITE, BLACK); //电机温度
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //℃

    //框框
    LCD_DrawRect(55, 365 - 50 + 8, 680, 1, GREEN);
    LCD_DrawRect(55, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(735, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(225 + 83 + 83, 365 - 50 + 8, 1, 65 + 50 - 38, GREEN);
    LCD_DrawRect(615, 365 - 50 + 8, 1, 65 + 50, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8 + 38, 350 + 85 + 20, 1, GREEN);
    LCD_DrawRect(180 - 20, 365 - 50 + 8 + 38 + 38, 350 + 85 + 20, 1, GREEN);

    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //单次里程 TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //单位 Km
#endif

}

void frmMain(void) {
#if DrawBus
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_DAT(700 - 12, 318 + 15 + 38, CAN_0x0CFB00D0.MotorSpeed, 1, 32000, WHITE, 4, 0); //电机转速
        if (CAN_0x0CFC00D0.VCU_DTC == 0)
            print_SZ_1(700 - 8, 318 + 15 + 38 * 2, CAN_0x0CFC00D0.VCU_DTC, 6, 0, WHITE); //故障代码
        else
            print_SZ_1(700 - 8, 318 + 15 + 38 * 2, CAN_0x0CFC00D0.VCU_DTC, 6, 0, RED); //故障代码
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(305, 318 + 15 + 38, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage, 4, 3, WHITE); //单体高电压
        print_SZ_1(305, 318 + 15 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage, 4, 3, WHITE); //单体低电压
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        //门开关图像报警
        if (LED2) {
            BMP_Men_Kai(150 + 195, 190 + 27, RED); //门2开
        } else
            BMP_Men_Guan(150 + 195, 190 + 27, WHITE); //门2关
        if (LED1)
            BMP_Men_Kai(150 + 184 + 215, 190 + 27, RED); //门1开
        else
            BMP_Men_Guan(150 + 184 + 215, 190 + 27, WHITE); //门1关        
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(360 - 15, 440 + 8, timer);
        updata_DAT(540 + 50, 318 + 15 + 38 * 2, CAN_0x0CB321EF.MotorCtrlTemp, 1, 40, WHITE, 3, 0); //电机控制器温度
        updata_DAT(540 + 50, 318 + 15 + 38, CAN_0x0CB321EF.MotorTemp, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DAT(150 + 45, 318 + 15 + 38, CAN_0x18F212F3.Voltage, 0.1, 0, WHITE, 4, 0); //总电压
        updata_DAT(150 + 45, 318 + 15 + 38 * 2, CAN_0x18F212F3.Current, 0.1, 3200, WHITE, 4, 0); //总电流
        //updata_DCDL(150 + 45 + 16, 318 + 15 + 38 * 2); //总电流
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(410 + 50, 318 + 15 + 38, CAN_0x181DD0F3.BMS_MAX_Cell_Temp, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(410 + 50, 318 + 15 + 38 * 2, CAN_0x181DD0F3.BMS_MIN_Cell_Temp, 1, 40, WHITE, 3, 0); //单体低温       
        disp_FONT_baojingNew(2, 447);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if ((LED15 == 1) && (!time_flag)) {//背光开启
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //时钟设置
                if (t == 10) t = 0;
            }
        }

        if (key_set) {
            key_set = 0;
            key_long_set = 0;
            key_up = 0;
            key_AV = 0;
            key_duble = 0;
            if (time_flag == 0) {
                f_index = 0; //更新只更新一次的界面
                frmID = 1;
            }
            time_flag = 0;
        }

        if (key_long_set) {
            key_long_set = 0;
            key_set = 0;
            key_up = 0;
            key_AV = 0;
            time_flag = 1;
        }

        if (key_AV) {
            key_AV = 0;
            key_long_set = 0;
            key_up = 0;
            if (time_flag)
                t_add = 1;
            else t_add = 0;
        }
#if VIDEO
        switch (VIDEO) {
            case 0:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;
                }
                break;
            case 1:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;

                    unsigned char mode = 1; //1,MCU

                    if (AV_CH < VIDEO_NUMBER && !time_flag) AV_CH++;
                    else AV_CH = 0;

                    switch (AV_CH) {
                        case 0: // DAV
                            CS_E = 0; //关闭 
                            mode = 1; //1,MCU
                            break;
                        case 1: //AV1
                            CS_E = 0; //倒车
                            mode = 2; //2,AV1 
                            break;
                        case 2: //AV2  SP2  CJ2
                            CS_E = 1; //打开 
                            CS_A = 1;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 3: //AV2  SP3  CJ3
                            CS_E = 1; //打开 
                            CS_A = 0;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 4: //AV2  SP4  CJ4
                            CS_E = 1; //打开 
                            CS_A = 1;
                            CS_B = 0;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        default:
                            CS_E = 0; //关闭 
                            mode = 1; //1,MCU
                            AV_CH = 0;
                            break;
                    }
                    LCD_CHS(mode);
                }

                //倒车视屏选择使能按键
                /*if ((VCU_Gear == 1) && !R_flag) {//倒挡
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 0; //0+1=1  倒车
                    R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //中门选择使能按键 优先级小于倒车
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//中门开
                        key_AV = 1; //模拟AV开关按一次
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 返回MCU界面
                        M_flag = 0;
                        R_flag = 0;
                    }
                }*/
                break;
            default:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;
                }
                break;
        }
#endif
    }

#elif MODE_FV
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        //updata_DAT(480 + 30, 318 + 13 - 5, MCU_NM, 0.25, 8192, WHITE, 4, 0); //电机转矩
        //updata_DCDL(585, 155 + 13 - 5 + 60);
        updata_DAT(480 + 40 - 10, 260 + 2 + 36 * 0, 0, 8, 1000, WHITE, 4, 0); //电池电流
        //print_SZ_1(480 + 40, 260 + 3 + 36 * 2, 0, 3, 0, WHITE); //电容电压   
        updata_DAT(480 + 40 - 10, 260 + 3 + 36 * 2, 0, 20, 2000, WHITE, 4, 0); //电机转速 
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(313 - 16 * 2, 260 + 2, 0 * 1.5, 4, 3, WHITE); //单体高电压
        print_SZ_1(313 - 16 * 2, 260 + 2 + 36 * 1, 0 * 1.5, 4, 3, WHITE); //单体低电压
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDY(585, 155 + 13 - 5 - 10);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 13, timer);
        updata_DAT(313, 260 + 2 + 36 * 2, 0, 1, 40, WHITE, 3, 0); //电机控制器温度
        updata_DAT(313, 260 + 2 + 36 * 3, 0, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 13 + 60 - 5 - 10);
        updata_QY();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(480 + 40 + 6, 260 + 2 + 36 * 1, 0, 0.2, 50, WHITE, 3, 0); //单体高温       
        disp_FONT_baojingNew(162, 260 + 1 + 36 * 4);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
        print_SZ_1(480 + 40 - 10, 260 + 3 + 36 * 3, 0 * 0.05, 4, 0, WHITE);
        //print_H(480 + 30 -16, 318+15 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        //print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //系统代码
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if ((LED15 == 1) && (!time_flag)) {//背光开启
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //时钟设置
                if (t == 4) t = 0;
            }
        }

        if (key_set) {
            key_set = 0;
            key_long_set = 0;
            key_up = 0;
            key_AV = 0;
            key_duble = 0;
            if (time_flag == 0) {
                f_index = 0; //更新只更新一次的界面
                frmID = 1;
            }
            time_flag = 0;
        }

        if (key_long_set) {
            key_long_set = 0;
            key_set = 0;
            key_up = 0;
            key_AV = 0;
            time_flag = 1;
        }
#if VIDEO
        switch (VIDEO) {
            case 0:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;
                }
                break;
            case 1:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;

                    unsigned char mode = 1; //1,MCU

                    if (AV_CH < VIDEO_NUMBER && !time_flag) AV_CH++;
                    else AV_CH = 0;

                    switch (AV_CH) {
                        case 0: // DAV
                            CS_E = 0; //关闭 
                            mode = 1; //1,MCU
                            break;
                        case 1: //AV1
                            CS_E = 0; //倒车
                            mode = 2; //2,AV1 
                            break;
                        case 2: //AV2  SP2  CJ2
                            CS_E = 1; //打开 
                            CS_A = 1;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 3: //AV2  SP3  CJ3
                            CS_E = 1; //打开 
                            CS_A = 0;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 4: //AV2  SP4  CJ4
                            CS_E = 1; //打开 
                            CS_A = 1;
                            CS_B = 0;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        default:
                            CS_E = 0; //关闭 
                            mode = 1; //1,MCU
                            AV_CH = 0;
                            break;
                    }
                    LCD_CHS(mode);
                }

                //倒车视屏选择使能按键
                /*if ((VCU_Gear == 1) && !R_flag) {//倒挡
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 0; //0+1=1  倒车
                    R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //中门选择使能按键 优先级小于倒车
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//中门开
                        key_AV = 1; //模拟AV开关按一次
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 返回MCU界面
                        M_flag = 0;
                        R_flag = 0;
                    }
                }*/
                break;
            default:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;
                }
                break;
        }
#endif
    }

#elif (MODE_EV && !DrawBus)
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(60, 318 + 8 + 38, CAN_0x18F81A9E.BMS_MAX_Cell_Voltage, 4, 3, WHITE); //单体高
        print_SZ_1(60, 318 + 8 + 38 * 2, CAN_0x18F81A9E.BMS_MIN_Cell_Voltage, 4, 3, WHITE); //单体低
        updata_DAT(313, 318 + 8 + 38, CAN_0x08029F80.DriveMotorTemp, 1, 40, WHITE, 3, 0); //电机温度
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        updata_DAT(480 + 30, 318 + 8, CAN_0x08019F80.VCU_MotorSpeed, 1, 8000, WHITE, 4, 0); //电机转速
        print_SZ_1(480 + 30, 318 + 8 + 38, ADV[0], 3, 1, WHITE); //蓄电池电压
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60, 0.05, 1600);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 5, timer);
        updata_DAT(313, 318 + 8, CAN_0x08029F80.MotorCtrlTemp/*witdh*/, 1, 40, WHITE, 3, 0); //电机控制器温度
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 60 + 60);
        updata_DAT(800 - 150, 318 + 8 + 38, CAN_0x18F8179E.BMS_MAX_Temp/*DS3231_ReadTemp()*/, 1, 40, WHITE, 3, 0); //单体高温
        updata_DAT(800 - 150, 318 + 8 + 38 * 2, CAN_0x18F8179E.BMS_MIN_Temp, 1, 40, WHITE, 3, 0); //单体低温
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(585, 155, 0.1);
        disp_FONT_baojingNew(162, 325 + 38 * 2);
        //LCD_DrawImageString_21x20(162, 325 + 38 * 2,main_page_3,WHITE,BLACK);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 15 + 66 * 4, 70);
        /*print_H(480 + 30 -16, 318 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        if(TCU_code==43) {
            TCU_code=0;  
            TCU_level=0;
        }
        if(TCU_level==3||TCU_level==4)
            color=YELLOW;
        else if(TCU_level==1||TCU_level==2)
            color=RED;
        else color=GREEN;
        print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //系统代码
    } else {
        f_index = 0;*/
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if ((LED15 == 1) && (!time_flag)) {//背光开启
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //时钟设置
                if (t == 4) t = 0;
            }
        }

        if (key_set) {
            key_set = 0;
            key_long_set = 0;
            key_up = 0;
            key_AV = 0;
            key_duble = 0;
            if (time_flag == 0) {
                f_index = 0; //更新只更新一次的界面
                frmID = 1;
            }
            time_flag = 0;
        }

        if (key_long_set) {
            key_long_set = 0;
            key_set = 0;
            key_up = 0;
            key_AV = 0;
            time_flag = 1;
        }
#if VIDEO
        switch (VIDEO) {
            case 0:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;
                }
                break;
            case 1:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;

                    unsigned char mode = 1; //1,MCU

                    if (AV_CH < VIDEO_NUMBER && !time_flag) AV_CH++;
                    else AV_CH = 0;

                    switch (AV_CH) {
                        case 0: // DAV
                            CS_E = 0; //关闭 
                            mode = 1; //1,MCU
                            break;
                        case 1: //AV1
                            CS_E = 0; //倒车
                            mode = 2; //2,AV1 
                            break;
                        case 2: //AV2  SP2  CJ2
                            CS_E = 1; //打开 
                            CS_A = 1;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 3: //AV2  SP3  CJ3
                            CS_E = 1; //打开 
                            CS_A = 0;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 4: //AV2  SP4  CJ4
                            CS_E = 1; //打开 
                            CS_A = 1;
                            CS_B = 0;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        default:
                            CS_E = 0; //关闭 
                            mode = 1; //1,MCU
                            AV_CH = 0;
                            break;
                    }
                    LCD_CHS(mode);
                }

                //倒车视屏选择使能按键
                /*if ((VCU_Gear == 1) && !R_flag) {//倒挡
                    key_AV = 1; //模拟AV开关按一次
                    AV_CH = 0; //0+1=1  倒车
                    R_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 返回MCU界面
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //中门选择使能按键 优先级小于倒车
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//中门开
                        key_AV = 1; //模拟AV开关按一次
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //防止一直进入这个函数，导致key_AV总是置1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 返回MCU界面
                        M_flag = 0;
                        R_flag = 0;
                    }
                }*/
                break;
            default:
                if (key_AV) {
                    key_AV = 0;
                    key_long_set = 0;
                    key_up = 0;
                    key_set = 0;
                    if (time_flag)
                        t_add = 1;
                    else t_add = 0;
                }
                break;
        }
#endif
    }
#endif   
}

/******************************************************/
void ICFrame(unsigned char index, unsigned char page) { //仪表框架
    unsigned char i;
    const unsigned char *ip1[16] = {in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16};
    const unsigned char *ip2[16] = {in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32};
    const unsigned char *ip3[16] = {in33, in34, in35, in36, in37, in38, in39, in40, ad1, ad2, ad3, ad4, ad5, ad6};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/1
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    LCD_DrawImageString_21x20(130 + 200 + 200, 130 - 85 + 4, cantx, WHITE, BLACK); //CAN通讯

    if (index == 1) {
        LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, IC_SYSTEM, WHITE, BLACK); //仪表            
        /***********************仪表开关量采集*********************************/
        /*************************第一列开关***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(35, 75 + 25 * i, ip1[i], WHITE, BLACK);
        }
        /*************************第二列开关***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(285, 75 + 25 * i, ip2[i], WHITE, BLACK);
        }
        /*************************第三列开关***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(535, 75 + 25 * i, ip3[i], WHITE, BLACK);
        }
        for (i = 8; i < 14; i++) {
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //Ω
            LCD_DrawImage1BPP_11x20(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_ASIC_11x20[86], WHITE, BLACK); //V
        }
        LCD_DrawImageString_21x20(505 + 100, 75 + 8 + 25 * 15, bbh, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else {
        if (index == 2) {
            const unsigned char *fp1[16] = {fout1, fout2, fout3, fout4, fout5, fout6, fout7, fout8, fout9, fout10, fout11, fout12, fout13, fout14, fout15, fadd};
            const unsigned char *fp2[16] = {fkl1, fkl2, fkl3, fkl4, fkl5, fkl6, fkl7, fkl8, fkl9, fkl10, fkl11, fkl12, fkl13, fkl14, fkl15, fkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //前
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65], WHITE, BLACK);
            }
            /*************************前模块输出***********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, fp1[i], WHITE, BLACK);
            }
            /***********************前模块开关采集*********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, fp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, fad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, fad2, WHITE, BLACK);
        } else if (index == 3) {
            const unsigned char *mp1[16] = {mout1, mout2, mout3, mout4, mout5, mout6, mout7, mout8, mout9, mout10, mout11, mout12, mout13, mout14, mout15, madd};
            const unsigned char *mp2[16] = {mkl1, mkl2, mkl3, mkl4, mkl5, mkl6, mkl7, mkl8, mkl9, mkl10, mkl11, mkl12, mkl13, mkl14, mkl15, mkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //顶
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65], WHITE, BLACK);
            }
            /*********************顶模块输出***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, mp1[i], WHITE, BLACK);
            }
            /************************顶模块开关*********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, mp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, mad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, mad2, WHITE, BLACK);
        } else if (index == 4) {
            const unsigned char *rp1[16] = {rout1, rout2, rout3, rout4, rout5, rout6, rout7, rout8, rout9, rout10, rout11, rout12, rout13, rout14, rout15, radd};
            const unsigned char *rp2[16] = {rkl1, rkl2, rkl3, rkl4, rkl5, rkl6, rkl7, rkl8, rkl9, rkl10, rkl11, rkl12, rkl13, rkl14, rkl15, rkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //后
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //模块
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //信息
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65], WHITE, BLACK);
            }
            /*********************后模块输出***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, rp1[i], WHITE, BLACK);
            }
            /*********************后模块开关***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, rp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, rad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, rad2, WHITE, BLACK);
        }
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 0, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP_11x20(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 0, BMP_ASIC_11x20['V'], WHITE, BLACK); //V

        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 1, BMP_Omu, WHITE, BLACK); //Ω
        LCD_DrawImage1BPP_11x20(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 1, BMP_ASIC_11x20['V'], WHITE, BLACK); //V

        //版本号
        LCD_DrawImageString_21x20(505 + 100, 75 + 8 + 25 * 15, bbh, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    }
}

void ICUpdate(unsigned char index) {
    unsigned int dump, i;
    unsigned char color, CanStatus = 1;
    if (index == 1) {
        for (i = 0; i < NODE_NUMBER; i++) {
            CanStatus = CanStatus && (NodeCount[i] < CAN_TIME);
        }
        if (CanStatus)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);

        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * (i + 8), ADR[i + 1], 3, 0, YELLOW);
        }
        for (i = 0; i < 6; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * (i + 8), ADV[i + 1] / 10, 3, 2, YELLOW);
        }
        print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * 14, ADV[0], 3, 1, YELLOW);
        dump = sw_input[0].byte + ((unsigned int) (sw_input[1].byte) << 8);
        for (i = 0; i < 16; i++) {
            if (i > 0 && i < 4) {
                if ((dump & 0x01) == 0x01) {//为控火开关
                    LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
                } else {
                    LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
                }
            } else if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = sw_input[2].byte + ((unsigned int) (sw_input[3].byte) << 8);
        for (i = 0; i < 16; i++) {
            /*if (i == 9) {//IN26 为控火开关
                if ((dump & 0x01) == 0x01) {
                    LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
                } else {
                    LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
                }
            } else */
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = sw_input[4].byte;
        for (i = 0; i < 8; i++) {//WAKE1 WAKE2 WAKE3为控火开关
            if (i == 5 || i == 6 || i == 7) {
                if ((dump & 0x01) == 0x01)
                    LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
                else
                    LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else
                LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            dump = dump >> 1;
        }
        //对接日期
        print_SZ_1(535 + 25, 75 + 25 * 15, TIME, 8, 0, YELLOW);
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, VERISON, 3, 2, YELLOW);
    } else if (index == 2) {
        if (Fcan_count == CAN_TIME)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);

        dump = fPOUT.WORDS; //POUT0 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                if (fPF[i] == 0) color = GREEN;
                else if (fPF[i] == 1) color = YELLOW;
                else color = RED;
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], color, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
            if (fpcur[i] / 100 > 10)
                print_SZ(30 + 250, 75 + 6 + 25 * i, fpcur[i] / 100, 3, 1, GREEN); //前模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD雨刮复位信号
        if (fADD)
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        else
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);

        dump = fKEY.BYTES[0]+((unsigned int) (fKEY.BYTES[1]) << 8); //KL1-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = fKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
        //模块模拟信号
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, fADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, fADV[i] / 10, 3, 2, YELLOW);
        }
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, Fversion, 3, 2, YELLOW);
    }

    /*中控模块*/
    if (index == 3) {
        if (Mcan_count == CAN_TIME)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);

        dump = mPOUT.WORDS; //POUT1 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                if (mPF[i] == 0) color = GREEN;
                else if (mPF[i] == 1) color = YELLOW;
                else color = RED;
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], color, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
            if (mpcur[i] / 100 > 10)
                print_SZ(30 + 250, 75 + 6 + 25 * i, mpcur[i] / 100, 3, 1, GREEN); //顶模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD雨刮复位信号
        if (mADD)
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        else
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);

        dump = mKEY.BYTES[0]+((unsigned int) (mKEY.BYTES[1]) << 8); //KL1-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = mKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, mADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, mADV[i] / 10, 3, 2, YELLOW);
        }
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, Mversion, 3, 2, YELLOW);
    }

    /*后控模块*/
    if (index == 4) {
        if (Rcan_count == CAN_TIME)
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, guzhang, RED, BLACK);
        else
            LCD_DrawImageString_21x20(130 + 200 + 200 + 11 + 11 + 11 + 50 + 20, 130 - 85 + 4, zhengchang, GREEN, BLACK);

        dump = rPOUT.WORDS; //POUT1 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                if (rPF[i] == 0) color = GREEN;
                else if (rPF[i] == 1) color = YELLOW;
                else color = RED;
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], color, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
            if (rpcur[i] / 100 > 10)
                print_SZ(30 + 250, 75 + 6 + 25 * i, rpcur[i] / 100, 3, 1, GREEN); //后模块电流
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD雨刮复位信号
        if (rADD)
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        else
            LCD_DrawImage1BPP(30, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);

        dump = rKEY.BYTES[0]+((unsigned int) (rKEY.BYTES[1]) << 8); //KL1-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255 + 150, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = rKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255 + 150, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, rADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, rADV[i] / 10, 3, 2, YELLOW);
        }
        //程序版本号
        print_SZ_1(535 + 200, 75 + 25 * 15, Rversion, 3, 2, YELLOW);
    }
}

/******************************************************/
static void MenuSet(unsigned char color, unsigned char id) {
    color = GREEN;
    if (key_set) {
        key_set = 0;
        if (time_flag == 0) {
            f_index = 0;
            frmID = id;
        }
        time_flag = 0;
    }
}

static void MenuFrame(void) {
    unsigned char color = WHITE;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线   

    LCD_DrawRect(0, 430, 800, 2, YELLOW); //底部横线
    LCD_DrawImageSBPP(130, 130 + 35 * 0, 50, MOTO_SYSTEM, color, BLACK); //电机

    LCD_DrawImageSBPP(130, 130 + 35 * 1, 50, DCDC_SYSTEM, color, BLACK); //DCDC

    LCD_DrawImageSBPP(130, 130 + 35 * 2, 50, AIR_SYSTEM, color, BLACK); //气泵

    LCD_DrawImageSBPP(130, 130 + 35 * 3, 50, OIL_SYSTEM, color, BLACK); //转向

    LCD_DrawImageSBPP(130, 130 + 35 * 4, 50, VCU_SYSTEM, color, BLACK); //整车


    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 0, 50, BMS_SYSTEM, color, BLACK); //BMS

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 1, 50, Battery_SYSTEM, color, BLACK); //电池   

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 2, 50, AC_SYSTEM, color, BLACK); //空调

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 3, 50, IC_SYSTEM, color, BLACK); //仪表

}

#define Menu_Number  9

static void MenuUpdate(void) {
    static unsigned char menu = 1;
    unsigned char color = BLACK, j = 0, i = 0;
    if (key_up) {//箭头向下走
        key_up = 0;
        if (time_flag) {
            t++; //时钟设置
            if (t == 10) t = 0;
        }
        if (!time_flag) {
            menu++;
            if (menu > Menu_Number) {
                menu = 1;
            }
        }
    }

    if (key_AV) {//箭头向上走
        key_AV = 0;
        if (time_flag)
            t_add = 1;
        if (!time_flag) {
            menu--;
            if (menu < 1) {
                menu = Menu_Number;
            }
        }
    }

#if 1
    switch (menu) {
        case 1://菜单1
            MenuSet(GREEN, 2);
            break;
        case 2://菜单2
            MenuSet(GREEN, 3);
            break;
        case 3:
            MenuSet(GREEN, 4);
            break;
        case 4:
            MenuSet(GREEN, 5);
            break;
        case 5:
            MenuSet(GREEN, 10);
            break;
        case 6:
            MenuSet(GREEN, 6);
            break;
        case 7:
            MenuSet(GREEN, 7);
            break;
        case 8:
            MenuSet(GREEN, 8);
            break;
        case 9:
            MenuSet(GREEN, 9);
            break;
        default:
            break;
    }
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 5; i++) {
            if ((j * 5 + i + 1) == menu)
                color = GREEN;
            else
                color = BLACK;
            LCD_DrawImage1BPP(105 + 350 * j, 131 + i * 35, BMP_Choose, color, BLACK);
        }
    }
#endif
}

void frmMenu(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        MenuFrame();
    } else if (f_index == 1) {
        f_index = 1;
        MenuUpdate();
        disp_FONT_baojingNew(2, 440);
        disp_time(330, 440, timer);
    } else {
        f_index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        time_flag = 1;
    }

    if (key_duble) {
        key_duble = 0;
        if (time_flag == 0) {
            f_index = 0;
            frmID = 30;
        }
    }
}

/******************************************************/

void MOTOFrame(unsigned char index, unsigned char page) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {djxtxx1, djxtxx2, djxtxx3, djxtxx4, djxtxx5, djxtxx6, djxtxx7, djxtxx8, djxtxx9, djxtxx10};
    const unsigned char *p1_2[10] = {djxtxx11, djxtxx12, djxtxx13, djxtxx14, djxtxx15, djxtxx16, djxtxx17, djxtxx18, djxtxx19, djxtxx20};
    const unsigned char *p2_1[10] = {djxtxx21, djxtxx22, djxtxx23, djxtxx24, djxtxx25, djxtxx26, djxtxx27, djxtxx28, djxtxx29, djxtxx30};
    const unsigned char *p2_2[10] = {djxtxx31, djxtxx32, djxtxx33, djxtxx34};
    const unsigned char *unit1_1[10] = {string_t, string_t, string_v, string_a, string_a, string_rpm, string_nm,};
    const unsigned char *unit1_2[10] = {0};
    const unsigned char *unit2_1[10] = {0};
    const unsigned char *unit2_2[10] = {0};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, MOTO_SYSTEM, WHITE, BLACK); //电机

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    switch (index) {
        case 1:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit1_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit1_2[i], WHITE, BLACK);
            }
            break;
        case 2:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p2_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit2_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p2_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit2_2[i], WHITE, BLACK);
            }
            break;
        case 3:
            break;
        default:
            break;
    }
}

void MOTOUpdate(unsigned char index) {
    _print_dat print_dat[] = {
        {
            {0, 1},
            {zhengchang, guzhang},
            {GREEN, RED}
        },
        {
            {1, 2, 3, 4},
            {haodian, fadian, tingzhi, zhunbei},
            {GREEN, GREEN, RED, YELLOW}
        },
        {
            {0, 1, 2, 3},
            {zhengchangzhuangtai, yijibaojing, erjibaojing, sanjibaojing},
            {GREEN, WHITE, YELLOW, RED}
        }
    };
    if (index == 1) {
        updata_DAT(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x0CB321EF.MotorCtrlTemp, 1, 40, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x0CB321EF.MotorTemp, 1, 40, WHITE, 3, 0);
        print_SZ_1(82 + 200 + 16, 100 - 8 + 38 * 2, CAN_0x0CB321EF.CtrlVoltage * 0.1, 3, 0, WHITE);
        updata_DAT(82 + 200 + 16 * 1, 100 - 8 + 38 * 3, CAN_0x0CB321EF.CtrlCurrent, 0.1, 1000, WHITE, 3, 0);
        updata_DAT(82 + 200 + 16 * 1, 100 - 8 + 38 * 4, CAN_0x0CB321EF.CtrlACCurrent, 0.1, 1000, WHITE, 3, 0);
        updata_DAT(82 + 200 - 16 * 1, 100 - 8 + 38 * 5, CAN_0x0CB221EF.MotorSpeed, 1, 20000, WHITE, 5, 0);
        updata_DAT(82 + 200 - 16 * 0, 100 - 8 + 38 * 6, CAN_0x0CB221EF.MotorTorque, 0.1, 2000, WHITE, 4, 0);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 7, CAN_0x0CFD00D0.MotorStatus, print_dat[1]);
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 8, CAN_0x0CFD00D0.CarStatus, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 9, CAN_0x0CFD00D0.MotorNum, 3, 0, WHITE);


        print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x0CFD00D0.MotorMode, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x0CB221EF.MCU_DTC, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 2, CAN_0x0CB221EF.Warning2.double4, 3, 0, WHITE);
        print_string(82 + 42 * 6 - 5 + 390, 100 + 38 * 3, CAN_0x0CFD00D0.MotorTemp, print_dat[0]);
        print_string(82 + 42 * 6 - 5 + 390, 100 + 38 * 4, CAN_0x0CFD00D0.MotorCtrlTempWarn, print_dat[0]);
        print_string(82 + 42 * 5.5 - 5 + 390, 100 + 38 * 5, CAN_0x0CF100D0.Warning4.double4, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5 + 390, 100 + 38 * 6, CAN_0x0CF100D0.Warning4.double3, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5 + 390, 100 + 38 * 7, CAN_0x0CF100D0.Warning4.double2, print_dat[2]);
        print_string(82 + 42 * 6 - 5 + 390, 100 + 38 * 8, CAN_0x0CF100D0.Warning4.bit2, print_dat[0]);
        print_string(82 + 42 * 6 - 5 + 390, 100 + 38 * 9, CAN_0x0CF100D0.Warning4.bit1, print_dat[0]);

    } else if (index == 2) {
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 0, CAN_0x0CF100D0.Warning5.double4, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 1, CAN_0x0CF100D0.Warning5.double3, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 2, CAN_0x0CF100D0.Warning5.double2, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 3, CAN_0x0CF100D0.Warning5.double1, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 4, CAN_0x0CF100D0.Warning6.double4, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 5, CAN_0x0CF100D0.Warning6.double3, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 6, CAN_0x0CF100D0.Warning6.double2, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 7, CAN_0x0CF100D0.Warning6.double1, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 8, CAN_0x0CF100D0.Warning7.double4, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5, 100 + 38 * 9, CAN_0x0CF100D0.Warning7.double3, print_dat[2]);

        print_string(82 + 42 * 5.5 - 5 + 390, 100 + 38 * 0, CAN_0x0CF100D0.Warning8.double4, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5 + 390, 100 + 38 * 1, CAN_0x0CF100D0.Warning8.double3, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5 + 390, 100 + 38 * 2, CAN_0x0CF100D0.Warning8.double2, print_dat[2]);
        print_string(82 + 42 * 5.5 - 5 + 390, 100 + 38 * 3, CAN_0x0CF100D0.Warning8.double1, print_dat[2]);
    } else if (index == 3) {
    }
}

/******************************************************/

/******************************************************/

void VCUFrame(unsigned char index, unsigned char page) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {zcxtxx1, zcxtxx2, zcxtxx3, zcxtxx4, zcxtxx5, zcxtxx6, zcxtxx7, zcxtxx8, zcxtxx9, zcxtxx10};
    const unsigned char *p1_2[10] = {zcxtxx11, zcxtxx12, zcxtxx13, zcxtxx14, zcxtxx15, zcxtxx16, zcxtxx17, zcxtxx18, zcxtxx19, zcxtxx20};
    const unsigned char *unit1_1[10] = {string_bai, string_bai};
    const unsigned char *unit1_2[10] = {0};

    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, VCU_SYSTEM, WHITE, BLACK); //vcu

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    switch (index) {
        case 1:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit1_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit1_2[i], WHITE, BLACK);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void VCUUpdate(unsigned char index) {
    _print_dat print_dat[] = {
        {
            {0, 1},
            {wuxiao, youxiao},
            {YELLOW, GREEN}
        },
        {
            {0, 1},
            {duankai, bihe},
            {YELLOW, GREEN}
        },
        {
            {0, 1, 2, 3},
            {zhengchangzhuangtai, yijibaojing, erjibaojing, sanjibaojing},
            {GREEN, WHITE, YELLOW, RED}
        }
    };

    if (index == 1) {
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x0CFA00D0.AcceleratePedalAperture * 0.4, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x0CFA00D0.BrakePedalAperture * 0.4, 3, 0, WHITE);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 2, CAN_0x0CFA00D0.Status1.bit7, print_dat[0]);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 3, CAN_0x0CFA00D0.Status1.bit6, print_dat[0]);
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 4, CAN_0x0CFA00D0.VcuLife, 3, 0, WHITE);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 5, CAN_0x0CFB00D0.Status1.double4, print_dat[1]);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 6, CAN_0x0CFB00D0.Status1.double3, print_dat[1]);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 7, CAN_0x0CFB00D0.Status1.double2, print_dat[1]);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 8, CAN_0x0CFB00D0.Status1.double1, print_dat[1]);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 9, CAN_0x0CFB00D0.Status2.double2, print_dat[1]);

        print_string(82 + 42 * 6 - 5 + 390, 100 + 38 * 0, CAN_0x0CFB00D0.Status2.double1, print_dat[1]);
        print_string(82 + 42 * 6 - 5 + 390, 100 + 38 * 1, CAN_0x0CFB00D0.Status3.bit5, print_dat[0]);
        print_SZ_1(82 + 200 - 16 * 2 + 390, 100 - 8 + 38 * 2, CAN_0x0CFC00D0.VCU_DTC, 6, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 3, CAN_0x0CFC00D0.FaultLevel, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 4, CAN_0x0CFA00D0.Speed >> 8, 3, 0, WHITE);
        print_string(82 + 42 * 5 - 5 + 390, 100 + 38 * 5, CAN_0x0CF100D0.Warning1.double4, print_dat[2]);
        print_string(82 + 42 * 5 - 5 + 390, 100 + 38 * 6, CAN_0x0CF100D0.Warning1.double3, print_dat[2]);
        print_string(82 + 42 * 5 - 5 + 390, 100 + 38 * 7, CAN_0x0CF100D0.Warning1.double2, print_dat[2]);
        print_string(82 + 42 * 5 - 5 + 390, 100 + 38 * 8, CAN_0x0CF100D0.Warning2.double2, print_dat[2]);
        print_string(82 + 42 * 5 - 5 + 390, 100 + 38 * 9, CAN_0x0CF100D0.Warning2.double1, print_dat[2]);
    } else if (index == 2) {

    } else if (index == 3) {
    }
}

/******************************************************/

void DCDCFrame(unsigned char index, unsigned char page) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {dcdcxx1, dcdcxx2, dcdcxx3, dcdcxx4};
    const unsigned char *p1_2[10] = {dcdcxx5, dcdcxx6};
    const unsigned char *unit1_1[10] = {string_v, string_v, string_a};
    const unsigned char *unit1_2[10] = {0};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, DCDC_SYSTEM, WHITE, BLACK); //DCDC系统信息

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    switch (index) {
        case 1:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit1_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit1_2[i], WHITE, BLACK);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void DCDCUpdate(unsigned char index) {
    _print_dat print_dat = {
        {1, 2},
        {gongzuo, tingzhi},
        {GREEN, YELLOW}
    };
    switch (index) {
        case 1:
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x18F86251.DcacVoltage * 0.1, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x18F86251.DcacOutVoltage * 0.1, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 2, CAN_0x18F86251.DcacOutCurrent, 3, 0, WHITE);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 3, CAN_0x18F86251.DcacWorkStatus, print_dat);

            print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 0, CAN_0x18F86251.DcacFaultLevel, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 1, CAN_0x18F86251.DcacFaultCode, 3, 0, WHITE);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

/******************************************************/

void DMQFrame(unsigned char index, unsigned char page) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {qbxtxx1, qbxtxx2, qbxtxx3, qbxtxx4};
    const unsigned char *p1_2[10] = {qbxtxx5, qbxtxx6};
    const unsigned char *unit1_1[10] = {string_v, string_v, string_a};
    const unsigned char *unit1_2[10] = {0};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, AIR_SYSTEM, WHITE, BLACK);

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    switch (index) {
        case 1:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit1_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit1_2[i], WHITE, BLACK);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void DMQUpdate(unsigned char index) {
    _print_dat print_dat = {
        {1, 2},
        {gongzuo, tingzhi},
        {GREEN, YELLOW}
    };
    print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x0C6CD7A4.DcacVoltage * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x0C6CD7A4.DcacOutVoltage * 0.1, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 2, CAN_0x0C6CD7A4.DcacOutCurrent, 3, 0, WHITE);
    print_string(82 + 42 * 6 - 5, 100 + 38 * 3, CAN_0x0C6CD7A4.DcacWorkStatus, print_dat);

    print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 0, CAN_0x0C6CD7A4.DcacFaultLevel, 3, 0, WHITE);
    print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 1, CAN_0x0C6CD7A4.DcacFaultCode, 3, 0, WHITE);
}

/******************************************************/
void DMYFrame(unsigned char index, unsigned char page) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {zxzlxx1, zxzlxx2, zxzlxx3};
    const unsigned char *p1_2[10] = {zxzlxx4, zxzlxx5, zxzlxx6};
    const unsigned char *p2_1[10] = {zxzlxx7, zxzlxx8, zxzlxx9};
    const unsigned char *p2_2[10] = {zxzlxx10, zxzlxx11};
    const unsigned char *unit1_1[10] = {string_v, string_v, string_a};
    const unsigned char *unit1_2[10] = {0};
    const unsigned char *unit2_1[10] = {string_v, string_a};
    const unsigned char *unit2_2[10] = {0};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 15, 130 - 85, 50, OIL_SYSTEM, WHITE, BLACK);

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    switch (index) {
        case 1:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit1_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit1_2[i], WHITE, BLACK);
            }
            break;
        case 2:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p2_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit2_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p2_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit2_2[i], WHITE, BLACK);
            }
            break;
        case 3:
            break;
        default:
            break;
    }
}

void DMYUpdate(unsigned char index) {
    _print_dat print_dat = {
        {1, 2},
        {gongzuo, tingzhi},
        {GREEN, YELLOW}
    };

    if (index == 1) {
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x18F602A0.DcacVoltage * 0.1, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x18F602A0.DcacOutVoltage * 0.1, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 2, CAN_0x18F602A0.DcacOutCurrent, 3, 0, WHITE);

        print_string(82 + 42 * 6 - 5 + 390, 100 + 38 * 0, CAN_0x18F602A0.DcacWorkStatus, print_dat);
        print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 1, CAN_0x18F602A0.DcacFaultLevel, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 2, CAN_0x18F602A0.DcacFaultCode, 3, 0, WHITE);
    } else if (index == 2) {
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x0CF603A1.DcacOutVoltage * 0.1, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x0CF603A1.DcacOutCurrent, 3, 0, WHITE);
        print_string(82 + 42 * 6 - 5, 100 + 38 * 2, CAN_0x0CF603A1.DcacWorkStatus, print_dat);

        print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 0, CAN_0x0CF603A1.DcacFaultLevel, 3, 0, WHITE);
        print_SZ_1(82 + 200 + 16 * 1 + 390, 100 - 8 + 38 * 1, CAN_0x0CF603A1.DcacFaultCode, 3, 0, WHITE);
    }
}

/******************************************************/
void BMSFrame(unsigned char index, unsigned char page) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {bmsxtxx1, bmsxtxx2, bmsxtxx3, bmsxtxx4, bmsxtxx5, bmsxtxx6, bmsxtxx7, bmsxtxx8, bmsxtxx9, bmsxtxx10};
    const unsigned char *p1_2[10] = {bmsxtxx11, bmsxtxx12, bmsxtxx13, bmsxtxx14, bmsxtxx15, bmsxtxx16, bmsxtxx17, bmsxtxx18, bmsxtxx19, bmsxtxx20};
    const unsigned char *p2_1[10] = {bmsxtxx21, bmsxtxx22, bmsxtxx23, bmsxtxx24, bmsxtxx25, bmsxtxx41, bmsxtxx42, bmsxtxx28, bmsxtxx29, bmsxtxx30};
    const unsigned char *p2_2[10] = {bmsxtxx31, bmsxtxx32, bmsxtxx33, bmsxtxx34, bmsxtxx35, bmsxtxx36, bmsxtxx37, bmsxtxx38, bmsxtxx39, bmsxtxx40};
    const unsigned char *p3_1[10] = {bmsxtxx26, bmsxtxx27};
    const unsigned char *p3_2[10] = {0};
    const unsigned char *unit1_1[10] = {string_bai, string_v, string_a, string_kom, 0, string_v, string_v, string_a, string_a};
    const unsigned char *unit1_2[10] = {0};
    const unsigned char *unit2_1[10] = {0, string_v, string_a,};
    const unsigned char *unit2_2[10] = {0};
    const unsigned char *unit3_1[10] = {0};
    const unsigned char *unit3_2[10] = {0};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 24, 130 - 85, 50, BMS_SYSTEM, WHITE, BLACK); //电池

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    switch (index) {
        case 1:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit1_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit1_2[i], WHITE, BLACK);
            }
            break;
        case 2:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p2_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit2_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p2_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit2_2[i], WHITE, BLACK);
            }
            break;
        case 3:
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12, 100 + 38 * i, p3_1[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 - 42, 100 + 38 * i, unit3_1[i], WHITE, BLACK);
            }
            for (i = 0; i < 10; i++) {
                LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p3_2[i], WHITE, BLACK); //
                LCD_DrawImageString_21x20(400 + 390 - 42, 100 + 38 * i, unit3_2[i], WHITE, BLACK);
            }
            for (i = 0; i < 2; i++) {
                if (i == 0) {
                    LCD_DrawImageString_21x20(12 + 390 * i, 100 + 38 * 2, zgdy, WHITE, BLACK);
                    LCD_DrawImageString_21x20(12 + 390 * i, 100 + 38 * 3, zgwd, WHITE, BLACK);
                } else {
                    LCD_DrawImageString_21x20(12 + 390 * i, 100 + 38 * 2, zddy, WHITE, BLACK);
                    LCD_DrawImageString_21x20(12 + 390 * i, 100 + 38 * 3, zdwd, WHITE, BLACK);
                }
                LCD_DrawImage1BPP_11x20(330 + 390 * i - 24 - 63 - 17, 100 + 38 * 2, BMP_ASIC_11x20[86], WHITE, BLACK); //V
                LCD_DrawImageString_21x20(330 + 390 * i - 28 - 63 - 17, 100 + 38 * 3, string_t, WHITE, BLACK); //℃ 
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 8.5 + 5, 100 + 38 * 2, hao, WHITE, BLACK); //号
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 8.5 + 5, 100 + 38 * 3, hao, WHITE, BLACK); //号
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 6.5 + 10, 100 + 38 * 2, xiang, WHITE, BLACK); //箱
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 6.5 + 10, 100 + 38 * 3, xiang, WHITE, BLACK); //箱
            }
            break;
        default:
            break;
    }
}

void BMSUpdate(unsigned char index) {
    unsigned char i;
    _print_dat print_dat[] = {
        {
            {0, 1},
            {zhengchang, guzhang},
            {GREEN, RED}
        },
        {
            {1, 0},
            {youxiao, wuxiao},
            {GREEN, YELLOW}
        }
    };

    switch (index) {
        case 1:
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x18F212F3.SOC * 0.4, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x18F212F3.Voltage * 0.1, 3, 0, WHITE);
            updata_DAT(82 + 200 + 16 * 0, 100 - 8 + 38 * 2, CAN_0x18F212F3.Current, 0.1, 3200, WHITE, 4, 0);
            print_SZ_1(82 + 200 - 16 * 2, 100 - 8 + 38 * 3, CAN_0x18F212F3.InsulationResistance, 6, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 4, CAN_0x18F212F3.BmsLife, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 0, 100 - 8 + 38 * 5, CAN_0x18F213F3.LowDischargeVoltage * 0.1, 4, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 0, 100 - 8 + 38 * 6, CAN_0x18F213F3.HighChargeVoltage * 0.1, 4, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 0, 100 - 8 + 38 * 7, CAN_0x18F213F3.HighChargeCurrent * 0.1, 4, 0, WHITE);
            updata_DAT(82 + 200 + 16 * 0, 100 - 8 + 38 * 8, CAN_0x18F213F3.HighChargeCurrent, 0.1, 6553, WHITE, 4, 0);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 9, CAN_0x18F214F3.BmsFaultCode1, 3, 0, WHITE);


            print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x18F214F3.BmsFaultCode2, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x18F214F3.BmsFaultCode3, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 2, CAN_0x18F214F3.Status3.double4, 3, 0, WHITE);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 3, CAN_0x18F214F3.Status3.bit6, print_dat[0]);
            print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 4, CAN_0x18F214F3.Status5.double4, 3, 0, WHITE);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 5, CAN_0x18F214F3.Status5.bit2, print_dat[1]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 6, CAN_0x18F214F3.Status5.bit1, print_dat[0]);
            print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 7, CAN_0x181ED0F3.BmsFaultLevel, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 8, CAN_0x181ED0F3.BmsFaultNum, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 390 + 16 * 1, 100 - 8 + 38 * 9, CAN_0x181FD0F3.byte[0], 3, 0, WHITE);
            break;
        case 2:
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 0, CAN_0x181FD0F3.byte[1], 3, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 1, CAN_0x181FD0F3.byte[2] * 0.1, 3, 0, WHITE);
            updata_DAT(82 + 200 + 16 * 1, 100 - 8 + 38 * 2, CAN_0x181FD0F3.byte[3], 0.1, 1000, WHITE, 3, 0);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 3, CAN_0x181FD0F3.byte[4] * 0.1, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 16 * 1, 100 - 8 + 38 * 4, CAN_0x181FD0F3.byte[5] * 0.1, 3, 0, WHITE);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 5, CAN_0x181ED0F3.Status2.bit6, print_dat[0]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 6, CAN_0x181ED0F3.Status2.bit7, print_dat[0]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 7, CAN_0x181ED0F3.Status1.bit1, print_dat[0]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 8, CAN_0x181ED0F3.Status1.bit2, print_dat[0]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 9, CAN_0x181ED0F3.Status1.bit3, print_dat[0]);

            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 0, CAN_0x181ED0F3.Status1.bit4, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 1, CAN_0x181ED0F3.Status1.bit5, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 2, CAN_0x181ED0F3.Status1.bit6, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 3, CAN_0x181ED0F3.Status1.bit7, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 4, CAN_0x181ED0F3.Status1.bit8, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 5, CAN_0x181ED0F3.Status2.bit1, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 6, CAN_0x181ED0F3.Status2.bit2, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 7, CAN_0x181ED0F3.Status2.bit3, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 8, CAN_0x181ED0F3.Status2.bit4, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 9, CAN_0x181ED0F3.Status2.bit5, print_dat[0]);
            break;
        case 3:
            for (i = 0; i < 31; i++) {
                if (BmsASIC[i] < 0x20) {
                    BmsASIC[i] = 0x20;
                }
                LCD_DrawImage1BPP_11x20(82 + 120 + 16 * i, 100 - 6 + 38 * 0, BMP_ASIC_11x20[BmsASIC[i]], WHITE, BLACK);
            }
            for (i = 0; i < 17; i++) {
                if (CarASIC[i] < 0x20) {
                    CarASIC[i] = 0x20;
                }
                LCD_DrawImage1BPP_11x20(82 + 120 + 16 * i, 100 - 6 + 38 * 1, BMP_ASIC_11x20[CarASIC[i]], WHITE, BLACK);
            }
            print_SZ_1(82 + 70 - 16 * 3 + 25, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage, 4, 3, WHITE); //电池最高电压
            print_SZ_1(82 + 70 + 16 * 5 + 10, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage_CaseNum, 3, 0, WHITE);
            print_SZ_1(82 + 70 + 16 * 10 + 10, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage_Num, 3, 0, WHITE);

            updata_DAT(82 + 70 - 16 * 1 + 25, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MAX_Cell_Temp, 1, 40, WHITE, 3, 0); //最高温度 
            print_SZ_1(82 + 70 + 16 * 5 + 10, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MAX_Cell_Temp_CaseNum, 3, 0, WHITE);
            print_SZ_1(82 + 70 + 16 * 10 + 10, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MAX_Cell_Temp_Num, 3, 0, WHITE);

            print_SZ_1(82 + 200 + 260 - 16 * 1, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage, 4, 3, WHITE); //电池最高电压
            print_SZ_1(82 + 200 + 260 + 16 * 6, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage_CaseNum, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage_Num, 3, 0, WHITE);

            updata_DAT(82 + 200 + 260 + 16 * 1, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MIN_Cell_Temp, 1, 40, WHITE, 3, 0); //电池最低电压
            print_SZ_1(82 + 200 + 260 + 16 * 6, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MIN_Cell_Temp_CaseNum, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 2, CAN_0x181DD0F3.BMS_MIN_Cell_Temp_Num, 3, 0, WHITE);

            break;
        default:
            break;
    }
}

/******************************************************/
void BATFrame(unsigned char index, unsigned char page) {
    unsigned char i, j;
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 + 24, 130 - 85, 50, Battery_SYSTEM, WHITE, BLACK);

    //分格
    for (i = 0; i < 6; i++) {
        LCD_DrawRect(i * 160, 45 + 70, 1, 360, GREEN);
        LCD_DrawRect(58 + i * 160, 45 + 70, 1, 360, GREEN);
    }
    for (i = 0; i < 11; i++)
        LCD_DrawRect(0, 45 + 70 + i * 36, 800, 1, GREEN);

    LCD_DrawImageString_21x20(50, 90, dcxh, WHITE, BLACK); //电池箱号
    LCD_DrawImage1BPP(50 + 42 + 42 + 21 + 15, 90 - 9, BMP_SZ_1[index], GREEN, BLACK);

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 10; i++) {
            if (i < 9) {//写编号个位
                LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                if (j > 0) {//写编号十位
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                }
            } else {//写最底下一行编号
                LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
            }
            LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
        }
    }

    for (j = 0; j < 1; j++) {
        for (i = 0; i < 6; i++) {
            if (i < 9) {//写编号个位
                LCD_DrawImage1BPP(5 + 16 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                if (j > 0) {//写编号十位
                    LCD_DrawImage1BPP(5 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                }
            } else {//写最底下一行编号
                LCD_DrawImage1BPP(5 + 16 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                LCD_DrawImage1BPP(5 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
            }
            LCD_DrawImage1BPP(5 + 3 + 16 + 16 + 100 + (j + 4) * 160, 46 + 70 + 8 + i * 36, BMP_T, YELLOW, BLACK);
        }
    }

    /*for (i = 0; i < 4; i++) {
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * i, 63, PDHDL, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 105, 100 + 38 * i, BMP_SZ_2[i + 1], WHITE, BLACK);
        LCD_DrawImage1BPP(400 + 320 - 24 - 22, 100 + 38 * i, BMP_a, WHITE, BLACK); //A
    }

    for (i = 0; i < 6; i++) {
        LCD_DrawImageSBPP(82 + 320, 100 + 38 * (i + 4), 63, PDHWD, WHITE, BLACK);
        LCD_DrawImage1BPP(82 + 320 + 105, 100 + 38 * (i + 4), BMP_SZ_2[i + 1], WHITE, BLACK);
        LCD_DrawImage1BPP(400 + 320 - 24 - 22, 100 + 38 * (i + 4), BMP_T, WHITE, BLACK); //℃
    }*/
}

void BATUpdate(unsigned char index) { 
    unsigned char i, j;
    if (index <= 6) {
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 10; i++) {
                if ((BAT_Cell_Voltage[index][j * 10 + i] == 0) || (BAT_Cell_Voltage[index][j * 10 + i] > 10000)) {//(BAT_Cell_Voltage[index - 1][j * 10 + i] < 10000) {
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[index][j * 10 + i], 4, 3, BLACK);
                } else
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[index][j * 10 + i], 4, 3, GREEN); //单体电压
            }
        }
        for (i = 0; i < 6; i++) {
            if ((BAT_Cell_Temp[index][i] == 0xFF) || (BAT_Cell_Temp[index][i] == 0))
                updata_DAT(60 + 4 * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index][i], 1, 40, BLACK, 3, 0);
            else
                updata_DAT(60 + 4 * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index][i], 1, 40, GREEN, 3, 0); //单体温度
        }
    } 
}

/******************************************************/
void ACFrame(unsigned char index, unsigned char page) {
    unsigned char i = 0;
    const unsigned char *p1_1[10] = {ktxtxx1, ktxtxx2, ktxtxx3, ktxtxx4, ktxtxx5, ktxtxx6, ktxtxx7, ktxtxx8, ktxtxx9, ktxtxx10};
    const unsigned char *p1_2[10] = {ktxtxx11, ktxtxx12, ktxtxx13, ktxtxx14, ktxtxx15, ktxtxx16, ktxtxx17, ktxtxx18, ktxtxx19, ktxtxx20};
    const unsigned char *p2_1[10] = {ktxtxx21, ktxtxx22, ktxtxx23, ktxtxx24, ktxtxx25, ktxtxx26, ktxtxx27, ktxtxx28, ktxtxx29, ktxtxx30};
    const unsigned char *p2_2[10] = {ktxtxx31, ktxtxx32, ktxtxx33, ktxtxx34, ktxtxx35, ktxtxx36, ktxtxx37, ktxtxx38, ktxtxx39, ktxtxx40};
    const unsigned char *p3_1[10] = {ktxtxx41, ktxtxx42, ktxtxx43, ktxtxx44, ktxtxx45, ktxtxx46};
    const unsigned char *p3_2[10] = {0};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    LCD_DrawImageSBPP(130 + 200 - 2, 130 - 85, 50, AC_SYSTEM, WHITE, BLACK);

    LCD_DrawRect(10, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390, 90, 1, 380, GREEN);
    LCD_DrawRect(10 + 390 + 390, 90, 1, 380, GREEN);
    for (i = 0; i < 11; i++)
        LCD_DrawRect(10, 90 + i * 38, 780, 1, GREEN);

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/3
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    if (index == 1) {
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(12, 100 + 38 * i, p1_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p1_2[i], WHITE, BLACK); //
        }
    } else if (index == 2) {
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(12, 100 + 38 * i, p2_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p2_2[i], WHITE, BLACK); //
        }
    } else if (index == 3) {
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(12, 100 + 38 * i, p3_1[i], WHITE, BLACK); //
        }
        for (i = 0; i < 10; i++) {
            LCD_DrawImageString_21x20(12 + 390, 100 + 38 * i, p3_2[i], WHITE, BLACK); //
        }
    }

}

void ACUpdate(unsigned char index) {
    _print_dat print_dat[] = {
        {
            {0, 1},
            {zhengchang, guzhang},
            {GREEN, RED}
        },
        {
            {0, 1, 2, 3},
            {zhengchangzhuangtai, yijibaojing, erjibaojing, sanjibaojing},
            {GREEN, WHITE, YELLOW, RED}
        },
        {
            {0, 1},
            {tingzhi, gongzuo},
            {YELLOW, GREEN}
        }
    };
    switch (index) {
        case 1:
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 0, CAN_0x0CF200D0.Warning1.double4, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 1, CAN_0x0CF200D0.Warning1.double3, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 2, CAN_0x0CF200D0.Warning1.double2, print_dat[1]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 3, CAN_0x0CF200D0.Warning1.bit2, print_dat[0]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 4, CAN_0x0CF200D0.Warning1.bit1, print_dat[0]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 5, CAN_0x0CF200D0.Warning2.double4, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 6, CAN_0x0CF200D0.Warning2.double3, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 7, CAN_0x0CF200D0.Warning2.double2, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 8, CAN_0x0CF200D0.Warning2.double1, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 9, CAN_0x0CF200D0.Warning3.double4, print_dat[1]);

            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 0, CAN_0x0CF200D0.Warning3.bit6, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 1, CAN_0x0CF200D0.Warning3.bit5, print_dat[0]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 2, CAN_0x0CF200D0.Warning3.double2, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 3, CAN_0x0CF200D0.Warning3.double1, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 4, CAN_0x0CF200D0.Warning4.double4, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 5, CAN_0x0CF200D0.Warning4.double3, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 6, CAN_0x0CF200D0.Warning4.double2, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 7, CAN_0x0CF200D0.Warning4.double1, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 8, CAN_0x0CF200D0.Warning5.double3, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 9, CAN_0x0CF200D0.Warning5.double2, print_dat[1]);
            break;
        case 2:
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 0, CAN_0x0CF200D0.Warning5.double1, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 1, CAN_0x0CF200D0.Warning6.double4, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 2, CAN_0x0CF200D0.Warning6.double3, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 3, CAN_0x0CF200D0.Warning6.double2, print_dat[1]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 4, CAN_0x0CF200D0.Warning6.bit2, print_dat[0]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 5, CAN_0x0CF200D0.Warning6.bit1, print_dat[0]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 6, CAN_0x0CF200D0.Warning7.double4, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 7, CAN_0x0CF200D0.Warning7.double3, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 8, CAN_0x0CF200D0.Warning7.double2, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 9, CAN_0x0CF200D0.Warning7.double1, print_dat[1]);

            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 0, CAN_0x0CF200D0.Warning8.double1, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 1, CAN_0x0CF300D0.Warning6.double4, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 2, CAN_0x0CF300D0.Warning6.double3, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 3, CAN_0x0CF300D0.Warning6.double2, print_dat[1]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 4, CAN_0x0CF300D0.Warning6.bit2, print_dat[0]);
            print_string(82 + 390 + 42 * 6 - 5, 100 + 38 * 5, CAN_0x0CF300D0.Warning6.bit1, print_dat[0]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 6, CAN_0x0CF300D0.Warning7.double4, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 7, CAN_0x0CF300D0.Warning7.double3, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 8, CAN_0x0CF300D0.Warning7.double2, print_dat[1]);
            print_string(82 + 390 + 42 * 5.5 - 5, 100 + 38 * 9, CAN_0x0CF300D0.Warning7.double1, print_dat[1]);
            break;
        case 3:
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 0, CAN_0x0CF300D0.Warning8.double4, print_dat[1]);
            print_string(82 + 42 * 5.5 - 5, 100 + 38 * 1, CAN_0x0CF300D0.Warning8.double1, print_dat[1]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 2, CAN_0x18F105D0.Warning1.double1, print_dat[2]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 3, CAN_0x18F105D0.Warning2.double1, print_dat[2]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 4, CAN_0x18F105D0.Warning3.double1, print_dat[2]);
            print_string(82 + 42 * 6 - 5, 100 + 38 * 5, CAN_0x18F105D0.Warning4.double1, print_dat[2]);
            break;
        default:
            break;
    }

}
/******************************************************/

/******************************************************/

/*******************************************************************************
//函数名: void frm_speed(void)
//功能:  设置处理
//参数:  全局变量
 ******************************************************************************/
void frm_speed(void) {
    if (f_index == 0) {
        f_index = 1;
        key_set = 0;
        key_duble = 0;
        LCD_Clear();
        LCD_DrawRect(0, 0, 800, 50, BLACK);
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImageString_21x20(360, 30, cssb, GREEN, BLACK); //车速速比

        LCD_DrawImageString_21x20(340 - 40, 145, subi, YELLOW, BLACK); //
        LCD_DrawImageString_21x20(340 - 40, 200, chesu, YELLOW, BLACK); //
        LCD_DrawImageString_21x20(430, 200, string_km1h, GREEN, BLACK); // /h 

    } else if (f_index == 1) {
        f_index = 1;
        print_SZ_2(340 + 32, 145, e_hm_pulse, 3, 0, GREEN); //SPEED_RATIO  
        print_SZ_2(340 + 32, 200, SPEED, 3, 0, GREEN); //Vspeed    
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        frmID = 1;
        f_index = 0;
    }
    if (key_duble) {
        key_duble = 0;
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        key_long_set = 0;
        frmID = 31;
        f_index = 0;
    }
}
#if 0
//密码输入
/*void update_code(unsigned int Tid,unsigned int *ptr){
   unsigned char color=0,color1=0;
   if(Tid==0){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*0+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*0+4,230,BMP_SZ_2[*ptr++],color1,BLACK);

   if(Tid==1){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*1+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*1+4,230,BMP_SZ_2[*ptr++],color1,BLACK);

   if(Tid==2){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*2+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*2+4,230,BMP_SZ_2[*ptr++],color1,BLACK);

   if(Tid==3){ color=RED; color1=RED;  }
   else      { color=GRAY;color1=WHITE;}
   disp_rectange(320+40*3+4,220,4,2,40,2,color);
   LCD_DrawImage1BPP(328+40*3+4,230,BMP_SZ_2[*ptr++],color1,BLACK);   
}

void frm_code(void){  
 static unsigned int  Tid=0;
 static unsigned int  bcd[4]={0,0,0,0};      
  if(f_index==0){
    f_index=1;
    Tid=0;
    key_set =0;
    key_duble=0;
    LCD_DrawRect(0,60,800,365,BLACK);
    LCD_DrawImage1BPP(360,30,BMP_Chesu, GREEN,BLACK);//车速
    LCD_DrawImage1BPP(400,30,BMP_Subi,GREEN,BLACK);//速比
    
    //LCD_DrawImage1BPP(400-40,190,Bmp_srmm,GREEN,BLACK);
    bcd[0]=1;
    bcd[1]=2;   
    bcd[2]=3;
    bcd[3]=4;  
  }else if(f_index==1){
    f_index=1;
    update_code(Tid,&bcd[0]);
  }else{
    f_index=0;
  }
  if(key_set){
    key_set=0;
    if(Tid>=3)Tid=0;
    else      Tid++;
    //验证密码     bcd[2]*1000+ bcd[0]*100+bcd[3]*10+bcd[1];//变换随机数A
    if(single_miles==(unsigned int)(bcd[0]*1000+ bcd[1]*100+bcd[2]*10+bcd[3])){
      frmID=32; 
      f_index=0;    
    }
  }
   if(key_up){
     key_up=0;
    if(Tid<=3){
      if(bcd[Tid]>0) bcd[Tid]--; 
      else           bcd[Tid]=0;
    }else Tid=0;
  }
  if(key_AV){
     key_AV=0;
    if(Tid<=3){
      if(bcd[Tid]<9) bcd[Tid]++; 
      else           bcd[Tid]=9;
    }else Tid=0;
  }
  if(key_duble){
    key_duble=0;
    frmID=0;
    f_index=0;
  }
}
 */
#endif

void disp_system(unsigned char id) {
    unsigned char color = 0;
    if (id == 0) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 140, BMP_SZ_2[1], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 140, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImageString_21x20(336 + 24, 140, sbsz, color, BLACK); //速比设置
    if (id == 1) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 190, BMP_SZ_2[2], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 190, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImageString_21x20(336 + 24, 190, lcsz, color, BLACK); //里程设置

    if (id == 2) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 240, BMP_SZ_2[3], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 240, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImageString_21x20(336 + 24, 240, tuichu, color, BLACK); //退出 
}

void frm_system(void) {
    static unsigned char ID = 0;
    if (f_index == 0) {
        f_index = 1;
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImageString_21x20(360, 30, cssb, GREEN, BLACK); //车速速比
        key_up = 1;
        ID = 11;
    } else if (f_index == 1) {
        f_index = 1;
    } else {
        f_index = 0;
    }
    if (key_up) {
        if (ID >= 2)ID = 0;
        else ID++;
    }
    if (key_AV) {
        if (ID <= 0)ID = 2;
        else ID--;
    }
    if (key_AV || key_up) {
        disp_system(ID);
        key_up = 0;
        key_AV = 0;
    }
    if (key_set) {
        key_set = 0;
        f_index = 0;
        frmID = ID + 32; //菜单号从2---7开始 
        if (frmID >= 34)frmID = 0; //返回主界面 
    }
}

//总里程设置

void update_miles(unsigned int Tid, unsigned int *ptr) {
    unsigned char color = 0, color1 = 0;
    if (Tid == 0) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 0, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 1) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 1, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 2) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 2, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 3) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 3, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 4) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 4, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 5) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 5, 230, BMP_SZ_2[*ptr++], color1, BLACK);

    if (Tid == 6) {
        color = RED;
        color1 = RED;
    } else {
        color = GRAY;
        color1 = WHITE;
    }
    LCD_DrawImage1BPP(268 + 40 * 6, 230, BMP_SZ_2[*ptr++], color1, BLACK);
}

void frm_miles(void) {
    static unsigned int Tid = 0;
    static unsigned int bcd[7] = {0, 0, 0, 0, 0, 0, 0};
    unsigned int i = 0;
    unsigned long tmiles = 0;
    if (f_index == 0) {
        f_index = 1;
        key_up = 0;
        key_AV = 0;
        key_set = 0;
        key_duble = 0;
        LCD_Clear();
        LCD_DrawRect(0, 60, 800, 365, BLACK);

        LCD_DrawImageString_21x20(360, 30, lcsz, GREEN, BLACK); //里程设置

        LCD_DrawImageString_21x20(200 + 60, 185, zjlc, WHITE, BLACK); //总计里程 

        LCD_DrawImageString_21x20(440 + 60, 187, string_km, WHITE, BLACK); //单位 Km 
    } else if (f_index == 1) {
        f_index = 1;
        update_miles(Tid, &bcd[0]);
        print_SZ_2(325 + 60, 185, total_miles / 10, 7, 0, YELLOW);
    } else {
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        if (Tid >= 6)Tid = 0;
        else Tid++;
        tmiles = 0;
        for (i = 0; i < 7; i++) {
            tmiles += bcd[i];
            tmiles = tmiles * 10;
        }
        total_miles = tmiles;
        save_flag = 1;
    }
    if (key_AV) {
        key_AV = 0;
        if (Tid <= 6) {
            if (bcd[Tid] < 9) bcd[Tid]++;
            else bcd[Tid] = 0;
        } else Tid = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
}

void disp_setDATE(void) {
    unsigned int i = 0;
    LCD_DrawImageString_21x20(360, 30, sbsz, GREEN, BLACK); //速比设置

    LCD_DrawImageString_21x20(300 + 60, 170, sbsz, YELLOW, BLACK); //

    LCD_DrawImage1BPP(210 + 60, 205, BMP_SZ_2[1], YELLOW, BLACK); // 
    LCD_DrawImage1BPP(210 + 60, 245, BMP_SZ_2[2], YELLOW, BLACK); //

    for (i = 0; i < 4; i++) {
        LCD_DrawRect(180 + 60, 120 + 35 + 40 * i, 320, 2, GRAY); //横  
    }
    LCD_DrawRect(180 + 60, 120 + 35, 2, 120, GRAY); //竖
    LCD_DrawRect(260 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(380 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(498 + 60, 120 + 35, 2, 120, GRAY); //
}

unsigned int new_pluse = 103;

void update_setDATE(void) {
    unsigned int temp = 0;
    unsigned int x = 180, y = 120;
    print_SZ_2(x + 100 + 60 + 20, y + 85, e_hm_pulse, 3, 0, GREEN); //   
    print_SZ_2(x + 210 + 60 + 30, y + 85, SPEED, 3, 0, GREEN); //车速

    //目标值
    print_SZ_2(x + 100 + 60 + 20, y + 125, new_pluse, 3, 0, RED); // 
    temp = (unsigned int) (SPEED * new_pluse / e_hm_pulse);
    //车速
    print_SZ_2(x + 210 + 60 + 30, y + 125, temp, 3, 0, RED);
}

void frm_setDATE(void) {
    if (f_index == 0) {
        f_index = 1;
        key_up = 0;
        key_AV = 0;
        key_set = 0;
        key_duble = 0;
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        disp_setDATE();
        new_pluse = e_hm_pulse; //
    } else if (f_index == 1) {
        f_index = 1;
        update_setDATE();
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        key_up = 0;
        key_AV = 0;
        e_hm_pulse = new_pluse;
        EEROM_WriteHMPulse(); //写入
        EEROM_ReadHMPulse(); //读出 校验  
    }

    if (key_up) {
        key_up = 0;
        if (new_pluse < 29990)new_pluse += 1;
        else new_pluse = 30000;
    }
    if (key_AV) {
        key_AV = 0;
        if (new_pluse > 20) new_pluse -= 1;
        else new_pluse = 5;
    }
    if (key_long_set) {
        key_long_set = 0;
        key_up = 0;
        key_AV = 0;
        frmID = 0;
        f_index = 0;
    }
}
/******************************************************************************/

/******************************************************************************/

void LCD_Exec(void) {
    switch (frmID) {
        case 0:
            frmMain();
            break;
        case 1:
            frmMenu();
            break;
        case 2:
            frmpage(MOTOFrame, MOTOUpdate, 2);
            break;
        case 3:
            frmpage(DCDCFrame, DCDCUpdate, 1);
            break;
        case 4:
            frmpage(DMQFrame, DMQUpdate, 1);
            break;
        case 5:
            frmpage(DMYFrame, DMYUpdate, 2);
            break;
        case 6:
            frmpage(BMSFrame, BMSUpdate, 3);
            break;
        case 7:
            frmpage(BATFrame, BATUpdate, 5);
            break;
        case 8:
            frmpage(ACFrame, ACUpdate, 3);
            break;
        case 9:
            frmpage(ICFrame, ICUpdate, 4);
            break;
        case 10:
            frmpage(VCUFrame, VCUUpdate, 1);
            break;
        case 30:
            frm_speed();
            break;
        case 31:
            frm_system(); //设置参数信息
            break;
        case 32:
            frm_setDATE(); //设置参数信息
            break;
        case 33:
            frm_miles(); //设置参数信息
            break;
        default:
            key_up = 0;
            key_set = 0;
            key_AV = 0;
            LCD_Clear();
            break;
    }
    if (key_duble) {
        key_duble = 0;
    }
}



