#include "main.h"

void INIT_port()
{
    PORTB = 0x00;
    DDRB = 0x08;
}

int main(void)
{
    INIT_port();
    INIT_PWM_timer();
    OCR2 = 0;

    bool state = false;

    while (true) {
        if (!state)
        {
            OCR2++;
            if (OCR2 > 254)
            {
                state = true;
            };
        };
        if (state)
        {
            OCR2--;
            if (OCR2 < 1)
            {
                state = false;
            }
        };
        _delay_ms(10);
    }
    return 0;
}