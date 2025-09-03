#ifndef DEMO_H
#define DEMO_H

#include "random.h"
#include "terminal.h"

#define DEMO_CHANGING_BACKGROUND_DURATION 10
#define DEMO_FLASHING_SQUARE_SIZE 250
#define DEMO_FLASHING_SQUARE_DURATION 10
#define DEMO_WELCOME_MESSAGE_DURATION 30

#define DEMO_VERY_SHORT_DELAY 100
#define DEMO_SHORT_DELAY 250
#define DEMO_MEDIUM_DELAY 500
#define DEMO_LONG_DELAY 1000
#define DEMO_VERY_LONG_DELAY 5000

void demo_changing_background(struct framebuffer_container* framebuffer_container);
void demo_flashing_square(struct framebuffer_container* framebuffer_container);
void demo_test();
void demo_welcome_message(struct framebuffer_container* framebuffer_container);

#endif