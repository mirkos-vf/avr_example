#include "main.h"

int main(void)
{
    USART_Init(8); //115200

    while(true)
    {
        USART_Transmit('O');
        USART_Transmit('k');
        USART_Transmit('!');
        USART_Transmit(0x0d);
        USART_Transmit(0x0a);

        _delay_ms(50);
    }

    return 0;
}