// header files
#include "gpio.h"
#include "tim.h"


uint8_t led_signal = 1; // should go into the data section... for testing and debugging practice.

// main function: repeatedly blinking LED 2.
void main (void) {
    ledInit();
    timInit();

    while (1) {
        ledToggle();
        led_signal = ledRead();
        timStartSecond(2); // 2 second delay

    }
}