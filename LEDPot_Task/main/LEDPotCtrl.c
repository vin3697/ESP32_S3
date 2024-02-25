/*

here is implementation of blinking of LED
and color change depending upon frequency

*/


#include <stdio.h>
//#include <math.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_timer.h"

#include "led_strip.h"

//header files LED and ADC
#include "wr_LED.h"
#include "read_ADC.h" 
#define PERIOD_MS 100


//#define COLOR_CHANGE TRUE

// to use blinking LED with frequencies
#define FREQCONSTANT 10
#define FREQMULTIPLLIER 0.0104

static const char *TAG         = "example";
static int voltage             = 0;

static uint8_t FrequencyCount  = 0;

/*
static int start_time        = 0;
static int end_time          = 0;
static int execution_time_ms = 0;
static int execution_time_us = 0;
*/

const TickType_t xDelay  = CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS; //delay of 10ms

//declarations of functions
static void blink_LED(void);

//blinking with Freq.
static void vLEDFreq_TimerSetup();
static void vLEDFreq_TimerCallback();

//color change w.r.t voltage
static void vColorChange_TimerSetup();
static void vColorChange_Callback();


//software timer implementation
TimerHandle_t xLEDblinkFreq_Timer = NULL;                             //Timer handle for BlinkLED freq w.r.t voltage
TimerHandle_t xColorChange_Timer  = NULL;                             //Timer handle for color change  w.r.t voltage

/*
                                        app_main function
*/
void app_main(void)
{
    // configure the peripherals!
    configure_led();
    configure_adc();
    
    #ifdef COLOR_CHANGE
        vColorChange_TimerSetup();
    #else
        vLEDFreq_TimerSetup();
    #endif
    
}

static void blink_LED(void){

    //ESP_LOGI(TAG, "Voltage in ms : %d", voltage);


    FrequencyCount = (uint8_t)(voltage * FREQMULTIPLLIER);      // normalized value between 0-10 (11 values)

    on_led();
    vTaskDelay((FREQCONSTANT - FrequencyCount)*xDelay);         // blink_LED execution time = [0ms, ~97ms] 
    off_led();
    ESP_LOGI(TAG, "Frequency with LED is blinking : %d", FrequencyCount);
    


}

/*
                             below is LED color change software timer implementation
*/

static void vColorChange_TimerSetup(){

    // create then start the auto-reload timer that is responsible for
    // changing the LED color with different frequencies.
    xColorChange_Timer = xTimerCreate( "colrChngTimer",               // Just a text name, not used by the kernel.
                                    pdMS_TO_TICKS(PERIOD_MS),     // timer period = 100milliSecs, as response time has to be 100ms
                                    pdTRUE,                       // timer is a Auto Reload timer which make the task periodic in nature.
                                    0,                            // id is not used by the callback so can take any value.
                                    vColorChange_Callback             // callback function that changes the color of LED w.r.t voltage.
                                );

    if( xColorChange_Timer == NULL )
    {
        // The timer was not created.
        ESP_LOGE(TAG, "Failed to create timer");
    }
    else
    {
        // start the timer.  No block time is specified.
        if( xTimerStart( xColorChange_Timer, 0 ) != pdPASS ) // xTimerStart(xTimer, xTicksToWait)
        {
            // The timer could not be set into the Active state.
            ESP_LOGE(TAG, "Failed to set color change timer into active state");
        }
    }

}

static void vColorChange_Callback(){

    //start_time = esp_timer_get_time();
    //get voltage from ADC

    voltage = read_adc();

    //end_time = esp_timer_get_time();
    //start_time = esp_timer_get_time();
    //color change method
    FrequencyCount = (voltage * FREQMULTIPLLIER);
    change_color(FrequencyCount);               //execution time for color change function ~ 360us

    //end_time = esp_timer_get_time();
    //execution_time_us = (end_time - start_time);

    //ESP_LOGI(TAG, "Execution time in micro seconds: %dus", execution_time_us);

}

/*
                             below is Blink LED Freq software timer implementation
*/

static void vLEDFreq_TimerSetup(){

    // create then start the auto-reload timer that is responsible for
    // blinking the LED with different frequencies.
    xLEDblinkFreq_Timer = xTimerCreate( "LEDblinkTimer",           // Just a text name, not used by the kernel.
                                    pdMS_TO_TICKS(PERIOD_MS),     // timer period = 100milliSecs, as response time has to be 100ms
                                    pdTRUE,                       // timer is a auto reload timer.
                                    0,                            // id is not used by the callback so can take any value.
                                    vLEDFreq_TimerCallback         // callback function that blinks LED w.r.t Freq.
                                );

    if( xLEDblinkFreq_Timer == NULL )
    {
        // The timer was not created.
        ESP_LOGE(TAG, "Failed to create timer");
    }
    else
    {
        // Start the timer.  No block time is specified.
        if( xTimerStart( xLEDblinkFreq_Timer, 0 ) != pdPASS ) // xTimerStart(xTimer, xTicksToWait)
        {
            // The timer could not be set into the Active state.
            ESP_LOGE(TAG, "Failed to set blink LED timer into active state");
        }
    }

}

//callback function for software timer :: LED blinking with Freq.
static void vLEDFreq_TimerCallback()
{

    
    //get voltage from ADC
    voltage = read_adc();          //voltage function takes ~38us for its execution
    
    //start_time = esp_timer_get_time();
    
    //blink freq with Pot
    blink_LED();                   //blinking function [0ms-97ms] for its execution

    /*
    end_time = esp_timer_get_time();
    execution_time_ms = (end_time - start_time);
    execution_time_ms = execution_time_ms/1000;
    ESP_LOGI(TAG, "Execution time of LED blink function in milli seconds: %dms", execution_time_ms);
    */

}


