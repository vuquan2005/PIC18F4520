// truyền một số lần nhấn nút qua USART

#include <p18f4520.h>
#include <usart.h>
#include <delays.h>
#include <stdio.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
// Config cần cho USART
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

unsigned char n = 0;
char txt[10];

#define PB PORTAbits.RA0

void main()
{
    ADCON1 = 0x0f;
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 1;

    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 1439);

    while (1)
    {
        if (ReadUSART() == 'a')
            break;
        while (PB == 0)
            ;
        while (PB == 1)
            ;
        n++;
        sprintf(txt, "%d", n);
        while (BusyUSART())
            ;
        putsUSART(txt);
    }
}