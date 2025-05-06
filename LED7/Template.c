#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

unsigned char ma_led[] =
    {0b11000000, 0b11111001,
     0b10100100, 0b10110000,
     0b10011001, 0b10010010,
     0b10000010, 0b11111000,
     0b10000000, 0b10010000};
unsigned int x, x1, x2, x3, x4;

void main(void)
{
    ADCON1 = 0x0F;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    x = 6869;
    PORTD = 0b00000000;
    while (1)
    {
        x1 = x / 1000;
        x2 = (x % 1000) / 100;
        x3 = ((x % 1000) % 100) / 10;
        x4 = ((x % 1000) % 100) % 10;

        PORTD = 0b00000001;
        PORTC = ma_led[x1];
        Delay1KTCYx(10);

        PORTD = 0b00000010;
        PORTC = ma_led[x2];
        Delay1KTCYx(10);

        PORTD = 0b00000100;
        PORTC = ma_led[x3];
        Delay1KTCYx(10);

        PORTD = 0b00001000;
        PORTC = ma_led[x4];
        Delay1KTCYx(10);
    }
}
