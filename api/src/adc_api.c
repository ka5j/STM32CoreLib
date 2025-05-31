#include "adc_api.h"
#include "../../core/include/bare_adc.h"

static uint8_t adc_initialized = 0;

void adc_init(ADC_Channel channel)
{
    if (!adc_initialized)
    {
        bare_adc_enable();
        adc_initialized = 1;
    }

    bare_adc_gpio_init((uint8_t)channel);      // Set analog mode
    bare_adc_channel_enable((uint8_t)channel); // Setup SQR3
}

uint16_t adc_read(ADC_Channel channel)
{
    return bare_adc_read_channel((uint8_t)channel);
}
