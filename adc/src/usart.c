#include "usart.h"

void USART_Init( unsigned int speed)
{
    UBRRH = (unsigned char) (speed >> 8); // NOLINT
    UBRRL = (unsigned char) speed;

    UCSRB = (1 << RXEN)|( 1<< TXEN ); // NOLINT
    // enable USART
    UCSRB |= ( 1 << RXCIE ); // NOLINT
    // enable interrupts
    UCSRA |= ( 1 << U2X ); // NOLINT
    UCSRC = ( 1 << URSEL ) | ( 1 << USBS ) | ( 1 << UCSZ1 ) | ( 1 << UCSZ0 ); //NOLINT
}

void USART_Transmit( unsigned char data )
{
    while ( !( UCSRA & ( 1 << UDRE ) ) ); // NOLINT
    UDR = data;
}