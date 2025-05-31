/*******************************************************************************************
 * @file    bare_adc.c
 * @author  ka5j
 * @brief   STM32F446RE ADC1 Bare Metal Driver for Analog Sensor Input
 * @version 1.0
 * @date    2025-05-30
 *
 * @note    Bare-metal access for single-conversion ADC input using ADC1.
 *******************************************************************************************/

#include "bare_adc.h"
#include "gpio_registers.h"
#include "rcc_registers.h"
#include "stm32f446re_addresses.h"

/***************************************
 * Internal Helper: Channel-to-Pin Map
 ***************************************/
static void enable_gpio_clock_for_channel(uint8_t channel)
{
    switch (channel)
    {
    case 0 ... 7:
        RCC->AHB1ENR |= (1 << 0); // GPIOA
        break;
    case 8 ... 9:
        RCC->AHB1ENR |= (1 << 1); // GPIOB
        break;
    case 10 ... 15:
        RCC->AHB1ENR |= (1 << 2); // GPIOC
        break;
    }
}

static void set_gpio_analog_mode_for_channel(uint8_t channel)
{
    enable_gpio_clock_for_channel(channel);

    if (channel <= 7)
    {
        GPIOA->MODER |= (3 << (channel * 2)); // Analog mode = 11
    }
    else if (channel == 8 || channel == 9)
    {
        GPIOB->MODER |= (3 << ((channel - 8) * 2));
    }
    else if (channel >= 10 && channel <= 15)
    {
        GPIOC->MODER |= (3 << ((channel - 10) * 2));
    }
}

/***************************************
 * Public Functions
 ***************************************/

void bare_adc_enable(void)
{
    RCC->APB2ENR |= (1 << 8); // Enable ADC1 clock

    ADC1->CR2 &= ~(1 << 1);  // Disable continuous mode
    ADC1->CR1 &= ~(3 << 24); // 12-bit resolution
    ADC1->CR2 |= (1 << 0);   // Enable ADC1
}

void bare_adc_gpio_init(uint8_t channel)
{
    set_gpio_analog_mode_for_channel(channel);
}

void bare_adc_channel_enable(uint8_t channel)
{
    // Set regular sequence length to 1
    ADC1->SQR1 &= ~(0xF << 20);

    // Set channel in SQR3 (first conversion in sequence)
    ADC1->SQR3 = (ADC1->SQR3 & ~0x1F) | (channel & 0x1F);
}

uint16_t bare_adc_read_channel(uint8_t channel)
{
    bare_adc_channel_enable(channel);

    ADC1->CR2 |= (1 << 30); // Start conversion (SWSTART)

    while (!(ADC1->SR & (1 << 1)))
        ; // Wait for EOC (End Of Conversion)

    return (uint16_t)(ADC1->DR & 0x0FFF); // Return 12-bit result
}
