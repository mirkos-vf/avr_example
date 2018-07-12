#include "main.h"
#include <stdbool.h>

int main() {
    unsigned char butcount = 0;

    DDRC = OUTPUT;
    DDRD = INPUT;
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
};
