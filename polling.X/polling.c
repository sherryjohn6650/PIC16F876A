//CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

//UART Interrupt
#include <xc.h>
#define _XTAL_FREQ 4000000 //4MHz

void transmit(char c)
{
    TXREG=c;
    while(TRMT==0);
    __delay_ms(100);
}
void main(void) 
{
    TRISB=0x00;
    TRISC=0x80;
    PORTB=0x00;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    GIE=0;
    PEIE=0;
    RCIE=0;
    while(1)
    {
        if(RCIF==1)
        {
            char c=RCREG;
            transmit(c);
            PORTB=0xFF;
            __delay_ms(200);
            PORTB=0x00;
            __delay_ms(200);
        }
        transmit('c');
        __delay_ms(100);
    }
    return;
}
