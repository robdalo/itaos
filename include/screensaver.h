#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <stdint.h>

#include "drawing.h"
#include "random.h"

#define SCREENSAVER_CHANGING_BACKGROUND_DELAY 500
#define SCREENSAVER_MOVING_SQUARE_DELAY 500
#define SCREENSAVER_MOVING_SQUARE_MARGIN 10
#define SCREENSAVER_MOVING_SQUARE_SIZE 210

void screensaver_changing_background(struct framebuffer_container* framebuffer_container);
void screensaver_moving_square(struct framebuffer_container* framebuffer_container);
void screensaver_test();

#endif
