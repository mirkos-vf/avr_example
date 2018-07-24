#include "main.h"

void PORT_init()
{
  PORTD = OUTPUT;
  DDRD = 0xFF;
}

void send_ok(){
  USART_Transmit('O');
  USART_Transmit('k');
  USART_Transmit('!');
  USART_Transmit(CR);
  USART_Transmit(LF);
}


int main() {
  uint16_t adc;

  PORT_init();
  USART_Init(8);
  ADC_init();

  send_ok();

  while(true)
  {
    adc = ADC_Convert();

    USART_Transmit((unsigned char) (adc / 1000 + 0x30));
    USART_Transmit((unsigned char) ((adc % 1000) / 100 + 0x30));
    USART_Transmit((unsigned char) ((adc % 100) / 10 + 0x30));
    USART_Transmit((unsigned char) (adc % 10 + 0x30));
    USART_Transmit(CR);
    USART_Transmit(LF);

    _delay_ms(10000);
  }
  return 0;
}