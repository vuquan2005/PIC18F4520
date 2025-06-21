# ⏱️ Timer

Mẫu sử dụng Timer thực tế xem [ở đây 📖](#-sử-dụng).

- [Nguồn xung](#nguồn-xung)
- [Chọn hệ số chia tần](#chọn-hệ-số-chia-tần)
- [Cờ tràn](#cờ-tràn)
- [Ngắt timer](#ngắt-timer)
- [Đọc ghi timer](#đọcghi-timer)
- [Hàm trong timers.h](#các-hàm-trong-thư-viện-timersh)

## ✏️ Thanh ghi

### 🖋️ Các thanh ghi liên quan đến Timer

#### [T0CON](#T0CON-1)

| TMR0ON | T08BIT | T0CS | T0SE | PSA | T0PS2 | T0PS1 | T0PS0 |
| ------ | ------ | ---- | ---- | --- | ----- | ----- | ----- |
| 7️⃣     | 6️⃣     | 5️⃣   | 4️⃣   | 3️⃣  | 2️⃣    | 1️⃣    | 0️⃣    |

- Thanh ghi chứa byte thấp của Timer0: TMR0L (8 bit, không định địa chỉ bit)
- Thanh ghi chứa byte cao của Timer0: TMR0H (8 bit, không định địa chỉ bit)
- Thanh ghi điều khiển ngắt : [INTCON](1-Ngat.md##intcon)

#### [T1CON](#T1CON-1)

| RD16 | T1RUN | T1CKPS1 | T1CKPS0 | T1OSCEN | T1SYNC | TMR1CS | TMR1ON |
| ---- | ----- | ------- | ------- | ------- | ------ | ------ | ------ |
| 7️⃣   | 6️⃣    | 5️⃣      | 4️⃣      | 3️⃣      | 2️⃣     | 1️⃣     | 0️⃣     |

- Thanh ghi chứa giá tri đếm byte thấp của Timer1: TMR1L
- Thanh ghi chứa giá tri đếm byte cao của Timer1: TMR1H

#### [T2CON](#T2CON-1)

| —   | T2OUTPS3 | T2OUTPS2 | T2OUTPS1 | T2OUTPS0 | TMR2ON | T2CKPS1 | T2CKPS0 |
| --- | -------- | -------- | -------- | -------- | ------ | ------- | ------- |
| 7️⃣  | 6️⃣       | 5️⃣       | 4️⃣       | 3️⃣       | 2️⃣     | 1️⃣      | 0️⃣      |

- Thanh ghi chứa giá tri đếm của Timer2: TMR2.
- Thanh ghi chu kỳ của Timer2(Period register): PR2.

#### [T3CON](#T3CON-1)

| RD16 | T3CCP2 | T3CKPS1 | T3CKPS0 | T3CCP1 | T3SYNC | TMR3CS | TMR3ON |
| ---- | ------ | ------- | ------- | ------ | ------ | ------ | ------ |
| 7️⃣   | 6️⃣     | 5️⃣      | 4️⃣      | 3️⃣     | 2️⃣     | 1️⃣     | 0️⃣     |

- Thanh ghi chứa giá tri đếm byte thấp của Timer1: TMR1L
- Thanh ghi chứa giá tri đếm byte cao của Timer1: TMR1H

## 🚀 Sử dụng

Lưu ý: có vẻ như timer1 và timer3 hoạt động ở chế độ 16bit. Bit 7 (RD16) trên 2 thanh ghi T1CON và T3CON chỉ là chế độ đọc/ghi, đồng bộ giữa hai thanh ghi L và H chứ không liên quan đến chế độ hoạt động của timer.

### Nguồn xung

- Trong: Fosc/4
- Ngoài: TMR0: T0CKI (RA4); TMR1/3 T13CKI (RC1)

### Chọn hệ số chia tần

Từ yêu cầu T hoặc F đầu bài, ta tính toán giá trị nạp vào timer.

Nếu N < 0 (t > 65536 (16bit) hoặc t > 256 (8bit)), thì ta tăng hệ số chia tần cho đến khi đạt yêu cầu.

Tần số vào timer:

$$ F_{in} = \dfrac{Fosc} {4 * K} $$

Tần số xung đầu ra:

$$ F = \dfrac{Fosc} {4 * K * tc} $$

Thời gian tràn timer (chu kỳ tràn):

$$ T = \dfrac{4 * K * tc} {Fosc} $$

Biến đổi ta có `giá trị timer cần đếm cho đến khi tràn:`

$$ tc = \dfrac{Fosc} {4 * K} * T $$

Hoặc:

$$ tc = \dfrac{Fosc} {4 * K} * \dfrac 1 F $$

Giá trị nạp vào timer:

$$ N = 2^n - tc + 1 $$

Với:

- F<sub>in</sub>: tần số xung đầu vào
- T: chu kỳ xung đầu ra (thời gian tràn timer)
- Fosc: tần số vi xử lý
- K: hệ số chia tần
- N: giá trị khởi đầu (nạp vào timer)
- tc: số giá trị timer cần đếm cho đến khi tràn

Ví dụ: `Tính giá trị nạp vào timer để timer0 tràn trong 100ms, Fosc  4MHz.`

$$ tc = \dfrac{Fosc} {4 * K} * T = \dfrac{4 * 10^3} {4 * 1} * 100*10^{-3} = 100 000 > 65536$$

Vì 100 000 > 65 536 nên ta tăng hệ số chia tần lên 2 (tuỳ timer có hay không có hệ số chia tần 1:2. Nếu không có, có thể chọn hệ số lớn hơn):

$$ tc = \dfrac{4 * 10^6} {4 * 2} * 100*10^{-3} = 50000 < 65536$$

Nạp vào timer:

```c
TMR1H = (65536 - 50000) / 256;
TMR1L = (65536 - 50000) % 256;
// Nếu dùng timers.h
WriteTimer1(65536 - 50000);
```

### Đọc/ghi timer

```c
// Ghi vào timer1
TMR1H = (65536 - tc) / 256;
TMR1L = (65536 - tc) % 256;
// Đọc giá trị timer1
unsigned int tmr = TMR1L + TMR1H * 256;

// Ghi bằng timers.h
WriteTimer1(65536 - tc);
```

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

### Các hàm trong thư viện timers.h

Dưới đây là TIMER1 chỉ mang tính tham khảo vui lòng tra [tài liệu tra cứu PIC (tr44)](0-Tai-lieu-tra-cuu-PIC.pdf) để biết thêm chi tiết về cách sử dụng và các đối số config.

```c
// Cần khai báo thư viện khi sử dụng các hàm liên quan đến timer
#include <timers.h>
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
    WriteTimer1(65536 - tc);
}
```

### Mẫu Timer

```c
#include <p18f4520.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON

void main()
{
 TRISE = 0b01;
 ADCON1 = 0x0F;
 
 while (1)
 {
        // Đặt giá trị ban đầu
        TMR1H = (65536 - 2000) / 256;
        TMR1L = (65536 - 2000) % 256;
        // Bật timer1
     T1CON = 0b00000001;
        // Đợi cho đến khi timer1 tràn
        while (PIR1bits.TMR1IF == 0)
            ;
        // Tắt timer1
     T1CON = 0b00000000;
        // Code tràn timer ở đây
        // Xoá cờ tràn
        PIR1bits.TMR1IF = 0;
 }
}
```

#### Dùng timers.h

```c
#include <p18f4520.h>
#include <timers.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON

void main()
{
 TRISE = 0b01;
 ADCON1 = 0x0F;
    //Timer1 on, internal clock source, 1:1 prescaler
 OpenTimer1(TIMER_INT_OFF & T1_PS_1_1 & T1_SOURCE_INT);
 while (1)
 {

        // Đặt giá trị ban đầu
        WriteTimer1(65536 - 2000);  // 250Hz
        // Đợi cho đến khi timer1 tràn
        while (PIR1bits.TMR1IF == 0)
            ;
        // Code tràn timer ở đây
        // Xoá cờ tràn
        PIR1bits.TMR1IF = 0;
 }
}
```
