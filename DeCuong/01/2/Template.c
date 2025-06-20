#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

char n = 0;

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
		n++;
		PORTA = PORTA & 0b00001000;
		PORTA = n | PORTA;
	}
}

void main(void)
{
	ADCON1 = 0x0f;
	TRISA = 0b00000000;
	TRISB = 0b00000001;

	INTCONbits.GIE = 1;
	INTCONbits.INT0IE = 1;
	INTCON2bits.INTEDG0 = 0;
	INTCONbits.INT0IF = 0;

	while (1)
	{
		PORTAbits.RA3 = !PORTAbits.RA3;
		Delay10KTCYx(100);
	}
}
