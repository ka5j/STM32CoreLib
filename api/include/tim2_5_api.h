#ifndef TIM2_5_API_H_
#define TIM2_5_API_H_

#include <stdint.h>

/**
 * @brief Abstracted timer port enumeration
 */
typedef enum
{
    TIMER_2,
    TIMER_3,
    TIMER_4,
    TIMER_5
} TimerPort;

/**
 * @brief Initialize the timer (prescaler + ARR config)
 */
void tim_init(TimerPort timer);

/**
 * @brief Start the timer
 */
void tim_start(TimerPort timer);

/**
 * @brief Stop the timer
 */
void tim_stop(TimerPort timer);

/**
 * @brief Enable PWM output mode
 */
void tim_pwm_enable(TimerPort timer);

/**
 * @brief Set PWM duty cycle
 * @param percent 0–100
 */
void tim_pwm_set_duty(TimerPort timer, uint8_t percent);

#endif // TIM2_5_API_H_
