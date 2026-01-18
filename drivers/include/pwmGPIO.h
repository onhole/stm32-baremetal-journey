#ifndef DRIVERS_INCLUDE_PWMGPIO__
#define DRIVERS_INCLUDE_PWMGPIO__

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_conf.h"

void pwmModerInit(void);
void pwmLedOn(void);
void pwm_setupEZ(void);

#endif