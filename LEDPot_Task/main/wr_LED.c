/*

LED functions : On, Off and Color change w.r.t Voltage at GPIO3/ADCH2

*/

#include <stdint.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "led_strip.h"


//header file : wr_LED
#include "wr_LED.h"

#define NUMCASES 10  // count from 0 till 10, total 11 cases

static const char *TAG = "example";

static led_strip_handle_t led_strip;

typedef struct
{
    uint16_t rLED;
    uint16_t gLED;
    uint16_t bLED;

}rgbPixel; 

const rgbPixel rgbAllvalues[] = {

    {255, 0, 0},    // case 0: Red
    {0, 255, 0},    // case 1: Green
    {0, 0, 255},    // case 2: Blue
    {255, 255, 0},  // case 3: Yellow
    {255, 0, 255},  // case 4: Magenta
    {0, 255, 255},  // case 5: Cyan
    {128, 128, 128},// case 6: Gray
    {255, 165, 0},  // case 7: Orange
    {128, 0, 128},  // case 8: Purple
    {0, 128, 128},  // case 9: Teal
    {0, 255, 125}   // case 10 : turquoise 

};

void chngLEDcolr(uint8_t VColor){


    if(VColor <= NUMCASES){
        
        rgbPixel rgbLEDpiXel = rgbAllvalues[VColor];
        led_strip_set_pixel(led_strip, 0, rgbLEDpiXel.rLED, rgbLEDpiXel.gLED, rgbLEDpiXel.bLED);

        //ESP_LOGI(TAG, "Red Pixel = %d , Green Pixel = %d, Blue Pixel = %d", rgbLEDpiXel.rLED, rgbLEDpiXel.gLED, rgbLEDpiXel.bLED);
    }
    else{
        led_strip_set_pixel(led_strip, 0, 0, 0, 0);
    }
    led_strip_refresh(led_strip);

}

void on_led(void){
    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    led_strip_set_pixel(led_strip, 0, 255, 0, 0);
    /* Refresh the strip to send data */
    led_strip_refresh(led_strip);
}

void off_led(void)
{
    /* Set all LED off to clear all pixels */
    led_strip_clear(led_strip);   
}

void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink addressable LED!");
    /* LED strip initialization with the GPIO and pixels number*/
    led_strip_config_t strip_config = {
        .strip_gpio_num = BLINK_GPIO,
        .max_leds = 1, // at least one LED on board
    };
#if CONFIG_BLINK_LED_STRIP_BACKEND_RMT
    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000, // 10MHz
        .flags.with_dma = false,
    };
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));
#else
#error "unsupported LED strip backend"
#endif
    /* Set all LED off to clear all pixels */
    led_strip_clear(led_strip);
}
