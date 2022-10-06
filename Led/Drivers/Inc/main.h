
#ifndef MAIN_H
#define MAIN_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <stdbool.h>
#include <inttypes.h>

#ifndef F_CPU
#define F_CPU                                       16000000
#endif

#define delay_ms(t)                                 _delay_ms(t)
#define delay_us(t)                                 _delay_us(t)

#endif