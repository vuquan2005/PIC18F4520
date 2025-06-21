#include <p18f4520.h>
#include <timers.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;
	TRISDbits.RD1 = 0;

	// Fosc = 12MHz
	T0CON = 0b00001000;
	// OpenTimer0(T0_16BIT & T0_PS_1_1 & T0_SOURCE_INT);

	while (1)
	{
		TMR0H = (65536-3000) / 256;
		TMR0L = (65536-3000) % 256;
		T0CONbits.TMR0ON = 1;

		// WriteTimer0(65536-3000);
		while (INTCONbits.TMR0IF == 0)
			;
		T0CONbits.TMR0ON = 0;
		INTCONbits.TMR0IF = 0;

		PORTDbits.RD1 = !PORTDbits.RD1;
	}
}
