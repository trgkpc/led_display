#include <iostream>
#include <string>
#define _SFR_IO8(id) (id)
#define print(name) print_impl(#name, name)
void print_impl(std::string name, int id)
{
    std::cout  << name << " " << id << std::endl;
}
void define_led(std::string X, int ddr, int port, int id)
{
    std::string name = "LED" + X;
    std::cout << "#define " << name << id << " ";
    std::cout << "LED<" << ddr << "," << port << "," << id << ">" << std::endl;
}
void define_leds(std::string X, int ddr, int port)
{
    for(int i=0; i<8; i++){
        define_led(X, ddr, port, i);
    }
}
#define LEDX_IMPL(X) define_leds(#X, DDR##X,  PORT##X)

#define _AVR_IO_H_
#include </usr/lib/avr/include/avr/iom328p.h>

int main()
{
    //print(DDRD);
    LEDX_IMPL(B);
    LEDX_IMPL(C);
    LEDX_IMPL(D);
}

