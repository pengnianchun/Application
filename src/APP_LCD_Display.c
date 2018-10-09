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

void print_SZ(unsigned int x, unsigned int y, //��ʾ����λ�� 
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

void print_SZ_1(unsigned int x, unsigned int y, //��ʾ����λ��//��������
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

void print_SZ_2(unsigned int x, unsigned int y, //��ʾ����λ��//��������
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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
void print_SZ_4(unsigned int x, unsigned int y, //��ʾ����λ�� //�Ŵ�4������
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

void disp_rectange(unsigned int x, unsigned int y, //������
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

void print_D(unsigned int x, unsigned int y, //��2������ʾ
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 2;
        dat = dat / 2;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

void print_H(unsigned int x, unsigned int y, //��16������ʾ
        unsigned long dat, //��ʾ������ 
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot, //��ʾС�����λ��
        unsigned char color1) { //��ʾ���ݵ���ɫ
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 16;
        dat = dat / 16;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //����С����  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //����ʾǰ��0
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
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //����ʾǰ��0
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

void LCD_DrawImageSBPP(unsigned int x, unsigned int y, //û�����֣�������0����ģΪBMP_BLANK       
        unsigned char witdh, //������
        __prog__ const unsigned char **img, //�ַ����׵�ַ
        unsigned char fcolor, //����ǰ��ɫ
        unsigned char bcolor //���屳��ɫ
        ) {
    unsigned char i;
    for (i = 0; img[i] != NULL; i++) {
        LCD_DrawImage1BPP(x + witdh * i, y, img[i], fcolor, bcolor);
    }
}

/*void LCD_DrawImageSBPP1(unsigned int x, unsigned int y,
        __prog__ const unsigned char **img, //�ַ����׵�ַ
        unsigned char fcolor, //����ǰ��ɫ
        unsigned char bcolor //���屳��ɫ
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
    const unsigned char *img; //��������
    unsigned char squence;
    unsigned char condition;
    unsigned int position; //��̬������ʾλ��
    unsigned int dat; //�䶯������
    unsigned char sum; //��ʾ���ݵ�λ��
} CAN_WARN_LIST;

#define CAN_LIST_NUMBER 130
CAN_WARN_LIST list[CAN_LIST_NUMBER] = {
    { qbmklx, 0}, //	ǰ��ģ������
    { dbmklx, 1}, //	����ģ������
    { hbmklx, 2}, //	��ģ������
    { zmwg, 3}, //	����δ�ر���
    { qmwg, 4}, //	ǰ��δ�ر���
    { xdcdyd, 5}, //	���ص�ѹ��  
    { chagre, 6}, //	���ڳ�磬��ֹ�г�   
    { hcmwg, 7}, //	�����δ�ر���   
    { clcs, 8}, //	��������
    { qmyjfbj, 9}, //	ǰ��Ӧ��������
    { qmyjfkg, 10}, //	ǰ��Ӧ��������
    { zmyjfbj, 11}, //	����Ӧ��������
    { zmyjfkg, 12}, //	����Ӧ��������
    { zpl, 13}, //	��ƫ��
    { ypl, 14}, //	��ƫ��
    { pzbjyx, 15}, //	��ײԤ����Ч
    { reserve, 16}, //	����
    { reserve, 17}, //	����
    { djxtxx14, 18}, //	��������¶ȱ���
    { djxtxx15, 19}, //	��������������¶ȱ���
    { djxtxx16, 20}, //	���������ĸ��Ӳ������
    { djxtxx17, 21}, //	�����������ѹ������ϱ���
    { djxtxx18, 22}, //	���������ģ�����
    { djxtxx19, 23}, //	���������CANͨ�Ź���
    { djxtxx20, 24}, //	�������������
    { djxtxx21, 25}, //	���������ĸ��Ӳ����ѹ
    { djxtxx22, 26}, //	������������������
    { djxtxx23, 27}, //	��������������Ӳ������
    { djxtxx24, 28}, //	���������ĸ�߹���
    { djxtxx25, 29}, //	����������ۺϹ��ϱ���
    { djxtxx26, 30}, //	������������ȱ���
    { djxtxx27, 31}, //	���������Ƿѹ����
    { djxtxx28, 32}, //	�����������ѹ����
    { djxtxx29, 33}, //	�������
    { djxtxx30, 34}, //	�����ת
    { djxtxx31, 35}, //	�������
    { djxtxx32, 36}, //	������ȱ���
    { djxtxx33, 37}, //	���ȱ�౨��
    { djxtxx34, 38}, //	������䱨��
    { zcxtxx16, 39}, //	�ƶ�̤�����
    { zcxtxx17, 40}, //	����̤�����
    { zcxtxx18, 41}, //	��λ�źŴ��󱨾�
    { zcxtxx19, 42}, //	�ƶ�ϵͳ����
    { zcxtxx20, 43}, //	���ø��±���
    { bmsxtxx28, 44}, //	�¶Ȳ��챨��
    { bmsxtxx29, 45}, //	��ظ��±���
    { bmsxtxx30, 46}, //	���ش���װ�����͹�ѹ����
    { bmsxtxx31, 47}, //	���ش���װ������Ƿѹ����
    { bmsxtxx32, 48}, //	SOC�ͱ���
    { bmsxtxx33, 49}, //	�����ع�ѹ����
    { bmsxtxx34, 50}, //	������Ƿѹ����
    { bmsxtxx35, 51}, //	SOC���߱���
    { bmsxtxx36, 52}, //	SOC���䱨��
    { bmsxtxx37, 53}, //	�ɳ�索��ϵͳ��ƥ�䱨��
    { bmsxtxx38, 54}, //	��ص���һ���Բ��
    { bmsxtxx39, 55}, //	��Ե����
    { bmsxtxx40, 56}, //	���ش���װ�����͹���
    { bmsxtxx41, 57}, //	��ѹ����״̬����
    { bmsxtxx42, 58}, //	��ص��±���
    { ktxtxx1, 59}, //	DCDC�����ѹ
    { ktxtxx2, 60}, //	DCDC�����ѹ
    { ktxtxx3, 61}, //	DCDC����Ƿѹ
    { ktxtxx4, 62}, //	DCDCͨ�Ź���
    { ktxtxx5, 63}, //	DCDC����
    { ktxtxx6, 64}, //	DCDC����
    { ktxtxx7, 65}, //	DCDC��·
    { ktxtxx8, 66}, //	DCDC����
    { ktxtxx9, 67}, //	DCDC����
    { ktxtxx10, 68}, //	����DCAC����Ƿѹ
    { ktxtxx11, 69}, //	����DCACͨ�Ź���
    { ktxtxx12, 70}, //	����DCAC����
    { ktxtxx13, 71}, //	DCDC�ۺϹ���
    { ktxtxx14, 72}, //	����DCAC�ۺϹ���
    { ktxtxx15, 73}, //	����DCAC��·
    { ktxtxx16, 74}, //	����DCAC����
    { ktxtxx17, 75}, //	����DCACȱ��
    { ktxtxx18, 76}, //	����DCAC�����ѹ
    { ktxtxx19, 77}, //	����DCAC�ۺϱ���
    { ktxtxx20, 78}, //	����DCAC����
    { ktxtxx21, 79}, //	����DCAC����
    { ktxtxx22, 80}, //	��ѹ�ͱ�DCACȱ��
    { ktxtxx23, 81}, //	��ѹ�ͱ�DCAC�����ѹ
    { ktxtxx24, 82}, //	��ѹ�ͱ�DCAC����Ƿѹ
    { ktxtxx25, 83}, //	��ѹ�ͱ�DCACͨ�Ź���
    { ktxtxx26, 84}, //	��ѹ�ͱ�DCAC����
    { ktxtxx27, 85}, //	��ѹ�ͱ�DCAC����
    { ktxtxx28, 86}, //	��ѹ�ͱ�DCAC����
    { ktxtxx29, 87}, //	��ѹ�ͱ�DCAC��·
    { ktxtxx30, 88}, //	��ѹ�ͱ�DCAC����
    { ktxtxx31, 89}, //	��ѹ�ͱ�DCAC�ۺϱ���
    { ktxtxx32, 90}, //	��ѹ�ͱ�DCACȱ��
    { ktxtxx33, 91}, //	��ѹ�ͱ�DCAC�����ѹ
    { ktxtxx34, 92}, //	��ѹ�ͱ�DCAC����Ƿѹ
    { ktxtxx35, 93}, //	��ѹ�ͱ�DCACͨ�Ź���
    { ktxtxx36, 94}, //	��ѹ�ͱ�DCAC����
    { ktxtxx37, 95}, //	��ѹ�ͱ�DCAC����
    { ktxtxx38, 96}, //	��ѹ�ͱ�DCAC����
    { ktxtxx39, 97}, //	��ѹ�ͱ�DCAC��·
    { ktxtxx40, 98}, //	��ѹ�ͱ�DCAC����
    { ktxtxx41, 99}, //	��ѹ�ͱ�DCAC����
    { ktxtxx42, 100}, //	��ѹ�ͱ�DCAC�ۺϱ���
    { dcxtxx1, 101}, //	����ܵ�ѹ����
    { dcxtxx2, 102}, //	���µ��²����
    { dcxtxx3, 103}, //	����¶ȹ���
    { dcxtxx4, 104}, //	BMSͨ�Ź���
    { dcxtxx5, 105}, //	BMS����
    { dcxtxx6, 106}, //	�����ѹ����
    { dcxtxx7, 107}, //	�����ѹ����
    { dcxtxx8, 108}, //	SOC����
    { dcxtxx9, 109}, //	����ܵ�ѹ����
    { dcxtxx10, 110}, //	����¶ȹ���
    { dcxtxx11, 111}, //	˲̬�ŵ��������
    { dcxtxx12, 112}, //	��̬�ŵ��������
    { dcxtxx13, 113}, //	����ѹ�����
    { dcxtxx14, 114}, //	��ؾ�Ե����
    { dcxtxx15, 115}, //	˲̬����������
    { dcxtxx16, 116}, //	��̬����������
    { dcxtxx17, 117}, //	SOC����
    { dcxtxx18, 118}, //	��������������
    { dcxtxx19, 119}, //	�¶ȴ���������
    { dcxtxx20, 120}, //	����ۺϱ���
    { zcxtxx21, 121}, //	��������ģʽ
    { zcxtxx22, 122}, //	����ǿ�ƽ�����ģʽ
    {NULL}
};

static void CAN_WARN_DYNAMIC_UPDATE(CAN_WARN_LIST list, unsigned int x, unsigned int y) {//������ʾ��̬�仯������
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

static void print_string(unsigned int x, unsigned int y, //��ʾ����λ�� 
        unsigned char dat, //��ʾ������ 
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

void disp_miles() {//��ʾ���
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
        if (t_add) {//Сʱ���ã�ʮλ
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
        if (t_add) {//Сʱ���ã���λ
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
        if (t_add) {//�������ã�ʮλ
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
        if (t_add) {//�������ã���λ
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
    LCD_DrawImage1BPP(x + 28 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //ð�� 

    if (time_flag) {
        color_back = FLASH;
    } else {
        color_back = 0;
        t = 0;
    }

    /*****************���������ӽ�����ʾ**********************/
    if (frmID == 1 || DrawBus) {
        LCD_DrawImage1BPP(x + 260, y, BMP_SZ_1[2], WHITE, BLACK); //2
        LCD_DrawImage1BPP(x + 260 + 16, y, BMP_SZ_1[0], WHITE, BLACK); //0

        if (color_back && (t == 4)) {
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
            if (t_add) {//�����ã�ʮλ
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
            if (t_add) {//�����ã���λ
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
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 2, 440, BMP_SZ[(dtimer.year >> 4)&0x0f], WHITE, BLACK); //��
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 3, 440, BMP_SZ[dtimer.year & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 4, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 5, 440, BMP_SZ[(dtimer.month >> 4)&0x0f], WHITE, BLACK); //��
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 6, 440, BMP_SZ[dtimer.month & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 7, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 8, 440, BMP_SZ[(dtimer.day >> 4)&0x0f], WHITE, BLACK); //��
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 9, 440, BMP_SZ[dtimer.day & 0x0f], WHITE, BLACK);
     */
}

#if DrawBus

void BMP_Men_Guan(unsigned int x, unsigned int y, unsigned char color) {
    //�����
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //������
    LCD_DrawRect(x + 36, y + 2, 1, 81, color);
    //����̤��
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);
    //�����ڿ�
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, color);
    //�����ڿ�
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, color);
}

void BMP_Men_Kai(unsigned int x, unsigned int y, unsigned char color) {
    //�����
    disp_rectange(x, y, 72, 2, 88, 2, color);
    //����̤��
    LCD_DrawRect(x + 7, y + 83, 57, 2, color);
    LCD_DrawRect(x + 7, y + 83, 1, 3, color);
    LCD_DrawRect(x + 7 + 56, y + 83, 1, 3, color);
    //������
    LCD_DrawRect(x + 36, y + 2, 1, 81, BLACK);
    //�����ڿ�
    disp_rectange(x + 4, y + 3, 30, 2, 78, 2, BLACK);
    disp_rectange(x + 4 + 35, y + 3, 29, 2, 78, 2, BLACK);
}

void BMP_BUS(unsigned int x, unsigned int y) {
    unsigned char i;
    disp_rectange(x + 209, y, 178, 2, 10, 2, WHITE);

    LCD_DrawRect(x, y + 8, 471, 2, WHITE); //�����
    LCD_DrawRect(x, y + 8, 2, 92, WHITE); //����
    LCD_DrawImage1BPP(x, y + 8 + 92, Bmp_Xiahuaxian, WHITE, BLACK); //���»���
    LCD_DrawRect(x + 54, y + 8 + 105, 471 - 54 + 12, 2, WHITE); //�����
    LCD_DrawRect(x + 8, y + 8 + 12, 471 - 8, 2, WHITE); //�ڿ�
    LCD_DrawRect(x + 8, y + 8 + 12, 2, 92 - 12, WHITE); //�ڿ��
    LCD_DrawRect(x + 471 + 10, y + 8 + 105 - 34, 2, 34, WHITE); //��ͷ�³�

    LCD_DrawImage1BPP(x + 91, y + 76, Bmp_Luntai, WHITE, BLACK); //��̥1
    LCD_DrawImage1BPP(x + 91 + 227, y + 76, Bmp_Luntai, WHITE, BLACK); //��̥2

    BMP_Men_Guan(x + 195, y + 27, WHITE);

    BMP_Men_Guan(x + 184 + 215, y + 27, WHITE);

    LCD_DrawImage1BPP(x + 471, y + 6, Bmp_Chetou1, WHITE, BLACK); //��ͷ1
    LCD_DrawImage1BPP(x + 471 + 24, y + 6 + 13, Bmp_Chetou2, WHITE, BLACK); //��ͷ2
    LCD_DrawRect(x + 471 + 12, y + 6 + 13, 12, 2, WHITE);
    LCD_DrawRect(x + 471 + 12, y + 6 + 13 + 5, 12, 2, WHITE);

    //С����1
    disp_rectange(x + 8 + 3, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    //С����2
    disp_rectange(x + 8 + 3 + 34, y + 8 + 12 + 3, 31, 1, 20, 1, WHITE);

    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 50, 32, 1, WHITE); //ɢ�ȿ�
    LCD_DrawRect(x + 8 + 3 + 15, y + 8 + 12 + 3 + 28 + 50, 32, 1, WHITE); //
    for (i = 0; i < 9; i++) {
        LCD_DrawRect(x + 8 + 3 + 15 + 4 * i, y + 8 + 12 + 3 + 50, 1, 28, WHITE); //
    }

    //�д���1
    disp_rectange(x + 8 + 3 + 34 + 34, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //�д���2
    disp_rectange(x + 8 + 3 + 34 + 34 + 56, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //ǰ����1
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 2 + 72 + 10, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);

    //ǰ����
    disp_rectange(x + 8 + 3 + 34 + 34 + 56 * 3 + 72 + 20, y + 8 + 12 + 3, 53, 1, 46, 1, WHITE);
}
#endif

#if MODE_FV

void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100*/
    static int update_press1 = 0;
    unsigned int press2 = 90; /*��ѹ������������0-1.2Mpa ,��ӦΪ0-120 ������0-100*/
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

    //����
    PRESS[0] = press1;
    if (press1 > update_press1) update_press1 += 2;
    else if (press1 < update_press1)update_press1--;
    else update_press1 = press1;

    if (update_press1 > 60) color = GREEN;
    else color = RED;
    if (update_press1 > 100) update_press1 = 100;
    print_SZ_1(33 - 7 - 16, 410 + 13 - 5 - 10, update_press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380 + 13 - 5 - 10, Bmp_QY1, color, BLACK); //��ѹ1ͼ��
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
    //����
    if (press2 > update_press2) update_press2 += 2;
    else if (press2 < update_press2)update_press2--;
    else update_press2 = press2;

    if (update_press2 > 60) color = GREEN;
    else color = RED;
    if (update_press2 > 100) update_press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380 + 13 - 5 - 10, Bmp_QY2, color, BLACK); //��ѹ2ͼ��
    print_SZ_1(712 - 7 - 16, 410 + 13 - 5 - 10, update_press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 108 + 12 - 5 - 10, 44, (260 - update_press2 * 2.6), BLACK); //260/100  
    if (update_press2 % 5 == 0) {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6), color);
    } else {
        LCD_DrawRect(712 + 5, (368 + 12 - 5 - 10 - update_press2 * 2.6), 44, (update_press2 * 2.6 + 1), color);
    }

}
#endif

/*void bmp_update(unsigned char num,//λ��
        __prog__ const unsigned char *bmp,
        unsigned char flag,//����
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
        //LCD_DrawImage1BPP(8 + 66, 10, Bmp_baojing[4], color, BLACK); //��ȫ��
    }

    if (rKL15)
        color = RED;
    else
        color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(8 + 66 * 2, 10, Bmp_baojing[3], color, BLACK); //�����
    }

    if (!fKL4)
        color = RED;
    else
        color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(8 + 66 * 3, 10, Bmp_baojing[7], color, BLACK); //��ǰɲ��Ƭ
        LCD_DrawImage1BPP_11x20(8 + 66 * 3 + 17, 10 + 15, BMP_ASIC_11x20[76], color, BLACK);
        print_SZ(8 + 66 * 3 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x181ED0F3.Status2.bit4)
        color = RED;
    else
        color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(8 + 66 * 4, 10, Bmp_baojing[5], color, BLACK); //��Ե����
    }

    if (rKL1)
        color = RED;
    else
        color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(8 + 66 * 5, 10, Bmp_baojing[2], color, BLACK); //ˮλ

    }

    if (CAN_0x0CFB00D0.Status1.double4 == 0)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        //LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[12], color, BLACK); //����
        LCD_DrawImage1BPP(8 + 66 * 6, 10, Bmp_baojing[11], color, BLACK); //��ѹ�����ж�
    }

    if (CAN_0x0CB221EF.Warning1.bit8)
        color = RED;
    else
        color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(8 + 66 * 7, 10, Bmp_baojing[9], color, BLACK); //�������

    }

    if (!fKL5)
        color = RED;
    else
        color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(8 + 66 * 8, 10, Bmp_baojing[7], color, BLACK); //��ǰɲ��Ƭ
        LCD_DrawImage1BPP_11x20(8 + 66 * 8 + 17, 10 + 15, BMP_ASIC_11x20[82], color, BLACK);
        print_SZ(8 + 66 * 8 + 17 + 11, 10 + 18, 1, 1, 0, color);
    }

    if (CAN_0x18F214F3.Status5.bit1)
        color = RED;
    else
        color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(8 + 66 * 9, 10, Bmp_baojing[14], color, BLACK); //������ع���
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
    /****************************�ڶ���ͼƬ****************************************/
    if (CAN_0x0CFB00D0.Status1.double4 == 0)
        color = YELLOW;
    else
        color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        //LCD_DrawImage1BPP(140 + 66 * 0, 74 - 5, Bmp_baojing[11], color, BLACK); //��ѹ�����ж�
    }

    /*if (Tradition && !Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chuantong, color, BLACK); //��ͳ
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && Hybrid && !Electric) color = GREEN;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chadian, color, BLACK); //���
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && !Hybrid && Electric) color = GREEN;
    else color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        if (color == GREEN) {
            LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, color, BLACK); //����
            LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, color, BLACK); //ģʽ
        }
    }

    if (!Tradition && !Hybrid && !Electric) {
        LCD_DrawImage1BPP(138 + 9, 74, BMP_Chundian, BLACK, BLACK); //����
        LCD_DrawImage1BPP(138 + 9, 74 + 22, BMP_Mode, BLACK, BLACK); //ģʽ
    }*/

    if (!mKL8)
        color = RED;
    else
        color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        //LCD_DrawImage1BPP(140 + 66 * 1, 74 - 5, Bmp_baojing[7], color, BLACK); //���ɲ��Ƭ
        //LCD_DrawImage1BPP_11x20(140 + 66 * 1 + 19, 74 - 5 + 15, BMP_ASIC_11x20[76], color, BLACK);
        //print_SZ(140 + 66 * 1 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (CAN_0x0CFA00D0.Status1.bit8)
        color = GREEN;
    else
        color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        LCD_DrawImage1BPP(140 + 66 * 2, 74 - 5, Bmp_baojing[12], color, BLACK); //��ɲ��        
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
        //��λ
    }

    if (CAN_0x0CFC00D0.FaultLevel)
        color = RED;
    else
        color = GRAY;
    if (color_old[17] != color) {
        color_old[17] = color;
        LCD_DrawImage1BPP(140 + 66 * 5, 74 - 5, Bmp_baojing[8], color, BLACK); //��������
    }

    if (!mKL9)
        color = RED;
    else
        color = GRAY;
    if (color_old[18] != color) {
        color_old[18] = color;
        //LCD_DrawImage1BPP(140 + 66 * 6, 74 - 5, Bmp_baojing[7], color, BLACK); //�Һ�Ħ��Ƭ
        //LCD_DrawImage1BPP_11x20(140 + 66 * 6 + 19, 74 - 5 + 15, BMP_ASIC_11x20[82], color, BLACK);
        //print_SZ(140 + 66 * 6 + 19 + 11, 74 - 5 + 18, 2, 1, 0, color);
    }

    if (0)
        color = RED;
    else
        color = GRAY;
    if (color_old[19] != color) {
        color_old[19] = color;
        //LCD_DrawImage1BPP(140 + 66 * 7, 74 - 5, Bmp_baojing[8], color, BLACK); //����״̬
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
    if (alarm_update_flag == 0) { //3S ����һ�� 
        switch (al_index) {
            case 0:
                al_index = 1;
                if (Fcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBMKLX, YELLOW, BLACK); //ǰ��
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 1:
                al_index = 2;
                if (Mcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DBMKLX, YELLOW, BLACK); //����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 2:
                al_index = 3;
                if (Rcan_count == CAN_TIME) {
                    LCD_DrawImageSBPP(x, y + 8, 42, HBMKLX, YELLOW, BLACK); //��
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (CAN_0x0C04A1A7.FaultLevel) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DJXTGZ, YELLOW, BLACK); //���ϵͳ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (CAN_0x0C06A1A7.VCUOilPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBWDBJ, YELLOW, BLACK); //�ͱ��¶ȱ���
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ظ��±���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUAirPumpTempWarn) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBWDBJ, YELLOW, BLACK); //�����¶ȱ���
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 6:
                al_index = 7;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //��ѹ���1����
                    print_SZ_2(x + 84, y + 8, 1, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x0C06A1A7.VCUOverSpeed) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chaosu, YELLOW, BLACK); //���ٱ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 7:
                al_index = 8;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //������ѹ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Guo, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYDC, YELLOW, BLACK); //��ѹ���2����
                    print_SZ_2(x + 84, y + 8, 2, 1, 0, YELLOW);
                    LCD_DrawImage1BPP(x + 84 + 11, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 11 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGG, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 8:
                al_index = 9;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����Ƿѹ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Zu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Qian, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTDYGD, YELLOW, BLACK); //�����ѹ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 9:
                al_index = 10;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //����Ƿѹ����
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
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGG, YELLOW, BLACK); //SOC����
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 10:
                al_index = 11;
                /*if (0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //���ǹ���±���
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
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCGD, YELLOW, BLACK); //SOC����
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 11:
                al_index = 12;
                if (CAN_0x1818D0F3.BMSFlag1.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCTXGZ, YELLOW, BLACK); //���ͨѶ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                /*if (VCU_FaultCode == 145 || VCU_FaultCode == 215) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Fang, YELLOW, BLACK); //�ŵ��������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                /*if (CAN_0x18EF4BEF.CAP_offline_Warning == 1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DRLX, YELLOW, BLACK); //��������
                    LCD_DrawRect(x + 84, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYQY, YELLOW, BLACK); //�ܵ�ѹǷѹ
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 13:
                al_index = 14;
                /*if (VCU_FaultCode == 146 || VCU_FaultCode == 216) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //����������
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DL, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZDYGY, YELLOW, BLACK); //�ܵ�ѹ��ѹ
                    LCD_DrawRect(x + 42 + 42 + 21, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 14:
                al_index = 15;
                /*if (VCU_FaultCode == 144 || VCU_FaultCode == 214) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dan, YELLOW, BLACK); //�����ѹ���챨��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_Ti, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag1.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JHGZ, YELLOW, BLACK); //�������
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 15:
                al_index = 16;
                /*if (VCU_FaultCode == 151 || VCU_FaultCode == 221) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Wendu, YELLOW, BLACK); //�¶Ȳ��챨��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //������¹���
                    LCD_DrawImageSBPP(x + 42, y + 8, 21, SWGG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 16:
                al_index = 17;
                /*if (0) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC�ͱ���
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YWBJ, YELLOW, BLACK); //������
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 17:
                al_index = 18;
                /*if (VCU_FaultCode == 316) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC�߱���
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Gao, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 21, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 21 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JYBJ, YELLOW, BLACK); //��Ե����
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 18:
                al_index = 19;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImageSBPP(x, y + 8, 11, SOC, YELLOW, BLACK); //SOC���챨��
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CDDL, YELLOW, BLACK); //����������
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                /*if (VCU_FaultCode == 220 || VCU_FaultCode == 150) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ص��±���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Di, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 21, y + 8, BMP_Wendu, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, FDDL, YELLOW, BLACK); //�ŵ��������
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GD, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (CAN_0x1818D0F3.BMSFlag3.bit6) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Charging, YELLOW, BLACK); //���ڳ�磬��ֹ�г�    
                    alarm_update_flag = 1;
                    break;
                }

            case 21:
                al_index = 22;
                /*if (BAT_COOL_FAULT) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //�����ȴϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Lengque, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, DCWD, YELLOW, BLACK); //����¶ȹ���
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GG, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 23;
                /*if (VCU_FaultCode == 310 || VCU_FaultCode == 311 || VCU_FaultCode == 312) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Jiare, YELLOW, BLACK); //���ȹ���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1818D0F3.BMSFlag2.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, WCGD, YELLOW, BLACK); //�²����
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 23:
                al_index = 24;
                /*if (Concentrated_Lubrication.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, JZRH, YELLOW, BLACK); //�����󻬱���
                    LCD_DrawImage1BPP(x + 84, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 84 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, GYHS, YELLOW, BLACK); //��ѹ����
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 24:
                al_index = 25;
                /*if (VCU_FaultCode == 163 || VCU_FaultCode == 233) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //��籨��
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit2) {
                    LCD_DrawRect(x, y, 100, 36, BLACK);
                    LCD_DrawImageSBPP(x, y + 8, 21, SOCTB, YELLOW, BLACK); //SOC����
                    LCD_DrawRect(x + 63 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 25:
                al_index = 26;
                /*if (BMS_ChargeGun_Comm == 1) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chong, YELLOW, BLACK); //���ͨѶ����
                    LCD_DrawImage1BPP(x + 21, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit3 || CAN_0x181CD0F3.BMSFlag4.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, CNXTBJ, YELLOW, BLACK); //����ϵͳ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 26:
                al_index = 27;
                /*if (fKL8) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Yanwu, YELLOW, BLACK); //������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x181CD0F3.BMSFlag4.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DTYCBJ, YELLOW, BLACK); //����ѹ���
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 27:
                al_index = 28;
                /*if (BMS_Warn_Type == 1 || BMS_Warn_Type == 2 || BMS_Warn_Type == 3) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dongli, YELLOW, BLACK); //������ع���
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DC, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCDL, YELLOW, BLACK); //DCDC��·
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 28:
                al_index = 29;
                /*if (VCU_FaultCode == 168) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Zhilu, YELLOW, BLACK); //֧·��ѹ���챨��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_DY, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Chayi, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Baojing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCGR, YELLOW, BLACK); //DCDC����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 29:
                al_index = 30;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ػ���Ԥ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK); //DCDC����Ƿѹ
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, QY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 30:
                al_index = 31;
                /*if (VCU_FaultCode == 314) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Chunnengxitong, YELLOW, BLACK); //����ϵͳ��ƥ��
                    LCD_DrawRect(x + 147, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSR, YELLOW, BLACK); //DCDC�����ѹ
                    LCD_DrawImageSBPP(x + 44 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 31:
                al_index = 32;
                /*if (VCU_FaultCode == 313) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_s, YELLOW, BLACK); //SOC����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_o, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tiaobian, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79A.DCDC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 21, DCDCSC, YELLOW, BLACK); //DCDC���״̬
                    LCD_DrawImage1BPP(x + 44 + 42, y + 8, BMP_Zhuangtai, YELLOW, BLACK); //
                    LCD_DrawRect(x + 44 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 32:
                al_index = 33;
                /*if (BMS_FireWarnLevel == 1 || BMS_FireWarnLevel == 2) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ػ���Ԥ��
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK); //��������Ƿѹ
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, QY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 33:
                al_index = 34;
                if (rKL11 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HCMWG, YELLOW, BLACK); //�����δ��                   
                    LCD_DrawRect(x + 21 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 34:
                al_index = 35;
                /*if (!mKL12 && KT_SIGNAL) {
                    LCD_DrawImageSBPP(x, y + 8, 42, ZLBJ, YELLOW, BLACK); //��������
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSR, YELLOW, BLACK); //���������ѹ
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
                    LCD_DrawRect(x, y, 200, 36, BLACK); //�����ʾ����
                    LCD_DrawImage1BPP(x, y + 8, BMP_Dijige, YELLOW, BLACK); //��x��������
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
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK); //���õ�ѹ��Դ
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
                    LCD_DrawImageSBPP(x, y + 8, 42, QBSSGL, YELLOW, BLACK); //����˲ʱ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 37:
                al_index = 38;
                /*if (BMS_FireFaultCode > 0) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_DC, YELLOW, BLACK); //��ػ���Ԥ������
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_Huozai, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Yujing, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGR, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 38:
                al_index = 39;
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit6) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBDL, YELLOW, BLACK); //���ö�·
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 39:
                al_index = 40;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //���ص�ѹ��
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
                    LCD_DrawImageSBPP(x, y + 8, 42, QBGY, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 41:
                al_index = 42;
                /*if (VCU_FaultCode >= 170 && VCU_FaultCode <= 179) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_v, YELLOW, BLACK); //VCUͨѶ����
                    LCD_DrawImage1BPP(x + 11, y + 8, BMP_c, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11, y + 8, BMP_u, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11, y + 8, BMP_Tongxin, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 11 + 11 + 11 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 11 + 11 + 11 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79D.AIRDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, QBQX, YELLOW, BLACK); //����ȱ��
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 42:
                al_index = 43;
                if (LED2 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, ZMWG, YELLOW, BLACK); //����δ��                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 43:
                al_index = 44;
                if (LED1 && SPEED > 5) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWG, YELLOW, BLACK); //ǰ��δ��                   
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 44:
                al_index = 45;
                /*if (OILDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Youbeng, YELLOW, BLACK); //�ͱ�ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit1) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK); //���������ѹ
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 45:
                al_index = 46;
                /*if (AIRDCAC_FaultCode) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Qibeng, YELLOW, BLACK); //����ϵͳ����
                    LCD_DrawImage1BPP(x + 42, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 42 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit2) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSR, YELLOW, BLACK); //���������ѹ
                    LCD_DrawImageSBPP(x + 42 + 42, y + 8, 21, GY, YELLOW, BLACK); //
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 46:
                al_index = 47;
                /*if (VCU_Status3.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, CLYS, YELLOW, BLACK); //��������
                    LCD_DrawRect(x + 42 + 42, y, 150, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit3) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK); //���õ�ѹ��Դ
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
                    LCD_DrawImage1BPP(x, y + 8 - 2, BMP_DCDC, YELLOW, BLACK); //DCDCϵͳ����
                    LCD_DrawImage1BPP(x + 65, y + 8, BMP_System, YELLOW, BLACK);
                    LCD_DrawImage1BPP(x + 65 + 42, y + 8, BMP_Guzhang, YELLOW, BLACK);
                    LCD_DrawRect(x + 65 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }*/
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit4) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBSSGL, YELLOW, BLACK); //����˲ʱ����
                    LCD_DrawRect(x + 42 + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 48:
                al_index = 49;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit5) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGR, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 49:
                al_index = 50;
                if (BAT24V_count == BAT24_TIME) {
                    LCD_DrawImage1BPP(x, y + 8, BMP_Xu, YELLOW, BLACK); //���ص�ѹ��
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
                    LCD_DrawImageSBPP(x, y + 8, 42, YBDL, YELLOW, BLACK); //���ö�·
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 51:
                al_index = 52;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit7) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBGY, YELLOW, BLACK); //���ù���
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 52:
                al_index = 53;
                if (CAN_0x1801A79B.OILDCAC_FaultCode.bit8) {
                    LCD_DrawImageSBPP(x, y + 8, 42, YBQX, YELLOW, BLACK); //����ȱ��
                    LCD_DrawRect(x + 42 + 42, y, 100, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 53:
                al_index = 54;
                if (fKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMWGFKBJ, YELLOW, BLACK); //ǰ���ⷧ�ǿ�����
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 54:
                al_index = 55;
                if (fKL10) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMYJFBJ, YELLOW, BLACK); //ǰ��Ӧ��������
                    LCD_DrawRect(x + 21 * 7, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 55:
                al_index = 56;
                if (mKL4) {
                    LCD_DrawImageSBPP(x, y + 8, 21, NYJFGKBJ, YELLOW, BLACK); //��Ӧ�����ǿ�����
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 56:
                al_index = 57;
                if (mKL6) {
                    LCD_DrawImageSBPP(x, y + 8, 21, QMCNYJFBJ, YELLOW, BLACK); //ǰ�ų���Ӧ��������
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 57:
                al_index = 58;
                if (mKL8) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMCNYJFBJ, YELLOW, BLACK); //���ų���Ӧ��������
                    LCD_DrawRect(x + 21 * 9, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 58:
                al_index = 59;
                if (rKL7) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFGKBJ, YELLOW, BLACK); //������Ӧ�����ǿ�����
                    //LCD_DrawRect(x + 21 * 10, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 59:
                al_index = 60;
                if (rKL9) {
                    LCD_DrawImageSBPP(x, y + 8, 21, HMWYJFBJ, YELLOW, BLACK); //������Ӧ��������
                    LCD_DrawRect(x + 21 * 8, y, 50, 36, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            default:
                al_index = 0;
                LCD_DrawRect(x, y, 250, 36, BLACK); //�����ʾ����
                break;
        }
    }

}
#endif

void updata_Dangwei(unsigned int x, unsigned int y) {//0 : N;  1��D;  2 :R;  3��P
    unsigned char gear = 0;
    if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 0) gear = 0;
    else if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 1) gear = 1;
    else if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 2) gear = 2;
    else if (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 3) gear = 3;
    else gear = 0;
    LCD_DrawImage1BPP(x, y, BMP_DANGWEI[gear], GREEN, BLACK); //��λ���� 
}

