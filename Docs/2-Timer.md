# ⏱️ Timer

Mẫu sử dụng Timer thực tế xem [ở đây 📖](#-sử-dụng).

-   [Nguồn xung](#nguồn-xung)
-   [Chọn hệ số chia tần](#chọn-hệ-số-chia-tần)
-   [Cờ tràn](#cờ-tràn)
-   [Ngắt timer](#ngắt-timer)
-   [Đọc ghi timer](#đọcghi-timer)
-   [Hàm trong timers.h](#các-hàm-trong-thư-viện-timersh)

## ✏️ Thanh ghi

### 🖋️ Các thanh ghi liên quan đến Timer

#### [T0CON](#T0CON-1)

| TMR0ON | T08BIT | T0CS | T0SE | PSA | T0PS2 | T0PS1 | T0PS0 |
| ------ | ------ | ---- | ---- | --- | ----- | ----- | ----- |
| 7️⃣     | 6️⃣     | 5️⃣   | 4️⃣   | 3️⃣  | 2️⃣    | 1️⃣    | 0️⃣    |

-   Thanh ghi chứa byte thấp của Timer0: TMR0L (8 bit, không định địa chỉ bit)
-   Thanh ghi chứa byte cao của Timer0: TMR0H (8 bit, không định địa chỉ bit)
-   Thanh ghi điều khiển ngắt : [INTCON](1-Ngat.md##intcon)

#### [T1CON](#T1CON-1)

| RD16 | T1RUN | T1CKPS1 | T1CKPS0 | T1OSCEN | T1SYNC | TMR1CS | TMR1ON |
| ---- | ----- | ------- | ------- | ------- | ------ | ------ | ------ |
| 7️⃣   | 6️⃣    | 5️⃣      | 4️⃣      | 3️⃣      | 2️⃣     | 1️⃣     | 0️⃣     |

-   Thanh ghi chứa giá tri đếm byte thấp của Timer1: TMR1L
-   Thanh ghi chứa giá tri đếm byte cao của Timer1: TMR1H

#### [T2CON](#T2CON-1)

| —   | T2OUTPS3 | T2OUTPS2 | T2OUTPS1 | T2OUTPS0 | TMR2ON | T2CKPS1 | T2CKPS0 |
| --- | -------- | -------- | -------- | -------- | ------ | ------- | ------- |
| 7️⃣  | 6️⃣       | 5️⃣       | 4️⃣       | 3️⃣       | 2️⃣     | 1️⃣      | 0️⃣      |

-   Thanh ghi chứa giá tri đếm của Timer2: TMR2.
-   Thanh ghi chu kỳ của Timer2(Period register): PR2.

#### [T3CON](#T3CON-1)

| RD16 | T3CCP2 | T3CKPS1 | T3CKPS0 | T3CCP1 | T3SYNC | TMR3CS | TMR3ON |
| ---- | ------ | ------- | ------- | ------ | ------ | ------ | ------ |
| 7️⃣   | 6️⃣     | 5️⃣      | 4️⃣      | 3️⃣     | 2️⃣     | 1️⃣     | 0️⃣     |

-   Thanh ghi chứa giá tri đếm byte thấp của Timer1: TMR1L
-   Thanh ghi chứa giá tri đếm byte cao của Timer1: TMR1H

## 🚀 Sử dụng

### Nguồn xung

-   Trong: Fosc/4
-   Ngoài: TMR0: T0CKI (RA4); TMR1/3 T13CKI (RC1)

## Chọn hệ số chia tần

Từ yêu cầu T hoặc F đầu bài, ta tính toán giá trị nạp vào timer.

Nếu N < 0 (t > 6536 (16bit) hoặc t > 256 (8bit)), thì ta tăng hệ số chia tần cho đến khi đạt yêu cầu.

$ F_{in} = \dfrac{Fosc} {4*K} $

$ T= \dfrac{tc*4*K} {Fosc} $

$ tc = \dfrac{T*Fosc} {4*K} $

$ N= 2^n - tc +1 $

Với:

-   F<sub>in</sub>: tần số xung đầu vào
-   T: chu kỳ xung đầu ra (thời gian tràn timer)
-   Fosc: tần số vi xử lý
-   K: hệ số chia tần
-   N: giá trị khởi đầu (nạp vào timer)
-   tc: số giá trị timer cần đếm cho đến khi tràn

### Bật/tắt timer

```c
// Bật timers
T0CONbits.TMR0ON = 1;
T1CONbits.TMR1ON = 1;
T2CONbits.TMR2ON =1;
T3CONbits.TMR3ON =1;
```

### Cờ tràn

```c
// Kiểm tra tràn: == 1;
// Đợi tràn while(timerIF == 0);
INTCONbits.TMR0IF == 1; // Cờ tràn timer 0
PIR1bits.TMR1IF == 1;   // Cờ tràn timer 1
PIR1bits.TMR2IF == 1;   // Cờ tràn timer 2
PIR2bits.TMR3IF == 1;   // Cờ tràn timer 3
```

### Ngắt timer

```c
RCONbits.IPEN = 1;
INTCONbits.GIE = 1;
// dùng GIEL, không dùng PEIE (lý do không biết:D)
INTCONbits.GIEL = 1;
// cho phép ngắt tràn TMR0, tương tự timer khác
INTCONbits.TMR0IE = 1;
// Set mức ưu tiến ngắt tràn timer0
INTCON2bits.TMR0IP = 1;
// Cờ tràn/ngắt timer
INTCONbits.TMR0IF = 0;
```

### Đọc/ghi timer

```c
// Ghi vào timer1
TMR1H = (65536 - t) / 256;
TMR1L = (65536 - t) % 256;
// Đọc giá trị timer1
unsigned int tmr = TMR1L + TMR1H * 256;
```

### Các hàm trong thư viện timers.h

Dưới đây là TIMER1 chỉ mang tính tham khảo vui lòng tra [tài liệu tra cứu PIC (tr44)](0-Tai-lieu-tra-cuu-PIC.pdf) để biết thêm chi tiết về cách sử dụng và các đối số config.

```c
#include <timers.h>
// Cần khai báo thư viện khi sử dụng các hàm liên quan đến timer
{
    // Hàm sử dụng để thiết lập các tham số cho timer
    OpenTimer1(unsigned char config1
                        &config2
                        &...);
    // Hàm sử dụng để đọc giá trị hiện thời của timer
    unsigned int timer_value = ReadTimer1();
    // Đợi timer tràn
    while (INTCONbits.TMR0IF == 1)
        ;
    // Hàm sử dụng để cấm hoạt động của timer
    CloseTimer1();
    // Hàm sử dụng để ghi giá trị vào timer
    WriteTimer1(unsigned int timer_value);
}
```
