#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

char n = 0;

void main(void)
{
	ADCON1 = 0x0f;
	TRISBbits.RB2 = 1; // btn 2
	TRISCbits.RC0 = 1; // btn 1
	TRISDbits.RD5 = 0;
	TRISDbits.RD6 = 0;

	while (1)
	{
		// Hiển thị led
		if (n > 3)
			PORTD = 0b01100000;
		else
			PORTD = (n << 5) & 0b01100000;

		if (PORTBbits.RB2 == 1) // btn 2 nhấn
		{
			while (PORTBbits.RB2 == 1)
				if (PORTCbits.RC0 == 1) // btn 1 nhả
				{
					n = 0;
					PORTD = 0;
				}
			// btn 2 nhả
			n++;
		}
		else if (PORTCbits.RC0 == 1) // btn 1 nhả
		{
			n = 0;
			PORTD = 0;
		}
	}
}
