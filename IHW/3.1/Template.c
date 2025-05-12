// Hiển thị số lần nhấn nút trên led 7 đoạn bằng ngắt ngoài

#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF

unsigned char x = 0, ma_led[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

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
    if (INTCON3bits.INT1IF == 1)
    {
        INTCON3bits.INT1IF = 0;
        x++;
    }
}
void main()
{
    ADCON1 = 0x0f;
    INTCONbits.GIE = 1;
    INTCON2bits.INTEDG1 = 0;
    INTCON3bits.INT1IE = 1;
    INTCON3bits.INT1IF = 0;

    TRISB = 0b00000010;
    TRISD = 0x00;

    while (1)
    {
        if (!(x > 9))
            PORTD = ma_led[x];
    }
}