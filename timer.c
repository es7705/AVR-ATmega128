#include <mega128a.h>

//unsigned char led = 0xfe;
//int i=0;
int msec = 0;
int sec=0;
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0=0x64;
    msec++;
    if(msec == 50) {msec = 0; sec++;}        // 50은 0.5초
}

// Declare your global variables here

void main(void)
{
    DDRA = DDRB = 0xff;
    PORTA = PORTB = 0xff;
// Timer/Counter 0 initialization
    ASSR=0<<AS0;  // 있으나 없으나
    TCCR0= 0x07;
    TCNT0=0x64;
    TIMSK=0x01;  // 오버플로우 모드
    SFIOR=(0<<ACME);
#asm("sei")

while (1)
      {
        if(sec % 2 == 0)    PORTA = 0x55;
        else PORTA = 0xaa;
      }
}
