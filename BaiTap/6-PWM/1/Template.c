// Tạo xung PWM trên RC2/CCP1

#include <P18f4520.h>
#include <pwm.h>
// #include <timers.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;

	TRISC = 0;
	T2CONbits.T2CKPS1 = 1;
	T2CONbits.T2CKPS0 = 1;
	// OpenTimer2(T2_PS_1_16)

	OpenPWM1(124);

	SetDCPWM1(250);
}