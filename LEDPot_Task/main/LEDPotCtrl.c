/*

here is implementation of blinking of LED w.r.t Voltage (Potentiometer Value)
and color change depending upon Potentiometer


*/


#include <stdio.h>
//#include <math.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "led_strip.h"

//header files LED and ADC
#include "wr_LED.h"
#include "read_ADC.h" 
#define PERIOD_MS 10



static const char *TAG   = "example";
static int voltage   = 0;

const TickType_t xDelay  = CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS; //delay of 10ms :: xDelay = 10 / portTICK_PERIOD_MS; || define response_time (pdMS_TO_TICKS(100)) :: 100ms to ticks  

//declarations of functions
static void blink_LED(void);

//blinking with Freq.
static void vLEDFreqTimerSetup();
static void vLEDfreqTimerCallback( TimerHandle_t pxTimer );

//color change w.r.t voltage
static void vcolrChngTimerSetup();
static void vcolrChngCallback();

// to use blinking LED with frequencies
#define COLOR_CHANGE TRUE

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
    
    // Starting the scheduler will start the timers running as they have already
    // been set into the active state.
    //vTaskStartScheduler(); 

}

static void blink_LED(void){

    voltage = voltage / 89;            //normalize value between 0-11
    //ESP_LOGI(TAG, "LED toggle");
    ESP_LOGI(TAG, "Frequency with LED is blinking : %d", voltage);
    if(voltage == 11){
        on_led();                      //for Freq. 11 LED will remain On!
    }
    else{
        //Toggle the LED state
        on_led();
        vTaskDelay(voltage*voltage*xDelay); // !delay less than 100ms
        off_led();
    }
    
}

/*
                             Below is LED color change software timer implementation
*/

static void vcolrChngTimerSetup(){

    // Create then start the Auto-reload timer that is responsible for
    // blinking the LED with different frequencies.
    xcolrChngTimer = xTimerCreate( "colrChngTimer",               // Just a text name, not used by the kernel.
                                    pdMS_TO_TICKS(PERIOD_MS),     // The timer period in milliSecs.
                                    pdTRUE,                       // The timer is a one-shot timer.
                                    0,                            // The id is not used by the callback so can take any value.
                                    vcolrChngCallback             // The callback function that changes the color of LED w.r.t voltage.
                                );

    if( xcolrChngTimer == NULL )
    {
        // The timer was not created.
        ESP_LOGE(TAG, "Failed to create timer");
    }
    else
    {
        // Start the timer.  No block time is specified, and even if one was
        // it would be ignored because the scheduler has not yet been
        // started.
        if( xTimerStart( xcolrChngTimer, 0 ) != pdPASS ) // xTimerStart(xTimer, xTicksToWait)
        {
            // The timer could not be set into the Active state.
            ESP_LOGE(TAG, "Failed to set color change timer into active state");
        }
    }

}

static void vcolrChngCallback(){

    //get voltage from ADC
    voltage = read_adc();

    //color change method
    chngLEDcolr(&voltage);

}

/*
                             Below is Blink LED Freq software timer implementation
*/

static void vLEDFreqTimerSetup(){

    // Create then start the Auto-reload timer that is responsible for
    // blinking the LED with different frequencies.
    xLEDblinkFreqTimer = xTimerCreate( "LEDblinkTimer",           // Just a text name, not used by the kernel.
                                    pdMS_TO_TICKS(PERIOD_MS),     // The timer period in milliSecs.
                                    pdTRUE,                       // The timer is a one-shot timer.
                                    0,                            // The id is not used by the callback so can take any value.
                                    vLEDfreqTimerCallback         // The callback function that blins LED w.r.t Freq.
                                );

    if( xLEDblinkFreqTimer == NULL )
    {
        // The timer was not created.
        ESP_LOGE(TAG, "Failed to create timer");
    }
    else
    {
        // Start the timer.  No block time is specified, and even if one was
        // it would be ignored because the scheduler has not yet been
        // started.
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
    voltage = read_adc();
    //blink freq with Pot
    blink_LED();

}


