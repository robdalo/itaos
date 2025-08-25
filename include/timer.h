#include <stdint.h>

#define TIMER_BASE 0x20003000
#define TIMER_COUNTER_LOWER 0x4

void timer_wait(int seconds);
