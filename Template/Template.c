#include <p18f4520.h>
// #include <delays.h>
// #include <timers.h>
// #include <pwm.h>
// #include <usart.h>
// #include <stdio.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF
//// Config cần cho USART
// #pragma config PWRT = ON
// #pragma config BOREN = OFF
// #pragma config LVP = OFF

void main(void)
{
    ADCON1 = 0x0f;
    
    while (1)
    {

    }
}

