#include "main.h"


void PORT_Init() { ;
    DDRB = INPUT;
    PORTB |= (1 << PORT3);
}

void send_ok(){
    USART_Transmit('O');
    USART_Transmit('k');
    USART_Transmit('!');
    USART_Transmit(CR);
    USART_Transmit(LF);
}

int main(void)
{
    USART_Init(8); //115200
    PORT_Init();
    send_ok();
    sei();

    while(true)
    {
        PORTB ^= (1 << PORT3);
        _delay_ms(500);
    }

    return 0;
}

ISR(USART_RXC_vect) {

}