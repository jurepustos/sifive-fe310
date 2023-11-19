#define GPIO_BASE 0x10012000
#define GPIO_GREEN_LED_PIN 19
#define GPIO_BLUE_LED_PIN 21
#define GPIO_RED_LED_PIN 22

typedef struct {
    volatile unsigned int INPUT_VAL;
    volatile unsigned int INPUT_EN;
    volatile unsigned int OUTPUT_EN;
    volatile unsigned int OUTPUT_VAL;
} GPIO_Registers;


void gpio_output_enable(unsigned int pin);
void gpio_input_enable(unsigned int pin);

int gpio_read_pin(unsigned int pin);
void gpio_set_pin(unsigned int pin);
void gpio_clear_pin(unsigned int pin);
void gpio_toggle_pin(unsigned int pin);

