/*
#include <mega128a.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

void main(void)
{
    int i = 0;
    // unsigned char led;
    char data[80];
    lcd_init(16);  // 초기화   16자리를 쓰겠다.
    lcd_gotoxy(0, 0);   // x, y 좌표 (0, 0) 윗줄
    lcd_putsf("Hello every!!");   // lcd_putsf (코드비전에만 있는 거임)출력할 문자열을 플레시 메모리에 넣음, 바꿀수 없는 값

    PORTA = 0x55;
    delay_ms(200);
    PORTA = 0xaa;
    delay_ms(200);

    while (1)
      {
        lcd_gotoxy(0 , 1);          // (0, 1) 아랫줄
        for(i = 0; i < 100; i++)
        {
            lcd_gotoxy(0 , 1); // 두 번째 줄에다 1초에 한 번씩 문자를 출력
            sprintf(data, "Your cnt=%2d sec", i);
            lcd_puts(data);     // sprintf 만든 문자열을 출력, 메모리에서
            delay_ms(1000);
        }

      }
}  // 1초마다 카운드 올라가는 것을 출력
*/

/*
#include <mega128a.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

void main(void)
{
    int i = 0;
    unsigned char data[6][80] = {"HELLO", "YONGJOO", "AIOT", "EMBEDDED", "555", "666"};

    lcd_init(16);  // 초기화  16자리를 쓰겠다.

    DDRA = 0xff;     // 1111 1111
    PORTA = 0Xff;
    DDRB = 0xff;
    PORTB = 0Xff;
    DDRD = 0Xfc;      // 2개만 입력 모드
    PORTD = 0Xff;

    while (1)
      {
        for(i = 0; i < 5; i+=2)
        {
            lcd_clear();       // lcd 화면 초기화
            lcd_gotoxy(0 , 0); // 첫 번째 줄에다 1초에 한 번씩 문자를 출력
            lcd_puts(data[i]);     // sprintf 만든 문자열을 출력, 메모리에서
            lcd_gotoxy(0 , 1); // 두 번째 줄에다 1초에 한 번씩 문자를 출력
            lcd_puts(data[i + 1]);     // sprintf 만든 문자열을 출력, 메모리에서
            delay_ms(1000);
        }


        PORTA = PORTB = 0x55;
        delay_ms(200);
        PORTA = PORTB = 0xaa;
        delay_ms(200);

        PORTA = PORTB = 0x55;
        delay_ms(200);
        PORTA = PORTB = 0xaa;
        delay_ms(200);

        PORTA = PORTB = 0xff;
        delay_ms(200);

        }
}*/ // 세 개의 문장이 출력 되고 led 왔다 갔다
