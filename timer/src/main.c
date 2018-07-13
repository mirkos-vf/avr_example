#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

unsigned char i;

void timer_ini(void)
{
    TCCR1B |= (1 << WGM12);
    TIMSK1 |= (1 << OCIE1A);
    OCR1AH = 0b00001111;
    OCR1AL = 0b00111100;
    TCCR1B |= (1 << CS12);
}

ISR(TIMER1_COMPA_vect)
{
    PORTD ^= (uint8_t) (1 << 2);
}

int main(){

    DDRD = 1 << 2;
    PORTD = 0b00000000;

    timer_ini();
    sei();

    while (true) {
        _delay_ms(50000000);
    }

    return 0;
}
