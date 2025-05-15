# USART ↔️

## 🚀 Sử dụng

-   [Thư viện, config](#thư-viện-config)
-   [Các hàm USART](#các-hàm-usart)
-   [Cách tính `spbrg`](#cách-tính-spbrg)

### Thư viện, config

```c
#include <usart.h>
// khi muốn dùng putsUSART truyền một chuỗi ký tự, dùng sprintf trong:
// #include <stdio.h>

// Config cần cho USART
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF
```

### Các hàm USART

#### `OpenUSSART`

```c
OpenUSART( unsigned char config, unsigned int spbrg);
```

Các config:

| Config            | Tác dụng                                                  |
| ----------------- | --------------------------------------------------------- |
| USART_TX_INT_ON   | cho phép ngắt truyền                                      |
| USART_TX_INT_OFF  | cấm ngắt truyền                                           |
| \_\_\_\_\_\_\_\_  | \_\_\_\_\_\_\_\_                                          |
| USART_RX_INT_ON   | cho phép ngắt nhận                                        |
| USART_RX_INT_OFF  | cấm ngắt nhận                                             |
| \_\_\_\_\_\_\_\_  | \_\_\_\_\_\_\_\_                                          |
| USART_SYNCH_MODE  | Chọn chế độ đồng bộ (Synchronous Mode)                    |
| USART_ASYNCH_MODE | Chọn chế độ không đồng bộ (Asynchronous Mode)             |
| USART_SYNCH_MODE  | Chọn chế độ đồng bộ (Synchronous Mode)                    |
| \_\_\_\_\_\_\_\_  | \_\_\_\_\_\_\_\_                                          |
| USART_EIGHT_BIT   | Chọn chế độ truyền/nhận 8 bit (8-bit transmit/receive)    |
| USART_NINE_BIT    | Chọn chế độ truyền/nhận 9 bit (9-bit transmit/receive)    |
| \_\_\_\_\_\_\_\_  | \_\_\_\_\_\_\_\_                                          |
| USART_SYNC_SLAVE  | Chọn chế độ tớ (Synchronous Slave mode)                   |
| USART_SYNC_MASTER | Chọn chế độ chủ (Synchronous Master mode)                 |
| \_\_\_\_\_\_\_\_  | \_\_\_\_\_\_\_\_                                          |
| USART_SINGLE_RX   | Chọn chế độ nhận từng byte (Single reception)             |
| USART_CONT_RX     | Chọn chế độ nhận liên tục các byte (Continuous reception) |
| \_\_\_\_\_\_\_\_  | \_\_\_\_\_\_\_\_                                          |
| USART_BRGH_HIGH   | Chọn tốc độ baud cao (High baud rate)                     |
| USART_BRGH_LOW    | Chọn tốc độ baud thấp (Low baud rate)                     |

#### `CloseUSART`

```c
while (BusyUSART())
    ;
```

Để đợi USART rảnh
BusyUSART là hàm báo bận/đang truyền

#### `CloseUSART`

```c
CloseUSART();
```

Được dùng khi không sử dụng USART nữa.

#### `ReadUSART`

```c
char kyTu = ReadUSART();
```

Hàm được sử dụng để nhận một byte từ USART.

#### `WriteUSART`

```c
WriteUSART(kyTu);
```

Được dùng khi muốn truyền một byte dữ liệu qua USART.

#### `putsUSART`

```c
putsUSART(txt);
```

Gửi một chuỗi ký tự (string) thông qua USART.

#### `putrsUSART`

```c
putrsUSART(txt);
```

Giống với putsUSART (ít dùng hơn putsUSART), nhưng chuỗi được lưu trữ trong ROM thay vì RAM.

### Cách tính `spbrg`

-   **USART_SYNCH_MODE**

Chế độ đồng bộ:

$$ spbrg = \dfrac {FOSC} {4 * BaudRate} -1 $$

-   **USART_ASYNCH_MODE** (_USART_BRGH_HIGH_)

Chế độ không đồng bộ, baude cao:

$$ spbrg = \dfrac {FOSC} {16 * BaudRate} -1 $$

-   **USART_ASYNCH_MODE** (_USART_BRGH_LOW_)

Chế độ không đồng bộ, baude thấp:

$$ spbrg = \dfrac {FOSC} {64 * BaudRate} -1 $$

### Mẫu USART

```c
#include <p18f4520.h>
#include <usart.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config PWRT=ON
#pragma config BOREN=OFF
#pragma config LVP=OFF

void main()
{
    char kyTu;
    ADCON1 = 0x0F;
    // Khai báo chân TX ra, RX vào
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;
    
    OpenUSART( config, spbrg);

    while (1)
    {
        kyTu = ReadUSART();
        WriteUSART(kyTu);
        // Do some thing
    }
}

```