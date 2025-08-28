#include "timer.h"

uint32_t timer_get_counter_lower() {

    volatile uint32_t* address = 
        (volatile uint32_t*)(TIMER_BASE + TIMER_COUNTER_LOWER);

    return *address;
}

void timer_wait(uint32_t seconds) {
    
    timer_wait_ms(seconds * 1000);
}

void timer_wait_ms(uint32_t milliseconds) {
    
    volatile uint32_t* address = 
        (volatile uint32_t*)(TIMER_BASE + TIMER_COUNTER_LOWER);

    uint32_t start = *address;
    uint32_t end = start + (milliseconds * 1000);

    while (start < end) {
        start = *address;
    }
}