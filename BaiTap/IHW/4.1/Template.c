// Hiển thị tần số xung trên chân RC0 (200-250Hz)

#include <p18f4520.h>
// #include <Delays.h>
#include <timers.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF

void main()
{
    ADCON1 = 0x0f;
    TRISCbits.RC0 = 1;
    // TRISCbits.RC1 = 0; // Test thời gian tràn timer0 (cắm timer count/OSCILLOSCOPE vào RC1)
    TRISB = 0;

    OpenTimer0(TIMER_INT_OFF & T0_SOURCE_INT & T0_EDGE_FALL & T0_16BIT & T0_PS_1_32);
    OpenTimer1(TIMER_INT_OFF & T1_16BIT_RW & T1_SOURCE_EXT & T1_PS_1_1 & T1_OSC1EN_OFF);

    while (1)
    {
        // Nạp giá trị đầu vào cho timer (cách tính xem Docs/2-Timer.md)
        WriteTimer0(65536 - 62501);
        // // Test timer0
        // PORTCbits.RC1 = 0; 
        // Delay10KTCYx(20);
        // Đợi timer0 tràn
        while (INTCONbits.TMR0IF == 0)
            ;
        // Xoá cờ tràn
        INTCONbits.TMR0IF = 0;
        // Hiển thị giá trị Timer đếm được trong 2s chia cho 2
        PORTB = ReadTimer1() / 2;
        // Xoá số lần đã đếm được trên timer1
        WriteTimer1(0);
        // PORTCbits.RC1 = 1; // Test timer0
    }
}
