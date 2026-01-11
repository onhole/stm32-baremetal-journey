#include "tim.h"

void timInit (void) {
    // enable the APB1 BUS
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk; // activated tim2
    uint32_t dummy;
    dummy = RCC->APB1ENR;
    dummy = RCC->APB1ENR; 

    // ensure the counter is 0
    TIM2->CNT = 0; // this is the actual counter that gets counted.

    // set your prescaler. the internal clock is 16MHz
    TIM2->PSC = 65535 - 1; // 16MHz / 65535 = 244
    TIM2->ARR = 244 - 1; // 244Hz / 244 = 1Hz = 1 cycle per second.

    // timer should be ready to activate
}

void timStartSecond(uint8_t delay) {
    TIM2->CR1 |= TIM_CR1_CEN; // goes to the TIM2_CR2 register and then turns on the first bit, which is the Counter Enable bit. This CR1 (channel 1 or control register 1) will start counting.
    for (uint8_t i = 1; i <= delay; i++) {
        while (!(TIM2->SR & TIM_SR_UIF)) {} // if UIF bit is 0, this function returns true, so it keeps running.
        TIM2->SR &= ~(TIM_SR_UIF); // the only 0 bit in the mask is the first bit, which will always make that 0th bit in SR 0, reseting only bit 1 and nothing else in SR. 
    }
}
