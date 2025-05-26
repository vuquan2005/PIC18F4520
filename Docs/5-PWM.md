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

$$ period = \dfrac {F_{OSC}} {4*K} * {T_{PWM}} -1 $$

Trong đó:

-   $T_{PWM}$ : là chu kỳ của xung tạo ra
-   $K$ : hệ số chia tần timer2 (1:1, 1:4, 1:16)

$period$ : thoả mãn khi $period < 255 $, nếu không thoả mãn tăng $K$.

#### SetDCPWM

```c
SetDCPWM1(dutycycle);
SetDCPWM2(dutycycle);
```

Cách tính dutycycle:

$$ dutycycle = \dfrac {F_{OSC}} {K} * T_{PWM} * PW $$

Trong đó:

-   $PW$ : tỷ lệ độ rộng xung dương so với xung $T_{PWM}$. VD: 70%.

#### ClosePWM

```c
ClosePWM1();
ClosePWM2();
```

### Mẫu PWM

```c
#include <P18f4520.h>
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
    // Tần số xung 1000Hz
	OpenPWM1(124);
    // Độ rộng xung dương 100%
	// SetDCPWM1(500);
    // Độ rộng xung dương 50%
	SetDCPWM1(250);
}
```
