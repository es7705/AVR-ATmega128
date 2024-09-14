/*
#define F_CPU 16000000L
#include <mega128a.h>
#include <stdio.h>
#include <delay.h>

int i = 0;
unsigned char step_data[] = {0x01, 0x02, 0x04, 0x08};    // 4스탭 방식
int step_index = -1;

unsigned char step_forward(void);
unsigned char step_backward (void);

interrupt [EXT_INT0] void ext_int0_isr(void)  // 0번 스위치
{
    for (i = 0; i < 512; i++)   // 반시계 방향으로 90도 회전
    {
        PORTE = step_backward();
        delay_ms(2);
        PORTA = 0X00;
    }
        PORTA = 0XFF;
}
interrupt [EXT_INT1] void ext_int1_isr(void) // 1번 스위치
{
    for (i = 0; i < 512; i++)   // 시계 방향으로 90도 회전
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

    EICRA = 0x00; // 하강 에지 0000 1010, 상승 에지 0000 1111, 로우 레벨 0000 0000
    EIMSK = 0x03; // 0000 0011
    EIFR = 0x03;  // 0000 0011

    #asm("sei")
}
*/

#define F_CPU 16000000L    // 마이크로컨트롤러의 CPU 클럭 주파수 설정
#include <mega128a.h>      // ATmega128A 라이브러리를 포함
#include <stdio.h>         // 표준 입출력 라이브러리
#include <delay.h>         // 딜레이 함수 라이브러리

int i = 0;                          // 반복문 제어 변수
unsigned char step_data[] = {0x01, 0x02, 0x04, 0x08};    // 4스탭 방식을 사용하는 스텝 데이터 배열
int step_index = -1;                 // 현재 스텝 인덱스

unsigned char step_forward(void);    // 스텝모터를 시계방향으으로 회전하는 함수 선언
unsigned char step_backward(void);   // 스텝모터를 반시계방향으로 회전하는 함수 선언

interrupt [EXT_INT0] void ext_int0_isr(void)  // 외부 인터럽트 0 처리 함수 (0번 스위치)
{
    for (i = 0; i < 512; i++)   // 반시계 방향으로 90도 회전
    {
        PORTE = step_forward();  // 스텝모터를 뒤로 돌리는 함수 호출
        delay_ms(2);                // 2밀리초 딜레이
        PORTA = 0X00;               // PORTA를 0으로 설정 (LED on)
    }
    PORTA = 0XFF;                   // 회전 완료 후 PORTA를 0xFF로 설정 (LED off)
}

interrupt [EXT_INT1] void ext_int1_isr(void)  // 외부 인터럽트 1 처리 함수 (1번 스위치)
{
    for (i = 0; i < 512; i++)   // 시계 방향으로 90도 회전
    {
        PORTE = step_backward();   // 스텝모터를 앞으로 돌리는 함수 호출
        delay_ms(2);                // 2밀리초 딜레이
        PORTB = 0X00;               // PORTB를 0으로 설정 (LED on)
    }
    PORTB = 0XFF;                   // 회전 완료 후 PORTB를 0xFF로 설정 (LED off)
}

unsigned char step_forward(void)
{
    step_index++;                  // 스텝 인덱스 증가
    if(step_index >= 4)            // 스텝 인덱스가 4 이상이면
        step_index = 0;             // 스텝 인덱스를 0으로 초기화
    return step_data[step_index];  // 현재 스텝 데이터 반환
}

unsigned char step_backward(void)
{
    step_index--;                  // 스텝 인덱스 감소
    if(step_index < 0)             // 스텝 인덱스가 0 미만이면
        step_index = 3;             // 스텝 인덱스를 3으로 초기화
    return step_data[step_index];  // 현재 스텝 데이터 반환
}

void main(void)
{
    DDRA = 0xff;    // PORTA를 출력 모드로 설정
    PORTA = 0xff;   // PORTA의 출력을 모두 켜기

    DDRB = 0xff;    // PORTB를 출력 모드로 설정
    PORTB = 0xff;   // PORTB의 출력을 모두 켜기

    DDRD = 0xfc;    // PORTD의 2번 비트까지 입력 모드, 나머지는 출력 모드로 설정
    //PORTD = 0xff;   // PORTD의 내부 풀업 저항 활성화

    DDRE = 0xff;    // PORTE를 출력 모드로 설정
    PORTE = 0xff;   // PORTE의 출력을 모두 켜기

    EICRA = 0x00;   // 외부 인터럽트 설정 레지스터 초기화 (하강 에지 0000 1010, 상승 에지 0000 1111, 로우 레벨 0000 0000)
    EIMSK = 0x03;   // 외부 인터럽트 마스크 레지스터 설정 (0000 0011)
    EIFR = 0x03;    // 외부 인터럽트 플래그 레지스터 설정 (0000 0011)

    #asm("sei")     // 전역적으로 인터럽트 활성화
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