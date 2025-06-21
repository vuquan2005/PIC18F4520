#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

char dem = 0;

void main(void)
{
	ADCON1 = 0x0f;
	TRISCbits.RC3 = 1;
	TRISD = 0;

	while (1)
	{
		while (PORTCbits.RC3 == 0)
			;
		while (PORTCbits.RC3 == 1)
			;
		dem++;

		PORTD = dem % 10;
	}
}
