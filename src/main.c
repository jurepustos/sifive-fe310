#include "gpio.h"
#include "interrupts.h"

int main() {
    gpio_output_enable(GPIO_GREEN_LED_PIN);
    gpio_set_pin(GPIO_GREEN_LED_PIN);

    while(1) {
        gpio_toggle_pin(GPIO_GREEN_LED_PIN);
    }

    return 0;
}

