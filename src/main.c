#include "gpio.h"
#include "interrupts.h"
#include "uart.h"

int main() {
    // initialize LED outputs
    gpio_output_enable(GPIO_GREEN_LED_PIN);
    gpio_output_enable(GPIO_BLUE_LED_PIN);
    gpio_output_enable(GPIO_RED_LED_PIN);

    // initialize UART
    uart_setup uart_settings = {
        .baud_rate = BAUD_115200,
        .stop_bits = 1,
        .mode = MODE_TX_RX
    };
    init_uart0(&uart_settings);
    init_uart1(&uart_settings);

    // initialize interrupt handling
    register_vector_table(&_vector_table);
    enable_external_interrupts();
    enable_timer_interrupts();
    enable_software_interrupts();
    enable_interrupts();



    return 0;
}

