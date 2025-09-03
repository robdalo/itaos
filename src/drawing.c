#include "drawing.h"

void drawing_clear(uint16_t colour, struct framebuffer_container* framebuffer_container) {

    volatile uint16_t* framebuffer = framebuffer_container->framebuffer;

    for (uint32_t x = 0; x < framebuffer_container->width; x++) {
        for (uint32_t y = 0; y < framebuffer_container->height; y++) {
            uint32_t offset = y * framebuffer_container->pitch_pixels + x;
            framebuffer[offset] = colour;
        }
    }
}

void drawing_draw_square(uint32_t x, uint32_t y, uint32_t width, uint32_t colour, struct framebuffer_container* framebuffer_container) {

    uint32_t x_max = x + width;
    uint32_t y_max = y + width;
    uint32_t y_start = y;

    volatile uint16_t* framebuffer = framebuffer_container->framebuffer;

    for (; x<x_max; x++) {
        y = y_start;
        for (; y<y_max; y++) {
            uint32_t offset = y * framebuffer_container->pitch_pixels + x;
            framebuffer[offset] = colour;
        }
    }
}

void drawing_set_pixel(
    uint32_t x, 
    uint32_t y, 
    uint32_t colour,
    struct framebuffer_container* framebuffer_container) {

    volatile uint16_t* framebuffer = framebuffer_container->framebuffer;

    uint32_t offset = y * framebuffer_container->pitch_pixels + x;

    framebuffer[offset] = colour;
}

void drawing_test() {
    
    framebuffer_init();

    struct framebuffer_container* framebuffer_container = framebuffer_get();

    drawing_draw_square(860, 440, 200, COLOUR_MINT, framebuffer_container);       
}