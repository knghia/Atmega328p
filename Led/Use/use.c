
#include "use.h"

extern void setup(void){
    DDRB |= (1<<6);
    PORTB |= (1<<6);
}

extern void loop(void){
    PORTB ^= (1<<6);
    delay_ms(500);
}