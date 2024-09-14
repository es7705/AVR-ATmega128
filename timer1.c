/*
#include <mega128a.h>
#include <alcd.h>
#include <stdio.h>
int hour = 0;
int min = 0;
int sec = 0;
int msec = 0;
unsigned led = 0xfe;
int i= 0;
char data[80];

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    // 10msec overflow
    TCNT1H=0xB1;
    TCNT1L=0xE0;
    msec++;
    if(msec==100) {sec++; msec=0;}
    if(sec==60) {min++; sec=0;}
    if(min==60) {hour++; min=0;}
    PORTA=led++;
}

// Declare your global variables here

void main(void)
{
    DDRA = DDRB =DDRG = 0xff;
    PORTA = PORTB = PORTC = 0xff; //  초기값

    ASSR=0<<AS0;

    TCCR1A=0x00;
    TCCR1B=0x02;        // 8분주
    TCNT1H=0xB1;
    TCNT1L=0xE0;        // 10msec
    TIMSK=0x04;
    ETIMSK=0x00;
    SFIOR = (0<ACME);

    lcd_init(16);
    lcd_gotoxy(0,0);
    lcd_puts("hour:min:sec:msec");
    #asm("sei")

while (1)
      {
         sprintf(data, "%3d:%3d:%3d:%3d", hour, min, sec, msec);
         lcd_gotoxy(0,1);
         lcd_puts(data);
      }
}
  */

#include <mega128a.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>
int hour=0, min=0, sec=0, msec=0;
int laphour=0, lapmin=0, lapsec=0, lapmsec=0;
unsigned led = 0xfe;
int i= 0;
char data[80];
char start = 0;
interrupt [EXT_INT0] void ext_int0_isr(void)  // 0번 스위치
{
    start = start ? 0 : 1;
}
interrupt [EXT_INT1] void ext_int1_isr(void) // 1번 스위치, lap 저장
{
    laphour = hour; lapmin = min; lapsec = sec; lapmsec = msec;      // lap 저장
    // hour = 0; min = 0; sec = 0; msec = 0; laphour = 0; lapmin = 0; lapsec = 0; lapmsec = 0;  //리셋
}

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    // 10msec overflow
    TCNT1H=0xB1;
    TCNT1L=0xE0;
    if(start == 1)
    {
        msec++;
        if(msec==100) {sec++; msec=0;}
        if(sec==60) {min++; sec=0;}
        if(min==60) {hour++; min=0;}
    }

    // if(PIND == 0xfd){laphour = 0; lapmin = 0; lapsec = 0; lapmsec = 0;}
    //PORTA=led++;
}

// Declare your global variables here

void main(void)
{


    DDRA = DDRB =DDRG = 0xff;
    PORTA = PORTB = PORTC = 0xff; //  초기값

    DDRD = 0Xfc;      // 2개만 입력 모드
    PORTD = 0Xff;
    ASSR=0<<AS0;

    TCCR1A=0x00;
    TCCR1B=0x02;        // 8분주
    TCNT1H=0xB1;
    TCNT1L=0xE0;        // 10msec
    TIMSK=0x04;
    ETIMSK=0x00;
    SFIOR = (0<ACME);

    EICRA=(0<<ISC31) | (0<<ISC30) | (0<<ISC21) | (0<<ISC20) | (1<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
    EICRB=(0<<ISC71) | (0<<ISC70) | (0<<ISC61) | (0<<ISC60) | (0<<ISC51) | (0<<ISC50) | (0<<ISC41) | (0<<ISC40);
    EIMSK=(0<<INT7) | (0<<INT6) | (0<<INT5) | (0<<INT4) | (0<<INT3) | (0<<INT2) | (1<<INT1) | (1<<INT0);
    EIFR=(0<<INTF7) | (0<<INTF6) | (0<<INTF5) | (0<<INTF4) | (0<<INTF3) | (0<<INTF2) | (1<<INTF1) | (1<<INTF0);

    lcd_gotoxy(0,0);
    lcd_puts("00:00:00:00");

    lcd_init(16);
    #asm("sei")

while (1)
      {

         lcd_gotoxy(0,0);
         sprintf(data, "T:%02d:%02d:%02d:%02d", hour, min, sec, msec);
         lcd_puts(data);

         lcd_gotoxy(0,1);
         sprintf(data, "Lap:%02d:%02d:%02d:%02d", laphour, lapmin, lapsec, lapmsec);
         lcd_puts(data);

         if(min == 5)
             {
                PORTA = 0x55;
                delay_ms(200);
                PORTA = 0xaa;
                delay_ms(200);
                PORTA = 0x55;
                delay_ms(200);
                PORTA = 0xaa;
                delay_ms(200);
                PORTA = 0xff;
             }
      }
}