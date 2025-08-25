#include <stdint.h>

#define MAILBOX_BASE 0x2000b880
#define MAILBOX_STATUS 0x18
#define MAILBOX_WRITE 0x20

#define MAILBOX_STATUS_READ_OK

uint32_t mailbox_read(uint32_t channel);
void mailbox_wait_read_status();
void mailbox_wait_write_status();
void mailbox_write(uint32_t channel, uint32_t message);
