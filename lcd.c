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
    lcd_init(16);  // �ʱ�ȭ   16�ڸ��� ���ڴ�.
    lcd_gotoxy(0, 0);   // x, y ��ǥ (0, 0) ����
    lcd_putsf("Hello every!!");   // lcd_putsf (�ڵ�������� �ִ� ����)����� ���ڿ��� �÷��� �޸𸮿� ����, �ٲܼ� ���� ��

    PORTA = 0x55;
    delay_ms(200);
    PORTA = 0xaa;
    delay_ms(200);

    while (1)
      {
        lcd_gotoxy(0 , 1);          // (0, 1) �Ʒ���
        for(i = 0; i < 100; i++)
        {
            lcd_gotoxy(0 , 1); // �� ��° �ٿ��� 1�ʿ� �� ���� ���ڸ� ���
            sprintf(data, "Your cnt=%2d sec", i);
            lcd_puts(data);     // sprintf ���� ���ڿ��� ���, �޸𸮿���
            delay_ms(1000);
        }

      }
}  // 1�ʸ��� ī��� �ö󰡴� ���� ���
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

    lcd_init(16);  // �ʱ�ȭ  16�ڸ��� ���ڴ�.

    DDRA = 0xff;     // 1111 1111
    PORTA = 0Xff;
    DDRB = 0xff;
    PORTB = 0Xff;
    DDRD = 0Xfc;      // 2���� �Է� ���
    PORTD = 0Xff;

    while (1)
      {
        for(i = 0; i < 5; i+=2)
        {
            lcd_clear();       // lcd ȭ�� �ʱ�ȭ
            lcd_gotoxy(0 , 0); // ù ��° �ٿ��� 1�ʿ� �� ���� ���ڸ� ���
            lcd_puts(data[i]);     // sprintf ���� ���ڿ��� ���, �޸𸮿���
            lcd_gotoxy(0 , 1); // �� ��° �ٿ��� 1�ʿ� �� ���� ���ڸ� ���
            lcd_puts(data[i + 1]);     // sprintf ���� ���ڿ��� ���, �޸𸮿���
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
}*/ // �� ���� ������ ��� �ǰ� led �Դ� ����
