#include "pwmTIM.h"

// Reset clock is 16_000_000 Hz
// Frequency_of_Clock = System_Frequency / (PSC + 1)(ARR + 1)

void timerSetup(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk; // activate tim2
    uint32_t dummy;
    dummy = RCC->APB1ENR;
    dummy = RCC->APB1ENR; 

    // INTIAL CKD, ALIGNMENT, CD
    // set the clock divison as 1x
    TIM2->CR1 |= (0b00 << TIM_CR1_CKD_Pos);
    // set the alignment mode as edge-aligned
    TIM2->CR1 |= (0b00 << TIM_CR1_CMS_Pos);
    // set count direction as up
    TIM2->CR1 |= (0UL << TIM_CR1_DIR_Pos);

    // PWM SETUP
    // Set 110 in the OCxM bit in the TIMx_CCMR register to actually enable PWM
    TIM2->CCMR1 |= (0b110 << TIM_CCMR1_OC1M_Pos);

    // FREQUENCY, DUTY CYCLE, PRESCALER-- about 1.kHz with a 25% duty cycle
    // Set the prescaler
    TIM2->PSC = 1000 - 1;
    // Set the ARR
    TIM2->ARR = 100 - 1;
    // Set the duty cycle
    TIM2->CCR1 = 25;

    // ENABLING
    // enable Capture/Compare output on Channel 1
    TIM2->CCER |= TIM_CCER_CC1E_Msk;

}