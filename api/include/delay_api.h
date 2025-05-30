#ifndef DELAY_H_
#define DELAY_H_

#include <stdint.h>

void delay_ms(uint32_t ms); // One-shot delay using your bare_systick functions
void delay_us(uint32_t us); // One-shot delay using your bare_systick functions

#endif
