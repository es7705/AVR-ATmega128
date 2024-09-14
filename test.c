#include <mega128a.h>
#include <delay.h>
void main(void)
{
    int i = 0;
    int j = 0;
    int f = 0;
    unsigned char ledA[12] = {0xff, 0xfe, 0xfc, 0xf8, 0xf1, 0xe3, 0xc7, 0x8f, 0x1f, 0x3f, 0x7f, 0xff };
    unsigned char ledB[12] = {0xff, 0xfe, 0xfc, 0xf8, 0xf1, 0xe3, 0xc7, 0x8f, 0x1f, 0x3f, 0x7f, 0xff };

    DDRA=0xff;      // 1111 1111
	PORTA=0xff;     // 1111 1111
    DDRB=0xff;      // 1111 1111
	PORTB=0xff;     // 1111 1111

    while (1)
    {
        if(f == 0)    // ����
        {
            PORTA = ledA[i];
            PORTB = ledB[j];
            if(i < 11)
            {
                i++;
            }

            if(i > 8)
            {
               j++;

                if(j == 11)
                {
                    f = 1;
                    i = 10;

                   j = 11;

                }
            }
        }


        if (f == 1)     // f == 1  , ����
        {

            PORTA = ledA[i];
            PORTB = ledB[j];
            if(j >= 0)
            {
                j--;
            }

            if(j == 7 )
            {
               i--;
            }
        }
        delay_ms(100);
     }
}
