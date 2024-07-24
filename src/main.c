#include "devices/gpio.h"
#include "riscv/interrupts.h"
#include "devices/uart.h"
#include "scheduler.h"


void init_led() {
    // initialize LED outputs
    gpio_output_enable(GPIO_GREEN_LED_PIN);
    gpio_output_enable(GPIO_BLUE_LED_PIN);
    gpio_output_enable(GPIO_RED_LED_PIN);
}

void init_uart() {
    // initialize UART
    uart_setup uart_settings = {
        .baud_rate = BAUD_115200,
        .stop_bits = 1,
        .mode = MODE_TX_RX
    };
    init_uart0(&uart_settings);
    init_uart1(&uart_settings);
}

void init_interrupts() {
    // initialize interrupt handling
    register_vector_table(&_vector_table);
    enable_external_interrupts();
    enable_timer_interrupts();
    enable_software_interrupts();
    enable_interrupts();
}

// called from riscv/start.S
int main() {
    init_led();
    init_uart();
    init_interrupts();
    start_scheduler();

    return 0;
}

