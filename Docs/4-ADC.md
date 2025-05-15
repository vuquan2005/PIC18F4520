# ADC 📈

## 🚀 Sử dụng

### Thư viện

```c
#include <adc.h>
```

### Các hàm ADC

#### OpenADC

```c
OpenADC(config1, config2, portConfig);
```

Các config1, config2 và portConfig tra tại [tài liệu tra cứu PIC (56-57-53)](/Docs/-Tai%20lieu%20tra%20cuu%20PIC.pdf)

#### BusyADC

```c
while (BusyADC())
    ;
```

Để đợi ADC rảnh/ chuyển đổi xong.
BusyADC là hàm báo bận/đang chuyển đổi AD.

#### ConvertADC

```c
ConvertADC();
```

Bắt đầu thực hiện quá trình chuyển đổi AD.

#### ReadADC

```c
int adc = ReadADC();
```

#### SetChanADC

```c
SetChanADC(channel);
// ADC_CH0 với kênh 0/ chân AN0
```

Lựa chọn kênh đầu vào tương tự cho bộ chuyển đổi AD.

#### CloseADC

```c
CloseADC();
```

Được dùng khi không chuyển đổi AD nữa.

### Cách tính giá trị chuyển đổi ADC

$$ D = \dfrac {V_{in} - V_{ref^-}}{V_{ref^+} - V_{ref^-}} * (2^n - 1) $$

Trong đó:

-   n : Độ phân giải của ADC (8-bit, 10-bit).

Đối với $ V_{ref^+} = VPP = 5(V) $ và $ V_{ref^-} = VSS = 0(V) $ thì:

$$ D = \dfrac {V_{in}} {5} * (2^n - 1) $$

### Mẫu ADC

```c
#include <P18f4520.h>
#include <adc.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config PBADEN = OFF

void main (void)
{
	unsigned int x;
    // Có thể không cần quan tâm 4 bit cuối do sẽ set lại trong portConfig trong OpenADC
	ADCON1 = 0x0f; // = 0b00001111;
    // Khai báo các chân AN là đầu vào
	// Open ADC
	OpenADC(ADC_FOSC_4 & ADC_RIGHT_JUST & ADC_2_TAD,
			ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS,
			portConfig);
	while (1)
	{
        SetChanADC(ADC_CH0);
        // Bắt đầu chuyển đổi
        ConvertADC();
        // Đợi hoàn thành
        while(BusyADC())
            ;
        // Đọc giá trị
        x = ReadADC();
        // Do somethings
	}
}
```
