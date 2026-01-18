#ifndef DRIVERS_INCLUDE_FAN__
#define DRIVERS_INCLUDE_FAN__

#include <stdint.h>
#include "stm32f4xx_rcc.h"
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_conf.h"


void timerSetup (void);
void tim_setupEZ(void);
void timSetDutyCycle(uint8_t duty);


#endif