// header files
#include "pwmTIM.h"
#include "pwmGPIO.h"
#include "gpio.h"


// main function: repeatedly blinking LED 2.
void main (void) {
    rccInit(); // will enable the AHB1 bus for ports A-H
    pwm_setupEZ(); // will enable AF for PA5 and then the correct AF1 for PA5.
    tim_setupEZ(); // will enable the clock to TIM2 and configure it accordingly.
    timSetDutyCycle(100);

    while (1) {
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
    // Optional: you can blink an LED or log the file/line
    // For now, just trap in an infinite loop
    while(1);
}
#endif

