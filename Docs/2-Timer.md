# ⏱️ Timer

Mẫu sử dụng Timer thực tế xem [ở đây 📖](#-sử-dụng).

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

#### [T3CON](#T3CON-1)

| RD16 | T3CCP2 | T3CKPS1 | T3CKPS0 | T3CCP1 | T3SYNC | TMR3CS | TMR3ON |
| ---- | ------ | ------- | ------- | ------ | ------ | ------ | ------ |
| 7️⃣   | 6️⃣     | 5️⃣      | 4️⃣      | 3️⃣     | 2️⃣     | 1️⃣     | 0️⃣     |

### 📝 Cách dùng

#### [T0CON](#T0CON)

| Bit | Tên Bit  | Mô tả                                               |
| --- | -------- | --------------------------------------------------- |
| 7️⃣  | `TMR0ON` | Bit điều khiển Bật/Tắt Timer.                       |
|     |          | 1 = Cho phép Timer0                                 |
|     |          | 0 = Dừng Timer0                                     |
| 6️⃣  | `T08BIT` | Bit lựa chọn 8-bit /16-bit của Timer0               |
|     |          | 1 = Timer0 dùng bộ đếm 8-bit                        |
|     |          | 0 = Timer0 dùng bộ đếm 16-bit                       |
| 5️⃣  | `T0CS`   | Bit lựa chọn nguồn xung cấp cho Timer0              |
|     |          | 1 = Sườn dương                                      |
|     |          | 0 = Sườn âm.                                        |
| 4️⃣  | `T0SE`   | Bit lựa chọn sườn xung đếm cho Timer0               |
|     |          | 1 = Sườn dương                                      |
|     |          | 0 = Sườn âm.                                        |
| 3️⃣  | `PSA`    | Bit thiết lập bộ chia tần đầu vào                   |
| 2️⃣  | `T0PS`   | Bit lựa chọn hệ số chia tần:                        |
| 1️⃣  | `T0PS`   | 111 = 1:256 ; 110 = 1:128 ; 101 = 1:64 ; 100 = 1:32 |
| 0️⃣  | `T0PS`   | 011 = 1:16 ; 010 = 1:8 ; 001 = 1:4 ; 000 = 1:2      |

#### [T1CON](#T1CON)

| Bit | Tên Bit   | Mô tả                                                                         |
| --- | --------- | ----------------------------------------------------------------------------- |
| 7️⃣  | `RD16`    | Bit lựa chọn chế độ ghi/đọc Timer1                                            |
|     |           | 1 = Timer1 dùng bộ đếm 8-bit                                                  |
|     |           | 0 = Timer1 dùng bộ đếm 16-bit                                                 |
| 6️⃣  | `T1RUN`   | Bit cho phép hệ thống lấy xung từ Timer1                                      |
|     |           | 1 = Hệ thống hoạt động bằng nguồn xung cấp từ Timer1                          |
|     |           | 0 = Hệ thống hoạt động bằng nguồn xung khác                                   |
| 5️⃣  | `T1CKPS1` | Các bit đặt hệ số chia tần số của xung cấp cho Timer1                         |
|     |           | 11 = Hệ số chia là 1:8                                                        |
| 4️⃣  | `T1CKPS0` | 10 = Hệ số chia là 1:4                                                        |
|     |           | 01 = Hệ số chia là 1:2                                                        |
|     |           | 00 = Hệ số chia là 1:1                                                        |
| 3️⃣  | `T1OSCEN` | Bit cho phép/cấm chức năng phát xung cho hệ thống                             |
|     |           | 1 = Cho phép                                                                  |
|     |           | 0 = Cấm                                                                       |
| 2️⃣  | `T1SYNC`  | Bit lựa chọn sự đồng bộ giữa xung ngoài cấp cho Timer1 và xung trên chip.     |
|     |           | Khi bit TMR1CS = 1:                                                           |
|     |           | 1 = Không đồng bộ                                                             |
|     |           | 0 = Đồng bộ xung ngoài với xung trên chip                                     |
|     |           | Khi bit TMR1CS = 0: T1SYNC không có giá trị. (Timer1 sử dụng nguồn xung nội). |
| 1️⃣  | `TMR1CS`  | Bit lựa chọn nguồn xung cấp cho Timer1                                        |
|     |           | 1 = Timer1 được cấp xung từ ngoài qua chân RC0/T1OSO/T13CKI                   |
|     |           | 0 = Timer1 được cấp xung nội (tần số bằng FOSC/4)                             |
| 0️⃣  | `TMR1ON`  | Bit điều khiển hoạt động của Timer1                                           |
|     |           | 1 = Timer1 hoạt động                                                          |
|     |           | 0 = Dừng Timer1                                                               |

#### [T2CON](#T2CON)

| Bit | Tên Bit | Mô tả |
| --- | ------- | ----- |

#### [T3CON](#T3CON)

| Bit | Tên Bit | Mô tả |
| --- | ------- | ----- |

## 🚀 Sử dụng

### TMR0

```c

```

### TMR1

```c

```

### TMR2

```c

```

### TMR3

```c

```

### Các hàm trong thư viện timers.h

Dưới đây là TIMER1 chỉ mang tính tham khảo vui lòng tra [tài liệu tra cứu PIC](0-Tai-lieu-tra-cuu-PIC.pdf) để biết thêm chi tiết về cách sử dụng và các đối số config.

```c
#include <timers.h>
// Cần khai báo thư viện khi sử dụng các hàm liên quan đến timer
{
    // Hàm sử dụng để cấm hoạt động của timer
    CloseTimer1();
    // Hàm sử dụng để thiết lập các tham số cho timer
    OpenTimer1(unsigned char config1
                        &config2
                        &...);
    // Hàm sử dụng để đọc giá trị hiện thời của timer
    int timer_value = ReadTimer1();
    // Hàm sử dụng để ghi giá trị vào timer
    WriteTimer1(unsigned int timer_value);
}
```
