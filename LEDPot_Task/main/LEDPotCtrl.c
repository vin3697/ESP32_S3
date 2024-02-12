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
#define PERIOD_MS 100

static const char *TAG   = "example";
static int voltage   = 0;

/*
//function to linearize the potentiometer values
//int NormValue();
//static float linearVoltage = 0;
//static int mapValue; 
*/

//#define response_time (pdMS_TO_TICKS(100))                         //100ms to ticks

const TickType_t xDelay  = CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS; //delay of 10ms //const TickType_t xDelay = 10 / portTICK_PERIOD_MS;  

//blinking function
static void blink_LED(void);

//software timer implementation
TimerHandle_t xLEDblinkFreqTimer = NULL;                             //Timer for BlinkLED freq w.r.t voltage

static void vLEDfreqTimerCallback( TimerHandle_t pxTimer )
{

    //get voltage from ADC
    voltage = read_adc();
    //blink freq with Pot
    blink_LED();

}

static void blink_LED(void){

    voltage = voltage / 89;       //normalize value between 0-11
    //ESP_LOGI(TAG, "LED toggle");
    ESP_LOGI(TAG, "Normvoltage   : %d", voltage);
    if(voltage == 11){
        on_led();
    }
    else{
        //Toggle the LED state
        on_led();
        vTaskDelay(voltage*voltage*xDelay); // !delay less than 100ms
        off_led();
    }
    
}


//main func
void app_main(void)
{
    // configure the peripherals!
    configure_led();
    configure_adc();

    // Create then start the Auto-reload timer that is responsible for
    // blinking the LED with different frequencies.
    xLEDblinkFreqTimer = xTimerCreate( "LEDblinkTimer",           // Just a text name, not used by the kernel.
                                    pdMS_TO_TICKS(PERIOD_MS),     // The timer period in milliSecs.
                                    pdTRUE,                       // The timer is a one-shot timer.
                                    0,                            // The id is not used by the callback so can take any value.
                                    vLEDfreqTimerCallback         // The callback function that switches the LCD back-light off.
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
        }
    }

}

    /*
    // configure the peripherals!
    configure_led();
    configure_adc();
    
    while (1) {
        
        //get voltage from ADC
        voltage = read_adc();
        
        //blink freq with Pot
        //blink_LED();

        //change LED color with Pot
        //voltage = NormValue();
        chngLEDcolr(&voltage);

    }
    */

/*
int NormValue(){

    float maxVoltage = 988; //milliVolts and min voltage is 0

    linearVoltage = voltage/maxVoltage;
    //ESP_LOGI(TAG, "ratio is voltage/maxVoltage : %f", linearVoltage);
    
    //ln() base to e
    linearVoltage = 680 * (log(linearVoltage+1));
    //ESP_LOGI(TAG, "after logarithmic value is   : %f", linearVoltage);
    //linearVoltage = linearVoltage / 52 ;
    
    return linearVoltage;

}
*/

