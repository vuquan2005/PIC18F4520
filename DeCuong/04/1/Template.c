#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;
	TRISD = 0;
	TRISBbits.RB1 = 1;
	TRISCbits.RC3 = 1;

	while (1)
	{
		if (PORTCbits.RC3 == 0) // btn1
		{
			if (PORTBbits.RB1 == 0) // btn2
				PORTD = 0b00010000;
			else
				PORTD = 0b00100000;
		}
		else
		{
			if (PORTBbits.RB1 == 0)
				PORTD = 0b01000000;
			else
				PORTD = 0b10000000;
		}
	}
}
