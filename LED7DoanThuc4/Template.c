#include <p18f4520.h>
#include <delays.h>
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

unsigned char ma_led[] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
unsigned char led[] = {0b00000001, 0b00000010, 0b00000100, 0b00001000};
unsigned int luyThua10[] = {10, 100, 1000};
unsigned char so[] = {0, 0, 0, 0};
unsigned char i;
unsigned char dotIndex;
unsigned int soHienthi;
float f = 45.67;

void main(void)
{
	ADCON1 = 0x0F;
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	PORTD = 0b00000000;
	while (1)
	{
		for (i = 0; i <= 3; i++)
		{
			if (f / luyThua10[i] < 1)
			{
				dotIndex = i;
				break;
			}
		}
		soHienthi = (unsigned int)(f * luyThua10[2 - dotIndex]);
		if (soHienthi >= 1000 && soHienthi <= 9999)
		{
			so[0] = soHienthi / 1000;
			so[1] = (soHienthi % 1000) / 100;
			so[2] = ((soHienthi % 1000) % 100) / 10;
			so[3] = ((soHienthi % 1000) % 100) % 10;
		}

		PORTD = 0b00000001;
		PORTC = ma_led[so[0]];
		Delay10KTCYx(1);

		PORTD = 0b00000010;
		PORTC = ma_led[so[1]];
		Delay10KTCYx(1);

		PORTD = 0b00000100;
		PORTC = ma_led[so[2]];
		Delay10KTCYx(1);

		PORTD = 0b00001000;
		PORTC = ma_led[so[3]];
		Delay10KTCYx(1);

		PORTD = led[dotIndex];
		PORTC = ma_led[so[dotIndex]] & 0b01111111;
		Delay10KTCYx(1);
	}
}
