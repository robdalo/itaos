#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>

#include "led.h"
#include "mailbox.h"

struct __attribute__((aligned(16))) framebuffer_container {
    uint32_t width;
    uint32_t height;
    uint32_t virtual_width;
    uint32_t virtual_height;
    uint32_t pitch;
    uint32_t bit_depth;
    uint32_t ignore_x;
    uint32_t ignore_y;
    uint32_t* framebuffer;
    uint32_t framebuffer_size;
};

extern struct framebuffer_container framebuffer_container_current;

int framebuffer_init(uint32_t width, uint32_t height, uint32_t bit_depth);

#endif