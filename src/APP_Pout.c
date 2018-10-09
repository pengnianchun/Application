/*
 * File:   APP_Pout.c
 * Author: pnc
 *
 * Created on 2017年7月28日, 下午4:53
 */


#include "APP_System.h"

void SYSTME_Logic(void) {
    /*F_PO1 = (WAKE_ACC);                    
    F_PO2 = (WAKE_ACC);         
    F_PO3 = (WAKE_ACC && IN11);*/
    F_PO4 = LED19;
    F_PO5 = IN13;
    F_PO6 = LED8;
    F_PO7 = LED4;    
    F_PO8 = WAKE_ON;
    F_PO9 = LED17;
    F_PO10 = WAKE_ACC;
    F_PO11 = (WAKE_ON && !LED15);
    F_PO12 = WAKE_ACC;
    F_PO13 = LED22;
    F_PO14 = LED15;
    /*Interval_Status(((CAN_0x18F13DF3.SOC*0.4) < 20),Run_90s);
    if((CAN_0x18F13DF3.SOC*0.4) >= 20){
        F_PO15 = 1;
    } else if((CAN_0x18F13DF3.SOC*0.4) < 20){
        F_PO15 = Flash[Run_90s].Status;
    }*/
    F_PO15 = WAKE_ON;
    F_PO16 = 0;

    M_PO1 = IN12;   
    M_PO2 = LED8;                          
    M_PO3 = LED21;    
    M_PO4 = LED24;
    M_PO5 = IN20;
    M_PO6 = IN19;
    M_PO7 = IN28;
    M_PO8 = IN19;
    M_PO9 = IN27;                         
    M_PO10 = IN29;                       
    M_PO11 = IN26;  
    M_PO12 = WAKE_ACC; 
    M_PO13 = LED15;  
    M_PO14 = IN11; 
    M_PO15 = (LED4);          
    M_PO16 = 0;
    
    R_PO1 = LED24;
    //Interval_Status(LED1 || LED2,Run_150ms);
    R_PO2 = WAKE_ON;
    R_PO3 = LED20;     
    R_PO4 = 0; 
    R_PO5 = LED4;
    R_PO6 = 0;
    R_PO7 = LED8;
    R_PO8 = WAKE_ON;
    R_PO9 = LED21; 
    R_PO10 = fKL7;
    R_PO11 = (LED1 && LED15);
    R_PO12 = LED15;
    R_PO13 = (LED2 && LED15);
    R_PO14 = IN11;
    R_PO15 = WAKE_ACC;
    R_PO16 = 0;

}

void POUT_Clear(void){
    gCTL[0].byte = 0x00;
    gCTL[1].byte = 0x00;
    gCTL[2].byte = 0x00;
    gCTL[3].byte = 0x00;
    gCTL[4].byte = 0x00;
    gCTL[5].byte = 0x00;
    gCTL[6].byte = 0x00;
    gCTL[7].byte = 0x00;
}