/*
#define F_CPU 16000000L
#include <mega128a.h>
#include <stdio.h>
#include <delay.h>

int i = 0;
unsigned char step_data[] = {0x01, 0x02, 0x04, 0x08};    // 4���� ���
int step_index = -1;

unsigned char step_forward(void);
unsigned char step_backward (void);

interrupt [EXT_INT0] void ext_int0_isr(void)  // 0�� ����ġ
{
    for (i = 0; i < 512; i++)   // �ݽð� �������� 90�� ȸ��
    {
        PORTE = step_backward();
        delay_ms(2);
        PORTA = 0X00;
    }
        PORTA = 0XFF;
}
interrupt [EXT_INT1] void ext_int1_isr(void) // 1�� ����ġ
{
    for (i = 0; i < 512; i++)   // �ð� �������� 90�� ȸ��
    {
        PORTE = step_forward();
        delay_ms(2);
        PORTB = 0X00;
    }
        PORTB = 0XFF;
}

unsigned char step_forward(void)
{
    step_index++;
    if(step_index>=4) step_index = 0;
    return step_data[step_index];
}

unsigned char step_backward (void)
{
    step_index--;
    if(step_index <0) step_index = 3;
    return step_data[step_index];
}

void main(void)
{
    DDRA = 0xff;
    PORTA = 0xff;
    DDRB = 0xff;
    PORTB = 0xff;

    DDRD = 0xfc;
    PORTD = 0xff;

    DDRE = 0xff;
    PORTE = 0xff;

    EICRA = 0x00; // �ϰ� ���� 0000 1010, ��� ���� 0000 1111, �ο� ���� 0000 0000
    EIMSK = 0x03; // 0000 0011
    EIFR = 0x03;  // 0000 0011

    #asm("sei")
}
*/

#define F_CPU 16000000L    // ����ũ����Ʈ�ѷ��� CPU Ŭ�� ���ļ� ����
#include <mega128a.h>      // ATmega128A ���̺귯���� ����
#include <stdio.h>         // ǥ�� ����� ���̺귯��
#include <delay.h>         // ������ �Լ� ���̺귯��

int i = 0;                          // �ݺ��� ���� ����
unsigned char step_data[] = {0x01, 0x02, 0x04, 0x08};    // 4���� ����� ����ϴ� ���� ������ �迭
int step_index = -1;                 // ���� ���� �ε���

unsigned char step_forward(void);    // ���ܸ��͸� �ð���������� ȸ���ϴ� �Լ� ����
unsigned char step_backward(void);   // ���ܸ��͸� �ݽð�������� ȸ���ϴ� �Լ� ����

interrupt [EXT_INT0] void ext_int0_isr(void)  // �ܺ� ���ͷ�Ʈ 0 ó�� �Լ� (0�� ����ġ)
{
    for (i = 0; i < 512; i++)   // �ݽð� �������� 90�� ȸ��
    {
        PORTE = step_forward();  // ���ܸ��͸� �ڷ� ������ �Լ� ȣ��
        delay_ms(2);                // 2�и��� ������
        PORTA = 0X00;               // PORTA�� 0���� ���� (LED on)
    }
    PORTA = 0XFF;                   // ȸ�� �Ϸ� �� PORTA�� 0xFF�� ���� (LED off)
}

interrupt [EXT_INT1] void ext_int1_isr(void)  // �ܺ� ���ͷ�Ʈ 1 ó�� �Լ� (1�� ����ġ)
{
    for (i = 0; i < 512; i++)   // �ð� �������� 90�� ȸ��
    {
        PORTE = step_backward();   // ���ܸ��͸� ������ ������ �Լ� ȣ��
        delay_ms(2);                // 2�и��� ������
        PORTB = 0X00;               // PORTB�� 0���� ���� (LED on)
    }
    PORTB = 0XFF;                   // ȸ�� �Ϸ� �� PORTB�� 0xFF�� ���� (LED off)
}

unsigned char step_forward(void)
{
    step_index++;                  // ���� �ε��� ����
    if(step_index >= 4)            // ���� �ε����� 4 �̻��̸�
        step_index = 0;             // ���� �ε����� 0���� �ʱ�ȭ
    return step_data[step_index];  // ���� ���� ������ ��ȯ
}

unsigned char step_backward(void)
{
    step_index--;                  // ���� �ε��� ����
    if(step_index < 0)             // ���� �ε����� 0 �̸��̸�
        step_index = 3;             // ���� �ε����� 3���� �ʱ�ȭ
    return step_data[step_index];  // ���� ���� ������ ��ȯ
}

void main(void)
{
    DDRA = 0xff;    // PORTA�� ��� ���� ����
    PORTA = 0xff;   // PORTA�� ����� ��� �ѱ�

    DDRB = 0xff;    // PORTB�� ��� ���� ����
    PORTB = 0xff;   // PORTB�� ����� ��� �ѱ�

    DDRD = 0xfc;    // PORTD�� 2�� ��Ʈ���� �Է� ���, �������� ��� ���� ����
    //PORTD = 0xff;   // PORTD�� ���� Ǯ�� ���� Ȱ��ȭ

    DDRE = 0xff;    // PORTE�� ��� ���� ����
    PORTE = 0xff;   // PORTE�� ����� ��� �ѱ�

    EICRA = 0x00;   // �ܺ� ���ͷ�Ʈ ���� �������� �ʱ�ȭ (�ϰ� ���� 0000 1010, ��� ���� 0000 1111, �ο� ���� 0000 0000)
    EIMSK = 0x03;   // �ܺ� ���ͷ�Ʈ ����ũ �������� ���� (0000 0011)
    EIFR = 0x03;    // �ܺ� ���ͷ�Ʈ �÷��� �������� ���� (0000 0011)

    #asm("sei")     // ���������� ���ͷ�Ʈ Ȱ��ȭ
}

/*
#define F_CPU 16000000L
#include <mega128a.h>
#include <stdio.h>
#include <delay.h>
int i = 0;
unsigned char step_data[] = {0x01, 0x02, 0x04, 0x08};
int step_index = -1;

unsigned char step_forward(void)
{
    step_index++;
    if(step_index>=4) step_index = 0;
    return step_data[step_index];
}

unsigned char step_backward (void)
{
    step_index--;
    if(step_index <0) step_index = 3;
    return step_data[step_index];
}

void main(void)
{
    DDRB = 0X0F;

    while (1)
    {
     for (i = 0; i < 2048*3; i++)
     {
        PORTB = step_forward();
        delay_ms(2);

     }
     delay_ms(1000);

    for (i = 0; i < 2048*3; i++)
    {
        PORTB = step_backward();
        delay_ms(2);

    }
    delay_ms(1000);
    }
} */