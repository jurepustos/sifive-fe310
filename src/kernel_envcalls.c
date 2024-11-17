#include "kernel_envcalls.h"
#include "devices/gpio.h"
#include "devices/uart.h"
#include "primitives.h"
#include "scheduler.h"

uint32 handle_envcall(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3,
                      uint32 arg4, uint32 arg5, uint32 arg6) {
    switch (id) {
    case ENV_WRITE_CONSOLE:
        return kernel_write_console(arg1, (char*)arg2, arg3);
        break;
    case ENV_READ_CONSOLE:
        return kernel_read_console(arg1, (char*)arg2, arg3);
        break;
    case ENV_SET_GREEN_LED:
        return kernel_set_green_led(arg1);
        break;
    case ENV_SET_RED_LED:
        return kernel_set_red_led(arg1);
        break;
    case ENV_SET_BLUE_LED:
        return kernel_set_blue_led(arg1);
        break;
    case ENV_SET_GPIO_PIN:
        return kernel_set_gpio_pin(arg1, arg2);
        break;
    case ENV_TERMINATE_TASK:
        return kernel_terminate_task(arg1);
        break;
    }

    return 0;
}

// writes up to `count` bytes from `buf` to interface `interface`
// or until a null character is written. Returns number of written characters.
// Return -1 upon error.
uint32 kernel_write_console(uint32 interface, char* buf, uint32 count) {
    uart_registers* uart;
    if (interface == 0) {
        uart = get_uart0();
    } else if (interface == 1) {
        uart = get_uart1();
    } else {
        return -1;
    }

    for (int32 i = 0; i < count; i++) {
        if (buf[i] == '\0') {
            uart_send_data(uart, '\n');
            return i + 1;
        } else {
            uart_send_data(uart, buf[i]);
        }
    }

    return count;
}

// read up to `count` bytes into `buf` from interface `interface`
// until a null character is read. Returns number of characters read.
// Return -1 upon error.
uint32 kernel_read_console(uint32 interface, char* buf, uint32 count) {
    uart_registers* uart;
    if (interface == 0) {
        uart = get_uart0();
    } else if (interface == 1) {
        uart = get_uart1();
    } else {
        return -1;
    }

    for (int32 i = 0; i < count; i++) {
        char recv = uart_receive_data(uart);
        if (recv == '\n' || recv == '\0') {
            buf[i] = '\0';
            return i + 1;
        } else {
            buf[i] = recv;
        }
    }

    return count;
}

// sets green LED to value of `enable`.
// Return -1 upon error.
uint32 kernel_set_green_led(uint32 enable) {
    if (enable) {
        gpio_set_pin(GPIO_GREEN_LED_PIN);
    } else {
        gpio_clear_pin(GPIO_GREEN_LED_PIN);
    }
    return 0;
}

// sets red LED to value of `enable`.
// Return -1 upon error.
uint32 kernel_set_red_led(uint32 enable) {
    if (enable) {
        gpio_set_pin(GPIO_RED_LED_PIN);
    } else {
        gpio_clear_pin(GPIO_RED_LED_PIN);
    }
    return 0;
}

// sets blue LED to value of `enable`.
// Return -1 upon error.
uint32 kernel_set_blue_led(uint32 enable) {
    if (enable) {
        gpio_set_pin(GPIO_BLUE_LED_PIN);
    } else {
        gpio_clear_pin(GPIO_BLUE_LED_PIN);
    }
    return 0;
}

// sets value of GPIO pin `pin` to `enable`.
// Return -1 upon error.
uint32 kernel_set_gpio_pin(uint32 pin, uint32 enable) {
    if (enable) {
        gpio_set_pin(pin);
    } else {
        gpio_clear_pin(pin);
    }
    return 0;
}

uint32 kernel_terminate_task(uint32 taskid) {
    return terminate_task(taskid);
}
