// truyền một số lần nhấn nút qua USART, không dùng ngắt, ngừng khi nhận ký tự 'a'

#include <p18f4520.h>
#include <usart.h>
#include <delays.h>
#include <stdio.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
// Config cần cho USART
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

unsigned char n = 0;
char x, txt[10];

#define PB PORTAbits.RA0

void main()
{
    ADCON1 = 0x0f;
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 1;
    // Mở USART, baudrate 4800, Fosc = 11.0592 MHz, baud cao, 8 bit,...
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 143);

    while (1)
    {
        // Đếm số lần nhấn nút
        while (PB == 0)
            ;
        while (PB == 1)
            ;
        n++;

        // Lớn hơn 12 thì dừng
        if (n > 12)
            break;

        // Chờ đợi để gửi xong// Chờ đợi để gửi xong
        while (BusyUSART())
            ;
        // Nếu nhận được ký tự 'a' thì dừng
        x = ReadUSART();
        if (x == 'a')
            break;

        // Chuyển số thành chuỗi (\r\n là xuống dòng, có thể bỏ qua)
        sprintf(txt, "%d,0\r\n", n);
        // Chờ USART rảnh
        while (BusyUSART())
            ;
        // Gửi chuỗi
        putsUSART(txt);
    }
    // Nếu chương trình gặp lỗi thì tạo vòng lặp ở đây để tránh chương trình lặp lại
    // while (1)
    //     ;
}