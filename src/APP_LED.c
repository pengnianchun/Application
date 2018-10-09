/*
 * File:   APP_LED.c
 * Author: pnc
 *
 * Created on 2017��7��28��, ����4:49
 */

#include "APP_System.h"

void LED_Logic(void) {     
    //ǰ�ſ�ָʾ //��������
    LED1 = IN2;
    
    //���ſ�ָʾ �յ�ָʾ
    LED2 = IN3;   
    
    //�����ƶ�ָʾ
    LED3 = 0; 
    
        //Interval_Status(IN1 || IN5 || WAKE_Danger,Flash_400ms);//ע��400ms��˸��Ч״̬
    //��ת��
    if (IN1 || WAKE_Danger)
        LED4 = FLASH;
        //LED4 = Flash[Flash_400ms].Status;
    else LED4 = 0;
  
    LED5 = 0; //ǰ����ָʾ Ԥ��ָʾ

    //���ָʾ  ����ѹ������
    LED6 = (CAN_0x181ED0F3.Status6.byte == 1);   
    
    //����ͷ����  ˮ�¸߱���
    LED7 = (CAN_0x18F214F3.Status4.bit8 || WAKE_Charge);

    
    //��ת���
    if (IN5 || WAKE_Danger)
        LED8 = FLASH;
        //LED8 = Flash[Flash_400ms].Status;
    else LED8 = 0;

    if (ADV[4] < 2500)//��ѹ1���ź� 0.6MP����
        LED9 = 1;
    else
        LED9 = 0;

    LED10 = 1; //�ܵ�Դָʾ   

    if (ADV[3] < 2500) //��ѹ2 0.6MP����
        LED11 = 1;
    else
        LED11 = 0;

    //SOC���� ���������ϱ���
    LED12 = ((CAN_0x0CF300D0.Warning2.double2 > 0) || (CAN_0x0CF300D0.Warning4.double1 > 0));

    //������� ���л�ˮ����
    LED13 = (0);

    //�������ϵͳ���� OBDָʾ
    LED14 = 0;

    LED15 = (IN6); //С�� ��������ϱ���ָʾ

    LED16 = (BAT24V_count >= BAT24_TIME); //���ص�ѹ�� ���ָʾ

    LED17 = (IN7); //Զ��� Զ��Ʊ���

    LED18 = (rKL8); //��ɲ פ���ƶ�����

    LED19 = (LED15 && IN9); //ǰ��� ǰ��Ʊ���

    LED20 = (IN10); //����� ����Ʊ���

    LED21 = (((CAN_0x0CFA00D0.byte[2] >> 3)&0x03) == 2); //������ ������

    LED22 = (IN8); //����� ����Ʊ���

    LED23 = 0;//������ ����������

    LED24 =  (rKL6); //ɲ��ָʾ ɲ��ָʾ


    Interval_Status(IN18, Flash_500ms);
    //Interval_Status(0, Flash_200ms);
    //������ Ϊ0ʱ�죬Ϊ1ʱ����   
    if ((rKL15 && SPEED > 5) //�����δ��
            || (LED1 && SPEED > 5) //ǰ��δ��
            || (LED2 && SPEED > 5) //����δ��
            || !fKL4 //��ǰĦ��Ƭ
            || !fKL5 //���Ħ��Ƭ 
            || (SPEED > 69)//���ٱ���
            )
        BUZZ = !FLASH_1s;
    else if (LED4     //��ת��
            || LED8   //��ת��
            || WAKE_Danger //Σ�ձ���
            || LED9  //��ѹ1����
            || LED11 //��ѹ2����
            || CAN_0x0CFC00D0.FaultLevel //��������
            )
        BUZZ = !FLASH;
    else
        BUZZ = 1;

    //���� С�ƿ��رպ� 
    if (LED15) {
        OC1RS = e_backlight;
    } else {
        OC1RS = 0;
    }

    //Ӳ���������ƣ���ֵ0���������Ӳ���������ƣ���ֵ1�������
    PO1 = (SPEED < 5);
    PO2 = (SPEED < 5);
}

