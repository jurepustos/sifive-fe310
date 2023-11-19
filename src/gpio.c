#include "gpio.h"

#define GPIO ((GPIO_Registers *) GPIO_BASE)

void gpio_output_enable(unsigned int pin) {
    GPIO->OUTPUT_EN |= (1 << pin);
}

void gpio_input_enable(unsigned int pin) {
    GPIO->INPUT_EN |= (1 << pin);
}

int gpio_read_pin(unsigned int pin) {
    return (GPIO->INPUT_VAL |= (1 << pin)) >> pin;
}

void gpio_set_pin(unsigned int pin) {
    GPIO->OUTPUT_VAL |= (1 << pin);
}

void gpio_clear_pin(unsigned int pin) {
    GPIO->OUTPUT_VAL &= ~(1 << pin);
}

void gpio_toggle_pin(unsigned int pin) {
    GPIO->OUTPUT_VAL ^= (1 << pin);
}
