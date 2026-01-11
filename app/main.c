// header files
#include "systick.h" // already includes stm32f4xx.h and stdint.h
#include "gpio.h"


uint8_t led_signal = 1; // should go into the data section... for testing and debugging practice.

// main function: repeatedly blinking LED 2.
void main (void) {
    ledInit();

    while (1) {
        ledToggle();
        led_signal = ledRead();
        systickMsDelay(250); // delay for 500ms.

    }
}