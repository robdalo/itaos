#include "led.h"

void led_debug(void) {
    
    gpio_set_function(LED_GPIO_PIN_NUMBER, LED_GPIO_PIN_FUNCTION);

    while (1) {
        timer_wait(LED_FLASH_DELAY);
        gpio_clear(LED_GPIO_PIN_NUMBER);
        timer_wait(LED_FLASH_DELAY);
        gpio_set(LED_GPIO_PIN_NUMBER);
    }
}
