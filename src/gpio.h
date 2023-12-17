#ifndef GPIO_H
#define GPIO_H

#include "primitives.h"

#define GPIO_BASE 0x10012000
#define GPIO_GREEN_LED_PIN 19
#define GPIO_BLUE_LED_PIN 21
#define GPIO_RED_LED_PIN 22

typedef struct {
    volatile uint32 INPUT_VALUE;
    volatile uint32 INPUT_ENABLE;
    volatile uint32 OUTPUT_ENABLE;
    volatile uint32 OUTPUT_VALUE;
    volatile uint32 PULLUP_ENABLE;
	volatile uint32 DRIVE_STRENGTH;
	volatile uint32 RISE_INTERRUPT_ENABLE;
	volatile uint32 RISE_INTERRUPT_PENDING;
	volatile uint32 FALL_INTERRUPT_ENABLE;
	volatile uint32 FALL_INTERRUPT_PENDING;
	volatile uint32 HIGH_INTERRUPT_ENABLE;
	volatile uint32 HIGH_INTERRUPT_PENDING;
	volatile uint32 LOW_INTERRUPT_ENABLE;
	volatile uint32 LOW_INTERRUPT_PENDING;
	volatile uint32 IO_FUNCTION_ENABLE;
	volatile uint32 IO_FUNCTION_SELECT;
	volatile uint32 OUTPUT_XOR;
    volatile uint32 PASSTHROUGH_HIGH_INTERRUPT_ENABLE;
    volatile uint32 PASSTHROUGH_LOW_INTERRUPT_ENABLE;
} gpio_registers;


void gpio_output_enable(uint32 pin);
void gpio_input_enable(uint32 pin);

int gpio_read_pin(uint32 pin);
void gpio_set_pin(uint32 pin);
void gpio_clear_pin(uint32 pin);
void gpio_toggle_pin(uint32 pin);



#endif
