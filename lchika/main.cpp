#define F_CPU 1000000
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void led(volatile uint8_t* port)
{
    (*port) = 1;
}

int main(void)
{
    DDRB = 0x00;
    DDRC = 0x00;
    DDRD = 0x01;

    PORTB = 0xff;
    PORTC = 0xff;
    PORTD = 0xff;

    while(1){
        //PIND = 0xff;
        led(&PIND);
        _delay_ms(100);
    }
}
