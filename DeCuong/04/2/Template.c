#include <p18f4520.h>
#include <timers.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;
	TRISB = 0;
	TRISCbits.RC0 = 1;

	T1CON = 0b00000011;

	// TMR1L = 250;
	while (1)
	{
		PORTB = TMR1L;
	}
}
