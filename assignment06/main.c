//Thanit Mitparien
//Assignment06, Problem02: This main will be using user_led.s and delay.s to
//blink LED light by passing state of LED and the delay duration between
//On and Off state. These parameters will be passing to control_user_led func
//which it will call up delay function inside.

#include <stdint.h>

#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION 1000000

extern void delay(uint32_t);
extern void control_user_led(uint8_t, uint32_t);

void main(void)
{
      while(1)
    {
        control_user_led(LED_ON, DELAY_DURATION);
        control_user_led(LED_OFF, DELAY_DURATION);
    }
}
