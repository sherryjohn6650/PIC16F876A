//CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 4000000 //4MHz

void main(void) 
{
    unsigned char count=255;
    unsigned char pause=0;
    TRISB=0x00;
    TRISC0=1;
    PORTB=0xFF;
    while(1)
    {
        if(RC0==1)
        {
            __delay_ms(500);
            if(RC0==1)
            {
                pause=!pause;
                while(RC0==1);
                __delay_ms(500);
            }
        }
        if(pause==0)
        {
            PORTB=count;
            __delay_ms(500);
            if(count==0)
                count=255;
            else
                count--;
        }
    }
    return;
}
