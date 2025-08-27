#include "framebuffer.h"

struct framebuffer_container framebuffer_container_current;

int framebuffer_init(
    uint32_t width, 
    uint32_t height, 
    uint32_t bit_depth) {

    uint32_t channel = 1;

    struct framebuffer_container* container = &framebuffer_container_current;

    container->width = width;
    container->height = height;
    container->virtual_width = width;
    container->virtual_height = height;
    container->bit_depth = bit_depth;

    // gpu uses a different memory addressing system so we have
    // to convert our address to the equivilent address for the gpu

    uint32_t container_address = (uint32_t)(container) + 0x40000000;

    // write framebuffer request to mailbox

    mailbox_write(channel, container_address);

    // read framebuffer request response from mailbox

    return mailbox_read(channel);
}
