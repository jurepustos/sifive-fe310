#include "gpio.h"

#define GPIO ((gpio_registers *) GPIO_BASE)

void gpio_output_enable(unsigned int pin) {
    GPIO->OUTPUT_ENABLE |= (1 << pin);
}

void gpio_input_enable(unsigned int pin) {
    GPIO->INPUT_ENABLE |= (1 << pin);
}

int gpio_read_pin(unsigned int pin) {
    return (GPIO->INPUT_VALUE |= (1 << pin)) >> pin;
}

void gpio_set_pin(unsigned int pin) {
    GPIO->OUTPUT_VALUE |= (1 << pin);
}

void gpio_clear_pin(unsigned int pin) {
    GPIO->OUTPUT_VALUE &= ~(1 << pin);
}

void gpio_toggle_pin(unsigned int pin) {
    GPIO->OUTPUT_VALUE ^= (1 << pin);
}
