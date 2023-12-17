#ifndef H
#define H

#include "primitives.h"
#define UART0_BASEADDR 0x10013000
#define UART1_BASEADDR 0x10023000

#define UART0_RX_PIN 16
#define UART0_TX_PIN 17
#define UART0_PINS_SEL 0xfffcffff  // pins 16 and 17
#define UART0_PINS_EN 0x00030000  // pins 16 and 17

#define UART1_TX_PIN 18
#define UART1_RX_PIN 23
#define UART1_PINS_SEL 0xff7bffff  // pins 18 and 23
#define UART1_PINS_EN 0x00840000  // pins 18 and 23

#define MODE_TX 0x0
#define MODE_RX 0x1
#define MODE_TX_RX 0x2

#define BAUD_115200 139	// this is clock divider for 115200

typedef struct {
	volatile uint32 TXDATA;
	volatile uint32 RXDATA;
	volatile uint32 TXCTRL;
	volatile uint32 RXCTRL;
	volatile uint32 INTERRUPT_ENABLE;
	volatile uint32 INTERRUPT_PENDING;
	volatile uint32 DIV;
} uart_registers;

typedef struct {
    uint32 baud_rate;		// UART communication baud rate. Only 115200 is supported
    uint32 stop_bits;		// Specifies the number of stop bits transmitted.
    uint32 mode;	        // Specifies whether the Receive or Transmit mode is enabled or disabled
} uart_setup;


static inline void uart_set_baud(uart_registers *uart, uint32 baud) {
	uart->DIV = baud;
}

static inline void uart_enable_tx(uart_registers *uart) {
	uart->TXCTRL |= 0x00000001;
}

static inline void uart_enable_rx(uart_registers *uart) {
	uart->RXCTRL |= 0x00000001;
}

static inline void uart_disable_tx(uart_registers *uart) {
	uart->TXCTRL &= 0xfffffffe;
}

static inline void uart_disable_rx(uart_registers *uart) {
	uart->RXCTRL &= 0xfffffffe;
}

static inline void uart_set_nstop(uart_registers *uart, uint32 nstop) {
	if (nstop == 1) {
		uart->RXCTRL &= 0xfffffffd;
	}
	else if (nstop == 2) {
		uart->RXCTRL |= 0x00000002;
	}
}

static inline void uart_enable_tx_interrupts(uart_registers *uart) {
    uart->INTERRUPT_ENABLE |= 0x00000001;
}

static inline void uart_enable_rx_interrupts(uart_registers *uart) {
    uart->INTERRUPT_ENABLE |= 0x00000002;
}

uart_registers* init_uart0(uart_setup *setup);
uart_registers* init_uart1(uart_setup *setup);
void clse_uart(uart_registers *uart);

void uart_send_data(uart_registers *uart, char data);
void uart_receive_data(uart_registers *uart, char data);

void uart_putc(uart_registers *uart, char c);
void uart_printf(uart_registers *uart, char *string);


#endif
