/*
 * File:   blink.c
 * Author: udits
 *
 * Created on 17 September, 2023, 10:37 AM
 */
#include <xc.h>
// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 6000000

unsigned char *dirB=(unsigned char *)0x86;
unsigned char *dirC=(unsigned char *)0x87;
unsigned char *dataB=(unsigned char *)0x06;
unsigned char *dataC=(unsigned char *)0x07;
unsigned char *pullup=(unsigned char *)0x81;
void main()
{   
     *dirC=0x00;
     *dirB=0xF0;
     *dataB=0x00;
     *pullup&=~0x80;
     unsigned char val;
    while(1)
    {   
        val=*dataB;
         switch(val)
    {
        case 0xE0: *dataC=0x00;
        break;
        case 0xD0:*dataC=0x02;
         break;
        case 0xB0:*dataC=0x80;
        break;
        case 0x70:*dataC=0x82;
        break;
        case 0xF0:*dataC=0x00;
        break;
    } 
    }
   return;
}
