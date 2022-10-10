.include "m328pdef.inc"

.cseg
.org 	0x00
ldi	r16,(1<<PINB0)
out     DDRB,r16
out     PORTB,r16

loop:	rjmp    loop