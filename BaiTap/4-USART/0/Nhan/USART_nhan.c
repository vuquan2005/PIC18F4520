#include <p18f4520.h>
#include <usart.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config PWRT=ON
#pragma config BOREN=OFF
#pragma config LVP=OFF

void main()
{
    int d = 0;
    ADCON1 = 0x0F;
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 1;
    TRISD = 0;
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 51);
    
    while (1)
    {
        d = ReadUSART();
        PORTD = d;
    }
}
