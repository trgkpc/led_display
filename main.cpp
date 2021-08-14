#define F_CPU 1000000
#include "firmware/led.hpp"
#include "firmware/pwm.hpp"
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRB = 0x00;
    DDRC = 0x00;
    DDRD = 0x01;

    PORTB = 0xff;
    PORTC = 0xff;
    PORTD = 0xff;
    
    auto led1 = LEDD0();
    PWM0A pwm = PWM0A();
    uint8_t t = 0;

    while(1){
        led1.toggle();
        pwm.set(t);
        _delay_ms(100);
        t += 25;
    }
}
