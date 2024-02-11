
#pragma once

//ADC1 Channels
#define EXAMPLE_ADC1_CHAN0          ADC_CHANNEL_2
#define EXAMPLE_ADC_ATTEN           ADC_ATTEN_DB_2_5


void configure_adc(void);
int read_adc(void);

/*

!DONT define variables with static and Done define static functions (their visiblity is to particular translation unit) 
static adc_oneshot_unit_handle_t adc1_handle;
static adc_cali_handle_t adc1_cali_chan0_handle = NULL;
static bool do_calibration1_chan0;
static int adc_raw;
static int voltage;
? only give the functions/variables which will be used by the other translation unit!
*/