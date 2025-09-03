#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>

#include "error.h"
#include "led.h"
#include "mailbox.h"

#define FRAMEBUFFER_WIDTH 1920
#define FRAMEBUFFER_HEIGHT 1080
#define FRAMEBUFFER_BIT_DEPTH 16

#define FRAMEBUFFER_GPU_OFFSET 0xc0000000
#define FRAMEBUFFER_MAILBOX_CHANNEL 8

#define FRAMEBUFFER_REQUEST_PHYSICAL 0x00048003
#define FRAMEBUFFER_REQUEST_VIRTUAL 0x00048004
#define FRAMEBUFFER_REQUEST_BIT_DEPTH 0x00048005
#define FRAMEBUFFER_REQUEST_ALLOCATE_FRAMEBUFFER 0x00040001
#define FRAMEBUFFER_REQUEST_FRAMEBUFFER_PITCH 0x00040008
#define FRAMEBUFFER_REQUEST_END_TAG 0

struct framebuffer_container {
    uint32_t width;
    uint32_t height;
    uint32_t bit_depth;
    uint32_t pitch;
    uint32_t pitch_pixels;
    uint16_t* framebuffer;
};

struct framebuffer_container* framebuffer_get();
void framebuffer_get_request(uint32_t width, uint32_t height, uint32_t bit_depth);
void framebuffer_init();
void framebuffer_test();

#endif