#include <stdint.h>

struct LED
{
    explicit LED(volatile uint8_t* DDRX_, volatile uint8_t* PORTX_, volatile uint8_t* PINX_, uint8_t id)
        : DDRX(DDRX_), PORTX(PORTX_), PINX(PINX_), bit(1<<id)
    {
        (*DDRX) |= bit;
        (*PORTX) &= ~bit;
    }

    void init()
    {
        (*DDRX) |= bit;
        (*PORTX) &= ~bit;
    }

    void on()
    {
        (*PORTX) |= bit;
    }

    void off()
    {
        (*PORTX) &= ~bit;
    }

    void toggle()
    {
        (*PORTX) ^= bit;
    }
    
private:
    volatile uint8_t* DDRX;
    volatile uint8_t* PORTX;
    volatile uint8_t* PINX;
    uint8_t bit;
};

#define GET_LED(NAME, ID) LED(&DDR##NAME, &PORT##NAME, &PIN##NAME, ID)
