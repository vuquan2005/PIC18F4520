# ✂️ Ngắt

Mẫu sử dụng ngắt thực tế xem [ở đây 📖](#-sử-dụng).

-   [Ngắt](#chung)
-   [Ngắt INT0](#int0)
-   [Ngắt INT1](#int1)
-   [Ngắt INT2](#int2)
-   [Mẫu ngắt](#mẫu-ngắt)
-   [Mẫu ngắt có ưu tiên cao/thấp](#mẫu-ngắt-có-phân-ưu-tiên-caothấp)

## ✏️ Thanh ghi

### 🖋️ Các thanh ghi liên quan đến ngắt

#### [RCON](#rcon-1)

| IPEN |
| ---- |
| 7️⃣   |

#### [INTCON](#intcon-1)

| GIE/GIEH | PEIE/GIEL | TMR0IE | INT0IE | RBIE | TMR0IF | INT0IF | RBIF |
| -------- | --------- | ------ | ------ | ---- | ------ | ------ | ---- |
| 7️⃣       | 6️⃣        | 5️⃣     | 4️⃣     | 3️⃣   | 2️⃣     | 1️⃣     | 0️⃣   |

#### [INTCON2](#intcon2-1)

| RBPU | INTEDG0 | INTEDG1 | INTEDG2️2 | —   | TMR0IP | —   | RBIP |
| ---- | ------- | ------- | --------- | --- | ------ | --- | ---- |
| 7️⃣   | 6️⃣      | 5️⃣      | 4️⃣        | 3️⃣  | 2️⃣     | 1️⃣  | 0️⃣   |

#### [INTCON3](#intcon3-1)

| INT2IP | INT1IP | —   | INT2IE | INT1IE | —   | INT2IF | INT1IF |
| ------ | ------ | --- | ------ | ------ | --- | ------ | ------ |
| 7️⃣     | 6️⃣     | 5️⃣  | 4️⃣     | 3️⃣     | 2️⃣  | 1️⃣     | 0️⃣     |

### 📝 Cách dùng

#### [RCON](#rcon)

| Bit | Tên Bit | Mô tả                            |
| --- | ------- | -------------------------------- |
| 7️⃣  | `IPEN`  | Bit cho phép ưu tiên ngắt        |
|     |         | 1 = Cho phép ưu tiên ngắt.       |
|     |         | 0 = Không cho phép ưu tiên ngắt. |

#### [INTCON](#intcon)

| Bit | Tên Bit     | Mô tả                                                                          |
| --- | ----------- | ------------------------------------------------------------------------------ |
| 7️⃣  | `GIE/GIEH ` | Bit cho phép ngắt toàn cục.                                                    |
|     |             | Khi IPEN = 0, cho phép tất cả ngắt không ưu tiên.                              |
|     |             | Khi IPEN = 1, cho phép tất cả ngắt ưu tiên cao.                                |
| 6️⃣  | `PEIE/GIEL` | Bit cho phép ngắt ngoại vi.                                                    |
|     |             | Khi IPEN = 0, cho phép tất cả ngắt ngoại vi không ưu tiên.                     |
|     |             | Khi IPEN = 1, cho phép ngắt ngoại vi ưu tiên thấp.                             |
| 5️⃣  | `TMR0IE`    | Bit cho phép ngắt tràn Timer0 (TMR0).                                          |
|     |             | 1 = Cho phép                                                                   |
|     |             | 0 = Cấm.                                                                       |
| 4️⃣  | `INT0IE`    | Bit cho phép ngắt ngoài INT0.                                                  |
|     |             | 1 = Cho phép                                                                   |
|     |             | 0 = Cấm.                                                                       |
| 3️⃣  | `RBIE`      | Bit cho phép ngắt khi thay đổi mức trên PortB.                                 |
|     |             | 1 = Cho phép                                                                   |
|     |             | 0 = Cấm.                                                                       |
| 2️⃣  | `TMR0IF`    | Cờ báo ngắt tràn [Timer0](2-Timer.md#cờ-tràn). _(Phải được xóa bằng phần mềm)_ |
| 1️⃣  | `INT0IF`    | Cờ báo ngắt ngoài INT0. _(Phải được xóa bằng phần mềm)_                        |
|     |             | 1 = Có ngắt                                                                    |
|     |             | 0 = Không có ngắt.                                                             |
| 0️⃣  | `RBIF`      | Cờ báo thay đổi mức trên PortB. _(Phải được xóa bằng phần mềm)_                |
|     |             | 1 = Có thay đổi                                                                |
|     |             | 0 = Không thay đổi.                                                            |

#### [INTCON2](#intcon2)

| Bit | Tên Bit   | Mô tả                                            |
| --- | --------- | ------------------------------------------------ |
| 7️⃣  | `RBPU`    | Bit cho phép treo các chân PORTB.                |
|     |           | 1 = Cấm                                          |
|     |           | 0 = Cho phép.                                    |
| 6️⃣  | `INTEDG0` | Bit lựa chọn sườn xung cho ngắt ngoài INT0       |
|     |           | 1 = Sườn dương                                   |
|     |           | 0 = Sườn âm                                      |
| 5️⃣  | `INTEDG1` | Bit lựa chọn sườn xung cho ngắt ngoài INT1.      |
|     |           | 1 = Sườn dương                                   |
|     |           | 0 = Sườn âm.                                     |
| 4️⃣  | `INTEDG2` | Bit lựa chọn sườn xung cho ngắt ngoài INT2.      |
|     |           | 1 = Sườn dương                                   |
|     |           | 0 = Sườn âm.                                     |
| 3️⃣  | -         | -                                                |
| 2️⃣  | `TMR0IP`  | Bit lựa chọn mức ưu tiên ngắt cho Timer0.        |
|     |           | 1 = Ưu tiên cao                                  |
|     |           | 0 = Ưu tiên thấp.                                |
| 1️⃣  | -         | -                                                |
| 0️⃣  | `RBIP`    | Bit lựa chọn mức ưu tiên ngắt do thay đổi PortB. |
|     |           | 1 = Ưu tiên cao                                  |
|     |           | 0 = Ưu tiên thấp.                                |

#### [INTCON3](#intcon3)

| Bit | Tên Bit  | Mô tả                                                   |
| --- | -------- | ------------------------------------------------------- |
| 7️⃣  | `INT2IP` | Bit lựa chọn mức ưu tiên ngắt ngoài INT2.               |
|     |          | 1 = Ưu tiên cao                                         |
|     |          | 0 = Ưu tiên thấp                                        |
| 6️⃣  | `INT1IP` | Bit lựa chọn mức ưu tiên ngắt ngoài INT1                |
|     |          | 1 = Ưu tiên cao                                         |
|     |          | 0 = Ưu tiên thấp                                        |
| 5️⃣  | -        | -                                                       |
| 4️⃣  | `INT2IE` | Bit cho phép ngắt ngoài INT2                            |
|     |          | 1 = Cho phép                                            |
|     |          | 0 = Cấm                                                 |
| 3️⃣  | `INT1IE` | Bit cho phép ngắt ngoài INT1.                           |
|     |          | 1 = Cho phép                                            |
|     |          | 0 = Cấm                                                 |
| 2️⃣  | -        | -                                                       |
| 1️⃣  | `INT2IF` | Cờ báo ngắt ngoài INT2. _(Phải được xóa bằng phần mềm)_ |
|     |          | 1 = Có ngắt                                             |
|     |          | 0 = Không có ngắt. _(Phải được xóa bằng phần mềm)_      |
| 0️⃣  | `INT1IF` | Cờ báo ngắt ngoài INT1                                  |
|     |          | 1 = Có ngắt                                             |
|     |          | 0 = Không có ngắt                                       |

## 🚀 Sử dụng

### Chung

```c
INTCONbits.GIE = 1;  // Cho phép ngắt toàn cục
// INTCONbits.PEIE = 1; // Chưa biết dùng =))
```

### INT0

```c
INTCONbits.INT0IE = 1;	 // Cho phép ngắt ngoài INT0
INTCON2bits.INTEDG0 = 0; // Ngắt sườn âm
INTCONbits.INT0IF = 0;	 // Xoá cờ ngắt INT0
// Nếu có ưu tiên
// INTCON2bits.TMR0IP = 1; // Ưu tiên cao
// INTCON2bits.TMR0IP = 0; // Ưu tiên thấp
```

### INT1

```c
INTCON3bits.INT1IE = 1;	 // Cho phép ngắt ngoài INT1
INTCON2bits.INTEDG1 = 0; // Ngắt sườn âm
INTCON3bits.INT1IF = 0;	 // Xoá cờ ngắt INT1
// Nếu có ưu tiên
// INTCON3bits.TMR1IP = 1; // Ưu tiên cao
// INTCON3bits.TMR1IP = 0; // Ưu tiên thấp
```

### INT2

```c
INTCON3bits.INT2IE = 1;	 // Cho phép ngắt ngoài INT2
INTCON2bits.INTEDG2 = 0; // Ngắt sườn âm
INTCON3bits.INT2IF = 0;	 // Xoá cờ ngắt INT2
// Nếu có ưu tiên
// INTCON3bits.TMR2IP = 1; // Ưu tiên cao
// INTCON3bits.TMR2IP = 0; // Ưu tiên thấp
```

### Mẫu ngắt

```c
#include <p18f4520.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF

// Khai báo hàm ngắt ngoài
void ngat_ngoai(void);
// Đặt hàm ngat_ngoai vào tại địa chỉ bộ nhớ 0x08, là địa chỉ vector ngắt ưu tiên cao
// Đối với ưu tiên thấp đặt vào tại địa chỉ bộ nhớ 0x18
#pragma code uu_tien_cao = 0x08
void ngat_cao(void)
{
    ngat_ngoai();
}
#pragma code
// Khai báo ngat_ngoai là hàm phục vụ ngắt
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)
{
    // Code ngắt tại đây
    if (INTCONbits.INT0IF == 1)
    {
        INTCONbits.INT0IF = 0;
        // Code ngắt INT0
    }
    if (INTCON3bits.INT1IF == 1)
    {
        INTCON3bits.INT1IF = 0;
        // Code ngắt INT1
    }
    if (INTCON3bits.INT2IF == 1)
    {
        INTCON3bits.INT2IF = 0;
        // Code ngắt INT2
    }
}
void main()
{
    ADCON1 = 0x0F;
    // Khai báo ba chân INT0, INT1,INT2 (RB0, RB1, RB2)
    TRISB = 0b00000111;
    // Cho phep ngat toan cuc
    INTCONbits.GIE = 1;
    // INT0
    INTCONbits.INT0IE = 1;   // Cho phép ngắt ngoài INT0
    INTCON2bits.INTEDG0 = 0; // Ngắt sườn âm
    INTCONbits.INT0IF = 0;   // Xoá cờ ngắt INT0
    // INT1
    INTCON3bits.INT1IE = 1;  // Cho phép ngắt ngoài INT1
    INTCON2bits.INTEDG1 = 0; // Ngắt sườn âm
    INTCON3bits.INT1IF = 0;  // Xoá cờ ngắt INT1
    // INT2
    INTCON3bits.INT2IE = 1;  // Cho phép ngắt ngoài INT2
    INTCON2bits.INTEDG2 = 0; // Ngắt sườn âm
    INTCON3bits.INT2IF = 0;  // Xoá cờ ngắt INT2

    // Code hàm main ở đây
}
```

### Mẫu ngắt có phân ưu tiên cao/thấp

```c
#include <p18f4520.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
void ngat_uu_tien_cao(void);
void ngat_uu_tien_thap(void);
#pragma code uu_tien_cao = 0x08
void ngat_cao(void)
{
    ngat_uu_tien_cao();
}
#pragma code
#pragma interrupt ngat_uu_tien_cao
void ngat_uu_tien_cao(void)
{
    // Code ngắt ưu tiên cao tại đây
    if (INTCONbits.INT0IF == 1)
    {
        INTCONbits.INT0IF = 0;
        // Code ngắt INT0
    }
    if (INTCON3bits.INT1IF == 1)
    {
        INTCON3bits.INT1IF = 0;
        // Code ngắt INT1
    }
    if (INTCON3bits.INT2IF == 1)
    {
        INTCON3bits.INT2IF = 0;
        // Code ngắt INT2
    }
}
#pragma code uu_tien_thap = 0x18
void ngat_thap(void)
{
    ngat_uu_tien_thap();
}
#pragma code
#pragma interrupt ngat_uu_tien_thap
void ngat_uu_tien_thap(void)
{
    // Code ngắt ưu tiên thấp tại đây
    if (INTCONbits.INT0IF == 1)
    {
        INTCONbits.INT0IF = 0;
        // Code ngắt INT0
    }
    if (INTCON3bits.INT1IF == 1)
    {
        INTCON3bits.INT1IF = 0;
        // Code ngắt INT1
    }
    if (INTCON3bits.INT2IF == 1)
    {
        INTCON3bits.INT2IF = 0;
        // Code ngắt INT2
    }
}
void main()
{
    ADCON1 = 0x0F;
    // Khai báo ba chân INT0, INT1,INT2 <=> RB0, RB1, RB2
    TRISB = 0b00000111;
    // Cho phep ngat toan cuc
    INTCONbits.GIE = 1;
    // INT0
    INTCONbits.INT0IE = 1;   // Cho phép ngắt ngoài INT0
    INTCON2bits.INTEDG0 = 0; // Ngắt sườn âm
    INTCONbits.INT0IF = 0;   // Xoá cờ ngắt INT0
    INTCON3bits.TMR1IP = 1;  // Set ưu tiên ngắt ngoài: cao
    // INT1
    INTCON3bits.INT1IE = 1;  // Cho phép ngắt ngoài INT1
    INTCON2bits.INTEDG1 = 0; // Ngắt sườn âm
    INTCON3bits.INT1IF = 0;  // Xoá cờ ngắt INT1
    INTCON3bits.TMR1IP = 0;  // Set ưu tiên ngắt ngoài: thấp
    // INT2
    INTCON3bits.INT2IE = 1;  // Cho phép ngắt ngoài INT2
    INTCON2bits.INTEDG2 = 0; // Ngắt sườn âm
    INTCON3bits.INT2IF = 0;  // Xoá cờ ngắt INT2
    INTCON3bits.TMR2IP = 0;  // Set ưu tiên ngắt ngoài: thấp

    // Code hàm main ở đây
}
```
