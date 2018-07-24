#include "adc.h"

void ADC_init()
{
  ADCSRA = (1 << ADEN); //Enable the ADC
  ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); // Determain the division factor
  ADMUX  |= (1 << REFS1) | (1 << REFS0);
};

uint16_t ADC_Convert()
{
  ADCSRA |= (1 << ADSC);
  while((ADCSRA & (1<<ADSC)))
    ;
  return (unsigned int) ADC;
}