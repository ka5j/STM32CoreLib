#ifndef ADC_API_H_
#define ADC_API_H_

#include <stdint.h>

typedef enum
{
    ADC_CHANNEL_0 = 0, // PA0
    ADC_CHANNEL_1 = 1, // PA1
    ADC_CHANNEL_2 = 2, // PA2
    ADC_CHANNEL_3 = 3,
    ADC_CHANNEL_4 = 4,
    ADC_CHANNEL_5 = 5,
    ADC_CHANNEL_6 = 6,
    ADC_CHANNEL_7 = 7,
    ADC_CHANNEL_8 = 8,   // PB0
    ADC_CHANNEL_9 = 9,   // PB1
    ADC_CHANNEL_10 = 10, // PC0
    ADC_CHANNEL_11 = 11, // PC1
    ADC_CHANNEL_12 = 12,
    ADC_CHANNEL_13 = 13,
    ADC_CHANNEL_14 = 14,
    ADC_CHANNEL_15 = 15
} ADC_Channel;

/**
 * @brief Initialize ADC1 and configure the channel's GPIO for analog input.
 */
void adc_init(ADC_Channel channel);

/**
 * @brief Read a 12-bit ADC value from the selected channel (blocking).
 */
uint16_t adc_read(ADC_Channel channel);

#endif // ADC_API_H_
