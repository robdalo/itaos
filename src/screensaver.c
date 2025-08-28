#include "screensaver.h"

void screensaver_changing_background(struct framebuffer_container* framebuffer_container) {

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

    int32_t colour = 0;

    while (1) {
        
        drawing_clear(colours[colour++], framebuffer_container);
        
        if (colour > 9)
            colour = 0;

        timer_wait_ms(500);
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

    int x = 0;
    int y = 0;
    int width = 200;
    int colour = 0;

    while(1) {

        timer_wait_ms(100);

        drawing_clear(COLOUR_BLACK, framebuffer_container);
        drawing_draw_square(x, y, width, colours[colour], framebuffer_container);

        x += width;

        if (x + width > framebuffer_container->width) {
            
            x = 0;
            y += 200;

            if (y + width > framebuffer_container->height)
                y = 0;
        }

        colour++;

        if (colour > 9)
            colour = 0;
    }
}

void screensaver_test() {

    framebuffer_init(1920, 1080, 16);

    struct framebuffer_container* framebuffer_container = framebuffer_get();

    screensaver_moving_square(framebuffer_container);
}