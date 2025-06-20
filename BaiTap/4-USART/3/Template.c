//

#include <p18f4520.h>
#include <usart.h>
#include <delays.h>
#include <stdio.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
// Config cần cho USART, lấy ở trang 16 tài liệu tra cứu pic
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

char n = 0;
#define PB PORTAbits.RA0

void main()
{
	ADCON1 = 0x0f;
	TRISC = 0b10000000;
	TRISD = 0;
	// Mở USART, baudrate 19200, Fosc = 12 MHz, baud cao, 8 bit,...
	OpenUSART(USART_RX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_BRGH_HIGH & USART_CONT_RX & USART_EIGHT_BIT, 38);

	while (BusyUSART())
		;
	WriteUSART(0x41);
	while (BusyUSART())
		;
	WriteUSART(0x61);

	while (1)
	{
		while (BusyUSART())
			;
		n = ReadUSART();
		PORTD = n;
	}
}