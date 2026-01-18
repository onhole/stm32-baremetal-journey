#include "pwmTIM.h"

// Reset clock is 16_000_000 Hz
// Frequency_of_Clock = System_Frequency / (PSC + 1)(ARR + 1)
/*
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
*/
void tim_setupEZ(void) {
    // enable clock
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    uint32_t dummy;
    dummy = RCC->APB1ENR;
    dummy = RCC->APB1ENR;

    /* Compute the prescaler value */
    uint16_t PrescalerValue = (uint16_t) (1000 - 1);
    uint16_t arrValue = (uint16_t) (100 - 1); // resolution
    uint16_t CCR1_Val = (uint16_t) (0); // initial duty cycle.

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);

    /*
    TIM2->PSC = 1000 - 1;
    // Set the ARR
    TIM2->ARR = 100 - 1;
    // Set the duty cycle
    TIM2->CCR1 = 25;
    */

    /* Time base configuration */
    TIM_TimeBaseStructure.TIM_Period = arrValue;
    TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    /* PWM1 Mode configuration: Channel1 */
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM2, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

    /* TIM3 enable counter */
    TIM_Cmd(TIM2, ENABLE);


}

void timSetDutyCycle(uint8_t duty) {
    // set the ccr1 value according to the duty cycle that is wanted.
    if (duty > 100) { // caps out at 100%.
        duty = 100;
    }
    TIM2->CCR1 = (TIM2->ARR * duty) / 100;
}