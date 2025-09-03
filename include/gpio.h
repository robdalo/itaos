#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO_BASE 0xfe200000
#define GPIO_FUNCTION_SELECT 0x00
#define GPIO_PIN_OUTPUT_SET 0x1c
#define GPIO_PIN_OUTPUT_CLEAR  0x28

void gpio_clear(uint32_t pin_number);
void gpio_set_function(uint32_t pin_number, uint32_t pin_function);
void gpio_set(uint32_t pin_number);

#endif