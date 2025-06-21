#include <p18f4520.h>
#include <pwm.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;
	TRISCbits.RC2 = 0;
	// 1:16
	T2CONbits.T2CKPS1 = 1;
	T2CONbits.T2CKPS0 = 1;

	OpenPWM1(149);
	SetDCPWM1(105);

	while (1)
		;
}
