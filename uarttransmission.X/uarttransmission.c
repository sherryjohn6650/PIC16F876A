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

//Character transmission
/*void main(void) 
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    char ch='B';
    while(1)
    {
        TXREG=ch;
        while(TRMT==0);
        __delay_ms(1000);
    }
    return;
}*/

//Using function
/*void transmit(char ch)
{
    TXREG=ch;
    while(TRMT==0);
    __delay_ms(1000);
}
void main(void) 
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    char ch='B';
    while(1)
    {
        transmit('B');
    }
    return;
}*/

//UART String Transmission
/*void uart_char_tx(char ch)
{
    TXREG=ch;
    while(TRMT==0);
}
void main()
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    char str[20]="Hello World ";
    while(1)
    {
        for(int i=0;str[i]!='\0';i++)
        {
            TXREG=str[i];
            while(TRMT==0);
        }
        __delay_ms(1000);
    }
}*/
//String transmission using function method 1
/*void uart_char_tx(char ch)
{
    TXREG=ch;
    while(TRMT==0);
}
void uart_str_tx(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        uart_char_tx(str[i]);
    }
}
void main()
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    char str[20]="Hello World\r";
    while(1)
    {
        uart_str_tx(str);
        __delay_ms(1000);
    }
}*/

//String transmission using function method 2
/*void uart_char_tx(char ch)
{
    TXREG=ch;
    while(TRMT==0);
}
void uart_str_tx(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
       TXREG=str[i];
       while(TRMT==0);
    }
     __delay_ms(1000);
}
void main()
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    char str[20]="Hello World\r";
    while(1)
    {
        uart_str_tx(str);
    }
}
*/
//String transmission using function- two strings
void uart_char_tx(char ch)
{
    TXREG=ch;
    while(TRMT==0);
}
void uart_str_tx(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
       TXREG=str[i];
       while(TRMT==0);
    }
     __delay_ms(1000);
}
void main()
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    char str[20]="Hello World\r";
    while(1)
    {
        uart_str_tx(str);
        uart_str_tx("Good Morning\r");
        __delay_ms(1000);
    }
}
