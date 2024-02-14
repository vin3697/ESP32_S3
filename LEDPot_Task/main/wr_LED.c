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


static const char *TAG = "example";

static led_strip_handle_t led_strip;

static uint16_t rLED, gLED, bLED; 


void chngLEDcolr(uint8_t *pVColor){

    switch (*pVColor)   // *pVcolor values[0,9]
    {
    case 0:
        rLED = 255;
        gLED = 0;
        bLED = 0;   //red
        break;
    
    case 1:
        rLED = 0;
        gLED = 255;
        bLED = 0;   //green
        break;

    case 2:
        rLED = 255;
        gLED = 255;
        bLED = 0;   //yellow
        break;

    case 3:
        rLED = 255;
        gLED = 0;
        bLED = 255; //magenta
        break;

    case 4:
        rLED = 0;
        gLED = 255;
        bLED = 255;  //cyan
        break;

    case 5:
        rLED = 128;
        gLED = 0;
        bLED =  128; //purple
        break;

    case 6:
        rLED = 255;
        gLED = 165;
        bLED = 0; //orange
        break;

    case 7:
        rLED = 255;
        gLED = 192;
        bLED = 203; //pink
        break;
    case 8:
        rLED = 0;
        gLED = 128;
        bLED = 0;  //dark-green
        break;
    case 9:
        rLED = 255;
        gLED = 140;
        bLED = 0;  //orange-red
        break;
    case 10:
        rLED = 0;
        gLED = 255;
        bLED = 125;  //turquoise
        break;
    default:
        rLED = 255;
        gLED = 255;
        bLED = 255;
        break;
    }
    //ESP_LOGI(TAG, "Normalized value of voltage : %d", *pVColor);
    ESP_LOGI(TAG, "RGB pixel values are : Red %d Green %d Blue %d ", rLED, gLED, bLED);
    led_strip_set_pixel(led_strip, 0, rLED, gLED, bLED);
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

/*
void app_main(void)
{

    //Configure the peripheral according to the LED type 
    configure_led();

    while (1) {
        ESP_LOGI(TAG, "Turning the LED");
        on_led();
        //Toggle the LED state
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        off_led();
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
*/