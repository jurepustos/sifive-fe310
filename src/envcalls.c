#include "primitives.h"
#include "envcalls.h"
#include "devices/uart.h"
#include "devices/gpio.h"


// writes up to `count` bytes from `buf` to interface `interface`
// or until a null character is written.
// Return -1 upon error.
int32 console_write(int32 interface, char* buf, int32 count) {
    uart_registers* uart;
    if (interface == 0) {
        uart = get_uart0();
    }
    else if (interface == 1) {
        uart = get_uart1();
    }
    else {
        return -1;
    }

    for (int32 i = 0; i < count; i++) {
        if (buf[i] == '\0') {
            uart_send_data(uart, '\n');
            return i+1;
        }
        else {
            uart_send_data(uart, buf[i]);
        }
    }

    return count;
}

// read up to `count` bytes into `buf` from interface `interface`
// until a null character is read.
// Return -1 upon error.
int32 console_read(int32 interface, char* buf, int32 count) {
    uart_registers* uart;
    if (interface == 0) {
        uart = get_uart0();
    }
    else if (interface == 1) {
        uart = get_uart1();
    }
    else {
        return -1;
    }

    for (int32 i = 0; i < count; i++) {
        char recv = uart_receive_data(uart);
        if (recv == '\n' || recv == '\0') {
            buf[i] = '\0';
            return i+1;
        }
        else {
            buf[i] = recv;
        }
    }

    return count;

}

// sets green LED to value of `enable`.
// Return -1 upon error.
int32 set_green_led(int32 enable) {
    if (enable) {
        gpio_set_pin(GPIO_GREEN_LED_PIN);
    }
    else {
        gpio_clear_pin(GPIO_GREEN_LED_PIN);
    }
    return 0;
}

// sets red LED to value of `enable`.
// Return -1 upon error.
int32 set_red_led(int32 enable) {
    if (enable) {
        gpio_set_pin(GPIO_RED_LED_PIN);
    }
    else {
        gpio_clear_pin(GPIO_RED_LED_PIN);
    }
    return 0;
}

// sets blue LED to value of `enable`.
// Return -1 upon error.
int32 set_blue_led(int32 enable) {
    if (enable) {
        gpio_set_pin(GPIO_BLUE_LED_PIN);
    }
    else {
        gpio_clear_pin(GPIO_BLUE_LED_PIN);
    }
    return 0;
}

// sets value of GPIO pin `pin` to `enable`.
// Return -1 upon error.
int32 gpio_set(int32 pin, int32 enable) {
    if (enable) {
        gpio_set_pin(pin);
    }
    else {
        gpio_clear_pin(pin);
    }
    return 0;
}
