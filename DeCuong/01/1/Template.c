#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;
	TRISD = 0b000000100;

	while (1)
	{
		if (PORTDbits.RD2 == 0)
			PORTD = 0b00000000;
		else
		{
			PORTD = 0b00010000;
			Delay10KTCYx(100);
			PORTD = 0b00100000;
			Delay10KTCYx(100);
			PORTD = 0b01000000;
			Delay10KTCYx(100);
			PORTD = 0b10000000;
			Delay10KTCYx(100);
		}
	}
}
