#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>

#include "drawing.h"
#include "font.h"

#define TERMINAL_COLUMN_LIMIT 235
#define TERMINAL_X_MARGIN 20
#define TERMINAL_Y_MARGIN 20
#define TERMINAL_FONT_WIDTH 8
#define TERMINAL_FONT_HEIGHT 16

void terminal_ascii_char_test(uint32_t delay, struct framebuffer_container* framebuffer_container);
void terminal_clear_char(struct framebuffer_container* framebuffer_container);
void terminal_clear_row(struct framebuffer_container* framebuffer_container);
void terminal_init();
void terminal_next_column();
void terminal_next_row();
void terminal_print_char(uint32_t ascii_code, uint16_t colour, struct framebuffer_container* framebuffer_container);
void terminal_print_string(char* value, uint16_t colour, struct framebuffer_container* framebuffer_container);
void terminal_print_string_delay(char* value, uint16_t colour, uint32_t delay, struct framebuffer_container* framebuffer_container);
void terminal_set_pixel(uint32_t x, uint32_t y, uint16_t colour, struct framebuffer_container* framebuffer_container);
void terminal_test();

#endif