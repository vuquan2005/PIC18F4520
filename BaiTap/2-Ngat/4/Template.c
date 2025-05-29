#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

int i = 0;

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
	if (INTCON3bits.INT1IF == 1)
	{
		INTCON3bits.INT1IF = 0;
		PORTCbits.RC2 = 0;

		for (i = 0; i < 20; i++)
		{
			PORTCbits.RC4 = !PORTCbits.RC4;
			Delay10KTCYx(20);
		}
	}
}

void main(void)
{
	ADCON1 = 0x0f;

	TRISB = 0b00000010;
	TRISC = 0b00000000;

	INTCONbits.GIE = 1;

	INTCON3bits.INT1IE = 1;
	INTCON2bits.INTEDG1 = 0;
	INTCON3bits.INT1IF = 0;

	while (1)
	{
		PORTCbits.RC2 = !PORTCbits.RC2;
		Delay10KTCYx(20);
	}
}
