#ifndef DRIVERS_INCLUDE_PWMGPIO__
#define DRIVERS_INCLUDE_PWMGPIO__

#include <stdint.h>
#include "stm32f4xx.h"

void pwmModerInit(void);
void pwmLedOn(void);

#endif