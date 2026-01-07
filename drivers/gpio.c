#include "gpio.h"

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