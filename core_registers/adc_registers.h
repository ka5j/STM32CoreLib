/*******************************************************************************************
 * @file    adc_registers.h
 * @author  ka5j
 * @brief   STM32F446RE ADC1 Register Definitions (Bare Metal)
 * @version 1.0
 * @date    2025-05-30
 *
 * @note    Only ADC1 is mapped here. Supports regular single-channel conversions.
 *******************************************************************************************/

#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#include <stdint.h>
#include "stm32f446re_addresses.h"

/*******************************************************************************************
 * ADC1 Base Address (AHB2 bus)
 *******************************************************************************************/
#define ADC1_BASE (APB2PERIPH_BASE + 0x2000UL)
#define ADC1 ((ADC_TypeDef *)ADC1_BASE)

/*******************************************************************************************
 * ADC Register Map (Simplified)
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t SR;    /*!< ADC status register,              offset: 0x00 */
    volatile uint32_t CR1;   /*!< ADC control register 1,           offset: 0x04 */
    volatile uint32_t CR2;   /*!< ADC control register 2,           offset: 0x08 */
    volatile uint32_t SMPR1; /*!< ADC sample time register 1,       offset: 0x0C */
    volatile uint32_t SMPR2; /*!< ADC sample time register 2,       offset: 0x10 */
    volatile uint32_t JOFR1; /*!< Injected channel data offset 1,   offset: 0x14 */
    volatile uint32_t JOFR2; /*!< Injected channel data offset 2,   offset: 0x18 */
    volatile uint32_t JOFR3; /*!< Injected channel data offset 3,   offset: 0x1C */
    volatile uint32_t JOFR4; /*!< Injected channel data offset 4,   offset: 0x20 */
    volatile uint32_t HTR;   /*!< ADC watchdog high threshold,      offset: 0x24 */
    volatile uint32_t LTR;   /*!< ADC watchdog low threshold,       offset: 0x28 */
    volatile uint32_t SQR1;  /*!< Regular sequence register 1,      offset: 0x2C */
    volatile uint32_t SQR2;  /*!< Regular sequence register 2,      offset: 0x30 */
    volatile uint32_t SQR3;  /*!< Regular sequence register 3,      offset: 0x34 */
    volatile uint32_t JSQR;  /*!< Injected sequence register,       offset: 0x38 */
    volatile uint32_t JDR1;  /*!< Injected data register 1,         offset: 0x3C */
    volatile uint32_t JDR2;  /*!< Injected data register 2,         offset: 0x40 */
    volatile uint32_t JDR3;  /*!< Injected data register 3,         offset: 0x44 */
    volatile uint32_t JDR4;  /*!< Injected data register 4,         offset: 0x48 */
    volatile uint32_t DR;    /*!< Regular data register,            offset: 0x4C */
} ADC_TypeDef;

#endif // ADC_REGISTERS_H_
