#include "gpio.h"

void gpio_set_function(uint32_t pin_number, uint32_t pin_function) {

    // 54 gpio pins, 3 bits per pin, 
    // 10 pins per register, 30 bits used per register

    uint32_t offset = (pin_number / 10) * 4; // 16 / 10 = 1 remainder 6
    uint32_t bit_shift = (pin_number % 10) * 3; // 6 * 3 = 18

    volatile uint32_t* address = (volatile uint32_t*)(GPIO_BASE + GPIO_FUNCTION_SELECT + offset);

    uint32_t value = *address;

    value &= ~(0b111 << bit_shift);
    value |= pin_function << bit_shift;

    *address = value;
}

void gpio_clear(uint32_t pin_number) {
    
    // 54 gpio pins, 1 bit per pin, 32 bits per register

    uint32_t offset = (pin_number / 32) * 4; // 16 / 32 = 0 remainder 16
    uint32_t bit_shift = (pin_number % 32);

    volatile uint32_t* address = (volatile uint32_t*)(GPIO_BASE + GPIO_PIN_OUTPUT_CLEAR + offset);

    uint32_t value = *address;

    value |= 1 << bit_shift;

    *address = value;
}

void gpio_set(uint32_t pin_number) {
    
    // 54 gpio pins, 1 bit per pin, 32 bits per register

    uint32_t offset = (pin_number / 32) * 4; // 16 / 32 = 0 remainder 16
    uint32_t bit_shift = (pin_number % 32);

    volatile uint32_t* address = (volatile uint32_t*)(GPIO_BASE + GPIO_PIN_OUTPUT_SET + offset);

    uint32_t value = *address;

    value |= 1 << bit_shift;

    *address = value;
}
