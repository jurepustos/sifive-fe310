#include "primitives.h"

int32 console_write(int32 interface, char* buf, int32 count);
int32 console_read(int32 interface, char* buf, int32 count);
int32 green_led_set(int32 enable);
int32 red_led_set(int32 enable);
int32 blue_led_set(int32 enable);
int32 gpio_set(int32 pin, int32 enable);
