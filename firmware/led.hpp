#pragma once
#include <avr/io.h>

#define DDRX    _SFR_IO8(DDRX_ADDR)
#define PORTX   _SFR_IO8(PORTX_ADDR)
#define LED_BIT (1<<(id))
template <uint8_t DDRX_ADDR, uint8_t PORTX_ADDR, uint8_t id>
struct LED
{
    LED()
        : bit(1<<id)
    {
    }

    void init()
    {
        DDRX |= LED_BIT;
    }

    void on()
    {
        PORTX |= LED_BIT;
    }

    void off()
    {
        PORTX &= ~LED_BIT;
    }

    void toggle()
    {
        PORTX ^= LED_BIT;
    }

    uint8_t bit;
};

#include "address/led.hpp"
