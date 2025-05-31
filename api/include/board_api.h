#ifndef BOARD_API_H_
#define BOARD_API_H_
#include <stdint.h>

#include "delay_api.h"
#include "gpio_api.h"
#include "usart_api.h"
#include "tim2_5_api.h"

#define BOARD_LED_PORT GPIO_PORTA
#define BOARD_LED_PIN PIN5

#define BOARD_BTN_PORT GPIO_PORTC
#define BOARD_BTN_PIN PIN13

void board_init(void);

void board_led_on(void);
void board_led_off(void);
void board_led_toggle(void);
uint8_t board_led_status(void);

void board_pwm_led_init(void);
void board_pwm_set_brightness(uint8_t percent);

void board_button_init(void);
uint8_t board_button_pressed(void);
void board_wait_for_button_press(void);

void board_usart_send(const char *msg);
char board_usart_receive_char(void);
void board_usart_clear(void);
// ANSI clear screen

uint16_t board_read_temp_sensor(void);   // PA1 / ADC1_IN1
uint16_t board_read_potentiometer(void); // PC0 / ADC1_IN10
uint16_t board_read_light_sensor(void);  // PC1 / ADC1_IN11

#endif
