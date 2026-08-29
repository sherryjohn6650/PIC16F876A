// CONFIG
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
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0x00;
    PORTB=0x00;
    TRISC=0x00;
    PORTC=0x00;
    while(1)
    {
        for(int i=0;i<=6;i++)
        {
            PORTA=(1<<i);
            __delay_ms(1000);
        }
        PORTA=0x00;
        for(int j=7;j>=0;j--)
        {
            PORTC=(1<<j);
            __delay_ms(1000);
        }
        PORTC=0x00;
        for(int k=7;k>=0;k--)
        {
            PORTB=(1<<k);
            __delay_ms(1000);
        }
        PORTB=0x00;
    }
    return;
}
