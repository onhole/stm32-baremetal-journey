// header files
#include "systick.h" // already includes stm32f4xx.h and stdint.h
#include "gpio.h"

#define LED (5)

uint8_t led_signal = 1; // should go into the data section... for testing and debugging practice.

// main function: repeatedly blinking LED 2.
void main (void) {
    rccInit();
    moderInit();

    while (1) {
        GPIOA->ODR ^= (1u << LED);
        led_signal = ((1u << LED) & GPIOA->ODR) >> LED;
        systickMsDelay(500); // delay for 500ms.

    }
}