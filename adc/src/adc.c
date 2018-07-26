#include "adc.h"

void ADC_init()
{
  ADMUX  |= (1 << REFS0);

  ADCSRA |= (1 << ADPS0) | (1 << ADPS1); // Determain the division factor
  ADCSRA = (1 << ADEN); //Enable the ADC

};

uint16_t ADC_Convert()
{
  ADCSRA |= (1 << ADSC);
  loop_until_bit_is_clear(ADCSRA, ADSC); // NOLINT
  return ADC;
}