void updata_SOC(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    static unsigned char soc = 100;
    soc = CAN_0x18F212F3.SOC * 0.4;
    /*if(F_DISP && (soc < BMS_SOC * 0.4)){//�����ӵ�Ч��
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
    print_SZ_1(x, y, soc, 3, 0, WHITE); //SOC��ֵ
    LCD_DrawRect(x - 360 + 2, y + 2, (soc * 3.31), 28, color); // 331/100  
    if (soc < 100)//��socΪ100ʱ�����//��ʱ�������
        LCD_DrawRect((x - 360 + 2 + soc * 3.31), y + 2, (331 - soc * 3.31), 28, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y, float factor) {
    //unsigned char color = GREEN;
    unsigned int DCDY = 50;
    DCDY = 0 * factor;
    if (DCDY >= 800)
        DCDY = 800;
    print_SZ_1(x, y, DCDY, 3, 0, WHITE); //��ص�ѹ��ֵ x=120+72+30   y=150+60-2
    if (frmID == 0)
        LCD_DrawRect(x - 358, y + 2, DCDY * 3.31 * 0.125, 28, GREEN); // 331/100  
    if (DCDY < 800 && frmID == 0)//��Ϊ100ʱ�����
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
            LCD_DrawRect(225 + 83 + 83 + 2, 150 + 5 + 2 + 60, (DCDL * 1.65 * 0.2), 28, GREEN); // �������Ϊ0�������
        if (DCDL < 500 && frmID == 0) {
            LCD_DrawRect((225 + 83 + 83 + 2 + DCDL * 1.65 * 0.2), 150 + 5 + 2 + 60, (165 - DCDL * 1.65 * 0.2), 28, BLACK);
            LCD_DrawRect(225 + 2, 150 + 5 + 2 + 60, 164, 28, BLACK);
        }
    }
}

void updata_DAT(unsigned int x, unsigned int y, //��������ֵ
        unsigned long dat, //��ʾ������ 
        float factor, //����
        unsigned int offset,
        unsigned char color1, //��ɫ
        unsigned char sum, //��ʾ���ݵļ�λ
        unsigned char dot //��ʾС�����λ��       
        ) {//ƫ����
    //unsigned char color = WHITE;
    unsigned int DAT = 100;
    DAT = dat * factor;
    if (DAT < offset) {
        print_SZ_1(x, y, offset - DAT, sum, dot, color1);
        LCD_DrawImage1BPP_11x20(x - 16, y + 7, BMP_ASIC_11x20[45], color1, BLACK);
    } else {
        LCD_DrawImage1BPP_11x20(x - 16, y + 7, BMP_ASIC_11x20[43], BLACK, BLACK);
        print_SZ_1(x, y, DAT - offset, sum, dot, color1); //��ص�����ֵ x=135+180+50+100+20+20   y=150+60-2
    }
}

static void frmpage(void (*frame)(unsigned char index, unsigned char page), void (*update)(unsigned char index), unsigned char page) {
    static unsigned char index_page = 1;
    if (f_index == 0) { //ֻ����һ��
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
    if (key_set) {//����������
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

//������

/*********************************************************
//������: void mainFrame(void)
//����: ��ʾ�����治��Ҫ���µ�����,�����ʽ
//����: ��
 *********************************************************/

void mainFrame(void) {
    unsigned int i;
    LCD_Clear();
    LCD_DrawRect(0, 0, 800, 1, GRAY);
    LCD_DrawRect(0, 64 - 5, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64 - 5, GRAY);
    }
    //�����ӵķ���Ƭ���2016/11/1
    LCD_DrawRect(136, 128 - 10, 528, 1, GRAY);
    for (i = 1; i < 10; i++) {
        LCD_DrawRect(70 + 66 * i, 64 - 5, 1, 64 - 5, GRAY);
    }
    //ÿ�ν��������棬����Ƭ��ɫ���ǻ�ɫ����������ֻ���һ���ϵ���ʾ��ɫ����ҳ��Ͳ���ʾ��ɫ
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }

