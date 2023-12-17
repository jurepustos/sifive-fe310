#include "uart.h"
#include "gpio.h"

#define GPIO ((gpio_registers *) GPIO_BASE)
#define UART0 ((uart_registers *) UART0_BASEADDR)
#define UART1 ((uart_registers *) UART1_BASEADDR)

static inline void init_uart_setup(uart_registers *uart, uart_setup *setup) {
	uart_set_baud(uart, setup->baud_rate);
	uart_enable_tx(uart);
	uart_enable_rx(uart);
	uart_set_nstop(uart, setup->stop_bits);
    uart_enable_tx_interrupts(uart);
    uart_enable_rx_interrupts(uart);
}

uart_registers* init_uart0(uart_setup *setup) {
    GPIO->IO_FUNCTION_SELECT &= UART0_PINS_SEL;
    GPIO->IO_FUNCTION_SELECT |= UART0_PINS_EN;

    init_uart_setup(UART0, setup);
    return UART0;
}

uart_registers* init_uart1(uart_setup *setup) {
    GPIO->IO_FUNCTION_SELECT &= UART1_PINS_SEL;
    GPIO->IO_FUNCTION_ENABLE |= UART1_PINS_EN;

    init_uart_setup(UART1, setup);
    return UART1;
}

void close_uart(uart_registers *uart) {
    uart_disable_tx(uart);
    uart_disable_rx(uart);
}

