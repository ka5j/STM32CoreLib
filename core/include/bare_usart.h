/*******************************************************************************************
 * @file    bare_usart.h
 * @author  ka5j
 * @brief   STM32F446RE USART Peripheral Low-Level Driver (Bare Metal)
 * @version 1.2
 * @date    2025-05-30
 *
 * @note    This file provides low-level register access for USARTx peripherals.
 *          It allows initialization, character transmission/reception, and string output.
 *          GPIO setup for each USART is handled based on the USARTx instance.
 *******************************************************************************************/

#ifndef BARE_USART_H_
#define BARE_USART_H_

#include <stdint.h>
#include "stm32f446re_addresses.h"
#include "usart_registers.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /*************************************
     * Public API (Modular, USARTx-Based)
     *************************************/

    /**
     * @brief Initialize specified USART peripheral with a given baud rate
     * @param usartx Pointer to USARTx (USART1, USART2, USART3, USART6)
     * @param baud Baud rate (e.g., 9600, 115200)
     */
    void bare_usart_init_port(USART_TypeDef *usartx, uint32_t baud);

    /**
     * @brief Send a null-terminated string over USART
     * @param usartx USART peripheral to use
     * @param msg String to send
     */
    void bare_usart_send_string_port(USART_TypeDef *usartx, const char *msg);

    /**
     * @brief Read a single character from USART (blocking)
     * @param usartx USART peripheral to read from
     * @return Received character
     */
    char bare_usart_read_char_port(USART_TypeDef *usartx);

    /**
     * @brief Clear terminal using ANSI escape codes
     * @param usartx USART peripheral to output escape codes
     */
    void bare_usart_clear_screen_port(USART_TypeDef *usartx);

    /*************************************
     * Optional: Default USART2 Shortcuts
     *************************************/

    void bare_usart_init(void);                   // Defaults to USART2 @ 115200
    void bare_usart_send_string(const char *msg); // Uses USART2
    char bare_usart_read_char(void);              // Uses USART2
    void bare_usart_clear_screen(void);           // Uses USART2

#ifdef __cplusplus
}
#endif

#endif // BARE_USART_H_