#if DrawBus
    LCD_DrawRect(0, 430 + 15, 800, 2, GREEN); //�ײ����� 

    BMP_BUS(150, 150 + 40); //��BUS

    LCD_DrawImage1BPP(170, 145, BMP_SOC, WHITE, BLACK); //SOC

    disp_rectange(225, 150 + 5 - 10, 335, 2, 32, 2, WHITE);
    for (i = 0; i < 3; i++)
        LCD_DrawRect(225 + 83 + 83 * i, 145 - 10, 2, 10, WHITE);

    LCD_DrawImage1BPP(225 - 4, 155 - 14 - 10, BMP_SZ[0], WHITE, BLACK); //0

    print_SZ(225 + 83 + 83 + 83 + 84 - 12, 155 - 14 - 10, 100, 3, 0, WHITE); //100
    LCD_DrawImage1BPP(650, 145, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImageString_21x20(10, 365 + 15 - 50 + 10, lc, YELLOW, BLACK); //���
    LCD_DrawImageString_21x20(125, 318 + 15 + 38 + 8, string_km, WHITE, BLACK); //��λ Km
    LCD_DrawImageString_21x20(125, 318 + 15 + 38 * 2 + 8, string_km, WHITE, BLACK); //��λ Km

    LCD_DrawImageString_21x20(165, 365 + 15 - 50 + 10, gydc, YELLOW, BLACK); //��ѹ���
    LCD_DrawImage1BPP_11x20(265, 318 + 15 + 38 + 8, BMP_ASIC_11x20['V'], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(265, 318 + 15 + 38 * 2 + 8, BMP_ASIC_11x20['A'], WHITE, BLACK); //A

    LCD_DrawImageString_21x20(295, 365 + 15 - 50 + 10, dtdy, YELLOW, BLACK); //�����ѹ
    LCD_DrawImage1BPP_11x20(395, 318 + 15 + 38 + 8, BMP_ASIC_11x20['V'], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(395, 318 + 15 + 38 * 2 + 8, BMP_ASIC_11x20['A'], WHITE, BLACK); //V

    LCD_DrawImageString_21x20(420, 365 + 15 - 50 + 10, dtwd, YELLOW, BLACK); //�����¶�
    LCD_DrawImageString_21x20(420 + 90, 318 + 15 + 10 + 38, string_t, WHITE, BLACK); //��
    LCD_DrawImageString_21x20(420 + 90, 318 + 15 + 10 + 38 * 2, string_t, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(540, 365 + 15 - 50 + 10, dj_kzq, YELLOW, BLACK); //���/������
    LCD_DrawImageString_21x20(640, 365 + 15 - 50 + 10 + 38, string_t, WHITE, BLACK); //��
    LCD_DrawImageString_21x20(640, 365 + 15 - 50 + 10 + 38 * 2, string_t, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(670, 365 + 15 - 50 + 10, zs_dtc, YELLOW, BLACK); //ת��/DTC
    LCD_DrawImageString_21x20(670 + 100 - 16, 365 + 15 - 50 + 10 + 38, string_rpm, WHITE, BLACK); //Rpm

    //LCD_DrawImageString_21x20(670, 365 + 15 - 50 + 10 + 38 * 2, string_rpm, WHITE, BLACK); //Rpm

    disp_rectange(5, 365 + 15 - 50, 150, 1, 115, 1, GREEN);
    disp_rectange(5 + 140 + 15, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 270 + 15, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 400 + 10, 365 + 15 - 50, 125 - 5, 1, 115, 1, GREEN);
    disp_rectange(5 + 530 + 5, 365 + 15 - 50, 125, 1, 115, 1, GREEN);
    disp_rectange(5 + 660 + 5, 365 + 15 - 50, 130 - 5, 1, 115, 1, GREEN);

#elif MODE_FV
    //������ص��� ��ѹ SOC ���
    LCD_DrawRect(0, 430 + 10 + 2, 800, 2, GREEN); //�ײ����� 

    LCD_DrawImage1BPP(175, 160 + 13 - 5 - 10, BMP_Voltage, WHITE, BLACK); //��ѹ
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

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8, ZGDY, WHITE, BLACK); //��ߵ�ѹ
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8, BMP_v, WHITE, BLACK); //V

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36, zddy, WHITE, BLACK); //��͵�ѹ
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36, BMP_v, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8, dcdl, WHITE, BLACK); //��ص���
    LCD_DrawImage1BPP(615 - 22, 260 + 8, BMP_a, WHITE, BLACK); //A

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8 + 36, zgwd, WHITE, BLACK); //����¶�
    LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36, BMP_T, WHITE, BLACK); //V

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36 * 2, djkzq, WHITE, BLACK); //���
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 260 + 8 + 36 * 2, djzs, WHITE, BLACK); //���ת��
    //LCD_DrawImage1BPP(615 - 22, 260 + 8 + 36 * 2, BMP_v, WHITE, BLACK); //V
    LCD_DrawImage1BPP(615 - 34, 260 + 8 + 36 * 2, BMP_RPM, WHITE, BLACK); //RPM

    LCD_DrawImageString_21x20(180 - 20 + 2, 260 + 8 + 36 * 3, djwd, WHITE, BLACK); //����¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 260 + 8 + 36 * 3, BMP_T, WHITE, BLACK); //��

    //LCD_DrawImageSBPP(225 + 83 + 83 + 2, 260 + 8 + 36 * 3, 63, FDJQH, WHITE, BLACK);
    LCD_DrawImageSBPP(615 - 34, 260 + 8 + 36 * 3, 11, CHAR_LH, WHITE, BLACK); //LH


    LCD_DrawRect(180 - 20, 260, 1, 180 + 2, WHITE);
    LCD_DrawRect(225 + 83 + 83, 260, 1, 180 - 36 + 2, WHITE);
    LCD_DrawRect(615, 260, 1, 180 + 2, WHITE);
    for (i = 0; i < 5; i++) {
        LCD_DrawRect(180 - 20, 260 + 36 * i, 350 + 85 + 20, 1, WHITE);
    }

    //��ѹ��1���
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 51, 3, WHITE); //
    LCD_DrawRect(33, 100 + 13 - 5 - 10, 3, 135, WHITE);
    LCD_DrawRect(84, 100 + 13 - 5 - 10, 3, 135, WHITE);

    LCD_DrawRect(33, 235 + 13 - 5 - 10, 3, 135, RED);
    LCD_DrawRect(84, 235 + 13 - 5 - 10, 3, 138, RED);
    LCD_DrawRect(33, 370 + 13 - 5 - 10, 51, 3, RED); //

    //���
    LCD_DrawImage1BPP(13 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21 - 5, 95 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21 - 5, 225 + 13 - 5 - 10, BMP_SZ_2[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21 - 5, 360 + 13 - 5 - 10, BMP_SZ_2[0], RED, BLACK); //0

    LCD_DrawImageSBPP(33 - 7 + 32 + 16, 410 + 13 - 5, 11, CHAR_MPA, WHITE, BLACK); //Mpa

    //��ѹ��2���
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
    ������ʾ�ĸ�ʽΪ:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //������� TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km

#elif MODE_EV
    LCD_DrawRect(0, 430 + 8, 800, 1, GREEN); //�ײ�����
    //������ص��� ��ѹ SOC ���
    LCD_DrawImage1BPP(175, 160, BMP_Voltage, WHITE, BLACK); //��ѹ
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

    LCD_DrawImage1BPP(175, 160 + 60, BMP_Current, WHITE, BLACK); //����
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

    LCD_DrawImageString_21x20(60, 365 - 50 + 10 + 8, dtdy, WHITE, BLACK); //�����ѹ
    LCD_DrawImage1BPP_11x20(15 + 130, 318 + 38 + 8 + 8, BMP_ASIC_11x20[86], WHITE, BLACK); //V
    LCD_DrawImage1BPP_11x20(15 + 130, 318 + 38 * 2 + 8 + 8, BMP_ASIC_11x20[86], WHITE, BLACK); //V

    LCD_DrawImageString_21x20(70 + 550, 365 - 50 + 10 + 8, dtwd, WHITE, BLACK); //�����¶�
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //��
    LCD_DrawImage1BPP(800 - 90, 318 + 10 + 8 + 38 * 2, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(180 - 20 + 2, 365 - 50 + 10 + 8, djkzq, WHITE, BLACK); //���������
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8, BMP_T, WHITE, BLACK); //��

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 365 - 50 + 10 + 8, djzs, WHITE, BLACK); //���ת��
    LCD_DrawImageString_21x20(615 - 34, 365 - 50 + 10 + 8, char_rpm, WHITE, BLACK); //RPM

    LCD_DrawImageString_21x20(225 + 83 + 83 + 2, 365 - 50 + 10 + 8 + 38, xdcdy, WHITE, BLACK); //���ת��
    LCD_DrawImage1BPP_11x20(615 - 22, 365 - 50 + 10 + 8 + 38, BMP_ASIC_11x20[86], WHITE, BLACK); //V


    LCD_DrawImageString_21x20(180 - 20 + 2, 365 - 50 + 10 + 8 + 38, djwd, WHITE, BLACK); //����¶�
    LCD_DrawImage1BPP(225 + 83 + 83 - 22, 365 - 50 + 10 + 8 + 38, BMP_T, WHITE, BLACK); //��

    //���
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
    ������ʾ�ĸ�ʽΪ:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440 + 3 + 13 - 5, Bmp_ODO, YELLOW, BLACK); //�ۼ���� ODO  

    LCD_DrawImage1BPP(210 - 16, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440 + 3 + 13 - 5, Bmp_TRIP, YELLOW, BLACK); //������� TRIF

    LCD_DrawImage1BPP(404 + 336 + 30, 440 + 10, BMP_HZ_KM, WHITE, BLACK); //��λ Km
