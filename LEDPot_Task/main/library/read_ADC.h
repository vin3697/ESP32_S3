
#pragma once

//ADC1 Channels
#define EXAMPLE_ADC1_CHAN0          ADC_CHANNEL_2
#define EXAMPLE_ADC_ATTEN           ADC_ATTEN_DB_2_5


void configure_adc(void);
int read_adc(void);