void LED_Danger(void){     //Σ�ձ���״̬
    F_PO6 = FLASH;
    F_PO7 = FLASH;
    M_PO2 = FLASH;
    M_PO15 = FLASH;
    R_PO5 = FLASH;
    R_PO7 = FLASH;
    LED4 = FLASH; //��ת���
    LED8 = FLASH; //��ת��� 
    BUZZ = !FLASH;
}

void LED_Clear(void){      //LEDȫ���ر�
    alarm_led[0].byte = 0xff;
    alarm_led[1].byte = 0x00;
    alarm_led[2].byte = 0x00;
    alarm_led[3].byte = 0x00;
}

void LED_Enable(void){
    alarm_led[0].byte = 0xC0; //����������
    alarm_led[1].byte = 0xff;
    alarm_led[2].byte = 0xff;
    alarm_led[3].byte = 0xff;
}

void LED_Test(void) { //�����е�LED�Ƶ�����ֻΪ����ʹ��
    static unsigned char tq = 0,task = 0;//led_test_count = 0,
    /*unsigned char led_test[26][3] = {
        {0x00, 0x00, 0x02}, //פ���ƶ�
        {0x00, 0x00, 0x08}, //����� 
        {0x00, 0x00, 0x20}, //�����
        {0x00, 0x00, 0x40}, //������
        {0x01, 0x00, 0x00}, //ǰ�ſ�
        {0x02, 0x00, 0x00}, //���ſ�  
        {0x04, 0x00, 0x00}, //�յ�  
        {0x00, 0x00, 0x04}, //ǰ���

        {0x00, 0x00, 0x10}, //������
        {0x00, 0x00, 0x80}, //ɲ���� 
        {0x00, 0x00, 0x01}, //Զ���
        {0x08, 0x00, 0x00}, //��ת���
        {0x80, 0x00, 0x00}, //��ת���
        {0x10, 0x00, 0x00}, //D
        {0x20, 0x00, 0x00}, //���ָʾ
        {0x40, 0x00, 0x00}, //����ͷ

        {0x00, 0x01, 0x00}, //��ѹ1
        {0x00, 0x02, 0x00}, //��Դָʾ
        {0x00, 0x08, 0x00}, //SOC
        {0x00, 0x40, 0x00}, //С��
        {0x00, 0x04, 0x00}, //��ѹ2
        {0x00, 0x10, 0x00}, //�������
        {0x00, 0x20, 0x00}, //��ع���
        {0x00, 0x80, 0x00}, //���

        {0x00, 0x00, 0x00}, //
        {0xff, 0xff, 0xff}};
if (led_test_count < 26) {
        alarm_led[1].byte = led_test[led_test_count][0];
        alarm_led[2].byte = led_test[led_test_count][1];
        alarm_led[3].byte = led_test[led_test_count][2];
    } else {
        if (FLASH) {
            alarm_led[1].byte = 0xff;
            alarm_led[2].byte = 0xff;
            alarm_led[3].byte = 0xff;
        } else {
            alarm_led[1].byte = 0x00;
            alarm_led[2].byte = 0x00;
            alarm_led[3].byte = 0x00;
        }
    }*/
    if (!tq && (task == 0)) {
        task = 1;
        alarm_led[1].byte = 0xaa;
        alarm_led[2].byte = 0xaa;
        alarm_led[3].byte = 0xaa;
    } else if (!tq && (task == 1)) {
        task = 2;
        alarm_led[1].byte = 0x55;
        alarm_led[2].byte = 0x55;
        alarm_led[3].byte = 0x55;
    }else if (!tq && (task == 2)) {
        task = 3;
        alarm_led[1].byte = 0xff;
        alarm_led[2].byte = 0xff;
        alarm_led[3].byte = 0xff;
    } else if (!tq && (task == 3)) {
        task = 0;
        alarm_led[1].byte = 0x00;
        alarm_led[2].byte = 0x00;
        alarm_led[3].byte = 0x00;
        if (tq < 20)
            BUZZ = 0; //�رշ����� 
    }
    
    if (tq >= 39) {
        tq = 0;
        //if (led_test_count > 44)led_test_count = 0;
        //led_test_count++;
    } else {
        tq++;
    }

    OC1RS = 1000;
    if (tq > 20) BUZZ = 1; //������     

}