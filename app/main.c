// header files
#include "pwmTIM.h"
#include "pwmGPIO.h"
#include "gpio.h"


uint8_t led_signal = 1; // should go into the data section... for testing and debugging practice.

// main function: repeatedly blinking LED 2.
void main (void) {
    rccInit(); // will enable the AHB1 bus for ports A-H
    timerSetup(); // will enable the clock to TIM2 and configure it accordingly.
    pwmModerInit(); // will enable AF for PA5 and then the correct AF1 for PA5.

    // TURN ON LED
    pwmLedOn();

    while (1) {
    }
}