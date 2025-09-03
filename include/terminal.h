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

void terminal_init();
void terminal_next_row();
void terminal_print_string(char* value, uint16_t colour, struct framebuffer_container* framebuffer_container);
void terminal_set_pixel(uint32_t x, uint32_t y, uint16_t colour, struct framebuffer_container* framebuffer_container);
void terminal_test();

#endif