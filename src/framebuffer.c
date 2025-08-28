#include "framebuffer.h"

volatile uint32_t __attribute__((aligned(16))) framebuffer_request[32] = { 1 };

struct framebuffer_container framebuffer_container_current = { .width = 1 };

struct framebuffer_container* framebuffer_get() {
    return &framebuffer_container_current;
}

void framebuffer_get_request(uint32_t width, uint32_t height, uint32_t bit_depth) {
    
    // total size must match number of items in array
    framebuffer_request[0] = 26 * 4; // total size
    framebuffer_request[1] = 0; // request code

    // physical width / height
    framebuffer_request[2] = FRAMEBUFFER_REQUEST_PHYSICAL;
    framebuffer_request[3] = 8;
    framebuffer_request[4] = 8;
    framebuffer_request[5] = width;
    framebuffer_request[6] = height;

    // virtual width / height
    framebuffer_request[7] = FRAMEBUFFER_REQUEST_VIRTUAL;
    framebuffer_request[8] = 8;
    framebuffer_request[9] = 8;
    framebuffer_request[10] = width;
    framebuffer_request[11] = height;

    // bit depth
    framebuffer_request[12] = FRAMEBUFFER_REQUEST_BIT_DEPTH;
    framebuffer_request[13] = 4;
    framebuffer_request[14] = 4;
    framebuffer_request[15] = bit_depth;

    // allocate framebuffer
    framebuffer_request[16] = FRAMEBUFFER_REQUEST_ALLOCATE_FRAMEBUFFER;
    framebuffer_request[17] = 8;
    framebuffer_request[18] = 4;
    framebuffer_request[19] = 0; // framebuffer address
    framebuffer_request[20] = 0; // framebuffer size

    // framebuffer pitch
    framebuffer_request[21] = FRAMEBUFFER_REQUEST_FRAMEBUFFER_PITCH;
    framebuffer_request[22] = 4;
    framebuffer_request[23] = 4;
    framebuffer_request[24] = 0; // framebuffer pitch

    // end tag
    framebuffer_request[25] = FRAMEBUFFER_REQUEST_END_TAG;
}

void framebuffer_init(
    uint32_t width, 
    uint32_t height, 
    uint32_t bit_depth) {

    // get the framebuffer request

    framebuffer_get_request(width, height, bit_depth);

    // gpu uses a different memory addressing system so we have
    // to convert our address to the equivilent address for the gpu

    uint32_t address = ((uint32_t)(&framebuffer_request)) + FRAMEBUFFER_GPU_OFFSET;

    // write framebuffer request to mailbox

    mailbox_write(FRAMEBUFFER_MAILBOX_CHANNEL, address);

    // read framebuffer request response from mailbox

    uint32_t response = mailbox_read(FRAMEBUFFER_MAILBOX_CHANNEL);

    if (response == 0)
        led_error(ERROR_FRAMEBUFFER_INIT);

    // populate framebuffer container

    framebuffer_container_current.width = framebuffer_request[10];
    framebuffer_container_current.height = framebuffer_request[11];
    framebuffer_container_current.bit_depth = framebuffer_request[15];
    framebuffer_container_current.pitch = framebuffer_request[24];
    framebuffer_container_current.pitch_pixels = framebuffer_container_current.pitch / 2; // pitch pixels for 16 bit colour
    framebuffer_container_current.framebuffer = (uint16_t*)(framebuffer_request[19] - FRAMEBUFFER_GPU_OFFSET);
}

void framebuffer_test() {

    framebuffer_init(1920, 1080, 16);

    led_debug();
}