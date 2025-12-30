// header files
#include <stdint.h>

// Define addresses for the clock, the direction, and port A.
#define RCC_BASE (0x40023800)
#define GPIOA_BASE (0x40020000)

#define RCC_AHB1ENR (RCC_BASE + 0x30)
#define GPIOA_MODER (GPIOA_BASE + 0x00)
#define GPIOA_ODR (GPIOA_BASE + 0x14)

#define RCC_GPIOAEN (*(volatile uint32_t *)(RCC_AHB1ENR)) // gets the 32-bit value of register RCC_AHB1ENR
#define GPIOA_ODR5 (*(volatile uint32_t *)(GPIOA_ODR)) // gets the 32-bit value of register GPIOA_ODR
#define GPIOA_MODER5 (*(volatile uint32_t *)(GPIOA_MODER)) // gets the 32-bit value of register GPIO_MODER

#define LED (5)

// function prototype for initializing clock and direction.
void rccInit (void);
void moderInit (void);

// main function: repeatedly blinking LED 2.
void main (void) {
    rccInit();
    moderInit();

    uint32_t led; // should go into .bss

    while (1) {
        GPIOA_ODR5 ^= (1 << 5);
        led = (GPIOA_ODR5 & (1 << 5) >> 5); // 1 if on, 0 if not.
        for (uint32_t i = 0; i < 1000000; i++);

    }
}

// subroutines.
void rccInit (void) {
    RCC_GPIOAEN |= (1);
    uint32_t dummy;
    dummy = RCC_GPIOAEN;
    dummy = RCC_GPIOAEN;

}

void moderInit (void) {
    GPIOA_MODER5 &= ~(3 << 10); // makes bit 11 and 10 become 0 and leave the rest untouched.
    GPIOA_MODER5 |= (1 << 10);

}