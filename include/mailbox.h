#ifndef MAILBOX_H
#define MAILBOX_H

#include <stdint.h>

#include "framebuffer.h"
#include "led.h"

#define MAILBOX_BASE 0x2000b880
#define MAILBOX_STATUS 0x18
#define MAILBOX_WRITE 0x20

uint32_t mailbox_read(uint32_t channel);
void mailbox_read_status_wait();
void mailbox_write(uint32_t channel, uint32_t message);
void mailbox_write_status_wait();

#endif