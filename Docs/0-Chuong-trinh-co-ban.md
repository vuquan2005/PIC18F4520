# Chương trình cơ bản

```c
#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

// Định nghĩa LED1 là chân RA3 của PORTA
#define LED1 PORTAbits.RA3
// Định nghĩa BTN là chân RB0 của PORTB
#define BTN PORTBbits.RB0

// Khai báo biến kiểu char (8bits)
char portB;

void main(void)
{
    // Khai báo các chân AN0-AN12 là đầu vào/ra số, chi tiết trong ADC
    ADCON1 = 0x0F;
    // Khai báo các PORT
    TRISA = 0; // PORTA là đầu ra tín hiệu
    TRISB = 1; // PORTB là đầu vào tín hiệu
	TRISAbits.TRISA0 = 1; // Khai báo chân RA0 là tín hiệu vào, không ảnh hưởng đến các chân khác
	TRISBbits.TRISB0 = 1; // Khai báo chân RB0 là tín hiệu ra, không ảnh hưởng đến các chân khác

    // Đưa chương trình vào vòng lặp
    while (1)
    {
        // đặt mức logic trên chân RA0 = 1, các chân khác = 0
        PORTA = 0b00000001;
        // đặt mức logic trên chân RA1 = 1, các chân khác giữ nguyên
        PORTAbits.RA1 = 1;
        // đọc giá trị của PORTB
        // portB = PORTB;
        if (BTN == 0)
        {
            // RA3 = 1, vì đã định nghĩa LED1 là chân RA3 của PORTA nên có thể dùng:
            LED1 = 1;
            // đợi 1s (với Fosc = 4MHz)
            Delay10KTCYx(100);
        }
        else
        {
            LED1 = 0;
            Delay10KTCYx(100);
        }
    }
}
```

Cách tính tham số nạp vào các hàm Delay:

$$ T_{delay} = \frac {4}{Fosc} * t * {n} $$

Trong đó:

-   Fosc là tần số của bộ dao động nội.
-   $T_{delay}$ là thời gian delay cần.
-   t là tham số nạp vào hàm Delay.
-   n là bội số của $T_{cy}$ trong Delay`n`TCYx(`t`). (10, 100, 1K, 10K)

_Nếu thời gian cần delay quá lớn, ta có thể chia nhỏ thành nhiều lần delay._