#endif

}

void frmMain(void) {
#if DrawBus
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_DAT(700 - 12, 318 + 15 + 38, CAN_0x0CFB00D0.MotorSpeed, 1, 32000, WHITE, 4, 0); //���ת��
        if (CAN_0x0CFC00D0.VCU_DTC == 0)
            print_SZ_1(700 - 8, 318 + 15 + 38 * 2, CAN_0x0CFC00D0.VCU_DTC, 6, 0, WHITE); //���ϴ���
        else
            print_SZ_1(700 - 8, 318 + 15 + 38 * 2, CAN_0x0CFC00D0.VCU_DTC, 6, 0, RED); //���ϴ���
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(305, 318 + 15 + 38, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage, 4, 3, WHITE); //����ߵ�ѹ
        print_SZ_1(305, 318 + 15 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage, 4, 3, WHITE); //����͵�ѹ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        //�ſ���ͼ�񱨾�
        if (LED2) {
            BMP_Men_Kai(150 + 195, 190 + 27, RED); //��2��
        } else
            BMP_Men_Guan(150 + 195, 190 + 27, WHITE); //��2��
        if (LED1)
            BMP_Men_Kai(150 + 184 + 215, 190 + 27, RED); //��1��
        else
            BMP_Men_Guan(150 + 184 + 215, 190 + 27, WHITE); //��1��        
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(360 - 15, 440 + 8, timer);
        updata_DAT(540 + 50, 318 + 15 + 38 * 2, CAN_0x0CB321EF.MotorCtrlTemp, 1, 40, WHITE, 3, 0); //����������¶�
        updata_DAT(540 + 50, 318 + 15 + 38, CAN_0x0CB321EF.MotorTemp, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 - 10);
        updata_DAT(150 + 45, 318 + 15 + 38, CAN_0x18F212F3.Voltage, 0.1, 0, WHITE, 4, 0); //�ܵ�ѹ
        updata_DAT(150 + 45, 318 + 15 + 38 * 2, CAN_0x18F212F3.Current, 0.1, 3200, WHITE, 4, 0); //�ܵ���
        //updata_DCDL(150 + 45 + 16, 318 + 15 + 38 * 2); //�ܵ���
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(410 + 50, 318 + 15 + 38, CAN_0x181DD0F3.BMS_MAX_Cell_Temp, 1, 40, WHITE, 3, 0); //�������
        updata_DAT(410 + 50, 318 + 15 + 38 * 2, CAN_0x181DD0F3.BMS_MIN_Cell_Temp, 1, 40, WHITE, 3, 0); //�������       
        disp_FONT_baojingNew(2, 447);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //�������ֽ���
        if (key_up) { //���ڱ����
            key_up = 0;
            if ((LED15 == 1) && (!time_flag)) {//���⿪��
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //ʱ������
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
                f_index = 0; //����ֻ����һ�εĽ���
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
                            CS_E = 0; //�ر� 
                            mode = 1; //1,MCU
                            break;
                        case 1: //AV1
                            CS_E = 0; //����
                            mode = 2; //2,AV1 
                            break;
                        case 2: //AV2  SP2  CJ2
                            CS_E = 1; //�� 
                            CS_A = 1;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 3: //AV2  SP3  CJ3
                            CS_E = 1; //�� 
                            CS_A = 0;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 4: //AV2  SP4  CJ4
                            CS_E = 1; //�� 
                            CS_A = 1;
                            CS_B = 0;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        default:
                            CS_E = 0; //�ر� 
                            mode = 1; //1,MCU
                            AV_CH = 0;
                            break;
                    }
                    LCD_CHS(mode);
                }

                //��������ѡ��ʹ�ܰ���
                /*if ((VCU_Gear == 1) && !R_flag) {//����
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 0; //0+1=1  ����
                    R_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //����ѡ��ʹ�ܰ��� ���ȼ�С�ڵ���
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//���ſ�
                        key_AV = 1; //ģ��AV���ذ�һ��
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //��ֹһֱ�����������������key_AV������1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 ����MCU����
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
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        //updata_DAT(480 + 30, 318 + 13 - 5, MCU_NM, 0.25, 8192, WHITE, 4, 0); //���ת��
        //updata_DCDL(585, 155 + 13 - 5 + 60);
        updata_DAT(480 + 40 - 10, 260 + 2 + 36 * 0, 0, 8, 1000, WHITE, 4, 0); //��ص���
        //print_SZ_1(480 + 40, 260 + 3 + 36 * 2, 0, 3, 0, WHITE); //���ݵ�ѹ   
        updata_DAT(480 + 40 - 10, 260 + 3 + 36 * 2, 0, 20, 2000, WHITE, 4, 0); //���ת�� 
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        print_SZ_1(313 - 16 * 2, 260 + 2, 0 * 1.5, 4, 3, WHITE); //����ߵ�ѹ
        print_SZ_1(313 - 16 * 2, 260 + 2 + 36 * 1, 0 * 1.5, 4, 3, WHITE); //����͵�ѹ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDY(585, 155 + 13 - 5 - 10);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 13, timer);
        updata_DAT(313, 260 + 2 + 36 * 2, 0, 1, 40, WHITE, 3, 0); //����������¶�
        updata_DAT(313, 260 + 2 + 36 * 3, 0, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 13 + 60 - 5 - 10);
        updata_QY();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DAT(480 + 40 + 6, 260 + 2 + 36 * 1, 0, 0.2, 50, WHITE, 3, 0); //�������       
        disp_FONT_baojingNew(162, 260 + 1 + 36 * 4);
    } else if (f_index == 7) {
        f_index = 1;
        updata_Dangwei(138 + 17 + 66 * 4, 74 - 5);
        print_SZ_1(480 + 40 - 10, 260 + 3 + 36 * 3, 0 * 0.05, 4, 0, WHITE);
        //print_H(480 + 30 -16, 318+15 + 38*2, tcu_spn, 5, 0, WHITE); //spn
        //print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //ϵͳ����
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //�������ֽ���
        if (key_up) { //���ڱ����
            key_up = 0;
            if ((LED15 == 1) && (!time_flag)) {//���⿪��
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //ʱ������
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
                f_index = 0; //����ֻ����һ�εĽ���
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
                            CS_E = 0; //�ر� 
                            mode = 1; //1,MCU
                            break;
                        case 1: //AV1
                            CS_E = 0; //����
                            mode = 2; //2,AV1 
                            break;
                        case 2: //AV2  SP2  CJ2
                            CS_E = 1; //�� 
                            CS_A = 1;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 3: //AV2  SP3  CJ3
                            CS_E = 1; //�� 
                            CS_A = 0;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 4: //AV2  SP4  CJ4
                            CS_E = 1; //�� 
                            CS_A = 1;
                            CS_B = 0;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        default:
                            CS_E = 0; //�ر� 
                            mode = 1; //1,MCU
                            AV_CH = 0;
                            break;
                    }
                    LCD_CHS(mode);
                }

                //��������ѡ��ʹ�ܰ���
                /*if ((VCU_Gear == 1) && !R_flag) {//����
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 0; //0+1=1  ����
                    R_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //����ѡ��ʹ�ܰ��� ���ȼ�С�ڵ���
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//���ſ�
                        key_AV = 1; //ģ��AV���ذ�һ��
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //��ֹһֱ�����������������key_AV������1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 ����MCU����
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
    if (f_index == 0) { //ֻ����һ��
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        print_SZ_1(60, 318 + 8 + 38, CAN_0x18F81A9E.BMS_MAX_Cell_Voltage, 4, 3, WHITE); //�����
        print_SZ_1(60, 318 + 8 + 38 * 2, CAN_0x18F81A9E.BMS_MIN_Cell_Voltage, 4, 3, WHITE); //�����
        updata_DAT(313, 318 + 8 + 38, CAN_0x08029F80.DriveMotorTemp, 1, 40, WHITE, 3, 0); //����¶�
    } else if (f_index == 2) {
        f_index = 3;
        disp_BMP_baojing();
        updata_DAT(480 + 30, 318 + 8, CAN_0x08019F80.VCU_MotorSpeed, 1, 8000, WHITE, 4, 0); //���ת��
        print_SZ_1(480 + 30, 318 + 8 + 38, ADV[0], 3, 1, WHITE); //���ص�ѹ
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(585, 155 + 60, 0.05, 1600);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440 + 5, timer);
        updata_DAT(313, 318 + 8, CAN_0x08029F80.MotorCtrlTemp/*witdh*/, 1, 40, WHITE, 3, 0); //����������¶�
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC(585, 155 + 60 + 60);
        updata_DAT(800 - 150, 318 + 8 + 38, CAN_0x18F8179E.BMS_MAX_Temp/*DS3231_ReadTemp()*/, 1, 40, WHITE, 3, 0); //�������
        updata_DAT(800 - 150, 318 + 8 + 38 * 2, CAN_0x18F8179E.BMS_MIN_Temp, 1, 40, WHITE, 3, 0); //�������
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
        print_SZ_1(480 + 30 + 16, 318 + 38, TCU_code, 3, 0, color); //ϵͳ����
    } else {
        f_index = 0;*/
    }

    if (AV_CH == 0) { //�������ֽ���
        if (key_up) { //���ڱ����
            key_up = 0;
            if ((LED15 == 1) && (!time_flag)) {//���⿪��
                if (e_backlight >= 1000) e_backlight = 100;
                else e_backlight += 100;
                EEROM_WriteBackLight();
            }
            if (time_flag) {
                t++; //ʱ������
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
                f_index = 0; //����ֻ����һ�εĽ���
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
                            CS_E = 0; //�ر� 
                            mode = 1; //1,MCU
                            break;
                        case 1: //AV1
                            CS_E = 0; //����
                            mode = 2; //2,AV1 
                            break;
                        case 2: //AV2  SP2  CJ2
                            CS_E = 1; //�� 
                            CS_A = 1;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 3: //AV2  SP3  CJ3
                            CS_E = 1; //�� 
                            CS_A = 0;
                            CS_B = 1;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        case 4: //AV2  SP4  CJ4
                            CS_E = 1; //�� 
                            CS_A = 1;
                            CS_B = 0;
                            CS_C = 1;
                            mode = 6; //AV2
                            break;
                        default:
                            CS_E = 0; //�ر� 
                            mode = 1; //1,MCU
                            AV_CH = 0;
                            break;
                    }
                    LCD_CHS(mode);
                }

                //��������ѡ��ʹ�ܰ���
                /*if ((VCU_Gear == 1) && !R_flag) {//����
                    key_AV = 1; //ģ��AV���ذ�һ��
                    AV_CH = 0; //0+1=1  ����
                    R_flag = 1; //��ֹһֱ�����������������key_AV������1
                }
                if ((VCU_Gear != 1) && R_flag) {
                    key_AV = 1;
                    AV_CH = 4; // 0 ����MCU����
                    R_flag = 0;
                    M_flag = 0;
                }*/

                //����ѡ��ʹ�ܰ��� ���ȼ�С�ڵ���
                /*if (VCU_Gear != 1) {
                    if (IN3 && !M_flag) {//���ſ�
                        key_AV = 1; //ģ��AV���ذ�һ��
                        AV_CH = 1; //1+1=2  AV1
                        M_flag = 1; //��ֹһֱ�����������������key_AV������1
                    }
                    if (!IN3 && M_flag) {
                        key_AV = 1;
                        AV_CH = 4; // 0 ����MCU����
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
void ICFrame(unsigned char index, unsigned char page) { //�Ǳ���
    unsigned char i;
    const unsigned char *ip1[16] = {in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16};
    const unsigned char *ip2[16] = {in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32};
    const unsigned char *ip3[16] = {in33, in34, in35, in36, in37, in38, in39, in40, ad1, ad2, ad3, ad4, ad5, ad6};
    LCD_Clear();
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������

    print_SZ_2(750, 50, index, 1, 0, WHITE); // x/1
    LCD_DrawImage1BPP_11x20(750 + 11, 50, BMP_ASIC_11x20[47], WHITE, BLACK);
    print_SZ_2(750 + 11 + 14, 50, page, 1, 0, WHITE);

    LCD_DrawImageString_21x20(130 + 200 + 200, 130 - 85 + 4, cantx, WHITE, BLACK); //CANͨѶ

    if (index == 1) {
        LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, IC_SYSTEM, WHITE, BLACK); //�Ǳ�            
        /***********************�Ǳ������ɼ�*********************************/
        /*************************��һ�п���***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(35, 75 + 25 * i, ip1[i], WHITE, BLACK);
        }
        /*************************�ڶ��п���***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(285, 75 + 25 * i, ip2[i], WHITE, BLACK);
        }
        /*************************�����п���***********************************/
        for (i = 0; i < 16; i++) {
            LCD_DrawImageString_21x20(535, 75 + 25 * i, ip3[i], WHITE, BLACK);
        }
        for (i = 8; i < 14; i++) {
            LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * i, BMP_Omu, WHITE, BLACK); //��
            LCD_DrawImage1BPP_11x20(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * i, BMP_ASIC_11x20[86], WHITE, BLACK); //V
        }
        LCD_DrawImageString_21x20(505 + 100, 75 + 8 + 25 * 15, bbh, WHITE, BLACK);
        LCD_DrawImage1BPP(505 + 200, 75 + 25 * 15, BMP_V, WHITE, BLACK);
    } else {
        if (index == 2) {
            const unsigned char *fp1[16] = {fout1, fout2, fout3, fout4, fout5, fout6, fout7, fout8, fout9, fout10, fout11, fout12, fout13, fout14, fout15, fadd};
            const unsigned char *fp2[16] = {fkl1, fkl2, fkl3, fkl4, fkl5, fkl6, fkl7, fkl8, fkl9, fkl10, fkl11, fkl12, fkl13, fkl14, fkl15, fkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_QIAN, WHITE, BLACK); //ǰ
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65], WHITE, BLACK);
            }
            /*************************ǰģ�����***********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, fp1[i], WHITE, BLACK);
            }
            /***********************ǰģ�鿪�زɼ�*********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, fp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, fad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, fad2, WHITE, BLACK);
        } else if (index == 3) {
            const unsigned char *mp1[16] = {mout1, mout2, mout3, mout4, mout5, mout6, mout7, mout8, mout9, mout10, mout11, mout12, mout13, mout14, mout15, madd};
            const unsigned char *mp2[16] = {mkl1, mkl2, mkl3, mkl4, mkl5, mkl6, mkl7, mkl8, mkl9, mkl10, mkl11, mkl12, mkl13, mkl14, mkl15, mkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_DING, WHITE, BLACK); //��
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65], WHITE, BLACK);
            }
            /*********************��ģ�����***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, mp1[i], WHITE, BLACK);
            }
            /************************��ģ�鿪��*********************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, mp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, mad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, mad2, WHITE, BLACK);
        } else if (index == 4) {
            const unsigned char *rp1[16] = {rout1, rout2, rout3, rout4, rout5, rout6, rout7, rout8, rout9, rout10, rout11, rout12, rout13, rout14, rout15, radd};
            const unsigned char *rp2[16] = {rkl1, rkl2, rkl3, rkl4, rkl5, rkl6, rkl7, rkl8, rkl9, rkl10, rkl11, rkl12, rkl13, rkl14, rkl15, rkh1};
            LCD_DrawImage1BPP(130 + 200, 130 - 85, BMP_HOU, WHITE, BLACK); //��
            LCD_DrawImage1BPP(130 + 200 + 25, 130 - 85, BMP_MOKUAI, WHITE, BLACK); //ģ��
            LCD_DrawImage1BPP(130 + 200 + 25 + 50, 130 - 85, BMP_Message, WHITE, BLACK); //��Ϣ
            for (i = 0; i < 15; i++) {
                LCD_DrawImage1BPP_11x20(60 + 280, 75 + 3 + 25 * i, BMP_ASIC_11x20[65], WHITE, BLACK);
            }
            /*********************��ģ�����***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(60, 75 + 25 * i, rp1[i], WHITE, BLACK);
            }
            /*********************��ģ�鿪��***************************************/
            for (i = 0; i < 16; i++) {
                LCD_DrawImageString_21x20(285 + 150, 75 + 25 * i, rp2[i], WHITE, BLACK);
            }
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 0, rad1, WHITE, BLACK);
            LCD_DrawImageString_21x20(535 + 63 - 11, 75 + 25 * 1, rad2, WHITE, BLACK);
        }
        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 0, BMP_Omu, WHITE, BLACK); //��
        LCD_DrawImage1BPP_11x20(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 0, BMP_ASIC_11x20['V'], WHITE, BLACK); //V

        LCD_DrawImage1BPP(535 + 63 + 42 + 16 * 4 - 4, 75 + 25 * 1, BMP_Omu, WHITE, BLACK); //��
        LCD_DrawImage1BPP_11x20(535 + 63 + 42 + 16 * 4 + 16 * 5, 75 + 25 * 1, BMP_ASIC_11x20['V'], WHITE, BLACK); //V

        //�汾��
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
                if ((dump & 0x01) == 0x01) {//Ϊ�ػ𿪹�
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
            /*if (i == 9) {//IN26 Ϊ�ػ𿪹�
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
        for (i = 0; i < 8; i++) {//WAKE1 WAKE2 WAKE3Ϊ�ػ𿪹�
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
        //�Խ�����
        print_SZ_1(535 + 25, 75 + 25 * 15, TIME, 8, 0, YELLOW);
        //����汾��
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, fpcur[i] / 100, 3, 1, GREEN); //ǰģ�����
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD��θ�λ�ź�
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
        //ģ��ģ���ź�
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 4, 75 + 25 * i, fADR[i], 3, 0, YELLOW);
        }
        for (i = 0; i < 2; i++) {
            print_SZ_2(535 + 63 + 42 + 16 * 5, 75 + 25 * i, fADV[i] / 10, 3, 2, YELLOW);
        }
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, Fversion, 3, 2, YELLOW);
    }

    /*�п�ģ��*/
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, mpcur[i] / 100, 3, 1, GREEN); //��ģ�����
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD��θ�λ�ź�
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
        //����汾��
        print_SZ_1(535 + 200, 75 + 25 * 15, Mversion, 3, 2, YELLOW);
    }

    /*���ģ��*/
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
                print_SZ(30 + 250, 75 + 6 + 25 * i, rpcur[i] / 100, 3, 1, GREEN); //��ģ�����
            else
                print_SZ(30 + 250, 75 + 6 + 25 * i, 0, 3, 1, GREEN);
        }
        //ADD��θ�λ�ź�
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
        //����汾��
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������   

    LCD_DrawRect(0, 430, 800, 2, YELLOW); //�ײ�����
    LCD_DrawImageSBPP(130, 130 + 35 * 0, 50, MOTO_SYSTEM, color, BLACK); //���

    LCD_DrawImageSBPP(130, 130 + 35 * 1, 50, DCDC_SYSTEM, color, BLACK); //DCDC

    LCD_DrawImageSBPP(130, 130 + 35 * 2, 50, AIR_SYSTEM, color, BLACK); //����

    LCD_DrawImageSBPP(130, 130 + 35 * 3, 50, OIL_SYSTEM, color, BLACK); //ת��

    LCD_DrawImageSBPP(130, 130 + 35 * 4, 50, VCU_SYSTEM, color, BLACK); //����


    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 0, 50, BMS_SYSTEM, color, BLACK); //BMS

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 1, 50, Battery_SYSTEM, color, BLACK); //���   

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 2, 50, AC_SYSTEM, color, BLACK); //�յ�

    LCD_DrawImageSBPP(130 + 350, 130 + 35 * 3, 50, IC_SYSTEM, color, BLACK); //�Ǳ�

}

