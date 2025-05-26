#include <P18f4520.h>
#include <pwm.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

char x = 0;

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
		x++;
		if (x > 3)
			x = 1;
	}
}

void main(void)
{
	ADCON1 = 0x0f;

	INTCONbits.GIE = 1;
	INTCONbits.INT0IE = 1;
	INTCON2bits.INTEDG0 = 0;
	INTCONbits.INT0IF = 0;

	TRISC = 0;
	T2CONbits.T2CKPS1 = 1;
	T2CONbits.T2CKPS0 = 1;

	OpenPWM1(149);
	while (1)
	{
		if (x == 1)
			SetDCPWM1(120);
		else if (x == 2)
			SetDCPWM1(240);
		else if (x == 3)
			SetDCPWM1(480);
	}
}
