#include <mega128a.h>
#include <delay.h>
int i=0;
unsigned char led=0xfe;  // 1111 1110

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    led=0xfe;           //1111 1110
    for(i=0;i<8;i++)
    {
     PORTA=led;
     led=(led<<1)|0x01;
     delay_ms(100);
    }
}

interrupt [EXT_INT1] void ext_int1_isr(void)
{
    led=0x7f;           // 0111 1111
    for(i=0;i<8;i++)
    {
     PORTB=led;
     led=(led>>1)|0x80;
     delay_ms(100);
    }
}

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    PORTA=PORTB=0xff;

    EICRA=0x00;  // 0000 1010 하강 에지 트리거, 상승 에지 트리거 0000 1111,로우레벨 트리거 0000 0000
    EIMSK=0x03;  // 0000 0011
    EIFR=0x03;   // 0000 0011
    // Global enable interrupts
    #asm("sei")  // 여기부터 인터럽트를 쓴다.
while (1)
      {
        PORTA=PORTB=0xaa; // 1010 1010
        delay_ms(200);
        PORTA=PORTB=0x55; // 0101 0101
        delay_ms(200);
      }
}