#define Menu_Number  9

static void MenuUpdate(void) {
    static unsigned char menu = 1;
    unsigned char color = BLACK, j = 0, i = 0;
    if (key_up) {//��ͷ������
        key_up = 0;
        if (time_flag) {
            t++; //ʱ������
            if (t == 10) t = 0;
        }
        if (!time_flag) {
            menu++;
            if (menu > Menu_Number) {
                menu = 1;
            }
        }
    }

    if (key_AV) {//��ͷ������
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
        case 1://�˵�1
            MenuSet(GREEN, 2);
            break;
        case 2://�˵�2
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
    if (f_index == 0) { //ֻ����һ��
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, MOTO_SYSTEM, WHITE, BLACK); //���

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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200, 130 - 85, 50, DCDC_SYSTEM, WHITE, BLACK); //DCDCϵͳ��Ϣ

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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200 - 24, 130 - 85, 50, BMS_SYSTEM, WHITE, BLACK); //���

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
                LCD_DrawImageString_21x20(330 + 390 * i - 28 - 63 - 17, 100 + 38 * 3, string_t, WHITE, BLACK); //�� 
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 8.5 + 5, 100 + 38 * 2, hao, WHITE, BLACK); //��
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 8.5 + 5, 100 + 38 * 3, hao, WHITE, BLACK); //��
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 6.5 + 10, 100 + 38 * 2, xiang, WHITE, BLACK); //��
                LCD_DrawImageString_21x20(12 + 390 * i + 42 * 6.5 + 10, 100 + 38 * 3, xiang, WHITE, BLACK); //��
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
            print_SZ_1(82 + 70 - 16 * 3 + 25, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage, 4, 3, WHITE); //�����ߵ�ѹ
            print_SZ_1(82 + 70 + 16 * 5 + 10, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage_CaseNum, 3, 0, WHITE);
            print_SZ_1(82 + 70 + 16 * 10 + 10, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MAX_Cell_Voltage_Num, 3, 0, WHITE);

            updata_DAT(82 + 70 - 16 * 1 + 25, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MAX_Cell_Temp, 1, 40, WHITE, 3, 0); //����¶� 
            print_SZ_1(82 + 70 + 16 * 5 + 10, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MAX_Cell_Temp_CaseNum, 3, 0, WHITE);
            print_SZ_1(82 + 70 + 16 * 10 + 10, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MAX_Cell_Temp_Num, 3, 0, WHITE);

            print_SZ_1(82 + 200 + 260 - 16 * 1, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage, 4, 3, WHITE); //�����ߵ�ѹ
            print_SZ_1(82 + 200 + 260 + 16 * 6, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage_CaseNum, 3, 0, WHITE);
            print_SZ_1(82 + 200 + 260 + 16 * 11, 100 - 8 + 38 * 2, CAN_0x181CD0F3.BMS_MIN_Cell_Voltage_Num, 3, 0, WHITE);

            updata_DAT(82 + 200 + 260 + 16 * 1, 100 - 8 + 38 * 3, CAN_0x181DD0F3.BMS_MIN_Cell_Temp, 1, 40, WHITE, 3, 0); //�����͵�ѹ
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
    LCD_DrawImageSBPP(130 + 200 + 24, 130 - 85, 50, Battery_SYSTEM, WHITE, BLACK);

    //�ָ�
    for (i = 0; i < 6; i++) {
        LCD_DrawRect(i * 160, 45 + 70, 1, 360, GREEN);
        LCD_DrawRect(58 + i * 160, 45 + 70, 1, 360, GREEN);
    }
    for (i = 0; i < 11; i++)
        LCD_DrawRect(0, 45 + 70 + i * 36, 800, 1, GREEN);

    LCD_DrawImageString_21x20(50, 90, dcxh, WHITE, BLACK); //������
    LCD_DrawImage1BPP(50 + 42 + 42 + 21 + 15, 90 - 9, BMP_SZ_1[index], GREEN, BLACK);

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 10; i++) {
            if (i < 9) {//д��Ÿ�λ
                LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                if (j > 0) {//д���ʮλ
                    LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                }
            } else {//д�����һ�б��
                LCD_DrawImage1BPP(5 + 16 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[0], WHITE, BLACK);
                LCD_DrawImage1BPP(5 + 16 + j * 160, 46 + 70 + i * 36, BMP_SZ_1[j + 1], WHITE, BLACK);
            }
            LCD_DrawImage1BPP(5 + 4 + 16 + 16 + 100 + j * 160, 46 + 70 + i * 36, BMP_V, YELLOW, BLACK);
        }
    }

    for (j = 0; j < 1; j++) {
        for (i = 0; i < 6; i++) {
            if (i < 9) {//д��Ÿ�λ
                LCD_DrawImage1BPP(5 + 16 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[i + 1], WHITE, BLACK);
                if (j > 0) {//д���ʮλ
                    LCD_DrawImage1BPP(5 + 16 + (j + 4) * 160, 46 + 70 + i * 36, BMP_SZ_1[j], WHITE, BLACK);
                }
            } else {//д�����һ�б��
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
        LCD_DrawImage1BPP(400 + 320 - 24 - 22, 100 + 38 * (i + 4), BMP_T, WHITE, BLACK); //��
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
                    print_SZ_1(60 + j * 160, 46 + 70 + 36 * i, BAT_Cell_Voltage[index][j * 10 + i], 4, 3, GREEN); //�����ѹ
            }
        }
        for (i = 0; i < 6; i++) {
            if ((BAT_Cell_Temp[index][i] == 0xFF) || (BAT_Cell_Temp[index][i] == 0))
                updata_DAT(60 + 4 * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index][i], 1, 40, BLACK, 3, 0);
            else
                updata_DAT(60 + 4 * 160 + 25, 46 + 70 + 36 * i, BAT_Cell_Temp[index][i], 1, 40, GREEN, 3, 0); //�����¶�
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
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //��������
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
//������: void frm_speed(void)
//����:  ���ô���
//����:  ȫ�ֱ���
 ******************************************************************************/
void frm_speed(void) {
    if (f_index == 0) {
        f_index = 1;
        key_set = 0;
        key_duble = 0;
        LCD_Clear();
        LCD_DrawRect(0, 0, 800, 50, BLACK);
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImageString_21x20(360, 30, cssb, GREEN, BLACK); //�����ٱ�

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
//��������
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
    LCD_DrawImage1BPP(360,30,BMP_Chesu, GREEN,BLACK);//����
    LCD_DrawImage1BPP(400,30,BMP_Subi,GREEN,BLACK);//�ٱ�
    
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
    //��֤����     bcd[2]*1000+ bcd[0]*100+bcd[3]*10+bcd[1];//�任�����A
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
    LCD_DrawImageString_21x20(336 + 24, 140, sbsz, color, BLACK); //�ٱ�����
    if (id == 1) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 190, BMP_SZ_2[2], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 190, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImageString_21x20(336 + 24, 190, lcsz, color, BLACK); //�������

    if (id == 2) color = GREEN;
    else color = WHITE;
    LCD_DrawImage1BPP(300 + 24, 240, BMP_SZ_2[3], color, BLACK);
    LCD_DrawImage1BPP(316 + 24, 240, BMP_SZ_2[10], color, BLACK);
    LCD_DrawImageString_21x20(336 + 24, 240, tuichu, color, BLACK); //�˳� 
}

void frm_system(void) {
    static unsigned char ID = 0;
    if (f_index == 0) {
        f_index = 1;
        LCD_DrawRect(0, 60, 800, 365, BLACK);
        LCD_DrawImageString_21x20(360, 30, cssb, GREEN, BLACK); //�����ٱ�
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
        frmID = ID + 32; //�˵��Ŵ�2---7��ʼ 
        if (frmID >= 34)frmID = 0; //���������� 
    }
}

//���������

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

        LCD_DrawImageString_21x20(360, 30, lcsz, GREEN, BLACK); //�������

        LCD_DrawImageString_21x20(200 + 60, 185, zjlc, WHITE, BLACK); //�ܼ���� 

        LCD_DrawImageString_21x20(440 + 60, 187, string_km, WHITE, BLACK); //��λ Km 
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
    LCD_DrawImageString_21x20(360, 30, sbsz, GREEN, BLACK); //�ٱ�����

    LCD_DrawImageString_21x20(300 + 60, 170, sbsz, YELLOW, BLACK); //

    LCD_DrawImage1BPP(210 + 60, 205, BMP_SZ_2[1], YELLOW, BLACK); // 
    LCD_DrawImage1BPP(210 + 60, 245, BMP_SZ_2[2], YELLOW, BLACK); //

    for (i = 0; i < 4; i++) {
        LCD_DrawRect(180 + 60, 120 + 35 + 40 * i, 320, 2, GRAY); //��  
    }
    LCD_DrawRect(180 + 60, 120 + 35, 2, 120, GRAY); //��
    LCD_DrawRect(260 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(380 + 60, 120 + 35, 2, 120, GRAY); //
    LCD_DrawRect(498 + 60, 120 + 35, 2, 120, GRAY); //
}

unsigned int new_pluse = 103;

void update_setDATE(void) {
    unsigned int temp = 0;
    unsigned int x = 180, y = 120;
    print_SZ_2(x + 100 + 60 + 20, y + 85, e_hm_pulse, 3, 0, GREEN); //   
    print_SZ_2(x + 210 + 60 + 30, y + 85, SPEED, 3, 0, GREEN); //����

    //Ŀ��ֵ
    print_SZ_2(x + 100 + 60 + 20, y + 125, new_pluse, 3, 0, RED); // 
    temp = (unsigned int) (SPEED * new_pluse / e_hm_pulse);
    //����
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
        EEROM_WriteHMPulse(); //д��
        EEROM_ReadHMPulse(); //���� У��  
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
            frm_system(); //���ò�����Ϣ
            break;
        case 32:
            frm_setDATE(); //���ò�����Ϣ
            break;
        case 33:
            frm_miles(); //���ò�����Ϣ
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



