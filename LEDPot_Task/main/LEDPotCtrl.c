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
// to use blinking LED with frequencies
//#define COLOR_CHANGE TRUE

static const char *TAG         = "example";
static int voltage             = 0;
static uint8_t normalizeFactor = 0;
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
static void vLEDFreqTimerSetup();
static void vLEDfreqTimerCallback( TimerHandle_t pxTimer );

//color change w.r.t voltage
static void vcolrChngTimerSetup();
static void vcolrChngCallback();


//software timer implementation
TimerHandle_t xLEDblinkFreqTimer = NULL;                             //Timer handle for BlinkLED freq w.r.t voltage
TimerHandle_t xcolrChngTimer     = NULL;                             //Timer handle for color change  w.r.t voltage

/*
                                        app_main function
*/
void app_main(void)
{
    // configure the peripherals!
    configure_led();
    configure_adc();
    
    #ifdef COLOR_CHANGE
        vcolrChngTimerSetup();
    #else
        vLEDFreqTimerSetup();
    #endif
    
}

static void blink_LED(void){

    //ESP_LOGI(TAG, "Voltage in ms : %d", voltage);

    normalizeFactor = (voltage / 96);      //normalized value between 0-10 (11 values)
    
    /*
    normalizeFactor = 10 LED off
    normalizeFactor = 0  LED On
    */
    on_led();
    vTaskDelay((10-normalizeFactor)*xDelay); // blink_LED execution time = [0ms, ~97ms] 
    off_led();
    
    
    /*
    if(normalizeFactor == 0){
        on_led();                          //here, Frequency = 0; LED will remain On!
    }
    else{
        //Toggle the LED state
        on_led();
        vTaskDelay((11-normalizeFactor)*xDelay); // blink_LED execution time = [0ms, ~97ms] 
        off_led();
    }*/
    ESP_LOGI(TAG, "Frequency with LED is blinking : %d", normalizeFactor);
    
}

/*
                             below is LED color change software timer implementation
*/

static void vcolrChngTimerSetup(){

    // create then start the auto-reload timer that is responsible for
    // changing the LED color with different frequencies.
    xcolrChngTimer = xTimerCreate( "colrChngTimer",               // Just a text name, not used by the kernel.
                                    pdMS_TO_TICKS(PERIOD_MS),     // timer period = 100milliSecs, as response time has to be 100ms
                                    pdTRUE,                       // timer is a Auto Reload timer which make the task periodic in nature.
                                    0,                            // id is not used by the callback so can take any value.
                                    vcolrChngCallback             // callback function that changes the color of LED w.r.t voltage.
                                );

    if( xcolrChngTimer == NULL )
    {
        // The timer was not created.
        ESP_LOGE(TAG, "Failed to create timer");
    }
    else
    {
        // start the timer.  No block time is specified.
        if( xTimerStart( xcolrChngTimer, 0 ) != pdPASS ) // xTimerStart(xTimer, xTicksToWait)
        {
            // The timer could not be set into the Active state.
            ESP_LOGE(TAG, "Failed to set color change timer into active state");
        }
    }

}

static void vcolrChngCallback(){

    //start_time = esp_timer_get_time();
    //get voltage from ADC

    voltage = read_adc();

    //end_time = esp_timer_get_time();
    //start_time = esp_timer_get_time();
    //color change method
    normalizeFactor = (voltage / 96);
    chngLEDcolr(&normalizeFactor);               //execution time for color change function ~ 360us

    //end_time = esp_timer_get_time();
    //execution_time_us = (end_time - start_time);

    //ESP_LOGI(TAG, "Execution time in micro seconds: %dus", execution_time_us);

}

/*
                             below is Blink LED Freq software timer implementation
*/

static void vLEDFreqTimerSetup(){

    // create then start the auto-reload timer that is responsible for
    // blinking the LED with different frequencies.
    xLEDblinkFreqTimer = xTimerCreate( "LEDblinkTimer",           // Just a text name, not used by the kernel.
                                    pdMS_TO_TICKS(PERIOD_MS),     // timer period = 100milliSecs, as response time has to be 100ms
                                    pdTRUE,                       // timer is a auto reload timer.
                                    0,                            // id is not used by the callback so can take any value.
                                    vLEDfreqTimerCallback         // callback function that blinks LED w.r.t Freq.
                                );

    if( xLEDblinkFreqTimer == NULL )
    {
        // The timer was not created.
        ESP_LOGE(TAG, "Failed to create timer");
    }
    else
    {
        // Start the timer.  No block time is specified.
        if( xTimerStart( xLEDblinkFreqTimer, 0 ) != pdPASS ) // xTimerStart(xTimer, xTicksToWait)
        {
            // The timer could not be set into the Active state.
            ESP_LOGE(TAG, "Failed to set blink LED timer into active state");
        }
    }

}

//callback function for software timer :: LED blinking with Freq.
static void vLEDfreqTimerCallback( TimerHandle_t pxTimer )
{

    
    //get voltage from ADC
    voltage = read_adc();          //voltage function takes ~38us for its execution
    
    //start_time = esp_timer_get_time();
    
    //blink freq with Pot
    blink_LED();                   //blinking function [0ms-97ms] for its execution

    //end_time = esp_timer_get_time();
    //execution_time_ms = (end_time - start_time);
    //execution_time_ms = execution_time_ms/1000;
    //ESP_LOGI(TAG, "Execution time of LED blink function in milli seconds: %dms", execution_time_ms);

}


