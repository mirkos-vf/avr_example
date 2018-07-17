#ifndef USART_MAIN_H
#define USART_MAIN_H

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "usart.h"

#define CR 0x0d
#define LF 0x0a

enum state {OUTPUT = 0x00, INPUT = 0xFF};

#endif //USART_MAIN_H
