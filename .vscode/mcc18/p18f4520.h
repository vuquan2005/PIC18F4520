#ifndef __18F4520_H
#define __18F4520_H

#pragma warning disable 520

// Define PORT registers
volatile unsigned char PORTA;
volatile unsigned char PORTB;
volatile unsigned char PORTC;
volatile unsigned char PORTD;
volatile unsigned char PORTE;

// Define TRIS registers
volatile unsigned char TRISA;
volatile unsigned char TRISB;
volatile unsigned char TRISC;
volatile unsigned char TRISD;
volatile unsigned char TRISE;

// Define other registers
volatile unsigned char ADCON1;

volatile unsigned char INTCON;
volatile unsigned char INTCON2;
volatile unsigned char INTCON3;

volatile unsigned char T0CON;
volatile unsigned char T1CON;
volatile unsigned char T2CON;
volatile unsigned char T3CON;

volatile unsigned char TMR0L;
volatile unsigned char TMR0H;
volatile unsigned char TMR1L;
volatile unsigned char TMR1H;
volatile unsigned char TMR3L;
volatile unsigned char TMR3H;

// Define PORTA bits
struct
{
	unsigned RA0 : 1;
	unsigned RA1 : 1;
	unsigned RA2 : 1;
	unsigned RA3 : 1;
	unsigned RA4 : 1;
	unsigned RA5 : 1;
	unsigned RA6 : 1;
	unsigned RA7 : 1;
} PORTAbits;

// Define PORTB bits
struct
{
	unsigned RB0 : 1;
	unsigned RB1 : 1;
	unsigned RB2 : 1;
	unsigned RB3 : 1;
	unsigned RB4 : 1;
	unsigned RB5 : 1;
	unsigned RB6 : 1;
	unsigned RB7 : 1;
} PORTBbits;

// Define PORTC bits
struct
{
	unsigned RC0 : 1;
	unsigned RC1 : 1;
	unsigned RC2 : 1;
	unsigned RC3 : 1;
	unsigned RC4 : 1;
	unsigned RC5 : 1;
	unsigned RC6 : 1;
	unsigned RC7 : 1;
} PORTCbits;

// Define PORTD bits
struct
{
	unsigned RD0 : 1;
	unsigned RD1 : 1;
	unsigned RD2 : 1;
	unsigned RD3 : 1;
	unsigned RD4 : 1;
	unsigned RD5 : 1;
	unsigned RD6 : 1;
	unsigned RD7 : 1;
} PORTDbits;

// Define PORTE bits
struct
{
	unsigned RE0 : 1;
	unsigned RE1 : 1;
	unsigned RE2 : 1;
	unsigned RE3 : 1;
} PORTEbits;

struct
{
	unsigned RA0 : 1;
	unsigned RA1 : 1;
	unsigned RA2 : 1;
	unsigned RA3 : 1;
	unsigned RA4 : 1;
	unsigned RA5 : 1;
	unsigned RA6 : 1;
	unsigned RA7 : 1;
} TRISAbits;

struct
{
	unsigned RB0 : 1;
	unsigned RB1 : 1;
	unsigned RB2 : 1;
	unsigned RB3 : 1;
	unsigned RB4 : 1;
	unsigned RB5 : 1;
	unsigned RB6 : 1;
	unsigned RB7 : 1;
} TRISBbits;

struct
{
	unsigned RC0 : 1;
	unsigned RC1 : 1;
	unsigned RC2 : 1;
	unsigned RC3 : 1;
	unsigned RC4 : 1;
	unsigned RC5 : 1;
	unsigned RC6 : 1;
	unsigned RC7 : 1;
} TRISCbits;

struct
{
	unsigned RD0 : 1;
	unsigned RD1 : 1;
	unsigned RD2 : 1;
	unsigned RD3 : 1;
	unsigned RD4 : 1;
	unsigned RD5 : 1;
	unsigned RD6 : 1;
	unsigned RD7 : 1;
} TRISDbits;

struct
{
	unsigned RE0 : 1;
	unsigned RE1 : 1;
	unsigned RE2 : 1;
	unsigned RE3 : 1;
} TRISEbits;

union
{
	struct
	{
		unsigned BOR : 1;
		unsigned POR : 1;
		unsigned PD : 1;
		unsigned TO : 1;
		unsigned RI : 1;
		unsigned : 1;
		unsigned SBOREN : 1;
		unsigned IPEN : 1;
	};
	struct
	{
		unsigned NOT_BOR : 1;
		unsigned NOT_POR : 1;
		unsigned NOT_PD : 1;
		unsigned NOT_TO : 1;
		unsigned NOT_RI : 1;
	};
} RCONbits;

union
{
	struct
	{
		unsigned RBIF : 1;
		unsigned INT0IF : 1;
		unsigned TMR0IF : 1;
		unsigned RBIE : 1;
		unsigned INT0IE : 1;
		unsigned TMR0IE : 1;
		unsigned PEIE : 1;
		unsigned GIE : 1;
	};
	struct
	{
		unsigned : 1;
		unsigned INT0IF : 1;
		unsigned T0IF : 1;
		unsigned : 1;
		unsigned INT0IE : 1;
		unsigned T0IE : 1;
		unsigned GIEL : 1;
		unsigned GIEH : 1;
	};
} INTCONbits;

