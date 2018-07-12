#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

unsigned char i;

void timer_ini(void)
{
    TCCR1B |= (1 << WGM12);
    TIMSK1 |= (1 << OCIE1A);
    OCR1AH = 0b11111010;
    OCR1AL = 0b00010010;
    TCCR1B |= (1 << CS12);
}

ISR(TIMER1_COMPA_vect)
{
    PORTD ^= (uint8_t) (1 << 2);
}

int main(){

    DDRD = 1 << 2;
    PORTD = 0b00000100;

    timer_ini();
    sei();

    while (true) {

    }

    return 0;
}
