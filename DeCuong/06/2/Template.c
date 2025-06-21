#include <p18f4520.h>
#include <pwm.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

// Mặc định PWM 2 sẽ xuất trên chân RC1/CPPAB
#pragma config CCP2MX = PORTBE // đưa về RB3/CCP2A

void main(void)
{
	ADCON1 = 0x0f;
	TRISB = 0;

	T2CONbits.T2CKPS1 = 1;
	T2CONbits.T2CKPS0 = 1;

	OpenPWM2(24);
	SetDCPWM2(30);

	while (1)
		;
}
