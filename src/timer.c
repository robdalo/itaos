#include "timer.h"

void timer_wait(int seconds) {
    
    volatile uint32_t* address = 
        (volatile uint32_t*)(TIMER_BASE + TIMER_COUNTER_LOWER);

    uint32_t start = *address;
    uint32_t end = start + (seconds * 1000000);

    while (start < end) {
        start = *address;
    }
}
