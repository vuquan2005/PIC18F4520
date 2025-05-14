#include <p18f4520.h>

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
    if (INTCONbits.TMR0IF == 1)
    {
        INTCONbits.TMR0IF = 0;
        T0CONbits.TMR0ON = 1;

        PORTDbits.RD0 = ~PORTDbits.RD0;
        TMR0H = 3037 / 255;
        TMR0L = 3037 % 255;
        T0CONbits.TMR0ON = 1;
    }
    
}

void main()
{
    ADCON1 = 0x0f;
    TRISD = 0;

    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.GIEL = 1; // không dùng PEIE (lý do không biết:D)
    INTCONbits.TMR0IE = 1;
    INTCON2bits.TMR0IP = 1;
    // TMR0 16bit, chia tan 32
    T0CON = 0b00000100;
    // 2s tran, tc =62500, nạp vào timer 3037
    TMR0H = 3037 / 255;
    TMR0L = 3037 % 255;
    T0CONbits.TMR0ON = 1;

    while (1)
    {
        PORTDbits.RD1 = ~PORTDbits.RD1;
        Delay10KTCYx(50);
    }
}
