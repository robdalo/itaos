#ifndef LED_H
#define LED_H

#include <stdint.h>

#include "gpio.h"
#include "timer.h"

#define LED_FLASH_BREAK 5
#define LED_FLASH_DELAY 1
#define LED_GPIO_PIN_NUMBER 16
#define LED_GPIO_PIN_FUNCTION 1

void led_debug(void);
void led_error(uint32_t error_code);
void led_flash(void);

#endif