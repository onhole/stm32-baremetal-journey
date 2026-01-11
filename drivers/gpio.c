#include "gpio.h"
#define LED (5)

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

void ledInit (void) {
    rccInit(); // turns on clock for AHB1ENR
    moderInit(); // GPIOA mode to output.
}

void ledToggle (void) {
    GPIOA->ODR ^= (1u << LED);
}

uint8_t ledRead (void) {
    return ((1u << LED) & GPIOA->ODR) >> LED;
}