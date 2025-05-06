#include<p18f4520.h>
#include<delays.h>

char led = 0;
//char led5 = 0;

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF

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
		led = led | 0b00001000;
		PORTB = led;
	}
	else
	{
		INTCON3bits.INT2IF = 0;
		led = led & 0b11110000;
		PORTB = led;
	}
}


void main()
{
	ADCON1 = 0x0F;
	TRISB = 0b00000101;
	
	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 0;
	INTCONbits.INT0IE = 1;
	INTCON2bits.INTEDG0 = 0;
	INTCONbits.INT0IF = 0;

	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 0;
	INTCON3bits.INT2IE = 1;
	INTCON2bits.INTEDG0 = 0;
	INTCON3bits.INT2IF = 0;

	while (1)
	{
		led = led | 0b10000000;
		led =led & 0b10001000; //Giu lai gia tri cho bit 10001000
		PORTB = led;
		Delay10KTCYx(50);

		led = led | 0b01000000;
		led =led & 0b01001000;
		PORTB = led;
		Delay10KTCYx(50);

		led = led | 0b00100000;
		led =led & 0b00101000;
		PORTB = led;
		Delay10KTCYx(50);

		led = led | 0b00010000;
		led =led & 0b00011000;
		PORTB = led;
		Delay10KTCYx(50);
	}
}