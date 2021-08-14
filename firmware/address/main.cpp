// 入出力機能
#include <iostream>
#include <fstream>
#include <string>
using std::cout, std::cerr, std::endl;
using std::ofstream;
using std::string, std::to_string;
#define _SFR_IO8(id) (id)
#define print(name) (cout << (#name) << " " <<(name) << endl);
ofstream f;
void define_led(string X, int ddr, int port, int id)
{
    string name = "LED_" + X + to_string(id);
    f << "#define" << " " << name << " ";
    f << "LED<" << ddr << "," << port << "," << id << ">" << endl;
}
void define_leds(string X, int ddr, int port)
{
    for(int i=0; i<8; i++){
        define_led(X, ddr, port, i);
    }
}
#define LED(X) define_leds(#X, DDR##X, PORT##X)

// ピン周りのファイル読み込み
#define _AVR_IO_H_
#include </usr/lib/avr/include/avr/iom328p.h>

int main()
{
    f = ofstream("led.hpp");
    LED(B);
    LED(C);
    LED(D);
    f.close();

}
