#include <P18f4520.h>
#include <pwm.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;

	TRISB = 0b00000001;
	TRISC = 0b00000000;
	T2CONbits.T2CKPS1 = 1;
	T2CONbits.T2CKPS0 = 1;

	OpenPWM1(149);
	while (1)
	{
		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;
		SetDCPWM1(120);

		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;

		SetDCPWM1(240);

		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;

		SetDCPWM1(480);
	}
}
