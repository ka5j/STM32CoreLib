/*******************************************************************************************
 * @file    nvic_registers.h
 * @author  ka5j
 * @brief   STM32F446RE NVIC Register Definitions (Bare Metal)
 * @version 1.0
 * @date    2025-05-01
 *
 * @note    This file defines memory-mapped register access for the NVIC system.
 *          Assumes 32-bit ARM Cortex-M4 platform with no CMSIS dependency.
 *******************************************************************************************/

#ifndef NVIC_REGISTERS_H_
#define NVIC_REGISTERS_H_

#include <stdint.h>
#include "stm32f446re_addresses.h" // Must define CORTEX_M4_PERIPH_BASE

/*******************************************************************************************
 * NVIC Base Address (ARM-defined for Cortex-M4)
 *******************************************************************************************/
#define NVIC_BASE (CORTEX_M4_PERIPH_BASE + 0x100U)
#define NVIC_NUM_INTERRUPTS 240U

/*******************************************************************************************
 * NVIC Register Structure (simplified to core features)
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t ISER[8]; /*!< Interrupt Set Enable Registers (0x100 - 0x11C) */
    uint32_t RESERVED0[24];
    volatile uint32_t ICER[8]; /*!< Interrupt Clear Enable Registers (0x180 - 0x19C) */
    uint32_t RESERVED1[24];
    volatile uint32_t ISPR[8]; /*!< Interrupt Set Pending Registers (0x200 - 0x21C) */
    uint32_t RESERVED2[24];
    volatile uint32_t ICPR[8]; /*!< Interrupt Clear Pending Registers (0x280 - 0x29C) */
    uint32_t RESERVED3[24];
    volatile uint32_t IABR[8]; /*!< Interrupt Active Bit Registers (0x300 - 0x31C) */
    uint32_t RESERVED4[56];
    volatile uint8_t IP[NVIC_NUM_INTERRUPTS]; /*!< Interrupt Priority Registers (0x400 - 0x4EF) */
    uint32_t RESERVED5[644];                  /*!< Reserved to align STIR at 0xF00 */
    volatile uint32_t STIR;                   /*!< Software Trigger Interrupt Register (0xF00) */
} NVIC_TypeDef;

#define NVIC ((NVIC_TypeDef *)NVIC_BASE)

#endif /* NVIC_REGISTERS_H_ */
