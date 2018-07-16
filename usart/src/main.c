#include "main.h"

void send_ok(void);

int main(void)
{
    USART_Init(8); //115200
    send_ok();

    while(true)
    {

    }

    return 0;
}

void send_ok(){
    USART_Transmit('O');
    USART_Transmit('k');
    USART_Transmit('!');
    USART_Transmit(0x0d);
    USART_Transmit(0x0a);
}