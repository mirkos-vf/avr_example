#include "pwm.h"

void INIT_PWM_timer() {
    ASSR = 0x00;
    TCCR2 = 0b01101110;
    TCNT2 = 0x00;
    OCR2 = 0;
    TIMSK|= 0x00;
}