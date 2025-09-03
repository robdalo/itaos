#include "screensaver.h"

void screensaver_changing_background(struct framebuffer_container* framebuffer_container) {

    random_generate_seed();

    while (1) {
        
        drawing_clear(colour_palette[random_get_between(0, 11)], framebuffer_container);
        timer_wait_ms(SCREENSAVER_CHANGING_BACKGROUND_DELAY);
    }    
}

void screensaver_moving_square(struct framebuffer_container* framebuffer_container) {
    
    uint32_t x = SCREENSAVER_MOVING_SQUARE_MARGIN;
    uint32_t y = SCREENSAVER_MOVING_SQUARE_MARGIN;

    random_generate_seed();

    while(1) {

        timer_wait_ms(SCREENSAVER_MOVING_SQUARE_DELAY);

        drawing_clear(COLOUR_BLACK, framebuffer_container);
        drawing_draw_square(x, y, SCREENSAVER_MOVING_SQUARE_SIZE, colour_palette[random_get_between(0, 11)], framebuffer_container);

        x += SCREENSAVER_MOVING_SQUARE_SIZE;

        if (x + SCREENSAVER_MOVING_SQUARE_SIZE > framebuffer_container->width) {
            
            x = SCREENSAVER_MOVING_SQUARE_MARGIN;
            y += SCREENSAVER_MOVING_SQUARE_SIZE;

            if (y + SCREENSAVER_MOVING_SQUARE_SIZE > framebuffer_container->height)
                y = SCREENSAVER_MOVING_SQUARE_MARGIN;
        }
    }
}

void screensaver_test() {

    framebuffer_init();

    struct framebuffer_container* framebuffer_container = framebuffer_get();

    screensaver_changing_background(framebuffer_container);
}