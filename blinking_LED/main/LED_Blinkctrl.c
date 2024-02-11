#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "led_strip.h"

//include the header files
#include "blinking_LED.h"
#include "oneshot_read_main.h" 

static const char *TAG = "example";

void app_main(void)
{

    //Configure the peripheral according to the LED type 
    configure_led();
    configure_adc();
    
    while (1) {
        ESP_LOGI(TAG, "Turning the LED");
        //Toggle the LED state
        on_led();
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        off_led();
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        read_adc();
    }
}