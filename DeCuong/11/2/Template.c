#include <p18f4520.h>
#include <usart.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF
// Config cần cho USART
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

// char txt[] = {'S', 'T', 'A', 'R', 'T'};
char txt[] = "START";

void main(void)
{
	ADCON1 = 0x0f;
	TRISCbits.RC6 = 0;
	TRISCbits.RC7 = 1;
	TRISDbits.RD7 = 0;

	OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH,
			  71);

	putsUSART(txt);

	while (1)
	{
		if (ReadUSART() == 'g')
			PORTDbits.RD7 = 1;
		else
			PORTDbits.RD7 = 0;
	}
}
