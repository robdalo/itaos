#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#define TIMER_BASE 0xfe003000
#define TIMER_COUNTER_LOWER 0x4

void timer_wait(uint32_t seconds);

#endif