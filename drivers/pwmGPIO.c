#include "pwmGPIO.h"

void pwmModerInit(void) {
    // Set GPIOA PA5 to AF
    GPIOA->MODER |= (0b10 << GPIO_MODER_MODE5_Pos);
    GPIOA->AFR[0] |= (GPIO_AFRL_AFRL5_0);
}

void pwmLedOn(void) {
    TIM2->CR1 |= TIM_CR1_CEN;
}