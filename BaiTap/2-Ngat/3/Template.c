// Hiển thị số lần nhấn nút 4 led, nút 1 tăng, nút 2 reset, led còn lại nhấp nháy liên tục

#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF

char x = 0;

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
    // kiểm tra cờ ngắt 0
    if (INTCONbits.INT0IF == 1)
    {
        INTCONbits.INT0IF = 0;
        // Code ngắt 0

        if (x < 8)
        {
            // nếu lớn hơn 8 thì không tăng biến đếm nữa
            x++;
        }

        // hiển thị x lên led
        PORTB = x << 3;
    }
    // kiểm tra cờ ngắt 2
    if (INTCON3bits.INT2IF == 1)
    {
        INTCON3bits.INT2IF = 0;
        // Code ngắt 2
        // reset biến đếm
        x = 0;
        // reset led
        PORTB = x << 3;
    }
}
void main()
{
    ADCON1 = 0x0f;
    // RB0 là nút nhấn, RB1 là nút nhấn, đầu vào, các chân khác đầu ra
    TRISB = 0b00000101;

    // Cấu hình ngắt ngoài
    INTCONbits.GIE = 1;  // Cho phép ngắt toàn cục
    INTCONbits.PEIE = 1; 

    INTCONbits.INT0IE = 1;   // Cho phép ngắt ngoài INT0
    INTCON2bits.INTEDG0 = 0; // Ngắt sườn âm
    INTCONbits.INT0IF = 0;   // Xoá cờ ngắt INT0

    INTCON3bits.INT2IE = 1;  // Cho phép ngắt ngoài INT2
    INTCON2bits.INTEDG2 = 0; // Ngắt sườn âm
    INTCON3bits.INT2IF = 0;  // Xoá cờ ngắt INT2

    while (1)
    {
        PORTBbits.RB7 = ~PORTBbits.RB7;
        Delay10KTCYx(50);
    }
}