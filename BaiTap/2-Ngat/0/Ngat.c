#include <p18f4520.h>
#include <delays.h>

// Trạng thái của LED 5
char led = 0;

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF

void ngat_ngoai(void);

#pragma code uu_tien_cao = 0x08
void ngat_cao(void)
{
	ngat_ngoai();
}
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)
{
	if (INTCONbits.INT0IF == 1)
	{
		INTCONbits.INT0IF = 0;
		// led = led | 0b00001000;
		// PORTB = led;
		led = 1;
		PORTB = PORTB | 0b00001000;
	}
	else
	{
		INTCON3bits.INT2IF = 0;
		// led = led & 0b11110000;
		// PORTB = led;
		led = 0;
		PORTB = PORTB & 0b11110000;
	}
}

void main()
{
	ADCON1 = 0x0F;
	TRISB = 0b00000101;

	INTCONbits.GIE = 1; // Cho phep ngat toan cuc

	INTCONbits.INT0IE = 1;	 // Cho phep ngat ngoai INT0
	INTCON2bits.INTEDG0 = 0; // Ngat suon am
	INTCONbits.INT0IF = 0;	 // Xoa co ngat INT0

	INTCON3bits.INT2IE = 1;	 // Cho phep ngat ngoai INT2
	INTCON2bits.INTEDG2 = 0; // Ngat suon am
	INTCON3bits.INT2IF = 0;	 // Xoa co ngat INT2

	while (1)
	{
		// led = led | 0b10000000;
		// led = led & 0b10001000; // Giu lai gia tri cho bit 10001000
		// PORTB = led;
		PORTB = (0b11110000 | (led << 3)) & 0b10001000;
		Delay10KTCYx(100);

		// led = led | 0b01000000;
		// led = led & 0b01001000;
		// PORTB = led;
		PORTB = (0b11110000 | (led << 3)) & 0b01001000;
		Delay10KTCYx(100);

		// led = led | 0b00100000;
		// led = led & 0b00101000;
		// PORTB = led;
		PORTB = (0b11110000 | (led << 3)) & 0b00101000;
		Delay10KTCYx(100);

		// led = led | 0b00010000;
		// led = led & 0b00011000;
		// PORTB = led;
		PORTB = (0b11110000 | (led << 3)) & 0b00011000;
		Delay10KTCYx(100);
	}
}