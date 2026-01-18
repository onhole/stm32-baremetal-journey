#include "stm32f4xx_conf.h"

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
    // Optional: you can blink an LED or log the file/line
    // For now, just trap in an infinite loop
    while(1);
}
#endif
