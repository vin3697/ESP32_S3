#pragma once
#include "led_strip.h"

//#define CONFIG_BLINK_GPIO 48
#define BLINK_GPIO 48
#define CONFIG_BLINK_LED_STRIP_BACKEND_RMT 1
#define CONFIG_BLINK_PERIOD 10

//#define CONFIG_BLINK_LED_STRIP 1


void on_led(void);
void off_led(void);
void configure_led(void);
void chngLEDcolr(uint8_t *pVColor);

/*
!DONT define variables with static and Done define static functions (their visiblity is to particular translation unit) 
static adc_oneshot_unit_handle_t adc1_handle;
static adc_cali_handle_t adc1_cali_chan0_handle = NULL;
static bool do_calibration1_chan0;
static int adc_raw;
static int voltage;
? only give the functions/variables which will be used by the other translation unit!
*/