#pragma once
#include "led_strip.h"

#define CONFIG_BLINK_PERIOD 100
//#define CONFIG_BLINK_GPIO 48
#define BLINK_GPIO 48
#define CONFIG_BLINK_LED_STRIP_BACKEND_RMT 1
#define CONFIG_BLINK_PERIOD 100

//#define CONFIG_BLINK_LED_STRIP 1


void on_led(void);
void off_led(void);
void configure_led(void);

