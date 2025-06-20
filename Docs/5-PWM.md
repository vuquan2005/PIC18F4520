# PWM 📊

## 🚀 Sử dụng

### Thư viện

```c
#include <pwm.h>
```

### Các hàm PWM

#### OpenPWM

```c
OpenPWM1(period);
OpenPWM2(period);
```

Cách tính giá trị period:

$$ period = \dfrac {Fosc} {4*K} * {T_{PWM}} -1 $$

Trong đó:

-   $T_{PWM}$ : là chu kỳ của xung PWM
-   $K$ : hệ số chia tần timer2 (1:1, 1:4, 1:16)

$period$ : thoả mãn khi $period < 255 $, nếu không thoả mãn tăng $K$.

#### SetDCPWM

```c
SetDCPWM1(dutycycle);
SetDCPWM2(dutycycle);
```

Cách tính dutycycle:

$$ dutycycle = \dfrac {Fosc} {K} * T_{PWM} * T_{on} $$

Trong đó:

-   $T_{on}$ : tỷ lệ độ rộng xung dương so với xung $T_{PWM}$ ($T_{on}$).

Ví dụ:

$T_{on} = 50\% = 0.5$

$ T_{on} = \dfrac 3 7 * T_{off} = 30\% = 0.3$. 

Vì: $T_{on} + T_{off} = 1$

#### ClosePWM

```c
ClosePWM1();
ClosePWM2();
```

### Mẫu PWM

```c
#include <p18f4520.h>
#include <pwm.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main (void)
{
    ADCON1 = 0x0f;

	TRISC=0;
    // Hệ số chia tần TMR2 = 16
	T2CONbits.T2CKPS1=1;
	T2CONbits.T2CKPS0=1;
	// Có thể dùng hàm OpenTimer2
	// OpenTimer2(T2_PS_1_16)

    // Tần số xung 1000Hz, Fosc = 8MHz
	OpenPWM1(124);

	// Ban đầu khi chưa nhấn
	// Độ rộng xung dương 25%
	SetDCPWM1(125);

	while (1)
	{
		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;
		// Nhấn 1 lần
		// Độ rộng xung dương 50%
		SetDCPWM1(250);
		while (PORTBbits.RB0 == 0)
			;
		while (PORTBbits.RB0 == 1)
			;
		// Nhấn 2 lần
		// Độ rộng xung dương 100%
		SetDCPWM1(500);
		
		// Lặp lại, đợi nút nhấn rồi về xung 50% bên trên
	}
}
```
