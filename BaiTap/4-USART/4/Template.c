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

void main(void)
{
	char d;
	ADCON1 = 0x0f;
	TRISB = 0;
	TRISD = 0b0001;
	TRISC = 0b10000000;

	OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 35);

	putrsUSART("Hehehe\r\n");
	while (BusyUSART())
		;

	while (1)
	{
		d = ReadUSART();
		switch (d)
		{
		case 'a':
			PORTBbits.RB2 = 1;
			break;
		case 'b':
			PORTBbits.RB2 = 0;
			break;
		case 'c':
			PORTBbits.RB3 = 1;
			break;
		case 'd':
			PORTBbits.RB3 = 0;
			break;
		
		default:
			break;
		}
	}
}
