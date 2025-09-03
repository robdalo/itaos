#include "screensaver.h"

void screensaver_changing_background(struct framebuffer_container* framebuffer_container) {

    uint32_t colours[11] = {
        COLOUR_BLACK,
        COLOUR_BLUE,
        COLOUR_GREEN,
        COLOUR_PINK,
        COLOUR_YELLOW,
        COLOUR_ORANGE,
        COLOUR_PURPLE,
        COLOUR_AQUA,
        COLOUR_PEACH,
        COLOUR_MINT,
        COLOUR_LAVENDER
    };

    int32_t colour = 0;

    while (1) {
        
        drawing_clear(colours[colour++], framebuffer_container);
        
        colour = colour > 10 ? 0 : colour;

        timer_wait_ms(400);
    }    
}

void screensaver_moving_square(struct framebuffer_container* framebuffer_container) {
    
    uint32_t colours[10] = {
        COLOUR_BLUE,
        COLOUR_GREEN,
        COLOUR_PINK,
        COLOUR_YELLOW,
        COLOUR_ORANGE,
        COLOUR_PURPLE,
        COLOUR_AQUA,
        COLOUR_PEACH,
        COLOUR_MINT,
        COLOUR_LAVENDER
    };

    uint32_t x_margin = 10;
    uint32_t y_margin = 20;
    uint32_t x = x_margin;
    uint32_t y = y_margin;
    uint32_t width = 210;
    uint32_t colour = 0;

    while(1) {

        timer_wait_ms(400);

        drawing_clear(COLOUR_BLACK, framebuffer_container);
        drawing_draw_square(x, y, width, colours[colour], framebuffer_container);

        x += width;

        if (x + width > framebuffer_container->width) {
            
            x = x_margin;
            y += 200;

            if (y + width > framebuffer_container->height)
                y = y_margin;
        }

        colour++;

        if (colour > 9)
            colour = 0;
    }
}

void screensaver_test() {

    framebuffer_init();

    struct framebuffer_container* framebuffer_container = framebuffer_get();

    screensaver_moving_square(framebuffer_container);
}