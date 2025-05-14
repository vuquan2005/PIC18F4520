// truuyền một chuỗi ký tự qua USART

#include <p18f4520.h>
#include <stdio.h>
#include <usart.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
// Config cần cho USART
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

unsigned char txt[50];
int msv = 3547;
float diem = 8.24f;

void main()
{
    ADCON1 = 0x0f;
    TRISCbits.RC6 = 0;
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF &
                  USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH,
              51);
    sprintf(txt, "Ho ten: Vu Quan, MSV: 202360%d%cDiem: %f", msv, 13, diem);
    while (BusyUSART())
        ;
    putsUSART(txt);
    while (1)
        ;
}