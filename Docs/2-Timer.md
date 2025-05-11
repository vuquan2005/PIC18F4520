# ⏱️ Timer

Mẫu sử dụng Timer thực tế xem [ở đây 📖](#-sử-dụng).


## ✏️ Thanh ghi

### 🖋️ Các thanh ghi liên quan đến Timer

#### [T0CON](#T0CON-1)

| TMR0ON | T08BIT | T0CS | T0SE | PSA | T0PS2 | T0PS1 | T0PS0 |
| ------ | ------ | ---- | ---- | --- | ----- | ----- | ----- |
| 7️⃣     | 6️⃣     | 5️⃣   | 4️⃣   | 3️⃣  | 2️⃣    | 1️⃣    | 0️⃣    |

-   Thanh ghi chứa byte thấp của Timer0: TMR0L (8 bit, không định địa chỉ bit)
-   Thanh ghi chứa byte cao của Timer0: TMR0H (8 bit, không định địa chỉ bit)
-   Thanh ghi điều khiển ngắt : [INTCON](/1-Ngat.md##intcon)

#### [T1CON](#T1CON-1)

| RD16 | T1RUN | T1CKPS1 | T1CKPS0 | T1OSCEN | T1SYNC | TMR1CS | TMR1ON |
| ---- | ----- | ------- | ------- | ------- | ------ | ------ | ------ |
| 7️⃣   | 6️⃣    | 5️⃣      | 4️⃣      | 3️⃣      | 2️⃣     | 1️⃣     | 0️⃣     |

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

| Bit | Tên Bit  | Mô tả                                       |
| --- | -------- | ------------------------------------------- |

#### [T1CON](#T1CON)

| Bit | Tên Bit     | Mô tả                                                           |
| --- | ----------- | --------------------------------------------------------------- |

#### [T2CON](#T2CON)

| Bit | Tên Bit   | Mô tả                                            |
| --- | --------- | ------------------------------------------------ |

#### [T3CON](#T3CON)


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

### Mẫu ngắt

```c

```

### Mẫu ngắt có phân ưu tiên cao/thấp

```c

```
