// header files
#include "systick.h" // already includes stm32f4xx.h and stdint.h

#define LED (5)

uint8_t led_signal = 1; // should go into the data section... for testing and debugging practice.

// function prototype for initializing clock and direction.
void rccInit (void);
void moderInit (void);

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

// subroutines.
void rccInit (void) {
    RCC->AHB1ENR |= (1u);
    uint32_t dummy;
    dummy = RCC->AHB1ENR;
    dummy = RCC->AHB1ENR;

}

void moderInit (void) {
    GPIOA->MODER &= ~(3u << 10); // makes bit 11 and 10 become 0 and leave the rest untouched.
    GPIOA->MODER |= (1u << 10);

}