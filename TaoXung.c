#include <p18f4520.h>
//#include <timers.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON

void main()
{
	TRISE = 0b01;
	ADCON1 = 0x0F;
	// Timer1 on, internal clock source, 1:1 prescaler, 16-bit mode
	T1CON = 0b00000001;
	while (1)
	{
		// neu nut nhan tren RE0 thi tat RE1
		if (PORTEbits.RE0 == 0)
		{
			PORTEbits.RE1 = 0;
		}
		else
		{
			// dat gia tri ban dau cho timer1
			// chi lap den 2000 lan cho den khi tran
			TMR1H = (65536 - 2000) / 256;
			TMR1L = (65536 - 2000) % 256;
			// lap cho den khi timer1 tran
			while (PIR1bits.TMR1IF == 0)
				;
			// dao nguoc RE1
			PORTEbits.RE1 = ~PORTEbits.RE1;
			// xoa co tran
			PIR1bits.TMR1IF = 0;
		}
	}
}

// void main()
// {
// 	TRISE = 0b01;
// 	ADCON1 = 0x0F;
//  //Timer1 on, internal clock source, 1:1 prescaler, 16-bit mode
// 	OpenTimer1(TIMER_INT_OFF & T1_PS_1_1 & T1_SOURCE_INT);
// 	while (1)
// 	{
// 		// neu nut nhan tren RE0 thi tat RE1
// 		if (PORTEbits.RE0 == 0)
// 		{
// 			PORTEbits.RE1 = 0;
// 		}
// 		else
// 		{
// 			// dat gia tri ban dau cho timer1
//			// chi lap den 2000 lan cho den khi tran
// 			WriteTimer1(65536 - 2000);
// 			// lap cho den khi timer1 tran
// 			while (PIR1bits.TMR1IF == 0)
// 				;
// 			// dao nguoc RE1
// 			PORTEbits.RE1 = ~PORTEbits.RE1;
// 			// xoa co tran
// 			PIR1bits.TMR1IF = 0;
// 		}
// 	}
// }