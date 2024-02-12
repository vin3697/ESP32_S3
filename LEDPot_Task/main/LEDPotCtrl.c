/*

here is implementation of blinking of LED w.r.t Voltage (Potentiometer Value)
and color change depending upon Potentiometer


*/


#include <stdio.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "led_strip.h"

//header files LED and ADC
#include "wr_LED.h"
#include "read_ADC.h" 

static const char *TAG   = "example";
static int voltage       = 0;
static float linearVoltage = 0;
const TickType_t xDelay  = CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS;


//blinking function
void blink_LED(void);

//function to linearize the potentiometer values
int NormValue();

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


int NormValue(){

    float maxVoltage = 988; //milliVolts and min voltage is 0

    linearVoltage = voltage/maxVoltage;
    ESP_LOGI(TAG, "Linear Voltage is voltage/maxVoltage : %f", linearVoltage);
    
    //ln() base to e
    linearVoltage = 680 * (log(linearVoltage+1));
    ESP_LOGI(TAG, "Logarithmic value is   : %f", linearVoltage);
    linearVoltage = linearVoltage / 52 ;
    
    return linearVoltage;

}


void blink_LED(void){

    ESP_LOGI(TAG, "Voltage in milliVolts is : %d", voltage);

    //normalize the voltage into linear values from 0 - 10
    int mapValue = NormValue();
    
    ESP_LOGI(TAG, "Normalization value is   : %d", mapValue);
    ESP_LOGI(TAG, "LED toggle");
    
    if(mapValue == 9){
        on_led();
    }
    else{
        //Toggle the LED state
        on_led();
        vTaskDelay(mapValue*xDelay);
        off_led();
    }
    
}