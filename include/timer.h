#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#define TIMER_BASE 0xfe003000
#define TIMER_COUNTER_LOWER 0x4

uint32_t timer_get_counter_lower();
uint32_t timer_get_counter_lower_seconds();
void timer_wait(uint32_t seconds);
void timer_wait_ms(uint32_t milliseconds);

#endif