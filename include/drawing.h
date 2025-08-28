#ifndef DRAWING_H
#define DRAWING_H

#include <stdint.h>

#include "colour.h"
#include "framebuffer.h"
#include "timer.h"

void drawing_clear(uint16_t colour, struct framebuffer_container* framebuffer_container);
void drawing_draw_square(uint32_t x, uint32_t y, uint32_t width, uint32_t colour, struct framebuffer_container* framebuffer_container);
void drawing_set_pixel(uint32_t x, uint32_t y, uint32_t colour, struct framebuffer_container* framebuffer_container);
void drawing_test();

#endif