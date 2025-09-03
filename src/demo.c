#include "demo.h"

void demo_changing_background(struct framebuffer_container* framebuffer_container) {

    uint32_t end = timer_get_counter_lower_seconds() + DEMO_CHANGING_BACKGROUND_DURATION;

    while(timer_get_counter_lower_seconds() < end) {
        
        uint16_t colour = colour_palette[random_get_between(0, 11)];

        drawing_clear(colour, framebuffer_container);
        timer_wait_ms(DEMO_SHORT_DELAY);
    }
}

void demo_flashing_square(struct framebuffer_container* framebuffer_container) {

    drawing_clear(COLOUR_BLACK, framebuffer_container);

    uint32_t size = DEMO_FLASHING_SQUARE_SIZE;

    uint32_t x = (FRAMEBUFFER_WIDTH / 2) - (size / 2);
    uint32_t y = (FRAMEBUFFER_HEIGHT / 2) - (size / 2);;

    uint32_t end = timer_get_counter_lower_seconds() + DEMO_FLASHING_SQUARE_DURATION;

    while(timer_get_counter_lower_seconds() < end) {
        drawing_draw_square(x, y, size, colour_palette[random_get_between(0, 11)], framebuffer_container);
        timer_wait_ms(DEMO_SHORT_DELAY);
    }
}

void demo_test() {
    
    framebuffer_init();

    struct framebuffer_container* framebuffer_container = framebuffer_get();

    while (1) {
     
        random_generate_seed();

        demo_changing_background(framebuffer_container);
        demo_flashing_square(framebuffer_container);
        demo_welcome_message(framebuffer_container);
    }
}

void demo_welcome_message(struct framebuffer_container* framebuffer_container) {

    drawing_clear(COLOUR_BLACK, framebuffer_container);

    terminal_init();

    terminal_print_string_delay("Welcome to itaos...", COLOUR_GREEN, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    terminal_print_string_delay("Starting demo mode...", COLOUR_AQUA, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();    

    terminal_print_string_delay("Attempting ASCII character test...", COLOUR_YELLOW, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    terminal_ascii_char_test(DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    terminal_print_string_delay("Completed ASCII character test...", COLOUR_YELLOW, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    terminal_print_string_delay("I am completely operational...", COLOUR_AQUA, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    terminal_print_string_delay("And all my circuits are functioning perfectly...", COLOUR_AQUA, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    terminal_print_string_delay("Receiving transmission...", COLOUR_LAVENDER, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    terminal_print_string_delay("Please wait...", COLOUR_LAVENDER, DEMO_VERY_SHORT_DELAY, framebuffer_container);
    terminal_next_row();
    terminal_next_row();

    timer_wait_ms(DEMO_VERY_LONG_DELAY);

    terminal_print_string_delay("ALL YOUR BASE ARE BELONG TO US", COLOUR_PURPLE, DEMO_VERY_SHORT_DELAY, framebuffer_container);

    uint32_t end = timer_get_counter_lower_seconds() + DEMO_WELCOME_MESSAGE_DURATION;

    while(timer_get_counter_lower_seconds() < end) {
        terminal_clear_row(framebuffer_container);
        timer_wait_ms(DEMO_MEDIUM_DELAY);
        terminal_print_string("ALL YOUR BASE ARE BELONG TO US", COLOUR_PURPLE, framebuffer_container);
        timer_wait_ms(DEMO_MEDIUM_DELAY);
    }
}
