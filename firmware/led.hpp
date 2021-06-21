#include <stdint.h>

struct LED
{
    LED(uint8_t id)
        : bit(1<<id)
    {
    }

    virtual void init() = 0;
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void toggle() = 0;
    uint8_t bit;
};

#define DEFINE_LED(X)           \
struct LED##X : LED             \
{                               \
    LED##X(uint8_t id)          \
        : LED(id)               \
    {                           \
        init();                 \
    }                           \
                                \
    void init() override        \
    {                           \
        DDR##X |= bit;          \
        PORT##X &= ~bit;        \
    }                           \
                                \
    void on() override          \
    {                           \
        PORT##X |= bit;         \
    }                           \
                                \
    void off() override         \
    {                           \
        PORT##X &= ~bit;        \
    }                           \
                                \
    void toggle() override      \
    {                           \
        PORT##X ^= bit;         \
    }                           \
};


