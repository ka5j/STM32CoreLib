#include "board_api.h"
#include "gpio_api.h"
#include "delay_api.h"
#include "usart_api.h"

#define BOARD_LED_PORT GPIO_PORTA
#define BOARD_LED_PIN PIN5

#define USER_BTN_PORT GPIO_PORTC
#define USER_BTN_PIN PIN13

void board_init(void)
{
    board_led_off(); // optional default
    board_button_init();
    usart_init(USART_PORT_2, 115200);
}

void board_led_on(void)
{
    led_set(BOARD_LED_PORT, BOARD_LED_PIN, ON);
}

void board_led_off(void)
{
    led_init(BOARD_LED_PORT, BOARD_LED_PIN); // ✅ ensure pin always configured
    led_set(BOARD_LED_PORT, BOARD_LED_PIN, OFF);
}

void board_led_toggle(void)
{
    led_toggle(BOARD_LED_PORT, BOARD_LED_PIN);
}

void board_button_init(void)
{
    button_init(BOARD_BTN_PORT, BOARD_BTN_PIN);
}

uint8_t board_button_pressed(void)
{
    return button_is_pressed(BOARD_BTN_PORT, BOARD_BTN_PIN);
}

void board_wait_for_button_press(void)
{
    while (!board_button_pressed())
        ;
}

void board_usart_send(const char *msg)
{
    usart_send_string(USART_PORT_2, msg);
}

char board_usart_receive_char(void)
{
    return usart_read_char(USART_PORT_2);
}

void board_usart_clear(void)
{
    usart_clear(USART_PORT_2);
}
