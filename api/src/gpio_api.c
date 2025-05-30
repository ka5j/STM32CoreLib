#include "bare_gpio.h"
#include "gpio_api.h"

static GPIO_TypeDef *get_port(GPIO_Port_t port)
{
    switch (port)
    {
    case GPIO_PORTA:
        return GPIOA;
    case GPIO_PORTB:
        return GPIOB;
    case GPIO_PORTC:
        return GPIOC;
    case GPIO_PORTD:
        return GPIOD;
    case GPIO_PORTE:
        return GPIOE;
    case GPIO_PORTF:
        return GPIOF;
    case GPIO_PORTG:
        return GPIOG;
    case GPIO_PORTH:
        return GPIOH;
    default:
        return GPIOA; // fallback
    }
}

void led_init(GPIO_Port_t port, GPIO_Pin_t pin)
{
    GPIO_TypeDef *gpio = get_port(port);
    bare_gpio_init(gpio, (GPIO_Pins_t)pin, GPIO_MODE_OUTPUT, GPIO_OTYPE_PP, GPIO_SPEED_LOW, GPIO_NOPULL);
}

void led_set(GPIO_Port_t port, GPIO_Pin_t pin, PinState state)
{
    GPIO_TypeDef *gpio = get_port(port);
    if (state)
    {
        bare_gpio_write(gpio, (GPIO_Pins_t)pin, state);
    }
    else
    {
        bare_gpio_write(gpio, (GPIO_Pins_t)pin, state);
    }
}

void led_toggle(GPIO_Port_t port, GPIO_Pin_t pin)
{
    GPIO_TypeDef *gpio = get_port(port);
    bare_gpio_toggle(gpio, (GPIO_Pins_t)pin);
}

uint8_t led_status(GPIO_Port_t port, GPIO_Pin_t pin)
{
    GPIO_TypeDef *gpio = get_port(port);
    return bare_gpio_check_state(gpio, (GPIO_Pins_t)pin);
}

void button_init(GPIO_Port_t port, GPIO_Pin_t pin)
{
    bare_gpio_init(get_port(port), pin, GPIO_MODE_INPUT, GPIO_OTYPE_PP, GPIO_SPEED_LOW, GPIO_PULLUP);
}

uint8_t button_is_pressed(GPIO_Port_t port, GPIO_Pin_t pin)
{
    return (bare_gpio_read(get_port(port), pin) == 0); // Active LOW
}