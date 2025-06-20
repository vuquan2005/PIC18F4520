#include <p18f4520.h>
// #include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;
	TRISD = 0b00000010;

	while (1)
	{
		while (PORTDbits.RD1 == 1)
			;
		while (PORTDbits.RD1 == 0)
			;
		PORTD = 0b00010000;
		while (PORTDbits.RD1 == 1)
			;
		while (PORTDbits.RD1 == 0)
			;
		PORTD = 0b00100000;
		while (PORTDbits.RD1 == 1)
			;
		while (PORTDbits.RD1 == 0)
			;
		PORTD = 0b01000000;
		while (PORTDbits.RD1 == 1)
			;
		while (PORTDbits.RD1 == 0)
			;
		PORTD = 0b10000000;
		while (PORTDbits.RD1 == 1)
			;
		while (PORTDbits.RD1 == 0)
			;
		PORTD = 0b11110000;
	}
}
