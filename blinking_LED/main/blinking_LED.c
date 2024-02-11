#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_strip.h"

#include "esp_log.h"

//#define CONFIG_BLINK_GPIO 48
#define BLINK_GPIO 48
#define CONFIG_BLINK_LED_STRIP_BACKEND_RMT 1
#define CONFIG_BLINK_PERIOD 100

//#define CONFIG_BLINK_LED_STRIP 1

static led_strip_handle_t led_strip;
static const char *TAG = "example";



static void on_led(void){
    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    led_strip_set_pixel(led_strip, 0, 255, 0, 0);
    /* Refresh the strip to send data */
    led_strip_refresh(led_strip);
}

static void off_led(void)
{
    /* Set all LED off to clear all pixels */
    led_strip_clear(led_strip);   
}

static void configure_led(void)
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

void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    configure_led();

    while (1) {
        //ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
        on_led();
        /* Toggle the LED state */
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        off_led();
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}