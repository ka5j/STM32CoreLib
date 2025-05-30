/*******************************************************************************************
 * @file    bare_usart.c
 * @author  ka5j
 * @brief   STM32F446RE USART Peripheral Low-Level Driver (Bare Metal)
 * @version 1.2
 * @date    2025-05-30
 *******************************************************************************************/

#include "bare_usart.h"
#include "gpio_registers.h"
#include "bare_gpio.h"
#include "gpio_api.h"
#include <stddef.h>

/*******************************************
 * Internal Helper: Enable Clocks & GPIOs
 *******************************************/
static void usart_gpio_clock_enable(USART_TypeDef *usartx)
{
    if (usartx == USART1)
    {
        RCC->APB2ENR |= (1 << 4); // USART1 clock
        RCC->AHB1ENR |= (1 << 0); // GPIOA clock
    }
    else if (usartx == USART2)
    {
        RCC->APB1ENR |= (1 << 17); // USART2 clock
        RCC->AHB1ENR |= (1 << 0);  // GPIOA clock
    }
    else if (usartx == USART3)
    {
        RCC->APB1ENR |= (1 << 18); // USART3 clock
        RCC->AHB1ENR |= (1 << 1);  // GPIOB clock
    }
    else if (usartx == USART6)
    {
        RCC->APB2ENR |= (1 << 5); // USART6 clock
        RCC->AHB1ENR |= (1 << 2); // GPIOC clock
    }
}

/*******************************************
 * Internal Helper: Configure TX/RX Pins
 *******************************************/
static void usart_gpio_setup(USART_TypeDef *usartx)
{
    if (usartx == USART1)
    {
        // PA9 = TX, PA10 = RX
        bare_gpio_AF(GPIOA, (GPIO_Pins_t)PIN9, AF7);  // TX
        bare_gpio_AF(GPIOA, (GPIO_Pins_t)PIN10, AF7); // RX
    }
    else if (usartx == USART2)
    {
        // PA2 = TX, PA3 = RX (default Nucleo)
        bare_gpio_AF(GPIOA, (GPIO_Pins_t)PIN2, AF7);
        bare_gpio_AF(GPIOA, (GPIO_Pins_t)PIN3, AF7);
    }
    else if (usartx == USART3)
    {
        // PB10 = TX, PB11 = RX
        bare_gpio_AF(GPIOB, (GPIO_Pins_t)PIN10, AF7);
        bare_gpio_AF(GPIOB, (GPIO_Pins_t)PIN11, AF7);
    }
    else if (usartx == USART6)
    {
        // PC6 = TX, PC7 = RX
        bare_gpio_AF(GPIOC, (GPIO_Pins_t)PIN6, AF8);
        bare_gpio_AF(GPIOC, (GPIO_Pins_t)PIN7, AF8);
    }
}

/*******************************************
 * Public: Initialize a USART Port
 *******************************************/
void bare_usart_init_port(USART_TypeDef *usartx, uint32_t baud)
{
    if (usartx == NULL)
        return;

    usart_gpio_clock_enable(usartx);
    usart_gpio_setup(usartx);

    // Calculate baud rate (assuming 16 MHz PCLK)
    uint32_t usartdiv = (16000000U + (baud / 2U)) / baud;
    usartx->BRR = usartdiv;

    usartx->CR1 |= (1 << 3);  // TE = Transmit enable
    usartx->CR1 |= (1 << 2);  // RE = Receive enable
    usartx->CR1 |= (1 << 13); // UE = USART enable
}

/*******************************************
 * Public: Send a Null-Terminated String
 *******************************************/
void bare_usart_send_string_port(USART_TypeDef *usartx, const char *msg)
{
    if (usartx == NULL || msg == NULL)
        return;

    while (*msg != '\0')
    {
        while (!(usartx->SR & (1 << 7)))
            ; // TXE: wait for transmit buffer
        usartx->DR = *msg++;
    }
}

/*******************************************
 * Public: Read a Character (Blocking)
 *******************************************/
char bare_usart_read_char_port(USART_TypeDef *usartx)
{
    if (usartx == NULL)
        return 0;

    while (!(usartx->SR & (1 << 5)))
        ; // RXNE: wait for data
    return (char)(usartx->DR & 0xFF);
}

/*******************************************
 * Public: Clear Screen via ANSI Codes
 *******************************************/
void bare_usart_clear_screen_port(USART_TypeDef *usartx)
{
    bare_usart_send_string_port(usartx, "\033[2J\033[H");
}

/*******************************************
 * Optional: Shortcuts for Default USART2
 *******************************************/
void bare_usart_init(void)
{
    bare_usart_init_port(USART2, 115200);
}

void bare_usart_send_string(const char *msg)
{
    bare_usart_send_string_port(USART2, msg);
}

char bare_usart_read_char(void)
{
    return bare_usart_read_char_port(USART2);
}

void bare_usart_clear_screen(void)
{
    bare_usart_clear_screen_port(USART2);
}
