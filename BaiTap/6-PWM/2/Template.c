// Tạo xung PWM ở chân RC1 T=1200us, 8MHz, xung theo số lần nhấn nút RB0

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
	// Hệ số chia 1:16
	T2CONbits.T2CKPS1 = 1;
	T2CONbits.T2CKPS0 = 1;
	// Tạo xung PWM ở chân RC1/CCP2B => sử dụng PWM2
	OpenPWM2(149);
	while (1)
	{
		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;
		// 20%
		SetDCPWM2(120);

		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;
		// 40%
		SetDCPWM2(240);

		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;
		// 80%
		SetDCPWM2(480);
	}
}
