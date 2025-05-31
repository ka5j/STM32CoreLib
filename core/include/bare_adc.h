/*******************************************************************************************
 * @file    bare_adc.h
 * @author  ka5j
 * @brief   STM32F446RE ADC1 Bare Metal Driver for Analog Sensor Input
 * @version 1.0
 * @date    2025-05-30
 *
 * @note    Bare-metal access for single-conversion ADC input using ADC1.
 *          Supports single-channel readout only.
 *******************************************************************************************/

#ifndef BARE_ADC_H_
#define BARE_ADC_H_

#include <stdint.h>
#include "adc_registers.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /***************************************
     * Public API
     ***************************************/

    /**
     * @brief Enable ADC1 with default settings (12-bit resolution, software trigger)
     */
    void bare_adc_enable(void);

    /**
     * @brief Configure the GPIO pin corresponding to the selected ADC channel for analog input
     * @param channel ADC channel number (0 to 15)
     */
    void bare_adc_gpio_init(uint8_t channel);

    /**
     * @brief Configure ADC1 to use a specific channel (used for regular sequence)
     * @param channel ADC channel number (0 to 15)
     */
    void bare_adc_channel_enable(uint8_t channel);

    /**
     * @brief Perform a blocking single conversion on the given channel and return the result
     * @param channel ADC channel number (0 to 15)
     * @return 12-bit ADC value (0–4095)
     */
    uint16_t bare_adc_read_channel(uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif // BARE_ADC_H_
