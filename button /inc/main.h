#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>

enum mode { INPUT = 0xFF, OUTPUT = 0x00};
