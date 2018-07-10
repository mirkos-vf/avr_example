#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main() {
    unsigned char butcount = 0;

    DDRC = 0x00; // A
    DDRD = 0xFF; // D
    PORTC = 0b00000001; // A0
    PORTD = 0b00000000;

    while(true) {
        if (!(PINC & 0b00000001)) // NOLINT
        {
            if ( butcount < 5 )
            {
                butcount++;
            }
            else
            {
                PORTD = 0b00000100;
            }
        }
        else
        {
            if ( butcount > 0 )
            {
                butcount--;
            }
            else
            {
                PORTD = 0b00000000;
            }
        }


    }


    return 0;
}