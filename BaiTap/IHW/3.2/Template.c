// Hiển thị số lần nhấn 2 nút trên 2 led 7 đoạn bằng ngắt ngoài có ưu tiên ngắt

#include <p18f4520.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF

unsigned char i1 = 0, i2 = 0;
unsigned char x = 0, ma_led[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void ngat_uu_tien_cao(void);
void ngat_uu_tien_thap(void);
#pragma code uu_tien_cao = 0x08
void ngat_cao(void)
{
    ngat_uu_tien_cao();
}
#pragma code
#pragma interrupt ngat_uu_tien_cao
void ngat_uu_tien_cao(void)
{
    if (INTCONbits.INT0IF == 1)
    {
        INTCONbits.INT0IF = 0;
        i1++;
    }
}
#pragma code uu_tien_thap = 0x18
void ngat_thap(void)
{
    ngat_uu_tien_thap();
}
#pragma code
#pragma interrupt ngat_uu_tien_thap

void ngat_uu_tien_thap(void)
{
    if (INTCON3bits.INT1IF == 1)
    {
        INTCON3bits.INT1IF = 0;
        i2++;
    }
}

void main()
{
    ADCON1 = 0x0f;

    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;

    INTCONbits.INT0IE = 1;
    INTCON3bits.INT1IE = 1;

    INTCON2bits.INTEDG0 = 0;
    INTCON2bits.INTEDG1 = 0;

    INTCON3bits.INT1IP = 0;

    INTCONbits.INT0IF = 0;
    INTCON3bits.INT1IF = 0;

    TRISB = 0b00000011;
    TRISC = 0x00;
    TRISD = 0x00;

    while (1)
    {
        if (i1 < 10)
            PORTC = ma_led[i1];
        if (i2 < 10)
            PORTD = ma_led[i2];
    }
}
