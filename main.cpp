#define F_CPU 1000000
#include "firmware/led.hpp"
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x00;
    DDRC = 0x00;
    DDRD = 0x01;

    PORTB = 0xff;
    PORTC = 0xff;
    PORTD = 0xff;
    
    LED LED0 = GET_LED(D, 0);

    while(1){
        LED0.toggle();
        _delay_ms(100);
    }
}
