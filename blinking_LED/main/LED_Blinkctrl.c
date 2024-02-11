#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "led_strip.h"
//header file
#include "blinking_LED.h"
static const char *TAG = "example";


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