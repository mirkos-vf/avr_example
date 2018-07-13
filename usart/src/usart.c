#include "usart.h"

void USART_Init( unsigned int speed)
{
    UBRR0H = (unsigned char) (speed >> 8); // NOLINT
    UBRR0L = (unsigned char) speed;

    UCSR0B = (1 << RXEN0)|( 1<< TXEN0 ); // NOLINT
    UCSR0B |= ( 1 << RXCIE0 ); // NOLINT
    UCSR0A |= ( 1 << U2X0 ); // NOLINT
    UCSR0C = ( 1 << 0 ) | ( 1 << USBS0 ) | ( 1 << UCSZ00 ) | ( 1 << UCSZ00 ); //NOLINT
}

void USART_Transmit( unsigned char data )
{
    while ( !( UCSR0A & ( 1 << UDRE0 ) ) );
    UDR0 = data;
}