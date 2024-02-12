#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "led_strip.h"

//header files LED and ADC
#include "wr_LED.h"
#include "read_ADC.h" 

static const char *TAG = "example";
static int voltage = 0;
const TickType_t xDelay = CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS;


//blinking function
void blink_LED(void);


void app_main(void)
{

    // configure the peripherals!
    configure_led();
    configure_adc();
    
    while (1) {
        
        //get voltage from ADC
        voltage = read_adc();
        
        //blink freq with Pot
        blink_LED();

        //change LED color with Pot
        //chngLEDcolr(&voltage);

    }

}

void blink_LED(void){

    ESP_LOGI(TAG, "Voltage in milliVolts is : %d", voltage);

    voltage = 10 - voltage/99;

    ESP_LOGI(TAG, "Normalization value is   : %d", voltage);
    ESP_LOGI(TAG, "LED toggle");

    if(voltage == 10){
        on_led();
    }
    else{
        //Toggle the LED state
        on_led();
        vTaskDelay(voltage*xDelay);
        off_led();
        vTaskDelay(voltage*xDelay);
    }

}