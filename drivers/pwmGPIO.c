#include "pwmGPIO.h"

/*
void pwmModerInit(void) {
    // Set GPIOA PA5 to AF
    GPIOA->MODER |= (0b10 << GPIO_MODER_MODE5_Pos);
    GPIOA->AFR[0] |= (GPIO_AFRL_AFRL5_0);
}

void pwmLedOn(void) {
    TIM2->CR1 |= TIM_CR1_CEN;
}
*/

void pwm_setupEZ(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);
    /* configure PA5 in af mode. */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2);

}
