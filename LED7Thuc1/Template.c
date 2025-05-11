// khai bao thu vien
#include <p18f4520.h>
#include <delays.h>
// Cau hinh he thong
#pragma config OSC = HS	  // chon che do thach anh ngoai
#pragma config MCLRE = ON // chon che do Rest tren chan MCLRE
// chuong trinh chinh
#define LED1 PORTDbits.RD0
#define LED2 PORTDbits.RD1

unsigned char maled[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
void main()
{
	// Thuật toán này chưa tối ưu, vui lòng xem led4thuc
	unsigned float f = 9.1;
	unsigned int nguyen = (int)f;
	unsigned int thuc = (int)(f * 10) % 10;
	unsigned char ledThuc = 0;

	TRISC = 0b00000000; // thiet lap huong du lieu
	TRISD = 0b00000000;
	ADCON1 = 0x0f;
	while (1)
	{
		PORTDbits.RD0 = 1;
		PORTDbits.RD1 = 0; // LED1 duoc cap nguon
		ledThuc = maled[nguyen] & 0b01111111;
		PORTC = ledThuc;
		Delay10KTCYx(1); // tre 1/100 giay
		PORTDbits.RD0 = 0;
		PORTDbits.RD1 = 1;
		PORTC = maled[thuc];
		Delay10KTCYx(1);
	}
}
