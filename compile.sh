avr-gcc -g -O2 -mmcu=atmega328p main.c 
avr-objcopy -j .text -j .data -O ihex a.out binary.hex
echo "avrdude -e -c avrisp2 -p m328p -U flash:w:binary.hex -F"
