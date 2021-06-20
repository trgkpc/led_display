# led display
- めちゃデカドットマトリクスをAVR(mega328p)で制御しようという斬新な試み
# 環境構築
- AVR用のコンパイラと書き込み
  - `sudo apt-get install avr-libc gcc-avr avrdude`
  - `#include <avr/interrupt.h>` が見つからないときはinclude順かもしれない

