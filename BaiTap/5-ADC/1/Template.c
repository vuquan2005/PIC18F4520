#include <p18f4520.h>
// #include <delays.h>
#include <adc.h>

int a = 0;

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main(void)
{
	ADCON1 = 0x0f;
	TRISD = 0;
	TRISC = 0;
	TRISEbits.RE1 = 0;
	TRISAbits.RA5 = 1;

	OpenADC(ADC_FOSC_2 &
				ADC_RIGHT_JUST &
				ADC_2_TAD,
			ADC_CH4 &
				ADC_INT_OFF &
				ADC_VREFPLUS_VDD &
				ADC_VREFMINUS_VSS,
			0b1010);

	while (1)
	{
		ConvertADC();
		while (BusyADC())
			;
		a = ReadADC();
		PORTD = a;
		PORTCbits.RC0 = a >> 8;
		PORTCbits.RC1 = a >> 9;
		if ((a >= 409) & (a <= 614))
			PORTEbits.RE1 = 1;
		else
			PORTEbits.RE1 = 0;
	}
}
