#include <P18f4520.h>
#include <adc.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main (void)
{
	unsigned int x;
	ADCON1=0b00001001;
	TRISC=0;
	TRISD=0;
    TRISEbits.TRISE0=1;
	TRISAbits.TRISA0=1;
	TRISBbits.TRISB7=1;
	
	OpenADC(ADC_FOSC_4 & ADC_RIGHT_JUST & ADC_2_TAD, 
			ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 
			0b1001);
	while (1)
	{
		if (PORTBbits.RB7==0) //nhan
		{
			SetChanADC( ADC_CH0 ); 
			ConvertADC();
			while(BusyADC());
			x=ReadADC();
			PORTC=x;
			PORTD=x>>8;
		}
		else
		{
			SetChanADC( ADC_CH5 ); 
			ConvertADC();
			while(BusyADC());
			x=ReadADC();
			PORTC=x;
			PORTD=x>>8;
			
		}
	}
}