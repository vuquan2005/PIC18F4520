#include <p18f4520.h>
#include <delays.h>
#include <timers.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

// lấy ở trang 73 tài liệu tra cứu PIC18F4520
char maled[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
char n1, n2;

void main(void)
{
    ADCON1 = 0x0F;
    TRISD = 0;
    TRISE = 0;
    TRISB = 0b00000001;
    TRISC = 0b00000001;

    // khai báo timer 3, nguồn xung ngoài, chế độ 1:1, on
    T3CON = 0b00000011;

    while (1)
    {
        if (PORTBbits.RB0 == 0)
            TMR3L = 0; // nếu nhấn nút thì reset số lần nhấn

        TMR3L;
        if (TMR3L >= 10)
            T3CONbits.TMR3ON = 0; // tắt timer 3 nếu lớn hơn 10

        n1 = TMR3L / 10;
        n2 = TMR3L % 10;
        // hiển lên led 1
        PORTE = 0b0001;
        PORTD = maled[n1];
        Delay10KTCYx(1);

        // hiển lên led 2
        PORTE = 0b0010;
        PORTD = maled[n2];
        Delay10KTCYx(1);
    }
}