#include "kernel.h"

extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

void kernel_main(void) {
    
    uint32_t width = 1920;
    uint32_t height = 1080;
    uint32_t bit_depth = 16;

    if (framebuffer_init(width, height, bit_depth) != 0)
        led_error(ERROR_FRAMEBUFFER_INIT);

    led_debug();

    while (1);
}

void zero_bss(void) {
    
    uint32_t *bss = &__bss_start__;

    while (bss < &__bss_end__) {
        *bss++ = 0;
    }
}