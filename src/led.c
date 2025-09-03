#include "led.h"

void led_debug() {
    
    gpio_set_function(LED_GPIO_PIN_NUMBER, LED_GPIO_PIN_FUNCTION);

    while (1) {
        timer_wait(LED_FLASH_DELAY);
        gpio_clear(LED_GPIO_PIN_NUMBER);
        timer_wait(LED_FLASH_DELAY);
        gpio_set(LED_GPIO_PIN_NUMBER);
    }
}

void led_error(uint32_t error_code) {

    gpio_set_function(LED_GPIO_PIN_NUMBER, LED_GPIO_PIN_FUNCTION);

    while (1) {

        for (uint32_t i=0; i<error_code; i++) {
            gpio_set(LED_GPIO_PIN_NUMBER);
            timer_wait(LED_FLASH_DELAY);
            gpio_clear(LED_GPIO_PIN_NUMBER);
            timer_wait(LED_FLASH_DELAY);
        }

        timer_wait(LED_FLASH_BREAK);
    }
}

void led_flash() {
    
    gpio_set_function(LED_GPIO_PIN_NUMBER, LED_GPIO_PIN_FUNCTION);

    timer_wait(LED_FLASH_DELAY);
    gpio_clear(LED_GPIO_PIN_NUMBER);
    timer_wait(LED_FLASH_DELAY);
    gpio_set(LED_GPIO_PIN_NUMBER);
}