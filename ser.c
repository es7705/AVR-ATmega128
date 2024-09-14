#include <mega128a.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>

void main(void)
{
    int i = 0;
    unsigned char led = 0xfe;
    char data[80];
    char res;

DDRA = 0xff;
PORTA = 0Xff;
DDRB = 0xff;
PORTB = 0Xff;
UCSR0A = 0x00;
UCSR0B = 0x18;       // 0001 1000
UCSR0C = 0x06;       // 0000 0110
UBRR0H = 0x00;      // 16비트를 상위 8비트 하위 8비트로 묶임
UBRR0L = 0x67;

printf("Connect sucess!!\n\r");

lcd_init(16);
lcd_gotoxy(0, 0);
lcd_putsf("SerIal connect!!");
printf("'a' led shift left \n\r 'b' led shift right \n\r none is blink");

while (1)
{
    scanf("%c", &res);
    switch (res)
    {
        case 'a':
        {
            led = 0xfe;
            for(i = 0; i < 8; i++)
            {
                 PORTA = led;
                 led = (led<<1) | 0x01;
                 delay_ms(100);
            }   break;
        }

        case 'b':
        {
            led = 0x7f;
            for(i = 0; i < 8; i++)
             {
                 PORTA = led;
                 led = (led>>1) | 0x80 ;
                 delay_ms(100);
             }   break;
        }

        case 'c':
        {
            lcd_gotoxy(0 , 1);          // (0, 1) 아랫줄

             for(i = 10; i >= 1; i--)
            {
                 lcd_gotoxy(0 , 1); // 두 번째 줄에다 1초에 한 번씩 문자를 출력
                 sprintf(data, "Your cnt=%2d sec", i);
                 lcd_puts(data);     // sprintf 만든 문자열을 출력, 메모리에서
                 delay_ms(1000);
            }
            lcd_clear();
            break;
            lcd_gotoxy(0, 0);
            lcd_putsf("SerIal connect!!");
        }

        case 'd':
        {
            led = 0xfe;
            for(i = 0; i < 8; i++)
             {
                 PORTA = led;
                 led = (led<<1) | 0x01 ;
                 delay_ms(100);
             }
             PORTA = 0xff;

             led = 0xfe;
             for(i = 0; i < 8; i++)
             {
                 PORTB = led;
                 led = (led<<1) | 0x01 ;
                 delay_ms(100);
             }
              PORTB = 0xff;
             break;


        }

        default:
        {
            lcd_gotoxy(0, 1);
            lcd_putsf("No key press!!");
        }
    }     // swich
 }
}

/*
#include <mega128a.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>

void main(void)
{
    int i;
    unsigned char led = 0xfe;
     char res;
DDRA = 0xff;
PORTA = 0Xff;
UCSR0A = 0x00;
UCSR0B = 0x18;       // 0001 1000
UCSR0C = 0x06;       // 0000 0110
UBRR0H = 0x00;
UBRR0L = 0x67;

printf("Connect sucess!!\n\r");
printf("Hello World\n\r");

lcd_init(16);
lcd_gotoxy(0, 0);
lcd_putsf("SerIal connect!!");
printf("'a' led shift left \n\r 'b' led shift right \n\r none is blink");

while (1)
{
    scanf("%c", &res);
    switch (res)
    {
        case 'a':
        {
            led = 0xfe;
            for(i = 0; i < 8; i++)
            {
                 PORTA = led;
                 led = (led<<1) | 0x01;
                 delay_ms(300);
            }   break;

        }

        case 'b':
        {
            led = 0x7f;
            for(i = 0; i < 8; i++)
             {
                 PORTA = led;
                 led = (led>>1) | 0x80 ;
                 delay_ms(300);
             }   break;


        }

        default:
        {
            lcd_gotoxy(0, 1);
            lcd_putsf("No key press!!");
        }
    }     // swich
 }

}            // 1월 8일 a를 누르면 led 내려감, b를 누르면 led 올라감
*/

/*
#include <mega128a.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>

void main(void)
{
    int i;
    unsigned char led = 0xfe;

DDRA = 0xff;
PORTA = 0Xff;
UCSR0A = 0x00;
UCSR0B = 0x18;       // 0001 1000
UCSR0C = 0x06;       // 0000 0110
UBRR0H = 0x00;
UBRR0L = 0x67;

printf("Connect sucess!!\n\r");
printf("Hello World\n\r");

lcd_init(16);
lcd_gotoxy(0, 0);
lcd_putsf("SerIal connect!!");

while (1)
{

    led = 0xfe;
    for(i = 0; i < 8; i++)
    {
        PORTA = led;
        led = (led<<1) | 0x01;
        delay_ms(300);
    }
 }

}
*/ // 1월 8일 문자열을 시리얼 통신으로 출력
