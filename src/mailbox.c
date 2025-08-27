#include "mailbox.h"

uint32_t mailbox_read(uint32_t channel) {
    
    // wait for read status OK and then read from mailbox
    // check channel on message matches specified channel
    // if not, read another message

    uint32_t value;

    do {
        mailbox_read_status_wait();

        volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE);
        
        value = *address;
    } while ((value & 0b1111) != channel);

    return value & ~(0b1111);
}

void mailbox_read_status_wait() {

    // wait until the read status is OK
    // read status is indicated by the 30th bit of the mailbox status register
    // ready to read is indicated by bit 30 being set to 0, not 1

    volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE + MAILBOX_STATUS);
    
    uint32_t value = *address;

    while ((value & (1 << 30)) != 0)
        value = *address;
}

void mailbox_write(uint32_t channel, uint32_t message) {

    mailbox_write_status_wait();

    volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE + MAILBOX_WRITE);

    *address = message + channel;
}

void mailbox_write_status_wait() {

    // wait until the write status is OK
    // write status is indicated by the 31st bit of the mailbox status register
    // ready to write is indicated by bit 31 being set to 0, not 1

    volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE + MAILBOX_STATUS);
    
    uint32_t value = *address;

    while ((value & (1 << 31)) != 0)
        value = *address;
}
