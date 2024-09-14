/*
#include <mega128a.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>
#define ADC_VREF_TYPE 0x00

char data[80];
unsigned char result = 0xff;
unsigned int adc_data;

interrupt [ADC_INT] void adc(void)
{
    adc_data=ADCW;
}

void main(void)
{
     DDRB = 0xff;
     PORTB = 0xff;  // PORT -> OUTPUT 선언된 포트르르 제어하는 레지스터, pin -> input 선언된 포트를 제어
     DDRF |= 0xfd;
     ADMUX =0x40;     // 0100 0000
     ADCSRA = 0xfe;   // 1111 1110
     ADCSRA |= 0x08;
     ADCSRA |= 0x40;
     #asm("sei");
    // int i = 0;
    // unsigned char led;


UCSR0A = 0x00;     // UCSR0A : USARTO 제어 레지스터
UCSR0B = 0x18;     // 0001 1000 -> 수신(0001), 송신(1000) 가능 상태
UCSR0C = 0x00;     // 0000 0110 -> 비동기, 정지비트 2비트 (0) + 길이 8비트 (110) + 비동기(0)
UBRR0L = 0x67;

ADMUX  = 0x40;
ADCSRA = 0xfe;
// ADCSRA |= 0X08;    // ADC INTERRUPT ENABLE
// ADCSRA |= 0X08;    // ADC START CONVERATION

lcd_init(16);
lcd_gotoxy(0,0);            // 좌표값 윗줄에 출력
lcd_putsf(" VAR Value..."); // lcd에 출력
#asm("sei")

while (1)
      {
      lcd_clear();
      lcd_putsf(" VAR Value..."); // lcd에 출력
       sprintf(data, "A/D = %d", adc_data);
       lcd_gotoxy(0,1);
       lcd_puts(data);
       delay_ms(300);
      }
}      // 가변저항값 불러와서 출력
*/

/////////////////////////////////////////////////////////////////////////

/*
#include <mega128a.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>
#define ADC_VREF_TYPE 0x00

unsigned char result = 0xff;
char data[80];
interrupt [ADC_INT] void adc(void)
{
    #asm("cli");
    result = ADCL;
    result = ADCH;
    #asm("sei");

   /*unsigned int adc_data;
    adc_data=ADCW;*/
}

void main(void)
{
     DDRB = 0xff;
     PORTB = 0xFF;  // PORT -> OUTPUT 선언된 포트르르 제어하는 레지스터, pin -> input 선언된 포트를 제어
     DDRF |= 0x00;

     ADMUX =0x20;
     ADCSRA = 0xA7;
     ADCSRA |= 0x08;   // 0000 1000
     ADCSRA |= 0x40;   // 0100 0000
 #asm("sei")
     // int i = 0;
    // unsigned char led;

/*
UCSR0A = 0x00;     // UCSR0A : USARTO 제어 레지스터
UCSR0B = 0x18;     // 0001 1000 -> 수신(0001), 송신(1000) 가능 상태
UCSR0C = 0x00;     // 0000 0110 -> 비동기, 정지비트 2비트 (0) + 길이 8비트 (110) + 비동기(0)
UBRR0L = 0x67;  */


lcd_init(16);
lcd_gotoxy(0,0);            // 좌표값 윗줄에 출력
lcd_putsf(" VAR Value..."); // lcd에 출력


while (1)
      {
       sprintf(data, "A/D = %4d", result);
       lcd_gotoxy(0,1);
       lcd_puts(data);
       delay_ms(100);
       /*if(result > 0x80) PORTB = 0x00;
       else PORTB = 0xff;      */
      }
}              // 1월 9일 가변저항 값 읽어와 lcd에 출력
*/

/////////////////////////////////////////////////////////////////////////

/*
#include <mega128a.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>
#define ADC_VREF_TYPE 0x00

unsigned char result = 0xff;
char data[80];
char ch0, ch1;
void f1()
{
     ADMUX =0x20;
     ADCSRA = 0xA7;    // 1010 0111
     ADCSRA |= 0x08;   // 0000 1000
     ADCSRA |= 0x40;   // 0100 0000
     delay_ms(10);
}

void f2()
{
     ADMUX =0x21;
     ADCSRA = 0xA7;    // 1010 0111
     ADCSRA |= 0x08;   // 0000 1000
     ADCSRA |= 0x40;   // 0100 0000
     delay_ms(10);
}

interrupt [ADC_INT] void adc(void)
{
    #asm("cli");
    result = ADCL;
    result = ADCH;
    #asm("sei");
}

void main(void)
{
     DDRB = 0xff;
     PORTB = 0xFF;  // PORT -> OUTPUT 선언된 포트르르 제어하는 레지스터, pin -> input 선언된 포트를 제어
     DDRF |= 0x00;

     #asm("sei")

lcd_init(16);
lcd_gotoxy(0,0);            // 좌표값 윗줄에 출력
lcd_putsf(" VAR Value..."); // lcd에 출력

    while (1)
      {

        f1();
        ch0 = result;

        f2();
        ch1 = result;


       sprintf(data, "AD0=%3d, AD1=%3d", ch0, ch1);
       lcd_gotoxy(0,1);
       lcd_puts(data);
       delay_us(10);
      }
} // F포트 0번은 가변저항 값 , 1번은 조도센서 값을 lcd에 출력
*/

