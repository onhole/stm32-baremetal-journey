#ifndef DRIVERS_INCLUDE_TIM_H_
#define DRIVERS_INCLUDE_TIM_H_
#include <stdint.h>
#include "stm32f4xx.h"

void timInit(void);
void timStartSecond(uint8_t delay);

#endif