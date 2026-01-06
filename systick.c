#include "systick.h"

// need to define what we are going to do with the systick registers.
#define CLK_ENABLE (1u << 0)
#define CLK_SOURCE_MODE (1u << 2)
#define COUNT_FLAG (1u << 16)

// since we are trying to do a ms systick clock, we need to define the decimal value as follows because it corresponds to the rest HCI, which is 16MHz.
// 16MHz = 16,000,000 cycles / second
// if we want to count by the milisecond, we need to 16MHz * 1s/1000ms = 16,000 cycles / 1 milisecond.
# define TICKS_PER_MS (16000)

// function
void systickMsDelay (uint32_t delay) {
    // Set the value for the loader.
    SysTick->LOAD = TICKS_PER_MS - 1;

    // Clear current value
    SysTick->VAL = 0; // reset value is all zeros anyways, so this would be okay.

    // Set the clock source. This register also starts from zero so doing this kind of mask is okay.
    SysTick->CTRL = CLK_SOURCE_MODE;

    // Enabling Systick now will start the countdown, this will cost a few bus cycle and therefore might make it slightly inaccurate.
    SysTick->CTRL |= CLK_ENABLE;

    for (int i = 0; i < delay; i++) {
        while (!(SysTick->CTRL & COUNT_FLAG)) {} // this reads only the 16th bit but it doesn't modify anything.
    }

    // finally disable to conserve power.
    SysTick->CTRL = 0; // this is again okay because we are just putting it back to reset value.
}
