#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <stdint.h>

#include "drawing.h"

void screensaver_changing_background(struct framebuffer_container* framebuffer_container);
void screensaver_moving_square(struct framebuffer_container* framebuffer_container);
void screensaver_test();

#endif
