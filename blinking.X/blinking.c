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
//Switch lock

void main(void) 
{
    TRISB=0xFF;
    PORTB=0x00;
    TRISC=0x00;
    PORTC=0x00;
    int count=0;
    while(1)
    {
        if(RB1==1)
        {
            if(count<5)
            {
                PORTC=0xFF;
                __delay_ms(1000);
                PORTC=0x00;
                __delay_ms(1000);
                count++;
            }
            else
            {
                PORTC=0x00;
            }
        }
     }
    return;
}
