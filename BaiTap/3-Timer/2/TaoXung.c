// Tạo xung trên chân RD1, tần số 50Hz nếu nút được nhấn, 100Hz nếu nút nhả

#include <p18f4520.h>
#include <timers.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON

void main()
{
	ADCON1 = 0x0F;
	TRISCbits.RC0 = 1;
	TRISDbits.RD1 = 0;

	// Timer1 on, internal clock source, 1:1 prescaler, 16-bit mode
	OpenTimer1(TIMER_INT_OFF & T1_PS_1_1 & T1_SOURCE_INT);
	while (1)
	{
		// neu nut nhan tren RE0 thi tat RD1
		if (PORTCbits.RC0 == 0)
		{
			WriteTimer1(65536 - 10000);
			// lap cho den khi timer1 tran
			while (PIR1bits.TMR1IF == 0)
				;
			// dao nguoc RD1
			PORTDbits.RD1 = ~PORTDbits.RD1;
			// xoa co tran
			PIR1bits.TMR1IF = 0;
		}
		else
		{
			WriteTimer1(65536 - 5000);
			while (PIR1bits.TMR1IF == 0)
				;
			PORTDbits.RD1 = ~PORTDbits.RD1;
			PIR1bits.TMR1IF = 0;
		}
	}
}