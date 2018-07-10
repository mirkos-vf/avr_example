#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // номер пина 2 в порту А -- на выход
    DDRD = 0xFF;
    PORTD = 0b00000100;
    // основной цикл
    while (1) {
        for( unsigned char i = 0; i <= 3; i ++) {
            PORTD = (uint8_t) (1 << i); // NOLINT
            _delay_ms(50);
        }
    }

    return 0;
}