#include <p18f4520.h>
#include <adc.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

int adcValue = 0;

void main(void)
{
	ADCON1 = 0x0f;
	TRISC = 0;
	TRISD = 0;
	TRISEbits.RE1 = 0;
	TRISAbits.RA1 = 1;

	OpenADC(ADC_RIGHT_JUST & ADC_20_TAD, ADC_CH1 & ADC_VREFMINUS_VSS & ADC_VREFPLUS_VDD, 0b1101);

	while (1)
	{
		ConvertADC();

		while (BusyADC())
			;

		adcValue = ReadADC();

		if (adcValue > 654)
			PORTEbits.RE1 = 1;
		else
			PORTEbits.RE1 = 0;

		PORTD = adcValue;
		PORTC = adcValue >> 8;
	}
}
