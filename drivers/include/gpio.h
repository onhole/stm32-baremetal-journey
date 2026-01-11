#ifndef GPIO_H_

#include "stm32f4xx.h"
#include <stdint.h>

void rccInit (void);
void moderInit (void);
void ledInit (void);
void ledToggle (void);
uint8_t ledRead (void);

#endif