#include "mailbox.h"

uint32_t mailbox_read(uint32_t channel) {
    
    // wait for read status OK and then read from mailbox
    // check channel on message matches specified channel
    // if not, read another message

    uint32_t value;

    do {  
        mailbox_wait_read_status();
        volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE);
        value = *address;
    } while ((value & 0b1111) != channel);

    return value & ~(0b1111);
}

void mailbox_wait_read_status() {

    // wait until the read status is OK
    // read status is indicated by the 30th bit of the mailbox status register

    volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE + MAILBOX_STATUS);
    
    uint32_t value = *address;

    while ((value & (1 << 30)) == 0);  
}

void mailbox_wait_write_status() {

    // wait until the write status is OK
    // read status is indicated by the 31st bit of the mailbox status register

    volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE + MAILBOX_STATUS);
    
    uint32_t value = *address;

    while ((value & (1 << 31)) == 0);
}

void mailbox_write(uint32_t channel, uint32_t message) {

    volatile uint32_t* address = (volatile uint32_t*)(MAILBOX_BASE + MAILBOX_WRITE);

    mailbox_wait_write_status();

    *address = channel + message;
}
