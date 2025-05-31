#include "board_api.h"

int main(void)
{
    board_pwm_led_init();
    board_pwm_set_brightness(100); // 75% brightness
                                   // hiiiiii
    while (1)
        ;
}
