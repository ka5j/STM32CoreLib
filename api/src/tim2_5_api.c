#include "tim2_5_api.h"
#include "../../core/include/bare_tim2_5.h"

static TIM2_5_TypeDef *get_timer_instance(TimerPort timer)
{
    switch (timer)
    {
    case TIMER_2:
        return TIM2;
    case TIMER_3:
        return TIM3;
    case TIMER_4:
        return TIM4;
    case TIMER_5:
        return TIM5;
    default:
        return TIM2;
    }
}

void tim_init(TimerPort timer)
{
    TIM2_5_TypeDef *TIMx = get_timer_instance(timer);
    bare_tim2_5_set(TIMx);
}

void tim_start(TimerPort timer)
{
    TIM2_5_TypeDef *TIMx = get_timer_instance(timer);
    bare_tim2_5_start(TIMx);
}

void tim_stop(TimerPort timer)
{
    TIM2_5_TypeDef *TIMx = get_timer_instance(timer);
    bare_tim2_5_stop(TIMx);
}

void tim_pwm_enable(TimerPort timer)
{
    TIM2_5_TypeDef *TIMx = get_timer_instance(timer);
    bare_tim2_5_PWM(TIMx);
}

void tim_pwm_set_duty(TimerPort timer, uint8_t percent)
{
    TIM2_5_TypeDef *TIMx = get_timer_instance(timer);
    bare_pwm_set_duty(TIMx, percent);
}
