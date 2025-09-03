#include "terminal.h"

uint32_t terminal_row_current;
uint32_t terminal_column_current;

void terminal_init() {
    terminal_row_current = 0;
    terminal_column_current = 0;
}

void terminal_next_column() {

    terminal_column_current++;

    if (terminal_column_current >= TERMINAL_COLUMN_LIMIT)
        terminal_next_row();
}

void terminal_next_row() {

    terminal_row_current++;
    terminal_column_current = 0;
}

void terminal_print_char(
    uint32_t ascii_code, 
    uint16_t colour,
    struct framebuffer_container* framebuffer_container) {

    for (uint32_t y=0; y<TERMINAL_FONT_HEIGHT; y++) {
        for (uint32_t x=0; x<TERMINAL_FONT_WIDTH; x++) {
            if (font_vga_8x16[ascii_code][y] & (1 << (7 - x)))
                terminal_set_pixel(x, y, colour, framebuffer_container);
        }
    }

    terminal_next_column();
}

void terminal_print_string(
    char* value,
    uint16_t colour,
    struct framebuffer_container* framebuffer_container) {

    while (*value != '\0') {
        terminal_print_char(*value++, colour, framebuffer_container);
    }
}

void terminal_set_pixel(
    uint32_t x, 
    uint32_t y, 
    uint16_t colour, 
    struct framebuffer_container* framebuffer_container) {

    x = TERMINAL_X_MARGIN + (terminal_column_current * TERMINAL_FONT_WIDTH) + x;
    y = TERMINAL_Y_MARGIN + (terminal_row_current * TERMINAL_FONT_HEIGHT) + y;

    drawing_set_pixel(x, y, colour, framebuffer_container);
}

void terminal_test() {
    
    framebuffer_init();

    struct framebuffer_container* framebuffer_container = framebuffer_get();

    terminal_init();

    terminal_print_string("Welcome to itaos...", COLOUR_MINT, framebuffer_container);
    terminal_next_row();
    terminal_next_row();
    terminal_print_string("Attempting ASCII character test...", COLOUR_WHITE, framebuffer_container);

    for (uint32_t i=0; i<128; i++)
        terminal_print_char(i, COLOUR_WHITE, framebuffer_container);

    terminal_next_row();
    terminal_print_string("Completed ASCII character test...", COLOUR_WHITE, framebuffer_container);
}