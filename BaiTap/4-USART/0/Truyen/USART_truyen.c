#include <p18f4520.h>
#include <usart.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config PWRT=ON
#pragma config BOREN=OFF
#pragma config LVP=OFF

char dem = 0;
void ngat_ngoai(void);

#pragma code uu_tien_cao = 0x08
void ngat_cao(void)
{
    ngat_ngoai();
}
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)
{
    if (INTCONbits.INT0IF == 1)
    {
        INTCONbits.INT0IF = 0;
        dem++;
        PORTD = dem;
    }
}

void main()
{
    ADCON1 = 0x0F;
    INTCONbits.GIE = 1;
	INTCONbits.PEIE = 0;
	INTCONbits.INT0IE = 1;
	INTCON2bits.INTEDG0 = 0;
	INTCONbits.INT0IF = 0;
    //
    TRISCbits.RC6 = 0;
    TRISBbits.RB0 = 1;
    TRISBbits.RB7 = 1;
    TRISD = 0;
    OpenUSART(USART_TX_INT_ON & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 51);
    while (1)
    {
        while (PORTBbits.RB7 == 1)
            ;
        while (PORTBbits.RB7 == 0)
            ;
        while (BusyUSART())
            ;
        WriteUSART(dem);
    }
}
