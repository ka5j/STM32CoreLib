#include "delay_api.h"
#include "bare_systick.h"

#define SYSTEM_CLOCK_HZ SYSTICK_1SEC_RELOAD_16MHZ

void delay_ms(uint32_t ms)
{
    uint32_t ticks = (SYSTEM_CLOCK_HZ / 1000U) * ms;

    // Set timer using your bare_systick API
    SysTick_Set_TIMER(ticks);
    SysTick_Init(ticks, SYSTICK_PROCESSOR_CLK, SYSTICK_DISABLE_INTERRUPT);

    // Wait for COUNTFLAG
    while (!(SYSTICK->CSR & (1 << 16)))
        ;

    // Disable SysTick after delay
    SYSTICK->CSR = 0;
}

void delay_us(uint32_t us)
{
    uint32_t ticks = (SYSTEM_CLOCK_HZ / 1000000U) * us;

    // Set timer using your bare_systick API
    SysTick_Set_TIMER(ticks);
    SysTick_Init(ticks, SYSTICK_PROCESSOR_CLK, SYSTICK_DISABLE_INTERRUPT);

    // Wait for COUNTFLAG
    while (!(SYSTICK->CSR & (1 << 16)))
        ;

    // Disable SysTick after delay
    SYSTICK->CSR = 0;
}
