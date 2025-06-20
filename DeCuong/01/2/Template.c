#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

char i = 0;

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
		PORTEbits.RE1 = 0;
		for (; i < 10; i++)
		{
			PORTEbits.RE2 = !PORTEbits.RE2;
			Delay10KTCYx(50);
		}
		i = 0;
	}
}

void main(void)
{
	ADCON1 = 0x0f;
	TRISEbits.RE1 = 0;
	TRISEbits.RE2 = 0;
	TRISBbits.RB0 = 1;

	INTCONbits.GIE = 1;

	INTCONbits.INT0IE = 1;
	INTCON2bits.INTEDG0 = 0;
	INTCONbits.INT0IF = 0;

	while (1)
	{
		PORTEbits.RE1 = !PORTEbits.RE1;
		Delay10KTCYx(50);
	}
}