/////////////////////////////////////////////////////////////////////////

/*
#include <mega128a.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>
#define ADC_VREF_TYPE 0x00

unsigned char result = 0xff;
char data[80];

void main(void)
{
     // DDRB = 0xff;
     // PORTB = 0xFF;  // PORT -> OUTPUT 선언된 포트르르 제어하는 레지스터, pin -> input 선언된 포트를 제어

lcd_init(16);
lcd_gotoxy(0,0);            // 좌표값 윗줄에 출력
lcd_putsf(" VAR Value..."); // lcd에 출력

    while (1)
      {

        ADMUX =0x22; // 00 : 전압 공급원천 / 0 : 10비트, 8비트 / 00010 : AD핀 주소
        ADCSRA = 0xA7;    // 1010 0111
        ADCSRA |= 0x08;   // 0000 1000
        ADCSRA |= 0x40;   // 0100 0000
        delay_ms(100);

       sprintf(data, "AD0=%3d", result);
       lcd_gotoxy(0,1);
       lcd_puts(data);
       delay_us(10);
      }
}
*/

/////////////////////////////////////////////////////////////////////////

/*
#include <mega128a.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>


#define ADC_VREF_TYPE 0x00

unsigned char result = 0xff;

interrupt [ADC_INT] void adc_isr(void)
{
#asm("cli");
result=ADCL;
result=ADCH;
#asm("sei");
}

void main(void)
{
    char data[80];
    unsigned char len;

DDRA = 0xff;
DDRB = 0xff;
DDRF=0x00;

UCSR0A=0x00;
UCSR0B=0x18;
UCSR0C=0x06;
UBRR0H=0x00;
UBRR0L=0x67;

// ADC initialization
// ADC Clock frequency: 250.000 kHz
// Select the ADC input used in interrupt mode: ADC0

ADMUX=0x22;
ADCSRA=0xa7;
ADCSRA |= 0x40;     // ADC start conversion
ADCSRA |= 0x08;     // ADC interrupt enable

lcd_init(16);
lcd_gotoxy(0,0);
lcd_putsf(" AVR Value...");
#asm("sei");

while (1)
      {
      PORTA=0xff,PORTB=0xff;

        if(result>=25) {PORTA=0x00,PORTB=0x00;len=80;}
        if(result>=26) {PORTA=0x00,PORTB=0x80;len=75;}
        if(result>=27) {PORTA=0x00,PORTB=0xc0;len=70;}
        if(result>=28) {PORTA=0x00,PORTB=0xe0;len=65;}
        if(result>=29) {PORTA=0x00,PORTB=0xf0;len=60;}
        if(result>=33) {PORTA=0x00,PORTB=0xf8;len=55;}
        if(result>=34) {PORTA=0x00,PORTB=0xfc;len=50;}
        if(result>=39) {PORTA=0x00,PORTB=0xfe;len=45;}
        if(result>=42) {PORTA=0x00,PORTB=0xff;len=40;}
        if(result>=47) {PORTA=0x80,PORTB=0xff;len=35;}
        if(result>=53) {PORTA=0xc0,PORTB=0xff;len=30;}
        if(result>=62) {PORTA=0xe0,PORTB=0xff;len=25;}
        if(result>=75) {PORTA=0xf0,PORTB=0xff;len=20;}
        if(result>=97) {PORTA=0xf8,PORTB=0xff;len=15;}
        if(result>=131) {PORTA=0xfc,PORTB=0xff;len=10;}
        if(result>=160) {PORTA=0xfe,PORTB=0xff;len=5;}
        // if(result<=25) {PORTA=0xff,PORTB=0xff;len=0;}
        lcd_gotoxy(0,1);
        sprintf(data,"length =%2dcm",len);
        lcd_puts(data);
        delay_ms(200);
      }
}
*/ // PSD 센서로 거리 측정하여 lcd에 거리 출력


