#ifndef GPIO_API_H_
#define GPIO_API_H_

#include <stdint.h>

typedef enum
{
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF,
    GPIO_PORTG,
    GPIO_PORTH
} GPIO_Port_t;

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} GPIO_Pin_t;

typedef enum
{
    OFF = 0,
    ON = 1
} PinState;

/* General GPIO functions */
void led_init(GPIO_Port_t port, GPIO_Pin_t pin);
void led_set(GPIO_Port_t port, GPIO_Pin_t pin, PinState state);
void led_toggle(GPIO_Port_t port, GPIO_Pin_t pin);
uint8_t led_status(GPIO_Port_t port, GPIO_Pin_t pin);
void button_init(GPIO_Port_t port, GPIO_Pin_t pin);
uint8_t button_is_pressed(GPIO_Port_t port, GPIO_Pin_t pin);

#endif
