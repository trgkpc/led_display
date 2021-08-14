#define F_CPU 1000000
#include "firmware/led.hpp"
#include "firmware/pwm.hpp"
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <util/delay.h>
#include <avr/interrupt.h>

auto led_green = LED_D0();
auto pwm = PWM0A();

int main(void)
{
    uint8_t t = 0;

    while(1){
        led_green.toggle();
        pwm.set(t);
        _delay_ms(100);
        t += 25;
    }
}
