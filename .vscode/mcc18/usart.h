#ifndef __USART_H
#define __USART_H

#define USART_TX_INT_ON 0b11111111	 // Transmit interrupt on
#define USART_TX_INT_OFF 0b01111111	 // Transmit interrupt off
#define USART_RX_INT_ON 0b11111111	 // Receive interrupt on
#define USART_RX_INT_OFF 0b10111111	 // Receive interrupt off
#define USART_BRGH_HIGH 0b11111111	 // High baud rate
#define USART_BRGH_LOW 0b11101111	 // Low baud rate
#define USART_CONT_RX 0b11111111	 // Continuous reception
#define USART_SINGLE_RX 0b11110111	 // Single reception
#define USART_SYNC_MASTER 0b11111111 // Synchrounous master mode
#define USART_SYNC_SLAVE 0b11111011	 // Synchrounous slave mode
#define USART_NINE_BIT 0b11111111	 // 9-bit data
#define USART_EIGHT_BIT 0b11111101	 // 8-bit data
#define USART_SYNCH_MODE 0b11111111	 // Synchronous mode
#define USART_ASYNCH_MODE 0b11111110 // Asynchronous mode

#define BAUD_IDLE_CLK_HIGH 0b11111111 // idle state for clock is a high level
#define BAUD_IDLE_CLK_LOW 0b11101111  // idle state for clock is a low level
#define BAUD_16_BIT_RATE 0b11111111	  // 16-bit baud generation rate
#define BAUD_8_BIT_RATE 0b11110111	  // 8-bit baud generation rate
#define BAUD_WAKEUP_ON 0b11111111	  // RX pin monitored
#define BAUD_WAKEUP_OFF 0b11111101	  // RX pin not monitored
#define BAUD_AUTO_ON 0b11111111		  // auto baud rate measurement enabled
#define BAUD_AUTO_OFF 0b11111110	  // auto baud rate measurement disabled

union USART
{
	unsigned char val;
	struct
	{
		unsigned RX_NINE : 1;		// Receive Bit 8 if 9-bit mode is enabled
		unsigned TX_NINE : 1;		// Transmit Bit 8 if 9-bit mode is enabled
		unsigned FRAME_ERROR : 1;	// Framing Error for USART
		unsigned OVERRUN_ERROR : 1; // Overrun Error for USART
		unsigned fill : 4;
	};
};

void OpenUSART(unsigned char config, unsigned spbrg);
#define DataRdyUSART() (PIR1bits.RCIF)
char ReadUSART(void);
void WriteUSART(char data);
void getsUSART(char *buffer, unsigned char len);
void putsUSART(char *data);
void putrsUSART(char *data);
#define getcUSART ReadUSART
#define putcUSART WriteUSART
#define unsigned char CloseUSART()
#define unsigned char BusyUSART()
void baudUSART(char baudconfig);

#endif