union
{
	struct
	{
		unsigned RBIP : 1;
		unsigned : 1;
		unsigned TMR0IP : 1;
		unsigned : 1;
		unsigned INTEDG2 : 1;
		unsigned INTEDG1 : 1;
		unsigned INTEDG0 : 1;
		unsigned RBPU : 1;
	};
	struct
	{
		unsigned : 7;
		unsigned NOT_RBPU : 1;
	};
} INTCON2bits;

union
{
	struct
	{
		unsigned INT1F : 1;
		unsigned INT2F : 1;
		unsigned : 1;
		unsigned INT1E : 1;
		unsigned INT2E : 1;
		unsigned : 1;
		unsigned INT1P : 1;
		unsigned INT2P : 1;
	};
	struct
	{
		unsigned INT1IF : 1;
		unsigned INT2IF : 1;
		unsigned : 1;
		unsigned INT1IE : 1;
		unsigned INT2IE : 1;
		unsigned : 1;
		unsigned INT1IP : 1;
		unsigned INT2IP : 1;
	};
} INTCON3bits;

struct
{
	unsigned T0PS0 : 1;
	unsigned T0PS1 : 1;
	unsigned T0PS2 : 1;
	unsigned PSA : 1;
	unsigned T0SE : 1;
	unsigned T0CS : 1;
	unsigned T08BIT : 1;
	unsigned TMR0ON : 1;
} T0CONbits;

union
{
	struct
	{
		unsigned TMR1ON : 1;
		unsigned TMR1CS : 1;
		unsigned T1SYNC : 1;
		unsigned T1OSCEN : 1;
		unsigned T1CKPS0 : 1;
		unsigned T1CKPS1 : 1;
		unsigned T1RUN : 1;
		unsigned RD16 : 1;
	};
	struct
	{
		unsigned : 2;
		unsigned NOT_T1SYNC : 1;
	};
} T1CONbits;

struct
{
	unsigned T2CKPS0 : 1;
	unsigned T2CKPS1 : 1;
	unsigned TMR2ON : 1;
	unsigned T2OUTPS0 : 1;
	unsigned T2OUTPS1 : 1;
	unsigned T2OUTPS2 : 1;
	unsigned T2OUTPS3 : 1;
} T2CONbits;

union
{
	struct
	{
		unsigned TMR3ON : 1;
		unsigned TMR3CS : 1;
		unsigned T3SYNC : 1;
		unsigned T3CCP1 : 1;
		unsigned T3CKPS0 : 1;
		unsigned T3CKPS1 : 1;
		unsigned T3CCP2 : 1;
		unsigned RD16 : 1;
	};
	struct
	{
		unsigned : 2;
		unsigned NOT_T3SYNC : 1;
	};
} T3CONbits;

unsigned char PIE1;
struct
{
	unsigned TMR1IE : 1;
	unsigned TMR2IE : 1;
	unsigned CCP1IE : 1;
	unsigned SSPIE : 1;
	unsigned TXIE : 1;
	unsigned RCIE : 1;
	unsigned ADIE : 1;
	unsigned PSPIE : 1;
} PIE1bits;
unsigned char PIR1;
struct
{
	unsigned TMR1IF : 1;
	unsigned TMR2IF : 1;
	unsigned CCP1IF : 1;
	unsigned SSPIF : 1;
	unsigned TXIF : 1;
	unsigned RCIF : 1;
	unsigned ADIF : 1;
	unsigned PSPIF : 1;
} PIR1bits;
unsigned char IPR1;
struct
{
	unsigned TMR1IP : 1;
	unsigned TMR2IP : 1;
	unsigned CCP1IP : 1;
	unsigned SSPIP : 1;
	unsigned TXIP : 1;
	unsigned RCIP : 1;
	unsigned ADIP : 1;
	unsigned PSPIP : 1;
} IPR1bits;
unsigned char PIE2;
union
{
	struct
	{
		unsigned CCP2IE : 1;
		unsigned TMR3IE : 1;
		unsigned HLVDIE : 1;
		unsigned BCLIE : 1;
		unsigned EEIE : 1;
		unsigned : 1;
		unsigned CMIE : 1;
		unsigned OSCFIE : 1;
	};
	struct
	{
		unsigned : 2;
		unsigned LVDIE : 1;
	};
} PIE2bits;
unsigned char PIR2;
union
{
	struct
	{
		unsigned CCP2IF : 1;
		unsigned TMR3IF : 1;
		unsigned HLVDIF : 1;
		unsigned BCLIF : 1;
		unsigned EEIF : 1;
		unsigned : 1;
		unsigned CMIF : 1;
		unsigned OSCFIF : 1;
	};
	struct
	{
		unsigned : 2;
		unsigned LVDIF : 1;
	};
} PIR2bits;
unsigned char IPR2;
union
{
	struct
	{
		unsigned CCP2IP : 1;
		unsigned TMR3IP : 1;
		unsigned HLVDIP : 1;
		unsigned BCLIP : 1;
		unsigned EEIP : 1;
		unsigned : 1;
		unsigned CMIP : 1;
		unsigned OSCFIP : 1;
	};
	struct
	{
		unsigned : 2;
		unsigned LVDIP : 1;
	};
} IPR2bits;

#endif /* __18F4520_H */