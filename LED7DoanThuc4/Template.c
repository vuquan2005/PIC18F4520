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
unsigned int luyThua10[] = {1, 10, 100, 1000};
unsigned char so[] = {0, 0, 0, 0};
unsigned char i;
unsigned int soHienthi;
float f = 0.456;

void main(void)
{
	ADCON1 = 0x0F;
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	PORTD = 0b00000000;
	while (1)
	{
		soHienthi = (unsigned int)(f);
		// lấy vị trí dấu chấm thập phân
		for (i = 0; i <= 3; i++)
		{
			if (soHienthi < 10)
				break;
			else
				soHienthi = soHienthi / 10;
		}
		// lấy toàn bộ các chữ số từ f sang soHienthi
		soHienthi = (unsigned int)(f * luyThua10[3 - i]);
		// lấy từng chữ số lưu vào các biến
		so[0] = soHienthi / 1000;
		so[1] = (soHienthi % 1000) / 100;
		so[2] = ((soHienthi % 1000) % 100) / 10;
		so[3] = ((soHienthi % 1000) % 100) % 10;
		// hiển thị các số trên led
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
		// hiển thị dấu chấm thập phân
		PORTD = led[i];
		PORTC = ma_led[so[i]] & 0b01111111;
		Delay10KTCYx(1);
	}
}
